int but; //Declaramos una variable entera para el estado del botón

void setup() {
  pinMode(13,INPUT); //Declaramos el pin 13 como entrada (botón)
  pinMode(7,OUTPUT); //Declaramos el pin 13 como salida (LED)
}

void loop() {
  but=digitalRead(13); //Definimos la variable but como el estado del pin 13 (0 o 1), es decir, si el botón está presionado o no.

  //Abrimos un condicional en el que si la variable but es 1 entonces el LED se enciende, de lo contrario, se apaga.
  if(but){ 
    digitalWrite(7,HIGH);
  }
  else{
    digitalWrite(7,LOW);
  }

}
