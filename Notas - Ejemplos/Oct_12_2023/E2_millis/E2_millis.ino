long tiempo; //Declaramos las variables tiempo, tiempo2, tiempo3 y t1, t2 y t3.
long tiempo2; 
long tiempo3;
long t1,t2,t3;
int op=1;

void setup() {
  pinMode(6,OUTPUT); //definimos los pines 6 y 7 como salidas
  pinMode(7,OUTPUT);
  for(int i=8;i<11;i++){
    pinMode(i,OUTPUT); //declaramos los pines del 8 al 10 como salidas
  }
  pinMode(A0,INPUT); //declaramos los pines analogicos A0 y A1 como entradas
  pinMode(A1,INPUT);
  tiempo= millis(); //Usamos la función millis para las variables tiempo, tiempo2, tiempo3 y t1, t2 y t3.
  tiempo2=millis();
  tiempo3=millis();
  t1=millis();
  t2=millis();
  t3=millis();
}

void loop() {
  if(millis()-tiempo>500){ //Prendemos el led del pin 7 cada 500 ms
    digitalWrite(7,!digitalRead(7));
    tiempo=millis();
  }
  
  if(millis()-tiempo2>300){  //Prendemos el led del pin 6 cada 300 ms
    digitalWrite(6,!digitalRead(6));
    tiempo2=millis();
  }

  bool estado1=analogRead(A0); //declaramos dos variables booleanas para leer el estado de A0 y A1
  bool estado2=analogRead(A1);
  
  if(estado1){ //Prendemos el led del pin 5 si el botón está presionado
    digitalWrite(5,HIGH);
  }
  else{
    digitalWrite(5,LOW);
  }
  
  if(estado2){ //Prendemos el led del pin 4 si el botón está presionado
    digitalWrite(4,HIGH);
  }
  else{
    digitalWrite(4,LOW);
  }

  if(millis()-t1>800){ //
    if(op==1){
    digitalWrite(10,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
    }
    else if(op==2){
      digitalWrite(10,LOW);
      digitalWrite(9,HIGH);
      digitalWrite(8,LOW);
    }
    else if(op==3){
      digitalWrite(10,LOW);
      digitalWrite(9,LOW);
      digitalWrite(8,HIGH);
    }
    else if(op==4){
      digitalWrite(10,HIGH);
      digitalWrite(9,HIGH);
      digitalWrite(8,LOW);
    }
    else if(op==5){
      digitalWrite(10,HIGH);
      digitalWrite(9,LOW);
      digitalWrite(8,HIGH);
    }
    else if(op==6){
      digitalWrite(10,LOW);
      digitalWrite(9,HIGH);
      digitalWrite(8,HIGH);
    }
    else if(op==7){
      digitalWrite(10,HIGH);
      digitalWrite(9,HIGH);
      digitalWrite(8,HIGH);
    }
    op++;
    if (op>7){
      op=1;
    }
    
    t1=millis();

  }

}
