#include <MeetAndroid.h>
#include <DistanceGP2Y0A21YK_aLUTs.h>
#include <SoftwareSerial.h>
#include <DistanceGP2Y0A21YK.h>
#include <Servo.h>
#include <NewPing.h>
#include <RoverPower.h>
#include <RoverDir.h>

//-----------------------------
//      DEBUG
//-----------------------------

#ifdef DEBUG
  #define DEBUG_PRINT(x)     Serial.print (x)
  #define DEBUG_PRINTDEC(x)     Serial.print (x, DEC)
  #define DEBUG_PRINTLN(x)  Serial.println (x)
#else
  #define DEBUG_PRINT(x)
  #define DEBUG_PRINTDEC(x)
  #define DEBUG_PRINTLN(x) 
#endif

//-----------------------------
//DRIVER CONSTANTS
//-----------------------------
//DRIVER DIR
#define DRIVER_DIR1 13
#define DRIVER_DIR2 12
#define DRIVER_DIR3 11
#define DRIVER_DIR4 10

//DRIVER PWM
#define DRIVER_PWM1 9
#define DRIVER_PWM2 8
#define DRIVER_PWM3 7
#define DRIVER_PWM4 6

//MOTOR VCC CURRENT LOAD
#define CH1_CURR 8
#define CH3_CURR 9

//ENCODER INTERRUPTION
#define INTER_L 0 // port 2
#define INTER_R 1 // port 3

//ENCODER SIGNALS
#define SIGNAL_L 22
#define SIGNAL_R 23

//-----------------------------
//END OF DRIVER CONSTANTS
//-----------------------------

//-----------------------------
//SENSORS CONSTANTS
//-----------------------------

//SERVO CONSTANTS
#define SERVO_PWM 5

//SONAR CONSTANTS
#define SONAR_TRIGGER 52
#define SONAR_ECHO    53
#define MAX_RANGE     200

//INFRA-RED CONSTANTS
#define INFRA_RED_PORT A8

//-----------------------------
//END SENSORS CONSTANTS
//-----------------------------

//-----------------------------
//SERIAL PROTOCOL CONSTANTS
//-----------------------------

//DIRECTIONS
#define COM_DIR_F 1
#define COM_DIR_L 2
#define COM_DIR_R 3
#define COM_DIR_B 4

//SPEED ID
#define COM_SPD 'S'
//DISTANCE ID
#define COM_DST 'D'
//POWER ID
#define COM_PWM	'P'
//DIRECTION ID
#define COM_DIR 'D'
//IR ID
#define COM_IR	'I'
//SONAR ID
#define COM_SON 'C'

#define SERIAL_BAUD_RATE 9600
//-----------------------------
//END SERIAL PROTOCOL CONSTANTS
//-----------------------------

//BLUETOOTH VARIABLES
//SoftwareSerial bluetooth(24,25);
MeetAndroid bluetooth;

//SONAR VARIABLES
NewPing sonar(SONAR_TRIGGER, SONAR_ECHO, MAX_RANGE);
volatile int sonarLastReading = 0;

//IR VARIABLES
DistanceGP2Y0A21YK irSensor;
unsigned int irLastReading = 0;

//SERVO VARIABLES
Servo towerServo;
unsigned long delayServo;
byte servoStage = 0;

//ROVER VARIABLES
RoverPower power(DRIVER_PWM1, DRIVER_PWM2, DRIVER_PWM3, DRIVER_PWM4);
RoverDir   dir(DRIVER_DIR1, DRIVER_DIR2, DRIVER_DIR3, DRIVER_DIR4);

//ENCODER VARIABLES
volatile int rotaryCountL = 0;
volatile int rotaryCountR = 0;
volatile unsigned int lastTime = 0;
volatile float currSpeed = 0;
volatile float tempSpeed = 0;
volatile float movDist = 0;

void setup()
{
	//SERIAL START
	#ifdef DEBUG
		Serial.begin(SERIAL_BAUD_RATE);
	#endif // DEBUG

	//COMMUNICATIONS START
	DEBUG_PRINT("STARTING COMM")
	//bluetooth.begin(SERIAL_BAUD_RATE);
	bluetooth.registerFunction(onCommandReceived, 'c');

	//SENSORS START
	DEBUG_PRINT("STARTING SENSORS");
	towerServo.attach(SERVO_PWM);
	irSensor.begin(INFRA_RED_PORT);

	//MOTOR START
	DEBUG_PRINT("STARTING ENGINE");
	attachInterrupt(INTER_L, &onInterruptLeft, CHANGE);
	attachInterrupt(INTER_R, &onInterruptRight, CHANGE);
	power.halt();
	dir.goFoward();
}

//TIME SHARING
long currTime;
//int commTimer = 10;
int sensorTimer = 10;
int servoTimer = 20;
int interruptTimer = 30;

void updateTimers(){
	currTime = millis();
	//commTimer = currTime + commTimer;
	sensorTimer = currTime + sensorTimer;
	servoTimer = currTime + servoTimer;
	interruptTimer = currTime + interruptTimer;
}

void loop()
{
	updateTimers();

	//MAIN TIME SHARING LOOP

	//if(currTime < commTimer){
	//	//communications
	//	//getCommand();
	//} else 

	if(currTime < sensorTimer){
		//sensor readings		
		getSensorReadings();

		//send data
		sendSensorsData();
	} else if (currTime < servoTimer) {

		//move servo
		sweepServo();
	} else if(currTime < interruptTimer){

		//calc speed - rotation - distance 
		calcMovedDistance();
		calcCurrentSpeed();
		sendRoverData();
	} 
}

void getSensorReadings(){
	irLastReading = irSensor.getDistanceCentimeter();
	sonarLastReading = sonar.ping_cm();

	DEBUG_PRINT("IR: ");
	DEBUG_PRINTDEC(irLastReading);
	DEBUG_PRINT("SONAR: ");
	DEBUG_PRINTDEC(sonarLastReading);
}

void onCommandReceived(byte flag, byte numOfValues){
	int data[numOfValues];

	int direction = data[0];
	switch (direction)
	{
	case COM_DIR_F:
		dir.goFoward();
		break;
	case COM_DIR_L:
		dir.goLeft();
		break;
	case COM_DIR_R:
		dir.goRight();
		break;
	case COM_DIR_B:
		dir.goBackward();
		break;
	default:
		break;
	}
	int pwm = data[1];
	power.throttle(pwm);

	DEBUG_PRINT("Receiving command ");
	DEBUG_PRINT("DIR: ");
	DEBUG_PRINTDEC(direction);
	DEBUG_PRINT("PWM: ");
	DEBUG_PRINTDEC(pwm);
}

void sweepServo(){
	if (millis() >= delayServo){
		delayServo = delayServo + 150;
		servoStage = servoStage +1;
		Serial.println(servoStage);
		if (servoStage == 7){ 
			servoStage = 1;
		}
	}
	switch (servoStage){
	case 1:
		towerServo.write(0);
		break;
	case 2:
		towerServo.write(60);
		break;
	case 3:
		towerServo.write(120);
		break;
	case 4:
		towerServo.write(180);
		break;
	case 5:
		towerServo.write(120);
		break;
	case 6:
		towerServo.write(60);
		break;
	} // end of sweep
}


void sendSensorsData(){
	bluetooth.send(COM_IR);
	bluetooth.send(irLastReading);
	bluetooth.send(COM_SON);
	bluetooth.send(sonarLastReading);
}

void sendRoverData(){
	int spd = currSpeed;
	bluetooth.send(COM_SPD);
	bluetooth.send(spd);
	int dist = movDist;
	bluetooth.send(COM_DST);
	bluetooth.send(dist);
}

void calcCurrentSpeed(){
	currSpeed = rotaryCountL / lastTime - currTime; //velocidade escalar 
}

void calcMovedDistance(){
	movDist = rotaryCountL/4 * (2 * PI * 3); //Raio da roda 3cm
}

void onInterruptLeft(){
	lastTime = millis(); //cada interrupção é um quarto de rotação
	rotaryCountL++;
}

void onInterruptRight(){
	lastTime = millis();
	rotaryCountR++;
}

//void getCommand(){
//	int commRead;
//	int pwmDir;
//	if(bluetooth.available()){
//		int commRead;
//		commRead = bluetooth.read();
//		switch (commRead){
//		case COM_DIR_F:
//			dir.goFoward();
//			break;
//		case COM_DIR_L:
//			dir.goLeft();
//			break;
//		case COM_DIR_R:
//			dir.goRight();
//			break;
//		case COM_DIR_B:
//			dir.goBackward();
//			break;
//		}
//		//TODO: este dado vem em inteiro??
//		pwmDir = Serial1.read();
//		power.throttle(pwmDir);
//	}
//}