#include <LCD_I2C.h>

LCD_I2C lcd(0x27, 16, 2); // Default address of most PCF8574 modules, change according
bool var1, var2, var3, var4; //Declaramos las variables para el estado de los botones

int x=0, y=0; //Declaramos las variables para las coordenadas del display (columna, fila) 
int temp=50; //Declaramos la variable para el delay

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
    pinMode(A0, INPUT); //Declaramos los pines A0, A1, A2, A3 como entradas
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    pinMode(A3, INPUT);
    lcd.begin();  //Inicia el display LCD
    lcd.backlight(); //Prende la luz de fondo
    lcd.clear();

    //Crea nuevos caracteres
    lcd.createChar(0, P1);
    lcd.createChar(1, P2);

    lcd.setCursor(x,y); //Se posiciona en la columna x=0 de la fila y=0
    lcd.write(1); //Se imprime el caracter P2
    delay(temp);
    lcd.clear(); //Se limpia la pantalla
    lcd.setCursor(x,y); //Se posiciona en la columna x=0 de la fila y=0
    lcd.write(0); //Se imprime el caracter P1
}

void loop(){

  //Se definen las variables que leeran el estado de los botones
  var1=digitalRead(A0); //Boton arriba
  var2=digitalRead(A1); //Boton abajo
  var3=digitalRead(A2); //Boton derecha
  var4=digitalRead(A3); //Boton izquierda

  //Si el boton arriba está encendido y la coordenada y=1 entonces el caracter sube a la coordanada y=0
  if(var1){ 
    if(y==1){
      y--;
      delay(temp);
      lcd.setCursor(x,y); //Se posiciona en la columna x de la fila y=0
      lcd.write(1); //SE imprime el caracter P2
      delay(temp);
      lcd.clear(); //Se limpia la pantalla
      lcd.setCursor(x,y); //Se posiciona en la columna x de la fila y=0
      lcd.write(0); //Se imprime el caracter P1
      
    }
  }
  //Si el boton abajo está encendido y la coordenada y=0 entonces el caracter baja a la coordanada y=1
  else if(var2){
    if(y==0){
      y++;
      delay(temp);
      lcd.setCursor(x,y); //Se posiciona en la columna 0 de la fila 0
      lcd.write(1); //SE imprime el caracter P2
      delay(temp);
      lcd.clear(); //Se limpia la pantalla
      lcd.setCursor(x,y); //Se posiciona en la columna 0 de la fila 0
      lcd.write(0); //Se imprime el caracter P1
      
    }
  }
   //Si el boton derecha está encendido y la coordenada x<15 entonces el caracter se mueve hacia la derecha tal que la coordanada x=x+1
   else if(var3){
    if(x<15){
      x++;
      delay(temp);
      lcd.setCursor(x,y); //Se posiciona en la columna x+1 de la fila y
      lcd.write(1);
      delay(temp);
      lcd.clear(); //Se limpia la pantalla
      lcd.setCursor(x,y); //Se posiciona en la columna x+1 de la fila y
      lcd.write(0);
    }
   }
    //Si el boton izquierda está encendido y la coordenada x>0 entonces el caracter se mueve hacia la izquierda tal que la coordanada x=x-1
   else if(var4){
    if(0<x){
      x--;
      delay(temp);
      lcd.setCursor(x,y); //Se posiciona en la columna x-1 de la fila y
      lcd.write(1);
      delay(temp);
      lcd.clear(); //Se limpia la pantalla
      lcd.setCursor(x,y); //Se posiciona en la columna x-1 de la fila y
      lcd.write(0);
    }
   }

  //La persona seguirá caminando en su lugar si ningún botón se oprime
   delay(temp);
   lcd.setCursor(x,y); //Se posiciona en la columna x de la fila y
   lcd.write(1); 
   delay(temp);
   lcd.clear(); //Se limpia la pantalla
   lcd.setCursor(x,y); //Se posiciona en la columna x de la fila y
   lcd.write(0);
      
}
