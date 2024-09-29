//Incluye las bibliotecas necesarias
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

//Definimos el umbral para los sensores de línea
#define Umbral 250

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

  //Configuramos los 5 seg de inicialización y espera del robot
  delay(5000);

}

void loop() {
  int temporizador=1;
  if(temporizador=1){
    delay(5000);
    temporizador=2;
  }
  
  //Leemos los valores de los sensores de línea
  int Valor_izq=analogRead(Sensor_izq);
  int Valor_centro=analogRead(Sensor_centro);
  int Valor_der=analogRead(Sensor_der);

  //Realiza la lectura del sensor ultrasónico
  int distancia=sonar.ping_cm();
  girarHorario();


  //Verificamos si el robot está dentro de la plataforma
  if(Valor_izq>Umbral && Valor_centro>Umbral && Valor_der>Umbral){ //El robot está dentro de la plataforma
  delay(50); 
    //Verificamos si el oponente está dentro de la distancia deseada
    if (distancia<30 && distancia!=0){  //Oponente detectado: atacar
      avanzar();
    }
  }
  
  else{ //El robot está a punto de salirse o ya está fuera de la plataforma
    detener();  //Primero detiene al robot
    delay(50);
    
    if(Valor_centro<Umbral) { //Está a punto de salirse por detras, avanza para reincorporarse
      avanzar();
    } 
    else if(Valor_der<Umbral){ //Está a punto de salirse por la derecha, gira a la izquierda
      girar();
      delay(500);
      avanzar();
      delay(500);
    }
    else if(Valor_izq<Umbral){ //Está a punto de salirse por la derecha, gira a la izquierda
      girarHorario();
      delay(500);
      avanzar();
      delay(500);
    }    
  }

}

// Funciones de movimiento del robot
void avanzar() {
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
}

void detener() {
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}


void retroceder() {
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
}

void girar() {
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
}

void girarHorario() {
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
}
