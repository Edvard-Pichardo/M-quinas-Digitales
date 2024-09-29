#include  Ultrasonic.h

//Definimos el sensor ultrasonico
Ultrasonic ultrasonic(4,3);
#define ECHO 4

//Definimos las entradas para los motores
const int IN1=5;
const int IN2=6;
const int IN3=9;
const int IN4=10;

//Definimos las entradas para los sensores reflexivos
#define Sensor_der A0  //Sesnor derecha
#define Sensor_centro A1 //Sensor central
#define Sensor_izq A2 //Sensor izquierda

//Definimos una variable para guardar la distancia medida por el sensor ultrasonico
int distancia;


void  setup(){
Serial.begin(9600); //Iniciamos la comunicación Serial
delay (5000); //Se espera 5 segundos reglamentarios en el torneo
}

void  loop(){

  //Sección de mediciones iniciales del robot sumo: distancia del oponente y plataforma
 int SR_der=analogRead(Sensor_der);
 int SR_centro=analogRead(Sensor_centro);
 int SR_izq=analogRead(Sensor_izq);
 distancia=ultrasonic.read();

 //El robot sumo comienza girando con una velocidad de 200
 while(distancia>30){
  ROTAR(200);
  distancia=ultrasonic.read();

  if(distancia<=30){
    break;
  }
 }
    
 while(distancia<=30){
    Stop();
    AVANZAR(255); 
    
    distancia=ultrasonic.read();
    
    SR_der=analogRead(Sensor_der);
    SR_centro=analogRead(Sensor_centro);
    SR_izq=analogRead(Sensor_izq);
    
    if(SR_der>650 || SR_centro> 650 ){ 
      break;
      }
    delay(10); 
    }
  
  
 if (SR_der < 650 )  // <  650 means white line
   {
   Stop();
   delay (50);
   BACKWARD(255);
   delay (500);
   } 
   
 if (SR_centro < 650 )  //
   {
   Stop();
   delay (50);
   AVANZAR(255);
   delay (500);
   }
   
} 



//--------------------------------------------
void  AVANZAR (int Speed){
  //When we want to let Motor To move AVANZAR,
  // just  void this part on the loop section .
  analogWrite(IN1,Speed);
  analogWrite(IN2,0);
  analogWrite(IN3,0);
  analogWrite(IN4,Speed);
}

//--------------------------------------------
void  BACKWARD (int Speed){
  //When we want to let Motor To move AVANZAR,
  //  just void this part on the loop section .
  analogWrite(IN1,0);
  analogWrite(IN2,Speed);
  analogWrite(IN3,Speed);
  analogWrite(IN4,0);
}

//--------------------------------------------
void  ROTAR (int Speed)
{
  //When we want to let Motor To ROTAR ,
  // just  void this part on the loop section .
  analogWrite(IN1,Speed);
  analogWrite(IN2,0);
  analogWrite(IN3,Speed);
  analogWrite(IN4,0);
}

//--------------------------------------------
void  Stop(){
  //When we want to  Motor To stop ,
  // just void this part on the  loop section .
  analogWrite(IN1,0);
  analogWrite(IN2,0);
  analogWrite(IN3,0);
  analogWrite(IN4,0);
}
