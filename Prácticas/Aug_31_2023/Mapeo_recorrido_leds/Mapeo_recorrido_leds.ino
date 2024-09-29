int valor; //Leemos el valor del potenciometro
int temp; //Definimos un entero para el delay
int valor_map;
int valor_map1;

void setup() {
  pinMode(A0, INPUT); //Indicamos el pin A0 como entrada
  
  for(int i=4;i>=13;i++){ //El ciclo for indica los pines del 4 al 13 como salidas
    pinMode(i,OUTPUT);
  }
  
  Serial.begin(9600); //Se indica la comunicación serial
}


void loop() {
  valor=analogRead(A0); //Leemos el estado del pin A0
  temp=200; //Definimos la variable del delay para 200 ms
  valor_map=map(valor,0,1023,1,100); //Declaramos el mapeo
 

  if(valor_map>0 && valor_map<=10){
    digitalWrite(4,HIGH);
    delay(temp);
    Serial.println("Hay un total de 1 led");
    digitalWrite(4,LOW);
    delay(temp);
  }
  else if(valor_map>10 && valor_map<=20){
    for(int i=4;i<=5;i++){
    digitalWrite(i,HIGH);
   }
   delay(temp);
   for(int i=4;i<=5;i++){
    digitalWrite(i,LOW);
   }
   Serial.println("Hay un total de 2 leds");
  }
  
  else if(valor_map>20 && valor_map<=30){
    for(int i=4;i<=6;i++){
    digitalWrite(i,HIGH);
   }
   delay(temp);
   for(int i=4;i<=6;i++){
    digitalWrite(i,LOW);
   }
   Serial.println("Hay un total de 3 leds");
  }
  
  else if(valor_map>30 && valor_map<=40){
    for(int i=4;i<=7;i++){
    digitalWrite(i,HIGH);
   }
   delay(temp);
   for(int i=4;i<=7;i++){
    digitalWrite(i,LOW);
   }
   Serial.println("Hay un total de 4 leds");
  }
  
  else if(valor_map>40 && valor_map<=50){
    for(int i=4;i<=8;i++){
    digitalWrite(i,HIGH);
   }
   delay(temp);
   for(int i=4;i<=8;i++){
    digitalWrite(i,LOW);
   }
   Serial.println("Hay un total de 5 leds");
  }
  
  else if(valor_map>50 && valor_map<=60){
    for(int i=4;i<=9;i++){
    digitalWrite(i,HIGH);
   }
   delay(temp);
   for(int i=4;i<=9;i++){
    digitalWrite(i,LOW);
   }
   Serial.println("Hay un total de 6 leds");
  }
  
  else if(valor_map>60 && valor_map<=70){
    for(int i=4;i<=10;i++){
    digitalWrite(i,HIGH);
   }
   delay(temp);
   for(int i=4;i<=10;i++){
    digitalWrite(i,LOW);
   }
   Serial.println("Hay un total de 7 leds");
  }
  
  else if(valor_map>70 && valor_map<=80){
    for(int i=4;i<=11;i++){
    digitalWrite(i,HIGH);
   }
   delay(temp);
   for(int i=4;i<=11;i++){
    digitalWrite(i,LOW);
   }
   Serial.println("Hay un total de 8 leds");
  }
  
  else if(valor_map>80 && valor_map<=90){
    for(int i=4;i<=12;i++){
    digitalWrite(i,HIGH);
   }
   delay(temp);
   for(int i=4;i<=12;i++){
    digitalWrite(i,LOW);
   }
   Serial.println("Hay un total de 9 leds");
  }
  
  else{
    for(int i=4;i<=13;i++){
    digitalWrite(i,HIGH);
   }
   delay(temp);
   for(int i=4;i<=13;i++){
    digitalWrite(i,LOW);
   }
   Serial.println("Hay un total de 10 leds");

  }
  

}
