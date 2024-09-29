int valor;
int valor_ent;
int pot=A0;
int temp;

void setup() {
  pinMode(3,OUTPUT);
  pinMode(pot,INPUT);
}

void loop(){

  valor_ent=analogRead(pot);
  valor=map(valor_ent,0,1023,0,100);
  temp=20;

  for(valor;valor<=255;valor=256){
    analogWrite(3,valor);
    delay(temp);
  }
  

  
}
