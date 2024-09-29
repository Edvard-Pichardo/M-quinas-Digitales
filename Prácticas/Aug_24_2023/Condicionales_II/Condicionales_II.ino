bool var;
int tiempo;
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
  var=digitalRead(A0);
  tiempo=50;
  if(var==true){
    digitalWrite(13,HIGH);
    digitalWrite(4,LOW);
    delay(tiempo);
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
    delay(tiempo);
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW);
    delay(tiempo);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    delay(tiempo);
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
    delay(tiempo);
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
    delay(tiempo);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    delay(tiempo);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    delay(tiempo);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    delay(tiempo);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    delay(tiempo);
  }

  else{
    digitalWrite(4,HIGH);
    digitalWrite(13,LOW);
    delay(tiempo);
    digitalWrite(5,HIGH);
    digitalWrite(4,LOW);
    delay(tiempo);
    digitalWrite(6,HIGH);
    digitalWrite(5,LOW);
    delay(tiempo);
    digitalWrite(7,HIGH);
    digitalWrite(6,LOW);
    delay(tiempo);
    digitalWrite(8,HIGH);
    digitalWrite(7,LOW);
    delay(tiempo);
    digitalWrite(9,HIGH);
    digitalWrite(8,LOW);
    delay(tiempo);
    digitalWrite(10,HIGH);
    digitalWrite(9,LOW);
    delay(tiempo);
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
    delay(tiempo);
    digitalWrite(12,HIGH);
    digitalWrite(11,LOW);
    delay(tiempo);
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
    delay(tiempo);
  }
 
}
