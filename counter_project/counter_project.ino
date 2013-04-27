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


void showdigit (int digit)

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


void beepon(){
  digitalWrite(buzz,HIGH);
  digitalWrite(led1,HIGH);
};

void beepoff(){
  digitalWrite(buzz,LOW);
  digitalWrite(led1,LOW);
};

void boomon(){
  digitalWrite(buzz,HIGH);
  digitalWrite(led2,HIGH);
};

void boomoff(){
  digitalWrite(buzz,LOW);
  digitalWrite(led2,LOW);
};

boolean beep = false;
boolean boom = false;
int timer;
int ticker;

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
};

void loop ()

{ 


  if(ticker >= 5){
    if(!beep){
      showdigit(timer);
      beepon();
      beep = true;
      if(timer <= 0){
        if(!boom){
          boomon();
          boom = true;
        }
        else {
          boomoff();
          boom = false;
          timer = 9;
        }
      }
      else {
        timer--;
      }
    }
    else{
      beepoff();
      beep = false;
    }
    ticker = 0;
  }
  ticker++;
  delay(100);
};

