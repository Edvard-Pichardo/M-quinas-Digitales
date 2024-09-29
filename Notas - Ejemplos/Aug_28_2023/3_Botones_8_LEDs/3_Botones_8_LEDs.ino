bool t1; //Declaramos valores booleanos para comprobar si un LED está encendido
bool t2;
bool t3;
bool t4;
bool t5;
bool t6;
bool t7;
bool t8;
bool var1; //Declaramos valores booleanos para ver el estado de los botones
bool var2;
bool var3;
int temp; //Declaramos un valor al tiempo

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
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  var1=digitalRead(A0);
  var2=digitalRead(A1);
  var3=digitalRead(A2);
  t1=digitalRead(13);
  t2=digitalRead(12);
  t3=digitalRead(11);
  t4=digitalRead(10);
  t5=digitalRead(9);
  t6=digitalRead(8);
  t7=digitalRead(7);
  t8=digitalRead(6);
  temp=100

  if(t1==true || t2==true || t3==true || t4==true || t5==true || t6==true || t7==true || t8==true){
    digitalWrite(13,LOW);
    digitalWrite(12, LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
    digitalWrite(7,LOW);
    digitalWrite(6,LOW);
    delay(temp);
  }

  if(var1==true && var2==false && var3==false){  //Enc. 3 leds
    digitalWrite(13,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);


}
