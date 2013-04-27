const int disp_g = 5;
const int disp_f = 4;
const int disp_a = 3;
const int disp_b = 2;
const int disp_e = 6;
const int disp_d = 7;
const int disp_c = 8;

const int buzz = 9;
const int led1 = 10;
const int led2 = 11;
const int push1 = 12;
const int push2 = 13;

int btn1State;
int btn2State;
boolean beep;
boolean boom;
boolean armed;
int timer;
int ticker;
long randomNumber;

void digit0 () {

  digitalWrite(disp_a, HIGH);
  digitalWrite(disp_b, HIGH);
  digitalWrite(disp_c, HIGH);
  digitalWrite(disp_d, HIGH);
  digitalWrite(disp_e, HIGH);
  digitalWrite(disp_f, HIGH);
  digitalWrite(disp_g, LOW);

};

void digit1 () {

  digitalWrite(disp_a,LOW);
  digitalWrite(disp_b, HIGH);
  digitalWrite(disp_c, HIGH);
  digitalWrite(disp_d, LOW);
  digitalWrite(disp_e, LOW);
  digitalWrite(disp_f, LOW);
  digitalWrite(disp_g, LOW);
};

void digit2 () {

  digitalWrite(disp_a,HIGH);
  digitalWrite(disp_b, HIGH);
  digitalWrite(disp_c, LOW);
  digitalWrite(disp_d, HIGH);
  digitalWrite(disp_e, HIGH);
  digitalWrite(disp_f, LOW);
  digitalWrite(disp_g, HIGH);
};

void digit3 () {

  digitalWrite(disp_a,HIGH);
  digitalWrite(disp_b, HIGH);
  digitalWrite(disp_c, HIGH);
  digitalWrite(disp_d, HIGH);
  digitalWrite(disp_e, LOW);
  digitalWrite(disp_f, LOW);
  digitalWrite(disp_g, HIGH);
};

void digit4 () {

  digitalWrite(disp_a,LOW);
  digitalWrite(disp_b, HIGH);
  digitalWrite(disp_c, HIGH);
  digitalWrite(disp_d, LOW);
  digitalWrite(disp_e, LOW);
  digitalWrite(disp_f, HIGH);
  digitalWrite(disp_g, HIGH);
};

void digit5 () {

  digitalWrite(disp_a,HIGH);
  digitalWrite(disp_b, LOW);
  digitalWrite(disp_c, HIGH);
  digitalWrite(disp_d, HIGH);
  digitalWrite(disp_e, LOW);
  digitalWrite(disp_f, HIGH);
  digitalWrite(disp_g, HIGH);
};

void digit6 () {

  digitalWrite(disp_a,HIGH);
  digitalWrite(disp_b, LOW);
  digitalWrite(disp_c, HIGH);
  digitalWrite(disp_d, HIGH);
  digitalWrite(disp_e, HIGH);
  digitalWrite(disp_f, HIGH);
  digitalWrite(disp_g, HIGH);
};

void digit7 () {

  digitalWrite(disp_a,HIGH);
  digitalWrite(disp_b, HIGH);
  digitalWrite(disp_c, HIGH);
  digitalWrite(disp_d, LOW);
  digitalWrite(disp_e, LOW);
  digitalWrite(disp_f, LOW);
  digitalWrite(disp_g, LOW);
};

void digit8 () {

  digitalWrite(disp_a, HIGH);
  digitalWrite(disp_b, HIGH);
  digitalWrite(disp_c, HIGH);
  digitalWrite(disp_d, HIGH);
  digitalWrite(disp_e, HIGH);
  digitalWrite(disp_f, HIGH);
  digitalWrite(disp_g, HIGH);

};

void digit9 () {

  digitalWrite(disp_a, HIGH);
  digitalWrite(disp_b, HIGH);
  digitalWrite(disp_c, HIGH);
  digitalWrite(disp_d, HIGH);
  digitalWrite(disp_e, LOW);
  digitalWrite(disp_f, HIGH);
  digitalWrite(disp_g, HIGH);

};


void showDigit (int digit)

{

  switch (digit) {

  case 0:
    digit0 ();
    break;

  case 1:
    digit1 ();
    break;

  case 2:
    digit2 ();
    break;

  case 3:
    digit3 ();
    break;

  case 4:
    digit4 ();
    break;

  case 5:
    digit5 ();
    break;

  case 6:
    digit6 ();
    break;

  case 7:
    digit7 ();
    break;

  case 8:
    digit8 ();
    break;

  case 9:
    digit9 ();
    break;

  default:

    break;

  }; 

};


void beepOn(){
  beep = true;
  digitalWrite(buzz,HIGH);
  digitalWrite(led1,HIGH);
};

void beepOff(){
  beep = false;
  digitalWrite(buzz,LOW);
  digitalWrite(led1,LOW);
};

void boomOn(){
  printTerrWin();
  boom = true;
  digitalWrite(buzz,HIGH);
  digitalWrite(led2,HIGH);
};

void boomOff(){
  boom = false;
  digitalWrite(buzz,LOW);
  digitalWrite(led2,LOW);
};

void resetTicker(){
  ticker = 0;
}

void resetTimer(){
  timer = 9;
}

void setup()

{
  pinMode(disp_a, OUTPUT);
  pinMode(disp_b, OUTPUT);
  pinMode(disp_c, OUTPUT);
  pinMode(disp_d, OUTPUT);
  pinMode(disp_e, OUTPUT);
  pinMode(disp_f, OUTPUT);
  pinMode(disp_g, OUTPUT);

  pinMode(buzz, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  pinMode(push1, INPUT);
  pinMode(push2, INPUT);

  timer = 9;
  ticker = 0;
  armed = true;
  beep = false;
  boom = false;
  btn1State = 0;
  btn2State = 0;

  Serial.begin(9600);

  Serial.print("Bomb has been planted!\n");

  randomSeed(analogRead(0));
};

void printTerrWin(){
  Serial.print("Terrorists win!\n");
}

void printCTWin(){
  Serial.print("Counter terrorist, win!\n");
}

void clean(){
  digitalWrite(disp_a, LOW);
  digitalWrite(disp_b, LOW);
  digitalWrite(disp_c, LOW);
  digitalWrite(disp_d, LOW);
  digitalWrite(disp_e, LOW);
  digitalWrite(disp_f, LOW);
  digitalWrite(disp_g, LOW);
  digitalWrite(buzz, LOW);
  digitalWrite(led2, LOW);
}

void desarm(){
  armed = false;
  clean();
  digitalWrite(buzz, HIGH);
  delay(150);
  digitalWrite(buzz, LOW);
}

void armedState(){
  if(boom){
      if(ticker >= 37){
        resetTicker();
        resetTimer();
        boomOff();
      }
    }
    else {
      if(timer >= 0){
        if(ticker >= 9){
          showDigit(timer);
          beepOn();
          resetTicker();
          timer--;
        }
        else {
          if(ticker >= 5 && beep){
            beepOff();
          }
        } 
      }
      else {
        boomOn();
      }
    }
    ticker++;
    delay(100);
}

void lap(){
  digitalWrite(disp_a, HIGH);
  delay(100);
  digitalWrite(disp_a, LOW);
  digitalWrite(disp_b, HIGH);
  delay(100);
  digitalWrite(disp_b, LOW);
  digitalWrite(disp_c, HIGH);
  delay(100);
  digitalWrite(disp_c, LOW);
  digitalWrite(disp_d, HIGH);
  delay(100);
  digitalWrite(disp_d, LOW);
  digitalWrite(disp_e, HIGH);
  delay(100);
  digitalWrite(disp_e, LOW);
  digitalWrite(disp_f, HIGH);
  delay(100);
  digitalWrite(disp_f, LOW);
}

void loop ()

{ 
  randomNumber = random(300);
  Serial.print(randomNumber);
  Serial.print('\n');
  btn1State = digitalRead(push1);
  btn2State = digitalRead(push2);

  if(randomNumber % 2 == 0){
    if(btn1State == HIGH){
      resetTimer();
      desarm();
    }
  }
  else {
    if(btn2State == HIGH){
      resetTimer();
      desarm();
    }
  }

  if (armed){
    armedState();    
  }  
  else {
    lap();
  }   
};





