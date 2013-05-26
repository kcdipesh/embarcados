#include <Servo.h>

//SERVO CONSTANTS
#define SERVO_PWM 8;

//DRIVER CONSTANTS
#define DRIVER_DIR1 13
#define DRIVER_DIR2 12
#define DRIVER_DIR3 11
#define DRIVER_DIR4 10

#define DRIVER_PWM1 24
#define DRIVER_PWM2 26
#define DRIVER_PWM3 28
#define DRIVER_PWM4 30

//SONAR CONSTANTS
#define SONAR_TRIGGER 34
#define SONAR_ECHO    36
#define LED_RANGE     35

//INFRA-RED CONSTANTS
#define INFRA_RED 8

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

void setup() {
  tower.attach(servo_port);
  
  Serial.begin(9200);
  Serial.write(servo_port);

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

void loop() {
  setFoward();
  halt();
  sweep();
  delay(50);
}

void setFoward(){
  digitalWrite(DRIVER_DIR1, HIGH);
  digitalWrite(DRIVER_DIR2, HIGH);
  digitalWrite(DRIVER_DIR3, HIGH);
  digitalWrite(DRIVER_DIR4, HIGH);
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




