#define TRIG 12 //Los pines para el sensor ultrasonico
#define ECHO 11

//Definimos las entradas para los motores
const int IN1=7;
const int IN2=6;
const int IN3=8;
const int IN4=9;

//Definimos las entradas para los sensores reflexivos
#define Sensor_der A0  //Sesnor derecha
#define Sensor_centro A1 //Sensor central
#define Sensor_izq A2  //Sesnor izq

//Definimos una variable para guardar la distancia medida por el sensor ultrasonico
long distancia;
 int SR_der;
 int SR_centro;
 int SR_izq;

void  setup(){
Serial.begin(9600); //Iniciamos la comunicación Serial

pinMode(TRIG,OUTPUT);
pinMode(ECHO,INPUT);

pinMode(Sensor_der,INPUT);
pinMode(Sensor_centro,INPUT);
pinMode(Sensor_izq,INPUT);

pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);

digitalWrite(TRIG,LOW);
delay (5000); //Se espera 5 segundos reglamentarios en el torneo
}

void  loop(){
  
  //Sección de mediciones iniciales del robot sumo: distancia del oponente y plataforma
 SR_der=analogRead(Sensor_der);
 SR_izq=analogRead(Sensor_izq);
 SR_centro=analogRead(Sensor_centro);
 distancia=medirDistancia();

 //Buscar un oponente:
 while(distancia>30 || distancia==0){
  ROTAR(150);
  
  SR_der=analogRead(Sensor_der);
  SR_centro=analogRead(Sensor_centro);
  SR_izq=analogRead(Sensor_izq);
  distancia=medirDistancia();

  if(distancia<=30 && distancia>0){
    break;
  }
  if(SR_der<250 || SR_centro<250){ 
      break;
  }
 }

 //Se detecta un oponente
 while(distancia<=30 && distancia>0){
    Stop(); //El robot se detiene
    AVANZAR(255);
    
    SR_der=analogRead(Sensor_der);
    SR_centro=analogRead(Sensor_centro);
    SR_izq=analogRead(Sensor_izq);
    distancia=medirDistancia();
    
    if(SR_der<250 || SR_centro<250){ 
      break;
      }
      
    delay(10); 
    }

  //Se detecta la línea blanca
  while(SR_der<250 || SR_izq<250 || SR_centro<250){

    SR_der=analogRead(Sensor_der);
    SR_centro=analogRead(Sensor_centro);
    SR_izq=analogRead(Sensor_izq);
    
    if(SR_der<250 || SR_izq<250){
      Stop();
      RETROCEDER(255);
      delay (500);
    }
    else if(SR_centro<250){
      Stop();
      AVANZAR(255);
      delay(500);
    }
    else if(SR_der>250 || SR_izq>250 || SR_centro>250){
      break;
    }
  
  }

   
} 



//--------------.------------------------------
void  AVANZAR (int vel){
  analogWrite(IN1,vel);
  analogWrite(IN2,0);
  analogWrite(IN3,vel);
  analogWrite(IN4,0);
}

//--------------------------------------------
void  RETROCEDER (int vel){
  analogWrite(IN1,0);
  analogWrite(IN2,vel);
  analogWrite(IN3,0);
  analogWrite(IN4,vel);
}

//--------------------------------------------
void  ROTAR (int vel){
  analogWrite(IN1,vel);
  analogWrite(IN2,0);
  analogWrite(IN3,0);
  analogWrite(IN4,vel);
}

//--------------------------------------------
void  ANTIROTAR (int vel){
  analogWrite(IN1,0);
  analogWrite(IN2,vel);
  analogWrite(IN3,vel);
  analogWrite(IN4,0);
}

//--------------------------------------------
void  Stop(){
  analogWrite(IN1,0);
  analogWrite(IN2,0);
  analogWrite(IN3,0);
  analogWrite(IN4,0);
}

//Creamos la función medirDistancia() que devolverá un valor de tipo long
long medirDistancia() {
  long t;
  long distancia;

  digitalWrite(TRIG,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG,LOW);

  t=pulseIn(ECHO,HIGH);
  distancia= t*0.01716;
  
  return distancia;
}
