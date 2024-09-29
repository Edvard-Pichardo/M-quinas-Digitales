byte motor1[3]={11,12,13};
byte motor2[3]={10,9,8};
void setup() {
  for(int i=0;i<3;i++){
    pinMode(motor1[i],OUTPUT);
    pinMode(motor2[i],OUTPUT);
  }

}

void loop() {
  analogWrite(motor1[0],120);
  digitalWrite(motor1[1],HIGH);
  digitalWrite(motor1[2],LOW);

  analogWrite(motor2[0],255);
  digitalWrite(motor2[1],HIGH);
  digitalWrite(motor2[2],LOW);
  delay(500);
  
  digitalWrite(motor1[0],HIGH);
  digitalWrite(motor1[1],LOW);
  digitalWrite(motor1[2],HIGH);

  digitalWrite(motor2[0],HIGH);
  digitalWrite(motor2[1],LOW);
  digitalWrite(motor2[2],HIGH);
  delay(500);

}
