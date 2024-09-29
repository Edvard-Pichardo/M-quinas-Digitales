int valor_map; //Creamos la variable valor mapeado
int pot=A0; //Creamos la variable del potenciometro
int valor_ent; //Creamos la variable que recoge el valor de entrada


void setup() {
  Serial.begin(9600); //Iniciamos la comunicacion serial
  pinMode(pot, INPUT); //Declaramos el pin A0 como entrada
}

void loop() {
  valor_ent=analogRead(pot); //Leemos el valor analógico de A0
  valor_map=map(valor_ent,0,1023,0,100); //Creamos el mapeo lineal que transforma el intervalo 0-1023 a un intervalo 0-100
  Serial.print("El valor analogico es: ");
  Serial.print(valor_ent); 
  Serial.print(" --- ");
  Serial.print("El valor mapeado es: ");
  Serial.println(valor_map);
  delay(500);  
}
