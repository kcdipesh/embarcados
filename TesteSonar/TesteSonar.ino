#include <SoftwareSerial.h>
#include <Servo.h>
#include <NewPing.h>

#define TRIGGER_PIN  7
#define ECHO_PIN     6
#define MAX_DISTANCE 200

#define SERVO_PWM 8

#define RX 12
#define TX 11

#define arraysize 10

int rangevalue[arraysize] = { 0, 0, 0, 0, 0 };

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
//SoftwareSerial bluetooth(RX,TX);
Servo tower;

void setup() {
  pinMode(9, HIGH);
  
  Serial.begin(9200);
  tower.attach(SERVO_PWM);
  //bluetooth.begin(9200);
  
}

void loop() {
  delay(100);                    
  //unsigned int us = sonar.ping_cm();
  unsigned int us = getSonar();

  //if (bluetooth.available()){
    Serial.println(us);
    //bluetooth.print(us);
   // bluetooth.println(" cm");
  //}
  //if (bluetooth.available()){
    //int angle = bluetooth.read();
    //if(0 < angle <= 180) {
      tower.write(10);
     // delay(15);
    //}
 // }
}

///             Get Sonar Function              ///
/* Programmer passes sonar number into this function
to return sonar reading. i.e. getSonar(sonar3);   */

int getSonar() {
      int pulse;
      for(int i = 0 ; i < arraysize; i ++){
          rangevalue[i] = sonar.ping_cm();
      }
      isort(rangevalue, arraysize);
      pulse = mode(rangevalue, arraysize);
    return pulse;
}

///////////////   end Sonar Function  ///////////////

// isort is used to sort the array of read values from a sonar //
void isort(int *a, int n){
  for (int i = 1; i < n; ++i){                    
    int j = a[i];                                 
    int k;                          
    for (k = i - 1; (k >= 0) && (j < a[k]); k--){
      a[k + 1] = a[k];
      }
    a[k + 1] = j;
  }
}
//////////////////////     End isort        ////////////////////

///        Mode function, returns the mode or median.        ///
int mode(int *x,int n){
  int i = 0;
  int count = 0;
  int maxCount = 0;
  int mode = 0;
  int bimodal;
  int prevCount = 0;
  while(i<(n-1)){
    prevCount=count;
    count=0;
    while(x[i] == x[i+1]){
      count++;
      i++;
    }
    if(count>prevCount&count>maxCount){
      mode=x[i];
      maxCount=count;
      bimodal=0;
    }
    if(count==0){
      i++;
    }
    if(count==maxCount){      //If the dataset has 2 or more modes.
      bimodal=1;
    }
    if(mode==0||bimodal==1){//Return the median if there is no mode.
      mode=x[(n/2)];
    }
    return mode;
  }
}
////////////////////         end mode       /////////////////////// 
