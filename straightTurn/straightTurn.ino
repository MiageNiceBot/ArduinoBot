// include the robot library
#include <ArduinoRobot.h>
#include <Wire.h>
#include <SPI.h>

void setup(){
  Robot.begin();
  Robot.beginTFT();
  Robot.displayLogos();
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  straight(2000);
  littleLeft(1100);
  straight(1000);
  delay(100000);
  //turn(90);
 // delay(1000);
 // straight(1000);
 // delay(1000);
 // turn(-90);
 // delay(1000);
 // straight(1000);
 // delay(1000);
 // turn(90);
 // delay(1000);
//  straight(1000);
 // delay(1000);
 // turn(-90);
 // delay(1000);
}

void straight(int duration) {
  Robot.motorsWrite(255, 255);
  delay(duration);
  Robot.motorsWrite(0, 0);
  }
  
void littleLeft(int duration) {
  Robot.motorsWrite(100, 255);
  delay(duration);
  Robot.motorsWrite(0, 0);
  }
  
 void littleRight(int duration) {
  Robot.motorsWrite(255, 100);
  delay(duration);
  Robot.motorsWrite(0, 0);
  }
  
void turn(int degree) {
  int rotDuration=90;
  if(degree<0){
    rotDuration=-rotDuration;
  }
  Robot.motorsWrite(-rotDuration, rotDuration);
  delay(600);
  Robot.motorsWrite(0, 0);
}
