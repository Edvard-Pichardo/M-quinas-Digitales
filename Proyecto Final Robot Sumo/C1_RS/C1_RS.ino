// Incluye las bibliotecas necesarias
#include <AFMotor.h> //Librería para controlar el módulo L298N
#include <NewPing.h> //Librería para controlar el sensor ultrasónico

//Definimos los pines para los motores
#define M1P1 2 //Motor 1 Pin 1
#define M1P2 3 //Motor 1 Pin 2
#define M2P1 4 //Motor 2 Pin 1
#define M2P2 5 //Motor 2 Pin 2

//Definimos los pines para los sensores de línea TCRT5000 
#define Sensor_izq A0
#define Sensor_centro A1
#define Sensor_der A2

//Definimos los pines para el sensor ultrasónico HC-SR04
#define TRIG 6
#define ECHO 7

//Definimos los umbrales para los sensores de línea
#define Umbral 500

//Configuramos los objetos: motor y sonar
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
NewPing sonar(TRIG, ECHO);

void setup() {
  //Declaramos los pines de los motores como salidas
  pinMode(M1P1, OUTPUT);
  pinMode(M1P2, OUTPUT);
  pinMode(M2P1, OUTPUT);
  pinMode(M2P2, OUTPUT);

  //Declaramos los pines de los sensores de línea como entradas
  pinMode(Sensor_izq, INPUT);
  pinMode(Sensor_centro, INPUT);
  pinMode(Sensor_der, INPUT);

  //Declaramos la comunicación serial
  Serial.begin(9600);
}

void loop() {
  //Leemos los valores de los sensores de línea
  int Valor_izq = analogRead(Sensor_izq);
  int Valor_centro = analogRead(Sensor_centro);
  int Valor_der = analogRead(Sensor_der);

  // Verifica si el robot está dentro de la plataforma
  if(Valor_izq>Umbral && Valor_centro>Umbral && Valor_der>Umbral){ //El robot está dentro de la plataforma
    moverAdelante();
  } 
  else{ // El robot está a punto de salirse de la plataforma
    detener();
  }

  //Realizamos la lectura del sensor ultrasónico
  int distancia = sonar.ping_cm();

  //Verificamos si el oponente está dentro de la distancia deseada
  if(distancia<20) { // Oponente detectado: atacar
    moverAdelante();
  } 
  else{ // No hay oponente: continuar explorando
    detener();
  }
}

// Funciones de movimiento del robot
void moverAdelante() {
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
}

void detener() {
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}
