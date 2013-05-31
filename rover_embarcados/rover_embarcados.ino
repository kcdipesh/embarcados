#include <Servo.h>

//SERVO CONSTANTS
#define SERVO_PWM 8;

//DRIVER CONSTANTS
#define DRIVER_DIR1 13
#define DRIVER_DIR2 12
#define DRIVER_DIR3 11
#define DRIVER_DIR4 10

#define DRIVER_PWM1 7
#define DRIVER_PWM2 6
#define DRIVER_PWM3 5
#define DRIVER_PWM4 4

#define CH1_CURR 8
#define CH3_CURR 9

#define INTER_L 0
#define INTER_R 1

#define SIGNAL_L 22
#define SIGNAL_R 23

#define TIME_FORWARDS 5000
#define TIME_BACKWARDS 5000
#define TIME_TURN 2000

//SONAR CONSTANTS
#define SONAR_TRIGGER 52
#define SONAR_ECHO    53
#define LED_RANGE     35

//INFRA-RED CONSTANTS
#define INFRA_RED 10

//SERVO VARIABLES
Servo tower;
int servo_pos = 0;
int servo_port = SERVO_PWM;

//SONAR VARIABLES
int duration = 0;
int cm_distance = 0;
int min_range = 5;
int max_range = 200;

//CLOCK VARIABLES
int cicles = 0;
int cicle_delay = 100;

volatile int rotaryCount = 0;

void isr()
{
  boolean up;

  Serial.println("Interrupt");

  if (digitalRead(SIGNAL_L))
    up = digitalRead (SIGNAL_R);
  else
    up = !digitalRead (SIGNAL_R);

  if (up)
    rotaryCount++;
  else
    rotaryCount--;
} 

void setup() {
  tower.attach(8);

  attachInterrupt(INTER_L, isr, CHANGE);
  attachInterrupt(INTER_R, isr, CHANGE);

  Serial.begin(9200);

  pinMode(DRIVER_DIR1, OUTPUT);
  pinMode(DRIVER_DIR2, OUTPUT);
  pinMode(DRIVER_DIR3, OUTPUT);
  pinMode(DRIVER_DIR4, OUTPUT);

  pinMode(DRIVER_PWM1, OUTPUT);
  pinMode(DRIVER_PWM2, OUTPUT);
  pinMode(DRIVER_PWM3, OUTPUT);
  pinMode(DRIVER_PWM4, OUTPUT);

  pinMode(SONAR_TRIGGER, OUTPUT);
  pinMode(SONAR_ECHO, INPUT);

  pinMode(INFRA_RED, INPUT);
}

int phase = 0 ;
unsigned long start;
int time_to_change = 0;

void loop() {

  start = millis();

  walk(121); 

  //while(millis() - start <= time_to_change){
    //if (analogRead(CH1_CURR) > 325 || analogRead(CH3_CURR)  > 325) { // > 1.46 amps
    //  Serial.println("Motor overload!, changing phase");
    //  break;
    //}
  //} 

  switch (phase++)
  {
  case 0:
    goFoward();   
    time_to_change = TIME_FORWARDS;
    Serial.println("Moving FOWARD"); 
    break;
  case 1: 
    halt();
    goLeft();
    time_to_change = TIME_TURN;
    Serial.println("Turning LEFT"); 

    break;
  case 2: 
    goBackward();
    time_to_change = TIME_BACKWARDS;
    Serial.println("Moving BACKWARD"); 

    break;
  case 3: 
    goRight();
    time_to_change = TIME_TURN;
    Serial.println("Turning RIGHT"); 
    phase = 0;
    break;
  } 
  delay(time_to_change);
  //delay(50);
}

void goFoward(){
  digitalWrite(DRIVER_DIR1, 1);
  digitalWrite(DRIVER_DIR2, 1);
  digitalWrite(DRIVER_DIR3, 0);
  digitalWrite(DRIVER_DIR4, 0);
}

void goBackward(){
  digitalWrite(DRIVER_DIR1, 0);
  digitalWrite(DRIVER_DIR2, 0);
  digitalWrite(DRIVER_DIR3, 1);
  digitalWrite(DRIVER_DIR4, 1);
}

void goRight(){
  digitalWrite(DRIVER_DIR1, 1);
  digitalWrite(DRIVER_DIR2, 0);
  digitalWrite(DRIVER_DIR3, 0);
  digitalWrite(DRIVER_DIR4, 1);
}

void goLeft(){
  digitalWrite(DRIVER_DIR1, 0);
  digitalWrite(DRIVER_DIR2, 1);
  digitalWrite(DRIVER_DIR3, 1);
  digitalWrite(DRIVER_DIR4, 0);
}

void walk(int power){
  analogWrite(DRIVER_PWM1, power);
  analogWrite(DRIVER_PWM2, power);
  analogWrite(DRIVER_PWM3, power);
  analogWrite(DRIVER_PWM4, power);
}

void halt(){
  analogWrite(DRIVER_PWM1, 0x00);
  analogWrite(DRIVER_PWM2, 0x00);
  analogWrite(DRIVER_PWM3, 0x00);
  analogWrite(DRIVER_PWM4, 0x00);
}

void sweep(){
  for(servo_pos = 0; servo_pos < 180; servo_pos += 1)  
  {                                  
    tower.write(servo_pos);          
  } 
  for(servo_pos = 180; servo_pos>=1; servo_pos-=1)     
  {                                
    tower.write(servo_pos);              
  } 
}

int getSonarDistance(){ 

  /* The following trigPin/echoPin cycle is used to determine the
   distance of the nearest object by bouncing soundwaves off of it. */
  digitalWrite(SONAR_TRIGGER, LOW); 
  delayMicroseconds(2); 

  digitalWrite(SONAR_TRIGGER, HIGH);
  delayMicroseconds(10); 

  digitalWrite(SONAR_TRIGGER, LOW);

  duration = pulseIn(SONAR_ECHO, HIGH);

  //Calculate the distance (in cm) based on the speed of sound.
  //cm_distance = duration/58.2;
  cm_distance = microsecondsToCentimeters(duration);

  if (cm_distance >= max_range || cm_distance <= min_range){
    digitalWrite(LED_RANGE, HIGH); 
    return cm_distance;
  } 
  else {
    digitalWrite(LED_RANGE, LOW);
    return cm_distance;
  }
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}













