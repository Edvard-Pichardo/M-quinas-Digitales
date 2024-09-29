#include <Wire.h> //Agrega la comunicacion I2C
#include <Adafruit_GFX.h> //Librería gráfica general de pantallas Adafruit
#include <Adafruit_SSD1306.h> //Librería de la pantalla SSD1306

#define ANCHO 128 //Se define el alto y el ancho de la pantalla
#define ALTO 64 
Adafruit_SSD1306 pantalla(ANCHO, ALTO, &Wire, -1); //Creamos nuestra pantalla

void setup() {
  Serial.begin(9600); //Iniciamos la comunicación serial
  
  if(!display.begin(SSD1306_SWITCHCAPVCC,0x3c)){
    Serial.println("No se encontró pantalla");
    for(;;);
  }

  display.clearDisplay(); //Limpiamos la pantalla de texto
  display.setTextSize(1); //Elegimos el tamaño del texto
  display.setTextColor(WHITE); //Elegimos el color del texto
  display.setCursor(0,0); //Nos posicionamos en la pantalla
  display.println("Hola a todos :)"); //Enviamos  el texto a la pantalla
  display.pantalla();
  delay(100);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
