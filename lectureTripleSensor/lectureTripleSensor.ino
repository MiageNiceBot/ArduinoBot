// include the robot library
#include <ArduinoRobot.h>
#include <Wire.h>
#include <SPI.h>

int sensorPinAvant = M2;  // pin is used by the sensor
int sensorPinDroit = M0;
int sensorPinGauche = M4;
int G=0,D=0,A=0;

int actualLine = 0;

void setup() {
  // initialize the Robot, SD card, and display
  Serial.begin(9600);
  Robot.begin();
  Robot.beginTFT();
  Robot.beginSD();
  Robot.stroke(0,0,0);
}

void loop() {
  Robot.clearScreen();
  
  G = 0;
  for(int i =0; i < 10; i++) {
    G +=getDistance(sensorPinGauche);
  }
  Robot.text(G/10, 0, 0);
  
  A = 0;
  for(int i =0; i < 10; i++) {
    A +=getDistance(sensorPinAvant);
  }
  Robot.text(A/10, 50, 0);
  
  D = 0;
  for(int i =0; i < 10; i++) {
    D +=getDistance(sensorPinDroit);
  }
  Robot.text(D/10, 100, 0);
  
  delay(1000);
}
