#include "Servo8Bit.h"

int LEDPin = 0;
int photocellPin = A1; // the cell and 10K pulldown are connected to a0
int photocellReading; // the analog reading from the sensor divider

int lowThreshold = 800; //inside light level
int highThreshold = 900;

Servo8Bit myServo;

void setup(){
  myServo.attach(0);
  //pinMode(LEDPin,OUTPUT);
}

void loop(void) {
photocellReading = analogRead(photocellPin); 



// lowthreshold will be inside light to darkness so servo pos is up
// highthreshold will be outside light, putting servo around halfway rotated
if(photocellReading < lowThreshold) {
  myServo.write(0);
  //digitalWrite(0, LOW);
} 
if(photocellReading > highThreshold) {
  myServo.write(85);
  //digitalWrite(0, HIGH);
}
delay(1000);
}


