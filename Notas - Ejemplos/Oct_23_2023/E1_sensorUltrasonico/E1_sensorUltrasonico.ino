//Definimos algunos pines importantes
#define TRIG 13 //Los pines para el sensor ultrasonico
#define ECHO 12
#define LED_VERDE A0 //Los pines para los LEDs
#define LED_BLANCO A1
#define LED_ROJO A2

//Declaramos dos motores a través del puente H L293D
byte motor1[3]={9,11,10};
byte motor2[3]={6,5,4};

void setup() {
  Serial.begin(9600); //Comunicación Serial
  for(int i=0;i<3;i++){ //Declaramos los pines de los motores como salidas
    pinMode(motor1[i],OUTPUT);
    pinMode(motor2[i],OUTPUT);
  }
  pinMode(LED_VERDE, OUTPUT); //Declaramos los pines de los LEDs como salidas
  pinMode(LED_BLANCO, OUTPUT);
  pinMode(LED_ROJO, OUTPUT);
}


void loop() {
  
  long distancia = medirDistancia(); //Definimos distancia como el número que nos regresa la función medirDistancia()

  //Abrimos un if para comprobar si la distancia es mayor o menor a 20 cm
  if(distancia > 20) { 
    moverMotores(255, 1, 1); //Los motores giran hacia la derecha
    
    //Apartado de LEDs
    digitalWrite(LED_VERDE, HIGH); //Se enciende Led verde
    digitalWrite(LED_BLANCO, LOW);
    digitalWrite(LED_ROJO, LOW);
  } 
  else{
    moverMotores(255, 0, 0); //Los motores giran hacia la izquierda
    
    //Apartado de LEDs
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_BLANCO, LOW);
    digitalWrite(LED_ROJO, HIGH); //Se enciende Led rojo
  }

  //Imprimir distancia en el monitor
  Serial.print("Distancia medida: ");
  Serial.print(distancia);
  Serial.println(" cm");
}


//Creamos la función medirDistancia() que devolverá un valor de tipo long
long medirDistancia() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  long t = pulseIn(ECHO, HIGH);
  // Calcula la distancia en centímetros
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
