void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT); //LED VERDE 1
pinMode(12,OUTPUT); //LED AMARILLO 1
pinMode(11,OUTPUT); //led ROJO 1
pinMode(5,OUTPUT); //LED VERDE 2
pinMode(4,OUTPUT); //LED AMARILLO 2
pinMode(3,OUTPUT); //LED ROJO 2

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(13,HIGH); //Enciende verde 1  
digitalWrite(11,LOW); //Apaga rojo 1
digitalWrite(3,HIGH); //Enciende rojo 2
digitalWrite(4,LOW); //Apaga amarillo 2 
delay(1000);
digitalWrite(13,LOW); //Comienza parpadeo de verde 1
delay(300);
digitalWrite(13,HIGH); 
delay(300);
digitalWrite(13,LOW);
delay(300);
digitalWrite(13,HIGH); //Termina parpadedo de verde 1
delay(300);
digitalWrite(13,LOW); //Apaga verde 1
digitalWrite(12,HIGH); //Enciende amarillo 1 
delay(900);
digitalWrite(12,LOW); //Apaga amarillo 1
digitalWrite(11,HIGH); //Enciende rojo 1 
digitalWrite(5,HIGH); //Enciende verde 2
digitalWrite(3,LOW); //Apaga rojo 2
delay(1000);
digitalWrite(5,LOW); //Comienza parpadeo de verde 2
delay(300);
digitalWrite(5,HIGH); 
delay(300);
digitalWrite(5,LOW);
delay(300);
digitalWrite(5,HIGH); //Termina parpadedo de verde 2
delay(300);
digitalWrite(5,LOW); //Apaga verde 2
digitalWrite(4,HIGH); //Enciende amarillo 2
delay(900);
}
