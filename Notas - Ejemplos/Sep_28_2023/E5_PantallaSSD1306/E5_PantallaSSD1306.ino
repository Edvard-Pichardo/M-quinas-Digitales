//Grafica de la función f(x)=x^3

#include <Wire.h> //Agrega la comunicacion I2C
#include <Adafruit_GFX.h> //Librería gráfica general de pantallas Adafruit
#include <Adafruit_SSD1306.h> //Librería de la pantalla SSD1306

#define ANCHO 128 //Define el alto y el ancho de la pantalla
#define ALTO 64

Adafruit_SSD1306 display(ANCHO, ALTO, &Wire, -1);  //Crea la pantalla

void setup() {
  Serial.begin(9600); //Iniciamos la comunicación serial
  
  if(!display.begin(SSD1306_SWITCHCAPVCC,0x3C)){
    Serial.println(F("No se encuentra la pantalla OLED"));
    for (;;) ;
  }

  display.clearDisplay(); //Limpia la pantalla
  display.display();
}

void Ejes(){ //Función que dibuja los ejes X y Y
  display.drawLine(0, ALTO / 2, ANCHO, ALTO / 2, SSD1306_WHITE); // Eje X
  display.drawLine(ANCHO / 2, 0, ANCHO / 2, ALTO, SSD1306_WHITE); // Eje Y

  //Etiquetas de los ejes
  display.setTextSize(1); //Tamaño del texto
  display.setTextColor(SSD1306_WHITE); //Color del texto
  display.setCursor(ANCHO-32,ALTO/2+5); //Posicion del texto 
  display.print("Eje X"); //Imprime texto
  display.setCursor(ANCHO/2-32,5); //Posicion del texto
  display.print("Eje Y"); //Imprime texto
}

void Graficar() { //Función que dibuja la gráfica
  float scale=0.02; //Escala para adaptarse al tamaño de la pantalla
  float x, y; //Variables de los ejes coordenados
  
  display.setTextColor(SSD1306_WHITE); //Color del texto
  
  for (int i=-ANCHO/2; i<ANCHO/2; i++) {
    x=i*scale;
    y=x*x*x; // Función f(x)=x^3

    //Mapea las coordenadas a la pantalla
    int x_OLED=(int)(x/scale+ANCHO/2);
    int y_OLED=(int)(-y/scale+ALTO/2);

    display.drawPixel(x_OLED, y_OLED, SSD1306_WHITE); //Dibuja la gráfica
  }
}

void loop() {
  display.clearDisplay(); //Limpia la pantalla
  Ejes(); //Dibuja los ejes X y Y
  Graficar(); //Grafica la función f(x)=x^3
  display.display();
  while(true){ }
}
