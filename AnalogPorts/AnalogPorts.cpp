// Do not remove the include below
#include "AnalogPorts.h"
/*
 - created 2011-10-31 by Massimo Pacilio
 - Use to send data to Processing sketch "MySQL_INSERT"
 - This sketch is in the public domain
 */

#include <math.h>

const unsigned int SENSOR_PIN = 0;
const unsigned int PHOTOCELL_PIN = 1;

const unsigned int BAUD_RATE = 9600;
const unsigned int THERMISTOR_MAX_RESISTENCE = 5;

int photocellReading;
int temp;

//equation to obtain the value of the temperature from a thermistor
//http://arduino.cc/playground/ComponentLib/Thermistor2
//http://en.wikipedia.org/wiki/Thermistor#Steinhart-Hart_equation
double thermister(int rawADC) {
  double temperature;
  temperature = log(((10240000 / rawADC) - THERMISTOR_MAX_RESISTENCE));
  temperature = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * temperature * temperature)) * temperature);
  temperature = temperature - 273.15; // Convert Kelvin to Celsius
  return temperature;
}

void setup() {
  Serial.begin(BAUD_RATE);

  pinMode(SENSOR_PIN, INPUT);
  pinMode(PHOTOCELL_PIN, INPUT);

  Serial.println("Comencing!");

}

void loop() {
  //assign to variable 'temp' the value of the temperature calculated by thermistor
//  temp = int(thermister(analogRead(SENSOR_PIN)));
//  Serial.print("\nTHERMISTOR: ");
//  Serial.println(temp);
  photocellReading = analogRead(PHOTOCELL_PIN);

  Serial.println(photocellReading);

//  Serial.print("light: ");
//  if (photocellReading < 10) {
//    Serial.println("Dark");
//  }
//  else if (photocellReading < 200) {
//    Serial.println("Dim");
//  }
//  else if (photocellReading < 500) {
//    Serial.println("Light");
//  }
//  else if (photocellReading < 800) {
//    Serial.println("Bright");
//  }
//  else {
//    Serial.println("Very bright");
//  }

  delay(500);
}

