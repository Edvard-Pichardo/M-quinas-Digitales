#include <LCD_I2C.h>

LCD_I2C lcd(0x27, 16, 2); // Default address of most PCF8574 modules, change according

byte P1[8] =  //Se define el caracter P1
{
    0b01100,
    0b01100,
    0b00000,
    0b01100,
    0b01100,
    0b01100,
    0b01100,
    0b01110,
};

byte P2[8] =  //Se define el caracter P2
{
    0b01100,
    0b01100,
    0b00000,
    0b01110,
    0b11100,
    0b01100,
    0b11010,
    0b10011,
};


void setup()
{
    lcd.begin();  //Inicia el display LCD
    lcd.backlight(); //Prende la luz de fondo
    lcd.clear();

    //Crea nuevos caracteres
    lcd.createChar(0, P1);
    lcd.createChar(1, P2);
}

void loop(){
  while(1){
    lcd.setCursor(0,0); //Se selecciona la columna 0 fila 0
    lcd.write(0); //Se imprime el caracter P1
    delay(50); 
    lcd.clear(); //Se limpia la pantalla
    lcd.setCursor(0,0); //SE selecciona la columna 0 fila 0
    lcd.write(1); //Se imprime el caracter P2
    delay(50); 
    lcd.clear(); //Se limpia la pantalla
  }
}
