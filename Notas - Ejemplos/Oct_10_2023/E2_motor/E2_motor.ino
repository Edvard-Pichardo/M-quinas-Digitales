byte motor1[3]={11,12,13}; //Define una matriz de tres entradas con los pines 11, 12 y 13
byte motor2[3]={10,9,8}; //Define una matriz de tres entradas con los pines 10, 9 y 8
int num; //Declaramos la variable entera num

void setup() {
  Serial.begin(9600); //Inicia la comunicacion Serial
  for(int i=0;i<3;i++){ //Define todas las entradas de las matrices como salidas
    pinMode(motor1[i],OUTPUT);
    pinMode(motor2[i],OUTPUT);
  }

}

void loop() {

   if(Serial.available()!=0){ //Inicia la comunicacion serial para recibir valores
    String str=Serial.readStringUntil('\n'); //Recibe una cadena en la variable str
    num=str.toInt(); //Transforma str en un número entero y la guarda en num
    num=min(num,255); //Si el valor introducido es mayor a 255 lo devuelve a 255
    num=max(num,0); //Si el valor introducido es menor a 0 entonces lo devuelve a 0
    delay(5);

    analogWrite(motor1[0],num);
    digitalWrite(motor1[1],HIGH);
    digitalWrite(motor1[2],LOW);

    analogWrite(motor2[0],num);
    digitalWrite(motor2[1],HIGH);
    digitalWrite(motor2[2],LOW);

    Serial.print("Velocidad de los motores: ");
    Serial.println(num);
    }
}
