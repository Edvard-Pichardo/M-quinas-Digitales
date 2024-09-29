bool var1; //DEclaramos las variables booleanas para los botones
bool var2;
bool var3;
int temp; //Declaramos una variable entera para el tiempo
void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT); //Definimos los pines de salida para los LEDs
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(A0,INPUT); //Definimos los pines de entrada para los botones
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  var1=digitalRead(A0); //Definimos las variables para los valores booleanos asociados a los botones
  var2=digitalRead(A1);
  var3=digitalRead(A2);
  temp=200; //Declaramos el tiempo para el delay


  if(var1==true && var2==false && var3==false){  //Enc. 3 leds
    digitalWrite(13,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    delay(temp);
    digitalWrite(13,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    delay(20);
  }

  else if(var1==false && var2==true && var3==false){ //Enc. 4 LEDs
    digitalWrite(12,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
    delay(temp);
    digitalWrite(12,LOW);
    digitalWrite(6,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    delay(20);
  }

  else if(var1==false && var2==false && var3==true){ //Enc. 2 LEDs
    digitalWrite(9,HIGH);
    digitalWrite(7,HIGH);
    delay(temp);
    digitalWrite(9,LOW);
    digitalWrite(7,LOW);
    delay(20);
  }
  
  else if(var1==true && var2==true && var3==false){ //Enc. 1 LEd
    digitalWrite(11,HIGH);
    delay(temp);
    digitalWrite(11,LOW);
    delay(20);
  }

  else if(var1==false && var2==true && var3==true){ //ENc. 7 LEds
    digitalWrite(9,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(10,HIGH);
    delay(temp);
    digitalWrite(9,LOW);
    digitalWrite(7,LOW);
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(6,LOW);
    digitalWrite(10,LOW);
    delay(20);
  }

  else if(var1==true && var2==false && var3==true){ //Enc. 6 LEDs
    digitalWrite(9,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(13,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(6,HIGH);
    delay(temp);
    digitalWrite(9,LOW);
    digitalWrite(7,LOW);
    digitalWrite(13,LOW);
    digitalWrite(8,LOW);
    digitalWrite(11,LOW);
    digitalWrite(6,LOW);
    digitalWrite(10,LOW);
    delay(20);
  }

  else if(var1==true && var2==true && var3==true){ //Enc. 8 LEDs
    digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(6,HIGH);
    delay(temp);
    digitalWrite(13,LOW);
    digitalWrite(12, LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
    digitalWrite(7,LOW);
    digitalWrite(6,LOW);
    delay(20);
    
  }

  else{ //Enc. 5 LEDs
    digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(7,HIGH);
    delay(temp);
    digitalWrite(13,LOW);
    digitalWrite(12, LOW);
    digitalWrite(11,LOW);
    digitalWrite(9,LOW);
    digitalWrite(7,LOW);
    delay(20);
  }

  
  
  
 
}
