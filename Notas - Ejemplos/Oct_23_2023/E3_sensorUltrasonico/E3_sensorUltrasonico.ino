#define TRIG 13
#define ECHO 12
#define LED_VERDE A0
#define LED_BLANCO A1
#define LED_ROJO A2

//Declaramos dos motores a través del puente H L293D
byte motor1[3]={9,11,10};
byte motor2[3]={6,5,4};

void setup() {
  Serial.begin(9600);
  for(int i=0;i<3;i++){ //Declaramos los pines de los motores como salidas
    pinMode(motor1[i],OUTPUT);
    pinMode(motor2[i],OUTPUT);
  }
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_BLANCO, OUTPUT);
  pinMode(LED_ROJO, OUTPUT);
}

void loop() {
  long distancia = medirDistancia();

  if (distancia > 300 && distancia <= 430) {
    //Los motores giran hacia la izquierda y la derecha al 20%
    moverMotores(51, 0, 1);  
    
    //Apartado de LEDs
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_BLANCO, LOW);
    digitalWrite(LED_ROJO, LOW);
    
    //Imprimir mensaje en el monitor
    Serial.println("Nada detectado");
  } 
  
  else if (distancia>200 && distancia<=300) {
    //Los motores giran hacia la derecha al 30%
    moverMotores(77, 1, 1); 
    
    //Apartado de LEDs
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_BLANCO, LOW);
    digitalWrite(LED_ROJO, HIGH);
    
    // Imprimir mensaje en el Monitor Serie
    Serial.print("Objeto detectado a: ");
    Serial.print(distancia);
    Serial.println(" cm");
  } 
  
  else if (distancia>100 && distancia<=200) {
    //Los motores giran hacia la derecha al 60%
    moverMotores(153, 1, 1); 
    
    //Apartado de LEDs
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_BLANCO, HIGH);
    digitalWrite(LED_ROJO, HIGH);
    
    //Imprimir mensaje en el monitor
    Serial.print("Objeto cerca a: ");
    Serial.print(distancia);
    Serial.println(" cm");
  } 
  
  else if (distancia>4 && distancia<=100) {
    //Los motores giran hacia la derecha al 100%
    moverMotores(255, 1, 1); 
    
    //Apartado de LEDs
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_BLANCO, HIGH);
    digitalWrite(LED_ROJO, HIGH);
    
    // Imprimir mensaje en el Monitor Serie
    Serial.print("Objeto muy cerca a: ");
    Serial.print(distancia);
    Serial.println(" cm");
  } 
  
  else if(distancia<=4) {
    //Los motores giran hacia la izquierda al 50%
    moverMotores(127, 0, 0); 
    
    //Apartado de LEDs
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_BLANCO, HIGH);
    digitalWrite(LED_ROJO, LOW);
    
    //Imprimir mensaje en el monitor
    Serial.println("Objeto encontrado");
  }
  
  else{
    //Apartado de LEDs
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_BLANCO, LOW);
    digitalWrite(LED_ROJO, LOW);
    
    //Imprimir mensaje en el monitor
    Serial.println("Nada detectado");
  }
}

long medirDistancia() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  long t = pulseIn(ECHO, HIGH);
  //Calcula la distancia en centímetros
  long distancia = (t/29.2)/2;
  
  return distancia;
}

//Creamos la función moverMotores que recibirá tres valores enteros
void moverMotores(int velocidad, int M1, int M2) {
  analogWrite(motor1[0], velocidad);
  digitalWrite(motor1[1], M1);
  digitalWrite(motor1[2], !M1);
  analogWrite(motor2[0], velocidad);
  digitalWrite(motor2[1], M2);
  digitalWrite(motor2[2], !M2);
}
