//Incluye las bibliotecas necesarias
#include <AFMotor.h> //Librería para controlar el módulo L298N
#include <NewPing.h> //Librería para controlar el sensor ultrasónico

//Definimos los pines para los motores
#define M1P1 2 //Motor 1 Pin 1
#define M1P2 3 //Motor 1 Pin 2
#define M2P1 6 //Motor 2 Pin 1
#define M2P2 7 //Motor 2 Pin 2

//Configuramos los objetos: motor y sonar
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

void setup() {
  //Declaramos los pines de los motores como salidas
  pinMode(M1P1, OUTPUT);
  pinMode(M1P2, OUTPUT);
  pinMode(M2P2, OUTPUT);
  pinMode(M2P1, OUTPUT);
}

void loop() {
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
}
