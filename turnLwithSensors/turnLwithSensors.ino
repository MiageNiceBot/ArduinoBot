// include the robot library
#include <ArduinoRobot.h>
#include <Wire.h>
#include <SPI.h>

int sensorA = M2;
int sensorD = M0;
int sensorG = M4;
int G=0,D=0,A=0;

void setup(){
  Robot.begin();
  Robot.beginTFT();
  Robot.displayLogos();
  delay(1000);
}

void loop() {
  
  if(getDistance(sensorA)>20){
    //Si Rien devant
    straight(300);
  } else {
    Robot.motorsWrite(0, 0);
    if ((getDistance(sensorG)>20) && (getDistance(sensorD)>20)){
      //Si aucun obstacle
      straight(300);
    } else if(getDistance(sensorG)<20){
      //Obstacle à gauche
      littleRight(300);
    } else if(getDistance(sensorD)<20){
      //Obstacle à droite
      littleLeft(300);
    }
  } 
  // put your main code here, to run repeatedly:
 // straight(2000);
  //littleLeft(1100);
 // straight(1000);
 // delay(100000);
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
  Robot.motorsWrite(150, 150);
  delay(duration);
  //Robot.motorsWrite(0, 0);
  }
  
void littleLeft(int duration) {
  Robot.motorsWrite(80, 150);
  delay(duration);
  //Robot.motorsWrite(0, 0);
  }
  
 void littleRight(int duration) {
  Robot.motorsWrite(150, 80);
  delay(duration);
  //Robot.motorsWrite(0, 0);
  }

/* Return distance detected by pin in cm */
int getDistance(int pin) {
  // read the value from the sensor
  int sensorValue = Robot.analogRead(pin);
  //Convert the sensor input to cm.
  int distance_cm = sensorValue * 1.45;
  return distance_cm;
}
