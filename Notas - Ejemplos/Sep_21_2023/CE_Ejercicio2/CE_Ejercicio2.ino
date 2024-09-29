#include <LCD_I2C.h>

LCD_I2C lcd(0x27, 16, 2); // Default address of most PCF8574 modules, change according
int temp=40;

byte P1[8] = //Se define el caracter P1
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

byte P2[8] =  //Se deine el caracter P2
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
  //Se abren dos ciclos for iterados para que el caracter recorra la columna i de la fila j 
  for(int j=0;j<=1;j++){
    for(int i=0;i<=15;i++){
      lcd.setCursor(i,j); //Se posiciona en la coluna i de la fila j
      lcd.write(1); //Se enciende el caracter P2
      delay(temp);
      lcd.clear(); //Se limpia la pantalla
      lcd.setCursor(i,j); //Se posiciona en la columna i de la fila j
      lcd.write(0); //Se enciende el caracter P1
      delay(temp); 
      lcd.clear(); //Se limpia la pantalla
    }
  }
}
