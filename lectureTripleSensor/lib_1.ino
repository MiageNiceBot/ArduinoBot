
/* Return distance detected by pin in cm */
int getDistance(int pin) {
  // read the value from the sensor
  int sensorValue = Robot.analogRead(pin);
  //Convert the sensor input to cm.
  int distance_cm = sensorValue * 1.45;
  return distance_cm;
}

int calculerValeur(int pourcent){
  return (255 * pourcent) / 100; 
}

void tout_droit(int pourcent){
  int valeur = calculerValeur(pourcent);
  Robot.motorsWrite(valeur, valeur);
}

void reculer(int pourcent){
  int valeur = calculerValeur(pourcent);
  Robot.motorsWrite(-valeur, -valeur);
}

void gauche(){
  Robot.motorsWrite(-127, 127);
  delay(400);
}

void droite(){
  Robot.motorsWrite(127, -127);
  delay(400);
}

void retourner(){
  Robot.motorsWrite(127, -127);
  delay(685);
}

void stopMotor() {
  Robot.motorsWrite(0, 0);
  delay(400);
}

void tourner(int degree){
  int compasValeur = Robot.compassRead();
}

void afficherValeur(int valeur){
  Robot.background(0, 0, 255);
  Robot.setCursor(44, 60);
  Robot.stroke(0, 255, 0);
  Robot.setTextSize(4);
  Robot.print(valeur);
}
