int pote=A0; //Indicamos el pin donde va el parametro 
int valor; //Leemos el valor del potencimatro
float voltaje; //Variable para calcular el voltaje

void setup() {
  pinMode(pote, INPUT); //Indicamos el pin A0 como entrada
  Serial.begin(9600); //Indicamos la comunicación serial
}

void loop() {
  valor=analogRead(A0); //Leemos el estado del pin A0 (enc//apagado)
  voltaje=valor*5/1023.0;
  Serial.print("Valor potenciometro: "); //Imprimimos el estado del LED
  Serial.print(valor); //Obtenemos el valor del potenciometro entre el intervalo 0-1023
  Serial.print("-- Valor voltaje: "); //Se imprime el valor del voltaje
  Serial.println(voltaje); //Leemos el valor del voltaje
  delay(100); //Hacemos un delay de 100 ms
}
