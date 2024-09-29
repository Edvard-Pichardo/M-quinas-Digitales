#include <LiquidCrystal.h>  //Incluyo librería LCD
const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4; //Se definen las ctes para las entradas de los pines
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //Se definen los pines de la pantalla LCD



void poema(int u){ //Defino la función poema, que imprimirá en la pantalla las líneas del poema "Mis pasos" de Octavio Paz
  switch(u){
    case 1:
      lcd.print("   Mis pasos");
      break;
    case 2:
      lcd.print("- Octavio Paz -");
      break;
    case 3:
      lcd.print("Mis pasos en");
      break;
    case 4:
      lcd.print("esta calle");
      break;
    case 5:
      lcd.print("Resuenan");
      break;
    case 6:
      lcd.print("En otra calle");
      break;
    case 7:
      lcd.print("Donde");
      break;
    case 8:
      lcd.print("Oigo mis pasos");
      break;
    case 9:
      lcd.print("Pasar en esta");
      break;
    case 10:
      lcd.print("calle");
      break;
    case 11:
      lcd.print("Donde");
      break;
    case 12:
      lcd.print("Solo es real");
      break;
    case 13:
      lcd.print("la neblina...");
      break;
    case 14:
      break;
    }
    
    
}

void setup() {
  lcd.begin(16, 2); //Declara LCD de 16x2
}

void loop() {
  for(int i=1;i<=13;i=i+2){ //Se declara un bucle for para imprimir las frases del poema dos a dos.
    lcd.setCursor(0, 0); //Mostrará el texto en la primera posición (columna=0) de la primera linea (fila=0)
    poema(i); //Imprime el texto del caso i de la función poema
    lcd.setCursor(0, 1); //Mostrará el texto en la primera posición (columna=0) de la segunda línea (fila=1)
    poema(i+1); //Imprime el texto del caso i+1 de la función poema
    delay(500); //Se espera 5 segundos
    lcd.clear(); //Limpia la pantalla
  }

}
