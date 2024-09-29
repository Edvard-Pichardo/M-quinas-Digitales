#include <Adafruit_GFX.h>  //Librería gráfica general de pantallas Adafruit
#include <Adafruit_SSD1306.h> //Librería de la pantalla SSD1306
#include <Wire.h> //Agrega la comunicacion I2C

#define ANCHO 128 //Se define el alto y el ancho de la pantalla
#define ALTO 64
Adafruit_SSD1306 display(ANCHO, ALTO, &Wire, -1); //Creamos nuestra pantalla

float XPosicion = ANCHO/2; //Declaramos la posicion de la pelota en el centro
float YPosicion = ALTO/2;
float Radio = 5;  //Declaramos el radio de la pelota
float xSpeed = 2; //Declaramos la velocidad en x de la pelota
float ySpeed = 2; //Declaramos la velocidad en y de la pelota

void setup() {
  Serial.begin(9600); //Iniciamos la comunicación serial 
  
  if(!display.begin(SSD1306_SWITCHCAPVCC,0x3C)){
    Serial.println(F("La pantalla SSD1306 no fue encontrada"));
    for(;;);
  }
  
  display.clearDisplay(); //Limpiamos la pantalla
  display.display(); //Ejecutamos la pantalla
}

void loop() {
  // Borrar la pantalla
  display.clearDisplay();
  
  // Actualizar la posición de la pelota
  XPosicion+=xSpeed; //Incrementa la posición en el eje x de la pelota (XPosicion) agregando la velocidad en el eje x 
  YPosicion+=ySpeed; //Incrementa la posición en el eje y de la pelota (YPosicion) agregando la velocidad en el eje Y 

  // Verifica las colisiones con los bordes de la pantalla
  if (XPosicion-Radio<0 || XPosicion+Radio>=ANCHO) {
    xSpeed = -xSpeed; //Cambia la dirección en el eje X
  }
  if (YPosicion-Radio<0 || YPosicion+Radio>=ALTO) {
    ySpeed = -ySpeed; //Cambia la dirección en el eje Y
  }

  // Dibujar la pelota en la pantalla
  display.drawCircle(XPosicion, YPosicion, Radio, SSD1306_WHITE);
  
  // Mostrar los cambios en la pantalla
  display.display();
  delay(10);
}
