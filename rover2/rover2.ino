#include <RoverDir.h>
#include <RoverPower.h>
#include <SoftTimer.h>
#include <Servo.h>
#include <NewPing.h>
#include <DelayRun.h>
#include <FrequencyTask.h>

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
#define INTER_L 0 // port 2
#define INTER_R 1 // port 3

#define SIGNAL_L 22
#define SIGNAL_R 23

#define TIME_FORWARDS 5000
#define TIME_BACKWARDS 5000
#define TIME_TURN 2000

//SONAR CONSTANTS
#define SONAR_TRIGGER 52
#define SONAR_ECHO    53
#define MAX_RANGE     200

//INFRA-RED CONSTANTS
#define INFRA_RED 10

//ROVER VARIABLES
RoverDir heading(DRIVER_DIR1, DRIVER_DIR2, DRIVER_DIR3, DRIVER_DIR4);
RoverPower power(DRIVER_PWM1, DRIVER_PWM2, DRIVER_PWM3, DRIVER_PWM4);

//SONAR VARIABLES
NewPing sonar(SONAR_TRIGGER, SONAR_ECHO, MAX_RANGE);
volatile int lastReading = 0;

//SERVO VARIABLES
Servo tower;
int servo_pos = 0;
int servo_port = SERVO_PWM;

//ENCODER VARIABLES
volatile int rotaryCountL = 0;
volatile int rotaryCountR = 0;

//TIME SHARING
DelayRun processTask(50, processReading);
DelayRun sonarTask(100, sonarReading, &processTask);
DelayRun sweepTask(5, sweep);
DelayRun samplingTask(5, sampling, &sweepTask);

void setup() { 
  Serial.begin(9200);

  processTask.followedBy = &sonarTask; // fecha loop de sonar

  tower.attach(8);

  attachInterrupt(INTER_L, onInterruptLeft, RISING);
  attachInterrupt(INTER_R, onInterruptRight, RISING);

  pinMode(INFRA_RED, INPUT);

  heading.goFoward();
  power.throttle(50);

  sonarTask.startDelayed();
}

boolean sonarReading(Task* me){
  // ler sonar
  lastReading = sonar.ping_cm();
  return true;
}

boolean processReading(Task* me){
  // processar sonar
  if(lastReading <= 30){
    power.halt();
  }
  return true;
}

boolean sweep(Task* me){
  // +5 graus de rotacao
  return true;
}

boolean sampling(Task*me){ 
  // loop de sweeps e ir reading
  return true;
}

int[] calculateMovingDistance(int[] dist){
  int[] res = new int[dist.length]; 

  for(int i = 0; i < res.length; i++){
    res[i] = infinity;
  }

  for(int i = 0; i < dist.length; i++){
    int adjacents = (int)Math.ceil((2* arc sen (L/(4*dist[i])))/(pi/36)); //pi/36 = 5º
    int limInf = Math.max(i-adjacents,0);
    int limSup = Math.min(i+adjacents, res.length-1);

    for(int j = limInf; j <= limSup; j++){
      //na verdade, nao dá pra andar distancia[i] nessa direçao, 
      //mas tem que fazer umas contas pra descobrir o quanto da pra andar e 
      //distancia[i] é ao menos um limite superior bem aproximado
      res[j] = Math.min(res[j], dist[i]);
    }
  }
  return res;
}


void onInterruptLeft() {
  //saber quanto moveu na esquerda
  rotaryCountL++;
}

void onInterruptRight() {
  //saber quanto moveu na direita
  rotaryCountR++;
}



