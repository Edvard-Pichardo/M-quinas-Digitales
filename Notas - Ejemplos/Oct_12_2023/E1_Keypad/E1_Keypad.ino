#include <Keypad.h> //Incluye la librerúa Keypad

byte motor1[3]={5,7,6}; //Declara la matriz para las entrdas del motor
byte motor2[3]={3,4,2}; //Declara la matriz para las entrdas del motor
int vel=125; //Declara la velocidad de los motores
byte der[2]={HIGH, LOW}; //Declaramos las condiciones para que el motor gire a lam izquierda o a la derecha por medio de matrices
byte izq[2]={LOW, HIGH};
bool cond1=true; //Variables booleanas para detectar si el motor gira a la derecha o a la izquierda con true o false
bool cond2=true;


const byte fil=4; //Define 4 filas
const byte col=4; //Define 4 columnas
char tecla; //Declara la variable char tecla
int tiempo=200; //Declara la variable entera tiempo

char kpad[fil][col]={ //Declara la matriz 4x4 para el teclado
  {'7','8','9','/'}, //A
  {'4','5','6','*'}, //B
  {'1','2','3','-'}, //C
  {'c','0','=','+'}  //D
}; //1   2   3   4

byte FilPin[fil]={A0,A1,A2,A3}; //Define los pines de conexión del teclado para sus filas y columnas
byte ColPin[col]={A4,A5,13,12};

Keypad teclado=Keypad{makeKeymap(kpad), FilPin, ColPin, fil,col}; //Declara el teclado

void setup() {
  Serial.begin(9600); //Inicia la comuniacion Serial
  for(int i=0;i<3;i++){ //Define los pines para los motores
    pinMode(motor1[i],OUTPUT);
    pinMode(motor2[i],OUTPUT);
  }
  
  Serial.println("Iniciando motores..."); //Imprime un mensaje en la consola
  delay(100);
  
  analogWrite(motor1[0],vel); //Enciende motor 1 a velocidad inicial (vel=125) girando a la derecha
  digitalWrite(motor1[1],der[0]);
  digitalWrite(motor1[2],der[1]);

  analogWrite(motor2[0],vel); //Enciende motor 2 a velocidad inicial (vel=125) girando a la derecha
  digitalWrite(motor2[1],der[0]);
  digitalWrite(motor2[2],der[1]);

  Serial.println("Motores girando a la derecha con velocidad 125");
  Serial.println(" ");
}


void loop() {
    tecla=teclado.getKey(); //Recibe un caracter del teclado

    switch(tecla){
    case '9':
      analogWrite(motor2[0],vel); //El motor2 gira a la derecha
      digitalWrite(motor2[1],HIGH);
      digitalWrite(motor2[2],LOW);
      cond1=true;
      
      Serial.print("Velocidad de los motores: ");
      Serial.println(vel);
      Serial.print("Tecla presionada: ");
      Serial.println(tecla);
      Serial.print("Accion: ");
      Serial.println("Motor 2 girando a la derecha");
      Serial.println(" ");
      break;
      
    case '8':
      vel=vel+5; //La velocidad aumenta en 5 y se establece el minimo y maximo que puede tomar
      vel=min(vel,255);
      vel=max(vel,0);
      delay(50);
      
      if(cond2){ //Si el motor2 gira a la derecha
        analogWrite(motor2[0],vel);
        digitalWrite(motor2[1],der[0]);
        digitalWrite(motor2[2],der[1]);
      }
      else{ //Si el motor2 gira a la izquierda
        analogWrite(motor2[0],vel);
        digitalWrite(motor2[1],izq[0]);
        digitalWrite(motor2[2],izq[1]);
      }
      if(cond1){ //Si el motor1 gira a la derecha
        analogWrite(motor1[0],vel);
        digitalWrite(motor1[1],der[0]);
        digitalWrite(motor1[2],der[1]);
      }
      else{ //Si el motor1 gira a la izquierda
        analogWrite(motor1[0],vel);
        digitalWrite(motor1[1],izq[0]);
        digitalWrite(motor1[2],izq[1]);
      }
      
      Serial.print("Velocidad de los motores: ");
      Serial.println(vel);
      Serial.print("Tecla presionada: ");
      Serial.println(tecla);
      if(vel<255){
        Serial.print("Accion: ");
        Serial.println("Velocidad aumentada (+5)");
        Serial.println(" ");
      }
      else{
        Serial.print("Accion: ");
        Serial.println("Velocidad maxima alcanzada (255)");
        Serial.println(" ");
      }
      break;
      
    case '7':
      analogWrite(motor1[0],vel); //El motor1 gira a la derecha
      digitalWrite(motor1[1],der[0]);
      digitalWrite(motor1[2],der[1]);
      cond1=true;
      
      Serial.print("Velocidad de los motores: ");
      Serial.println(vel);
      Serial.print("Tecla presionada: ");
      Serial.println(tecla);
      Serial.print("Accion: ");
      Serial.println("Motor 1 girando a la derecha");
      Serial.println(" ");
      break;

    case '6':
      analogWrite(motor1[0],vel); //El motor1 gira a la izquierda
      digitalWrite(motor1[1],izq[0]);
      digitalWrite(motor1[2],izq[1]);
      cond1=false;

      analogWrite(motor2[0],vel); //El motor2 gira a la izquierda
      digitalWrite(motor2[1],izq[0]);
      digitalWrite(motor2[2],izq[1]);
      cond2=false;

      Serial.print("Velocidad de los motores: ");
      Serial.println(vel);
      Serial.print("Tecla presionada: ");
      Serial.println(tecla);
      Serial.print("Accion: ");
      Serial.println("Motores girando a la izquierda");
      Serial.println(" ");
      break;

    case '5':
      if(cond1){
        analogWrite(motor2[0],vel); //El motor2 gira a la izquierda contrario al motor1
        digitalWrite(motor2[1],izq[0]);
        digitalWrite(motor2[2],izq[1]);
        cond2=false;
      }
      else if(!cond1){
        analogWrite(motor2[0],vel); //El motor2 gira a la derecha contrario al motor1
        digitalWrite(motor2[1],der[0]);
        digitalWrite(motor2[2],der[1]);
        cond2=true;
      }

      Serial.print("Velocidad de los motores: ");
      Serial.println(vel);
      Serial.print("Tecla presionada: ");
      Serial.println(tecla);
      Serial.print("Accion: ");
      Serial.println("Motores girando en sentido contrario uno del otro");
      Serial.println(" ");
      break;

    case '4':
      analogWrite(motor1[0],vel); //El motor1 gira a la derecha
      digitalWrite(motor1[1],der[0]);
      digitalWrite(motor1[2],der[1]);
      cond1=true;

      analogWrite(motor2[0],vel); //El motor2 gira a la derecha
      digitalWrite(motor2[1],der[0]);
      digitalWrite(motor2[2],der[1]);
      cond2=true;

      Serial.print("Velocidad de los motores: ");
      Serial.println(vel);
      Serial.print("Tecla presionada: ");
      Serial.println(tecla);
      Serial.print("Accion: ");
      Serial.println("Motores girando a la derecha");
      Serial.println(" ");
      break;

    case '3':
      analogWrite(motor2[0],vel); //El motor 2 gira a la izquierda
      digitalWrite(motor2[1],izq[0]);
      digitalWrite(motor2[2],izq[1]);
      cond2=false;
      
      Serial.print("Velocidad de los motores: ");
      Serial.println(vel);
      Serial.print("Tecla presionada: ");
      Serial.println(tecla);
      Serial.print("Accion: ");
      Serial.println("Motor 2 girando a la izquierda");
      Serial.println(" ");
      break;

    case '2':
      vel=vel-5; //La velocidad disminuye en 5 y se establece el minimo y maximo que puede tomar
      vel=min(vel,255);
      vel=max(vel,0);
      delay(50);
      
      if(cond2){ //Si el motor2 gira a la derecha
        analogWrite(motor2[0],vel);
        digitalWrite(motor2[1],der[0]);
        digitalWrite(motor2[2],der[1]);
      }
      else{ //Si el motor2 gira a la izquierda
        analogWrite(motor2[0],vel);
        digitalWrite(motor2[1],izq[0]);
        digitalWrite(motor2[2],izq[1]);
      }
      if(cond1){ //Si el motor1 gira a la derecha
        analogWrite(motor1[0],vel);
        digitalWrite(motor1[1],der[0]);
        digitalWrite(motor1[2],der[1]);
      }
      else{ //Si el motor1 gira a la izquierda
        analogWrite(motor1[0],vel);
        digitalWrite(motor1[1],izq[0]);
        digitalWrite(motor1[2],izq[1]);
      }
      
      Serial.print("Velocidad de los motores: ");
      Serial.println(vel);
      Serial.print("Tecla presionada: ");
      Serial.println(tecla);
      if(vel>0){
        Serial.print("Accion: ");
        Serial.println("Velocidad disminuida (-5)");
        Serial.println(" ");
      }
      else{
        Serial.print("Accion: ");
        Serial.println("Velocidad minima alcanzada (0)");
        Serial.println(" ");
      }
      break;

    case '1':
      analogWrite(motor1[0],vel); //El motor 1 gira a la izquierda
      digitalWrite(motor1[1],izq[0]);
      digitalWrite(motor1[2],izq[1]);
      cond1=false;
      
      Serial.print("Velocidad de los motores: ");
      Serial.println(vel);
      Serial.print("Tecla presionada: ");
      Serial.println(tecla);
      Serial.print("Accion: ");
      Serial.println("Motor 1 girando a la izquierda");
      Serial.println(" ");
      break;

    case 'c':
      vel=255;

      if(cond2){ //Si el motor2 gira a la derecha
        analogWrite(motor2[0],vel);
        digitalWrite(motor2[1],der[0]);
        digitalWrite(motor2[2],der[1]);
      }
      else{ //Si el motor2 gira a la izquierda
        analogWrite(motor2[0],vel);
        digitalWrite(motor2[1],izq[0]);
        digitalWrite(motor2[2],izq[1]);
      }
      if(cond1){ //Si el motor1 gira a la derecha
        analogWrite(motor1[0],vel);
        digitalWrite(motor1[1],der[0]);
        digitalWrite(motor1[2],der[1]);
      }
      else{ //Si el motor1 gira a la izquierda
        analogWrite(motor1[0],vel);
        digitalWrite(motor1[1],izq[0]);
        digitalWrite(motor1[2],izq[1]);
      }
      
      Serial.print("Velocidad de los motores: ");
      Serial.println(vel);
      Serial.print("Tecla presionada: ");
      Serial.println(tecla);
      Serial.print("Accion: ");
      Serial.println("Velocidad maxima (255)");
      Serial.println(" ");
      break;

    case '0':
      vel=0;

      if(cond2){ //Si el motor2 gira a la derecha
        analogWrite(motor2[0],vel);
        digitalWrite(motor2[1],der[0]);
        digitalWrite(motor2[2],der[1]);
      }
      else{ //Si el motor2 gira a la izquierda
        analogWrite(motor2[0],vel);
        digitalWrite(motor2[1],izq[0]);
        digitalWrite(motor2[2],izq[1]);
      }
      
      if(cond1){ //Si el motor1 gira a la derecha
        analogWrite(motor1[0],vel);
        digitalWrite(motor1[1],der[0]);
        digitalWrite(motor1[2],der[1]);
      }
      else{ //Si el motor1 gira a la izquierda
        analogWrite(motor1[0],vel);
        digitalWrite(motor1[1],izq[0]);
        digitalWrite(motor1[2],izq[1]);
      }
      
      Serial.print("Velocidad de los motores: ");
      Serial.println(vel);
      Serial.print("Tecla presionada: ");
      Serial.println(tecla);
      Serial.print("Accion: ");
      Serial.println("Velocidad minima (0)");
      Serial.println(" ");
      break;

    case '=':
      vel=125;

      if(cond2){ //Si el motor2 gira a la derecha
        analogWrite(motor2[0],vel);
        digitalWrite(motor2[1],der[0]);
        digitalWrite(motor2[2],der[1]);
      }
      else{ //Si el motor2 gira a la izquierda
        analogWrite(motor2[0],vel);
        digitalWrite(motor2[1],izq[0]);
        digitalWrite(motor2[2],izq[1]);
      }
      
      if(cond1){ //Si el motor1 gira a la derecha
        analogWrite(motor1[0],vel);
        digitalWrite(motor1[1],der[0]);
        digitalWrite(motor1[2],der[1]);
      }
      else{ //Si el motor1 gira a la izquierda
        analogWrite(motor1[0],vel);
        digitalWrite(motor1[1],izq[0]);
        digitalWrite(motor1[2],izq[1]);
      }
      
      Serial.print("Velocidad de los motores: ");
      Serial.println(vel);
      Serial.print("Tecla presionada: ");
      Serial.println(tecla);
      Serial.print("Accion: ");
      Serial.println("Velocidad media (125)");
      Serial.println(" ");
      break;
    
    default:
      break;
  }

}
