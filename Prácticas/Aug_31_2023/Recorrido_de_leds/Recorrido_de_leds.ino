int valor; //Leemos el valor del potenciometro
int temp; //Definimos un entero para el delay

void setup() {
  pinMode(A0, INPUT); //Indicamos el pin A0 como entrada
  
  for(int i=4;i>=13;i++){ //El ciclo for indica los pines del 4 al 13 como salidas
    pinMode(i,OUTPUT);
  }
  
  Serial.begin(9600); //Se indica la comunicación serial
}


void loop() {
  valor=analogRead(A0); //Leemos el estado del pin A0
  temp=200; //Definimos la variable del delay para 500 ms 
  
  if(valor>0 && valor<=102){
    digitalWrite(4,HIGH);
    delay(temp);
    Serial.println("Hay un total de 1 led");
    digitalWrite(4,LOW);
    delay(temp);
  }
  else if(valor>102 && valor<=204){
    for(int i=4;i<=5;i++){
    digitalWrite(i,HIGH);
   }
   delay(temp);
   for(int i=4;i<=5;i++){
    digitalWrite(i,LOW);
   }
   Serial.println("Hay un total de 2 led");
  }
  
  else if(valor>204 && valor<=306){
    for(int i=4;i<=6;i++){
    digitalWrite(i,HIGH);
   }
   delay(temp);
   for(int i=4;i<=6;i++){
    digitalWrite(i,LOW);
   }
   Serial.println("Hay un total de 3 led");
  }
  
  else if(valor>306 && valor<=408){
    for(int i=4;i<=7;i++){
    digitalWrite(i,HIGH);
   }
   delay(temp);
   for(int i=4;i<=7;i++){
    digitalWrite(i,LOW);
   }
   Serial.println("Hay un total de 4 led");
  }
  
  else if(valor>408 && valor<=510){
    for(int i=4;i<=8;i++){
    digitalWrite(i,HIGH);
   }
   delay(temp);
   for(int i=4;i<=8;i++){
    digitalWrite(i,LOW);
   }
   Serial.println("Hay un total de 5 led");
  }
  
  else if(valor>510 && valor<=612){
    for(int i=4;i<=9;i++){
    digitalWrite(i,HIGH);
   }
   delay(temp);
   for(int i=4;i<=9;i++){
    digitalWrite(i,LOW);
   }
   Serial.println("Hay un total de 6 led");
  }
  
  else if(valor>612 && valor<=714){
    for(int i=4;i<=10;i++){
    digitalWrite(i,HIGH);
   }
   delay(temp);
   for(int i=4;i<=10;i++){
    digitalWrite(i,LOW);
   }
   Serial.println("Hay un total de 7 led");
  }
  
  else if(valor>714 && valor<=816){
    for(int i=4;i<=11;i++){
    digitalWrite(i,HIGH);
   }
   delay(temp);
   for(int i=4;i<=11;i++){
    digitalWrite(i,LOW);
   }
   Serial.println("Hay un total de 8 led");
  }
  
  else if(valor>816 && valor<=918){
    for(int i=4;i<=12;i++){
    digitalWrite(i,HIGH);
   }
   delay(temp);
   for(int i=4;i<=12;i++){
    digitalWrite(i,LOW);
   }
   Serial.println("Hay un total de 9 led");
  }
  
  else{
    for(int i=4;i<=13;i++){
    digitalWrite(i,HIGH);
   }
   delay(temp);
   for(int i=4;i<=13;i++){
    digitalWrite(i,LOW);
   }
   Serial.println("Hay un total de 10 led");

  }
  
  

  
  
  

}
