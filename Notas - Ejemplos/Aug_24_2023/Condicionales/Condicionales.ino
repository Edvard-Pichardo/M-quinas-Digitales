bool var; //Declaramos una variable booleana
void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(A0,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  var=digitalRead(A0); //Definimos nuestra variable para ver el estado de la entrada A0
  
  if(var==true){ //Usamos el condicional if para definir las acciones para los dos posibles casos del botón
    digitalWrite(13,HIGH);
    digitalWrite(4,LOW);
    delay(100);
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
    delay(100);
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW);
    delay(100);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    delay(100);
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
    delay(100);
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
    delay(100);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    delay(100);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    delay(100);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    delay(100);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    delay(100);
  }

  else{
    digitalWrite(4,HIGH);
    digitalWrite(13,LOW);
    delay(100);
    digitalWrite(5,HIGH);
    digitalWrite(4,LOW);
    delay(100);
    digitalWrite(6,HIGH);
    digitalWrite(5,LOW);
    delay(100);
    digitalWrite(7,HIGH);
    digitalWrite(6,LOW);
    delay(100);
    digitalWrite(8,HIGH);
    digitalWrite(7,LOW);
    delay(100);
    digitalWrite(9,HIGH);
    digitalWrite(8,LOW);
    delay(100);
    digitalWrite(10,HIGH);
    digitalWrite(9,LOW);
    delay(100);
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
    delay(100);
    digitalWrite(12,HIGH);
    digitalWrite(11,LOW);
    delay(100);
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
    delay(100);
  }
 
}
