#include <Wire.h> //Agrega la comunicacion I2C
#include <Adafruit_GFX.h> //Librería gráfica general de pantallas Adafruit
#include <Adafruit_SSD1306.h> //Librería de la pantalla SSD1306
#include <math.h> //Librería que proporciona funciones matemáticas adicionales 

#define ANCHO 128 //Se define el alto y el ancho de la pantalla
#define ALTO 64
#define Pot_max 1023 //Valor máximo del potenciómetro

Adafruit_SSD1306 display(ANCHO, ALTO, &Wire, -1); //Creamos nuestra pantalla

void setup() {
  if(!display.begin(SSD1306_SWITCHCAPVCC,0x3C)){
    Serial.println(F("No se encuentra la pantalla OLED"));
    for (;;) ;
  }

  display.clearDisplay(); //Limpiamos la pantalla
  display.display();
}


void Medidor_analog(int valor) { //Función para dibujar el medidor analógico
  int centroX=ANCHO/2;  //Define el centro del medidor
  int centroY=ALTO-1;
  int radio=50; //Define el radio del medidor
  int A1=180; //Define los ángulos de comienzo y final 
  int A0=0;
  int numSeg=360;  //Número de segmentos para dibujar el arco
  int divisiones=5; //Número de líneas graduadas
  int circleRadius=3;  //Radio del círculo en la base del indicador
  
  
  //Calcula el ángulo entre los segmentos
  float div_angular=(A0-A1)/(float)numSeg; //(float) transforma numSeg en tipo float
  
  //Dibuja el medidor con un semicírculo
  for(int i=0; i<=numSeg; i++) {
    float angulo=A1+i*div_angular;
    int x=centroX+radio*cos(angulo*PI/180);
    int y=centroY-radio*sin(angulo*PI/180);
    display.drawPixel(x, y, SSD1306_WHITE);
    
    //Dibuja las líneas graduadas del medidor
    if(i%(numSeg/divisiones)== 0){
      int x2=centroX+(radio-5)*cos(angulo*PI/180);
      int y2=centroY-(radio-5)*sin(angulo*PI/180);
      display.drawLine(x, y, x2, y2, SSD1306_WHITE);
    }
  }

  //Dibuja un círculo en la base del indicador
  display.fillCircle(centroX, centroY, circleRadius, SSD1306_WHITE);
  
  //Dibuja el indicador
  int angulo=map(valor, 0, Pot_max, A1, A0);
  int x1=centroX+radio*cos(angulo*PI/180);
  int y1=centroY-radio*sin(angulo*PI/180);
  display.drawLine(centroX, centroY, x1, y1, SSD1306_WHITE);
  
  //Etiquetas de entrada y valor (A0)
  display.setTextSize(1); //Tamaño del texto
  display.setTextColor(SSD1306_WHITE); //Color del texto
  
  display.setCursor(0,0);
  display.print("Entrada A0");
  
  display.setCursor(ANCHO-25, 0);
  display.print(valor);
}

void loop() {
  int potvalor=analogRead(A0); //Lee el valor del potenciómetro en A0
  display.clearDisplay(); //Limpia pantalla
  Medidor_analog(potvalor); //Se manda la variable potvalor a la función Medidor_analog
  display.display();
  delay(50); 
}
