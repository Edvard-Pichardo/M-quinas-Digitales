#include <LiquidCrystal.h>  //Incluye la librería LCD
const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4; //Se definen las ctes para las entradas de los pines
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); //Se crea la pantalla LCD

void setup() {
  lcd.begin(16, 2); //Se inicia la pantalla con 16 filas y 2 columnas
  lcd.setCursor(0, 0); //Se posiciona en la fila 0 columna 0
  lcd.print("Termino: 0"); //Se imprime el primer termino de la sucesion
  lcd.setCursor(0, 1); //Se posiciona en la fila 0 columna 1
  lcd.print("0"); //Se imprime el valor del primer termino de la sucesion
  delay(250);
}

void loop() {
  //Definimos las variables para lamacenar los terminos de la sucesion
  String a = "0"; // Término n-2 (Definido como string)
  String b = "1"; // Término n-1 (Definido como string)
  String c;       // Término n   (Definido como string)

  //Calculamos cada término de la sucesion mediante un bucle for 
  for (int i=1; i<78; i++){ //Como ya se imprimió el primer termino entonces quedan 77 más
    c = addStrings(a, b); //Este comando suma las cadenas a y b
    a = b; //Redefine los terminos
    b = c;

    lcd.clear(); //Limpia la pantalla
    lcd.setCursor(0, 0);
    lcd.print("Termino: "); //Imprime el término
    lcd.print(i);
    lcd.setCursor(0, 1); 
    lcd.print(c);  //Imprime el termino de la sucesion

    delay(250);
  }

}


String addStrings(String num1, String num2) {
  int carry = 0;
  String result = "";

  int i = num1.length() - 1;
  int j = num2.length() - 1;

  while (i >= 0 || j >= 0 || carry > 0) {
    int x = (i >= 0) ? num1[i] - '0' : 0;
    int y = (j >= 0) ? num2[j] - '0' : 0;

    int sum = x + y + carry;
    carry = sum / 10;
    sum %= 10;
    
    result = char('0' + sum) + result;

    if (i >= 0) i--;
    if (j >= 0) j--;
  }

  return result;
}
