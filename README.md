ArduinoBot
============
Répertoire git pour le concours de robot de la JNM.  Vive la miage Nice! 

Quelques points techniques
--------------------------

```
Robot.MotorsWrite(x, y)
```

Cette fonction permet de faire bouger les roues. X et Y sont les valeurs représentant la force de poussée des roues (respectivement la roue gauche et droite), ces valeurs peuvent aller de -255 à 255. La valeur négative fait reculer la roue, tandis que la positive fait avancer la roue. 

Pour faire tourner le robot, il faut que X et Y soient opposés (donc que X = -Y). 
Il est important de préciser que cette fonction ne contrôle pas le temps de déplacement. La logique est que le robot, tant qu'il n'a pas reçu d'autre directive, va appliquer la dernière directive mouvement donné. Pour le faire courir 2s, il faut:

```
void loop(){                                        // Boucle infini lancé par le programme
	Robot.MotorsWrite(255, 255);     // Avance tout droit à fond
	delay(2000);                              // On pause le programme 2s, cela signifie que le robot va foncer pendant 2s tout droit
	Robot.motorsStop();                   // On arrête le robot
	delay(2000);                              // On l'arrête pendant 2s avant que la boucle loop ne reparte
}
```

```
Robot.turn(degrees)
```		

Cette fonction va faire en sorte que le robot se tourne de X degrés par rapport à sa rotation actuelle. Contrairement au motorswrite ou on pourrait tout simplement mettre les valeurs opposés pour tourné comme on l'a vu précédemment, la fonction turn va se baser par rapport au compass interne du robot et la rotation sera donc 'précise'. Notons que cette précision n'est pas d'une fiabilité optimale comme on a pu le remarqué hier, il sera donc nécessaire dans nos programmes de prendre cela en compte.

```
Robot.analogRead(sensorPin)
```		

Permet d'utiliser le sonar placer sur la pin "sensorPin". Cette fonction va retourner une valeur qu'il faut ensuite multiplié par 1.27 pour la convertir en centimètre. Notez que c'est un sonar, donc la distance récupéré doit être divisé par 2 pour obtenir la vrai distance enter le robot et l'objet. 
On peut placer plusieurs sonar sur le robot;

Lancement du Robot
------------------

Pour compiler avec le robot, c'est plutôt simple. Branchez le câble USB sur la board haute du robot (surtout pas celle du bas!). Choisissez dans Outils > Port le port usb sur lequel vous avez connecté le robot (type COM4 Arduino). Sélectionnez ensuite dans Outils > Type de carte > Arduino Robot Control. Enfin au niveau des icônes au dessus de l'onglet de votre programme cliquez sur la flêche horizontal et "Téléversez" votre programme. Un point important est que si vous souhaitez faire avancer le robot, vous ne pouvez pas le faire avec les branchements. Donc si votre programme fait bouger le robot, retirez tout les câbles sinon il n'avancera pas. 

Merci à l'administrateur du github de rajouter ces textes dans le README si ça ne te dérange pas :'p 
Voilà, si des détails manquent ou sont incomplets, n'hésitez pas à compléter cela dans le README du github créé ;') 

A venir
-------
M. Buffa va nous faire un cours avancé dans le courant de la semaine prochaine, on notifiera tout le monde sur le mur une fois que cela sera définit. 

A VENREDI pour la prochaine séance ensemble! Les robots sont disponibles comme d'habitude vis vous souhaitez pratiquer individuellement comme plusieurs d'entre vous le font déjà.

