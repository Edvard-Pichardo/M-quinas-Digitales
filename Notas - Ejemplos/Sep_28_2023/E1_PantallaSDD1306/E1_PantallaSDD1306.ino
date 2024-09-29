#include <Wire.h> //Agrega la comunicacion I2C
#include <Adafruit_GFX.h> //Librería gráfica general de pantallas Adafruit
#include <Adafruit_SSD1306.h> //Librería de la pantalla SSD1306

#define ANCHO 128 //Se define el alto y el ancho de la pantalla
#define ALTO 64 
Adafruit_SSD1306 display(ANCHO, ALTO, &Wire, -1); //Creamos nuestra pantalla

int pot; //Declaramos la variable del potenciometro 0-1023
int map_pot; //Declaramos la variable para el mapeo de la variable pot 0-64
int voltaje; //Declaramos la variable para el voltaje 0-5


void setup() {
  Serial.begin(9600); //Iniciamos la comunicación serial

  pinMode(A0,INPUT); //Declaramos pot como entrada
  
  if(!display.begin(SSD1306_SWITCHCAPVCC,0x3C)){
    Serial.println("No se encuentra la pantalla OLED");
    while(true);
  }

  display.clearDisplay(); //Limpiamos la pantalla de texto
  display.setTextSize(1); //Elegimos el tamaño del texto
  display.setTextColor(WHITE); //Elegimos el color del texto
  display.display();

}

void loop() {

 display.drawLine(0,62,128,62,WHITE); //Dibujamos el eje x
 display.drawLine(0,0,0,64,WHITE); //Dibujamos el eje y
 display.setCursor(90,56);
 display.print("Eje x"); //Nombramos al eje x
 display.setCursor(0,0);
 display.print("Eje y"); //Nombramos al eje y
 display.display();
  
 for(int i=0;i<=127;i++){
  pot=analogRead(A0); //Definimos pot como el valor análogico de la entrada A0
  map_pot=map(pot,0,1023,0,62); //Definimos el mapeo de pot de 0-1023 a 0-64
  voltaje=(pot*5)/1024; //Calculamos el valor del voltaje
  Serial.print("Valor Analógico: ");
  Serial.print(pot);
  Serial.print(" -- ");
  Serial.print("Voltaje: ");
  Serial.println(voltaje);
  display.drawPixel(i,62-map_pot,WHITE);
  display.display();
  delay(10);
 }

 while(true);

}
