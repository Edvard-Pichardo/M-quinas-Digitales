#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4; //Se definen las ctes para las entradas de los pines
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //Se definen los pines de la pantalla LCD
int sensor; //Declaramos la variable entera sensor
float voltaje; //Declaramos la variable float voltaje
float temperatura; //Declaramos la variable temperatura

void setup() {
  lcd.begin(16, 2); //Declara LCD de 16x2
  pinMode(A0, INPUT);  //Declaramos el pin A0 como entrada
  Serial.begin(9600);  //Inicializa la comunicación serial
}

void loop() {
  sensor=analogRead(A0);  //Definimos sensor como el valor de la entrada A0 (0-1023)
  voltaje=sensor*(5.0/1023.0);  //Convierte a voltaje (0.0-5.0)

  temperatura=(voltaje-0.5)/0.01;  //Calcula la temperatura en °C

  lcd.setCursor(0, 1);  //Nos colocamos en la segunda linea de la pantalla
  lcd.clear();  //Borramos cualquier cosa que esté en esa línea
  lcd.print("Temperatura: "); //Imprime "Temperatura: " en la pantalla
  lcd.setCursor(0, 1);  //Nos colocamos en la segunda linea de la pantalla otra vez
  lcd.print(temperatura, 0);  //Imprimimos la temperatura sin puntos decimales
  lcd.print(" C");

  delay(20); 
}



//Nota sobre  la relación entre la temperatura y la salida del tensor:
//El sensor TMP36 está diseñado de tal manera que cuando la temperatura es muy baja, es decir, tiene un voltaje de salida cercano a 0V,
//el voltaje de salida no es completamente 0V, sino que se establece en aproximadamente 0.5V cuando está a una temperatura muy baja.
//Esto se hace para permitir temperaturas negativas y mantener una relación lineal entre la temperatura y el voltaje de salida.
//El sensor TMP36 tiene una sensibilidad de 10 mV/°C. 
//Por lo que, por cada 1°C de cambio en la temperatura, el voltaje de salida cambia en 0.01V (10 mV).
//De esta forma, para obtener la temperatura en grados Celsius, se resta el voltaje de offset de 0.5V y se divide por la sensibilidad de 0.01V/°C.
