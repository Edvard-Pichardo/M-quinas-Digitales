#include <NewPing.h> //Librería para controlar el sensor ultrasónico

//Definimos los pines para el sensor ultrasónico HC-SR04
#define TRIG 12
#define ECHO 11

NewPing sonar(TRIG, ECHO);
void setup() {
  Serial.begin(9600);
}

void loop() {
   //Realiza la lectura del sensor ultrasónico
  int distancia=sonar.ping_cm();

  Serial.println(distancia);

}
