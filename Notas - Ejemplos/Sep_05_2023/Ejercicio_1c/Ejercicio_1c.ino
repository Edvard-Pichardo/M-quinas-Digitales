int but; //Declaramos una variable entera para el estado del botón
int cont=0; //Declaramos una variable entera como contador y la igualamos a cero

void setup() {
  pinMode(13,INPUT); //DEclaramos el pin 13 como entrada (botón)
  pinMode(7,OUTPUT); //Declaramos el pin 7 como salida (LED)
}

void loop() {
  but=digitalRead(13); //Definimos la variable but como el estado del pin 13 (0 o 1), es decir, si el botón está presionado o no.
  delay(200); //Debido a la estructura física del botón, necesitamos un delay pequeño para que pueda estar totalmente en uno de sus estados.

  //Abrimos un condicional tal que, si la variable but es 1 y cont es 0, entonces se enciende el LED y se le suma 1 a cont, además, se realiza un delay por la misma razón comentada anteriormente.
  if(but && cont==0){
    digitalWrite(7,HIGH);
    cont++;
    delay(200);
  }
  //Abrimos un else if, tal que si but es 1 y cont es 1 entonces el LED se apaga y se le resta 1 a cont, además, se realiza un delay por la misma razón comentada anteriormente.
  else if(but && cont==1){
    digitalWrite(7,LOW);
    cont--;
    delay(200);
  }


}
