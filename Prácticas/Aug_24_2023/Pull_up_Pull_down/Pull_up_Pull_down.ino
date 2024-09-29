void setup() {
  // put your setup code here, to run once:
  pinMode(7,OUTPUT);
  pinMode(A0,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(7, digitalRead(A0));

}
