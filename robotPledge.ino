/*
Algorithme de Pledge 
-Utiliser un compteur, si il est gale  0 je vais tout droit,
-Si on tombe sur un mur on le suit 
- si on tourne  droite +1 ( ou + l'angle)
- si on tourne  gauche -1 ( ou - l'angle)
*/
  int DIST = 40;
  int compteur = 0; // peut devenir un angle
  //float compteur = 0; //angle
  int devant = B_TK2;  // pin is used by the sensor
  int droite = B_TK2;
  int gauche = B_TK1;
  
void setup() {

  Serial.begin(9600);
  Robot.begin();
  Robot.beginTFT();
  Robot.beginSD();
  

}

void loop() {
  
  if( compteur == 0 and getDistance(devant) > DIST) { // algo cpt = 0 on va tout droit
     Robot.motorsWrite(255,255);
     
  } else if (compteur == 0 and getDistance(devant) < DIST ) { // on tourne  droite il y a un mur devant
    Robot.turn(90);
  } else if (getDistance(gauche) < DIST ) { // il y a bien le mur  gauche
    Robot.motorsWrite(255,255);
  } else if (getDistance(gauche) > DIST and getDistance(devant) > DIST and compteur != 0) { // plus de mur  gauche faut tourner  gauche 
    Robot.turn(-90);
  } else if (getDistance(gauche) < DIST and getDistance(devant) < DIST and getDistance(droite) > 40) { // on tourne  droite car mur  gauche et devant
    Robot.turn(90);
  } else {
     Robot.motorsWrite(0,0);
  }

}

float getDistance(int sensor) {
  // read the value from the sensor
  int sensorValue = Robot.analogRead(sensor);
  //Convert the sensor input to cm.
  float distance_cm = sensorValue * 1.27;
  return distance_cm;
}
