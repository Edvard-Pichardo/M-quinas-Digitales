int pote; //Declaramos la variable del potenciometro
int pote_map; //Declaramos la variable del mapeo del potenciometro
bool inter; //Declaramos la variable del interruptor
int inter_in; //DEclaramos la variable del interruptor pero en su forma entera
char caracter; //Declaramos la variable para el caracter introducido
int temp; //Definimos un entero para el delay


void setup() {
  pinMode(A0, INPUT); //Indicamos el pin A0 como entrada
  pinMode(A1,INPUT); //Indicamos el pin A1 como entrada
  for(int i=5;i<=13;i++){ //Definimos los pines del 5 al 13 como salidas
    pinMode(i,OUTPUT);
  }
  Serial.begin(9600); //Se indica la comunicación serial
}


void loop() {
  pote=analogRead(A0); //Leemos el estado del pin A0
  pote_map=map(pote, 0, 1023, 1, 100); //Declaramos el mapeo del potenciometro
  inter=analogRead(A1); //Leemos el estado del pin A1

  //Primero definimos las condiciones para el tiempo del delay dependiente del valor del potenciometro
  if(pote_map>=0 && pote_map<14){ 
    temp=800;  
  }
  else if(pote_map>=14 && pote_map<28){
    temp=700;
  }
  else if(pote_map>=28 && pote_map<42){
    temp=600;
  }
  else if(pote_map>=42 && pote_map<56){
    temp=500;
  }
  else if(pote_map>=56 && pote_map<70){
    temp=400;
  }
  else if(pote_map>=70 && pote_map<84){
    temp=300;
  }
  else if(pote_map>=84 && pote_map<100){
    temp=200;
  }
  else{
    temp=100;
  }


  //Definimos los condicionales cuando el interruptor está encendido/apagado
  if(inter==false){ 
    inter_in=0;
    Serial.print("La velocidad es ");
    Serial.print(temp);
    Serial.print(" ms");
    Serial.print(" -- ");
    Serial.print("Se presiono el caracter ");
    Serial.print(caracter);
    Serial.print(" -- ");
    Serial.print("El estado del switch es ");
    Serial.println(inter_in);
    if(Serial.available()){ //Definimos la entrada de caracteres desde la terminal
      caracter=Serial.read(); //Definimos la variable caracter para que guarde el caracter introducido
    }
    
    //Declaramos la primera condición, los leds se encienden uno a uno girando hacia las manecillas del reloj empezando por D1
    if(caracter=='1'){ 
      for(int i=13;i>=6;i--){
        digitalWrite(i,HIGH);
        delay(temp);
        digitalWrite(i,LOW);
      }
    }
    //Declaramos la segunda condición, los leds se prenden uno a uno pero en sentido contrario
    else if(caracter=='2'){
      for(int i=6;i<=13;i++){
        digitalWrite(i,HIGH);
        delay(temp);
        digitalWrite(i,LOW);
      }
    }
    //Declaramos la tercera condición, todos los leds prenden
    else if(caracter=='3'){
      for(int i=13;i>=6;i--){
        digitalWrite(i,HIGH);
      }
    }
    //Declaramos la última condición, cualquier otro caracter los leds se apagan
    else{
      for(int i=13;i>=6;i--){
        digitalWrite(i,LOW);
      }
    }
  }
  
  else{
    inter_in=1;
    Serial.print("La velocidad es ");
    Serial.print(temp);
    Serial.print(" ms");
    Serial.print(" -- ");
    Serial.print("Se presiono el caracter ");
    Serial.print(caracter);
    Serial.print(" -- ");
    Serial.print("El estado del switch es ");
    Serial.println(inter_in);
    if(Serial.available()){ //Definimos la entrada de caracteres desde la terminal
      caracter=Serial.read(); //Definimos la variable caracter para que guarde el caracter introducido
    }

    //Definimos la primera condición, los leds D2, D4, D6, D8 parpadean
    if(caracter=='P'){
      for(int i=6;i<=12;i=i+2){
        digitalWrite(i,HIGH);
      }
      delay(temp);
      for(int i=6;i<=12;i=i+2){
        digitalWrite(i,LOW);
      }
      delay(temp);
    }
    //Definimos la segunda condicón, los leds D1, D3, D5, D7 parpadean
    else if(caracter=='I'){
      for(int i=7;i<=13;i=i+2){
        digitalWrite(i,HIGH);
      }
      delay(temp);
      for(int i=7;i<=13;i=i+2){
        digitalWrite(i,LOW);
      }
      delay(temp);
    }
    //Definimos la tercer condición, parpadean todos los leds
    else if(caracter=='L'){
      for(int i=6;i<=13;i++){
        digitalWrite(i,HIGH);
      }
      delay(temp);
      for(int i=6;i<=13;i++){
        digitalWrite(i,LOW);
      }
      delay(temp);
    }
    //Definimos la última condición, los leds se apagan
    else{
      for(int i=6;i<=13;i++){
        digitalWrite(i,LOW);
      }
    }
  }
}
  
