//Definimos los pines para los sensores de línea TCRT5000 
#define Sensor A0

//Definimos el umbral para los sensores de línea
#define Umbral 400

void setup() {
  //Declaramos los pines de los sensores de línea como entradas
  pinMode(Sensor, INPUT);

  //Declaramos la comunicación serial
  Serial.begin(9600);
}

void loop() {
  //Leemos los valores de los sensores de línea
  int Valor=analogRead(Sensor);
  delay(20);

  if(Valor>250){
    Serial.println("Color negro");
    Serial.print("Valor: ");
    Serial.println(Valor);
    Serial.println(" ");
    delay(500);
  }
  else{
    Serial.println("Color blanco");
    Serial.print("Valor: ");
    Serial.println(Valor);
    Serial.println(" ");
    delay(500);
  }
  
}
