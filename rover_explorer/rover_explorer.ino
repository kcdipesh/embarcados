#include <DistanceGP2Y0A21YK.h>
#include <Servo.h>
#include <NewPing.h>
#include <RoverPower.h>
#include <RoverDir.h>

//SERVO CONSTANTS
#define SERVO_PWM 8

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

//ENCODER INTERRUPTION
#define INTER_L 0 // port 2
#define INTER_R 1 // port 3

#define SIGNAL_L 22
#define SIGNAL_R 23

//SONAR CONSTANTS
#define SONAR_TRIGGER 52
#define SONAR_ECHO    53
#define MAX_RANGE     200

//INFRA-RED CONSTANTS
#define INFRA_RED_PORT 10

//SONAR VARIABLES
NewPing sonar(SONAR_TRIGGER, SONAR_ECHO, MAX_RANGE);
volatile int sonarLastReading = 0;

//IR VARIABLES
DistanceGP2Y0A21YK irSensor;
int irLastReading = 0;

//SERVO VARIABLES
Servo towerServo;
int servoPos = 0;
byte servoDir = 0;

//ENCODER VARIABLES
volatile int rotaryCountL = 0;
volatile int rotaryCountR = 0;

void setup()
{
  Serial2.begin(9600);
  towerServo.attach(SERVO_PWM);
  irSensor.begin(INFRA_RED_PORT);
}

void loop()
{
  irLastReading = irSensor.getDistanceCentimeter();
  sonarLastReading = sonar.ping_cm();
  if (servoDir && servoPos <= 180)
  {
    towerServo.write(servoPos++);
  }
  else {

  }
  Serial2.print(irLastReading);
  Serial2.print(" ");
  Serial2.print(sonarLastReading);
  delay(50);
}


