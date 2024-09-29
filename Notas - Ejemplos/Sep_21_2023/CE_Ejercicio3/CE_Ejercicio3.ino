#include <LCD_I2C.h>

LCD_I2C lcd(0x27, 16, 2); // Default address of most PCF8574 modules, change according
int temp=40;
int pot=A0;
int valor;
int x;

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
    pinMode(pot, INPUT); //Declaramos el pin A0 como entrada
    lcd.begin();  //Inicia el display LCD
    lcd.backlight(); //Prende la luz de fondo
    lcd.clear();

    //Crea nuevos caracteres
    lcd.createChar(0, P1);
    lcd.createChar(1, P2);
}

void loop(){
  valor=analogRead(pot); //Leemos el valor analógico de A0
  x=map(valor,0,1023,0,15); //mapeamos valor que va de 0-1023 a un intervalo de 0-15

      //Notemos que la posición del caracter en la columna depende del valor x, asociado al valor mapeado de la entrada del potenciometro
      lcd.setCursor(x,0); //Se posiciona en la coluna x de la fila 0
      lcd.write(1); //Se enciende el caracter P2
      delay(temp);
      lcd.clear(); //Se limpia la pantalla
      lcd.setCursor(x,0); //Se posiciona en la columna x de la fila 0
      lcd.write(0); //Se enciende el caracter P1
      delay(temp); 
      lcd.clear(); //Se limpia la pantalla
}
