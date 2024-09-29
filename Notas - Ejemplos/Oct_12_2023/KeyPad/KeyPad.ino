#include <Keypad.h>

const byte fil=4; //4 filas
const byte col=4; //4 columnas
char tecla;
int tiempo=200;

char kpad[fil][col]={
  {'7','8','9','/'}, //A
  {'4','5','6','*'}, //B
  {'1','2','3','-'}, //C
  {'c','0','=','+'}  //D
}; //1   2   3   4

byte FilPin[fil]={A0,A1,A2,A3};
byte ColPin[col]={A4,A5,13,12};

Keypad teclado=Keypad{makeKeymap(kpad), FilPin, ColPin, fil,col};
void setup() {
  Serial.begin(9600);
  for(int i=2;i<11;i++){
    pinMode(i,OUTPUT);
  }

}

void loop() {
  tecla=teclado.getKey();

  switch(tecla){
    case '9':
      for(int i=2;i<11;i++){
        digitalWrite(i,LOW);
      }
      digitalWrite(2,HIGH);
      Serial.println(tecla);
      break;
    case '8':
      for(int i=2;i<11;i++){
        digitalWrite(i,LOW);
      }
      digitalWrite(3,HIGH);
      Serial.println(tecla);
      break;
    case '7':
      for(int i=2;i<11;i++){
        digitalWrite(i,LOW);
      }
      digitalWrite(4,HIGH);
      Serial.println(tecla);
      break;
    case '6':
      for(int i=2;i<11;i++){
        digitalWrite(i,LOW);
      }
      digitalWrite(5,HIGH);
      Serial.println(tecla);
      break;
    case '5':
      for(int i=2;i<11;i++){
        digitalWrite(i,LOW);
      }
      digitalWrite(6,HIGH);
      Serial.println(tecla);
      break;
    case '4':
      for(int i=2;i<11;i++){
        digitalWrite(i,LOW);
      }
      digitalWrite(7,HIGH);
      Serial.println(tecla);
      break;
    case '3':
      for(int i=2;i<11;i++){
        digitalWrite(i,LOW);
      }
      digitalWrite(8,HIGH);
      Serial.println(tecla);
      break;
    case '2':
      for(int i=2;i<11;i++){
        digitalWrite(i,LOW);
      }
      digitalWrite(9,HIGH);
      Serial.println(tecla);
      break;
    case '1':
      for(int i=2;i<11;i++){
        digitalWrite(i,LOW);
      }
      digitalWrite(10,HIGH);
      Serial.println(tecla);
      break;
    case 'c':
      for(int i=2;i<11;i++){
        digitalWrite(i,HIGH);
      }
      Serial.println(tecla);
      break;
    case '0':
      for(int i=2;i<11;i++){
        digitalWrite(i,LOW);
      }
      Serial.println(tecla);
      break;
    case '=':
      Serial.println(tecla);
      for(int i=2;i<11;i++){
        digitalWrite(i,HIGH);
      }
      delay(tiempo);
      for(int j=2;j<11;j++){
        digitalWrite(j,LOW);
      }
      delay(tiempo);
      for(int i=2;i<11;i++){
        digitalWrite(i,HIGH);
      }
      delay(tiempo);
      for(int j=2;j<11;j++){
        digitalWrite(j,LOW);
      }
      delay(tiempo);
      break;
    default:
      break;
  }

}
