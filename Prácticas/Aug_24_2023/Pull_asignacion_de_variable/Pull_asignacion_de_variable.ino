bool variable;
void setup() {
  // put your setup code here, to run once:
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(A0,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  variable=digitalRead(A0);
  digitalWrite(7,variable);
  digitalWrite(8,!variable);

}
