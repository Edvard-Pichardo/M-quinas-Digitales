int but0; //Declaramos ldos variables para el estado de los dos botones utilizados
int but1;

void setup() {
  pinMode(A0, INPUT); //Declaramos A0 como entrada, en este caso del estado del botón 0
  pinMode(A1,INPUT); //Declaramos A1 como entrada, en este caso del estado del botón 1
  pinMode(7,OUTPUT); //Declaramos el pin  7 como salida, en este caso para el estado del LED

}

void loop() {
  but0=digitalRead(A0); //Definimos but0 como el estado digital del pin A0
  but1=digitalRead(A1); //Definimos but1 como el estado digital del pin A1
  delay(200); //Por cuestiones mecanicas con el botón, necesitamos un delay

  //Abrimos un condicional donde si but0 es 1 pero but1 es 0 entonces el LED se prende
  if(but0 && !but1){
    digitalWrite(7,HIGH);
    delay(200); 
    }
  //Abrimos un else if donde si but0 es 0 pero but1 es 1 entonces el LED se apaga
  else if(but1 && !but0){
    digitalWrite(7,LOW);
    delay(200);
  }
    

}
