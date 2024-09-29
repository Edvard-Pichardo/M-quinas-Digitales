void setup() {
  for(int i=13;i>=4;i--){ //ciclo for, desde que i vale 4 hasta 13, define los pines 4 a 13 como salidas
    pinMode(i, OUTPUT);
  }
}

void loop() {
  int i; //Se define un numero entero i
  int temp=250; //Se define una variable entera para el delay

  for(i=13;i>=4;i--){ //Esta instrucción enciende y apaga los leds de forma descendente del pin 13 al pin 4 uno a uno
    digitalWrite(i,HIGH);
    delay(temp);
    digitalWrite(i,LOW);
  }

  for(i=4;i<=13;i++){ //Esta instrucción enciende y apaga los leds de forma ascendente del pin 13 al pin 4 uno a uno
    digitalWrite(i,HIGH);
    delay(temp);
    digitalWrite(i,LOW);
  }
}
