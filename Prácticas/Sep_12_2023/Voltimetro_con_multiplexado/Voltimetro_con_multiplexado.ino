int temp; //Declaramos una variable entera para el delay
int pot=A0; //Declaramos la variable del potenciometro
int valor_pot; //Declaramos la variable para guardar el valor del potenciometro
int valor_map;
int voltaje; //Declaramos una variable para guardar el valor del voltaje

int unidades;
int decimas;
int centenas;

void cero(){ //Definimos la función cero
  digitalWrite(8,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(2,LOW);
}

void uno(){ //Definimos la función uno
  digitalWrite(8,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
  digitalWrite(3,LOW);
  digitalWrite(2,LOW);
}

void dos(){ //Definimos la función dos
  digitalWrite(8,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(2,HIGH);
}

void tres(){  //Definimos la función tres
  digitalWrite(8,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(3,LOW);
  digitalWrite(2,HIGH);
}

void cuatro(){  //Definimos la función cuatro
  digitalWrite(8,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(2,HIGH);
}

void cinco(){  //Definimos la función cinco
  digitalWrite(8,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(2,HIGH);
}

void seis(){  //Definimos la función seis
  digitalWrite(8,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(2,HIGH);
}

void siete(){  //Definimos la función siete
  digitalWrite(8,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
  digitalWrite(3,LOW);
  digitalWrite(2,LOW);
}

void ocho(){  //Definimos la función ocho
  digitalWrite(8,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(2,HIGH);
}

void nueve(){  //Definimos la función nueve
  digitalWrite(8,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(2,HIGH);
}

//Definimos la función "prender" el cuál nos ayudará a prender el dígito utilizado
void prender(int u){ 
  switch(u){
    case 0:
      cero();
      break;
    case 1:
      uno();
      break;
    case 2:
      dos();
      break;
    case 3:
      tres();
      break;
    case 4:
      cuatro();
      break;
    case 5:
      cinco();
      break;
    case 6:
      seis();
      break;
    case 7:
      siete();
      break;
    case 8:
      ocho();
      break;
    case 9:
      nueve();
      break;
    default:
      break;
    }
}



void setup() {
  Serial.begin(9600); //Utilizamos la comunicación serial
  for(int i=2;i<=11;i++){ //Declaramos los pines del 2 al 11 como salidas
    pinMode(i,OUTPUT);
  }
  
  pinMode(pot, INPUT); //Declaramos el pin A0 como entrada analogica del potenciometro
  
}

void loop() {

  temp=5; //Definimos el delay como 5 ms   Nota: En algunos ordenadores, este tiempo se debe aumentar para que se vean todos los dígitos

  //Iniciamos un bucle infinito para leer el valor del potenciometro y encender sus dígitos en los display
  while(1){  
    valor_pot=analogRead(pot); //Leemos el valor del potenciometro de 0 a 1023
    voltaje=map(valor_pot,0,1023,0,500); //Mapeamos estos valores de 0-1023 a 0-500

    //Separamos el valor de voltaje en digitos mediante divisiones y modulo
    centenas=voltaje/100; 
    decimas=(voltaje/10)%10;
    unidades=voltaje%10;
    delay(20);

    Serial.println(voltaje); //Imprimimos el voltaje en la simulación a través de una pantalla, este comando fue usado para verificar que todo funcionara correctamente
    
    digitalWrite(9,HIGH); //Se enciende el pin 9 que satura la señal del transistor conectado a él, lo que permite el paso de señal al display unidades
    prender(unidades); //Se manda el digito de las unidades a la función prender para que se vea el digito en el display de unidades
    delay(temp); //Se espera un tiempo muy pequeño
    digitalWrite(9,LOW); //Se apaga el pin 9, lo que desatura el transistor conectado a él, lo que apaga el display unidades
    digitalWrite(10,HIGH); //Inmediatamente se activa el pin 10 lo que satura la señal del transistor conectado a él y permite el paso de la señal al display decimas
    prender(decimas); //Se manda el dígito decimas a la función prender para que se vea el dígito en el display de decimas
    delay(temp); 
    digitalWrite(10,LOW); //Se apaga el pin 10, lo que desatura el transistor conectado a él, lo que apaga el display decimas
    digitalWrite(11,HIGH); //Inmediatamente se activa el pin 11 lo que satura la señal del transistor conectado a él y permite el paso de la señal al display centenas
    prender(centenas); //Se manda el dígito centenas a la función prender para que se vea el dígito en el display centenas
    delay(temp);
    digitalWrite(11,LOW); //Se apaga el pin 11, lo que desatura el transistor conectado a él, lo que apaga el display centenas y el bucle vuelve a empezar
  }

 
    
  }

  

  
  
