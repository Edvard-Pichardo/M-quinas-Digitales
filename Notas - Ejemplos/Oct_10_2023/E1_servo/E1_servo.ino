#include <Servo.h> //Incluye la librería Servo

int num; //Declara la variable entera num

Servo myservo;  //Crea dos objetos myservo y myservo2
Servo myservo2;

void setup() {
  Serial.begin(9600); //Incluye la comuniacion Serial
  
  myservo.attach(10,1000,2000);  //Asocia myservo al pin 10 y especifica los valores de pulso mínimo (1000 µs) y pulso máximo (2000 µs) para el servo. 
  myservo2.attach(9,1000,2000);  //Asocia myservo2 al pin 9 y especifica los valores de pulso mínimo (1000 µs) y pulso máximo (2000 µs) para el servo. 
  myservo.write(0); //Coloca a myservo en una posición de 0 grados
  myservo2.write(180); //Coloca a myservo2 en una posicion de 180 grados
}

void loop() {
  if(Serial.available()!=0){ //Abre la comunicación serial para recibir datos
    String str=Serial.readStringUntil('\n'); //Recibe una cadena de caracteres
    num=str.toInt(); //Transforma la cadena de caracteres a números enteros (si se puede)
    num=min(num,180); //Si el numero introducido es mayor a 180 entonces el resultado se va a 180
    num=max(num,0); //Si el numero introducido es menor a 0 entonces el resultado se va a 0
    delay(5);
    //num=Serial.parceInt();
   
    myservo.write(num); //Mueve myservo a la posicion de num grados
    Serial.print("Servo 1: "); //Imprime la posición de myservo en la pantalla
    Serial.print(myservo.read());
    myservo2.write(180-num); //Mueve myservo2 a la posición complemento de myservo
    Serial.print(", Servo 2: "); //Imprime la posición de myservo2 en la pantalla
    Serial.println(myservo2.read());
    delay(5);
    

  }
}
