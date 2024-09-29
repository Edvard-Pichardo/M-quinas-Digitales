int temp; //Declaramos una variable entera para el delay
bool primo; //Declaramos la variable booleana para ver si un número es primo o no
int rest; //Declaramos una variable entera que guaradará el resto de una división


int unidades; //Declaramos variables para guardar las unidades, decenas, centenas y millares de un número entero
int decimas;
int centenas;
int millares;

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

void H(){ //Definimos la función que forma la letra H
  digitalWrite(8,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(2,HIGH);
}

void O(){ //Definimos la función que forma la letra O
  digitalWrite(8,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(2,LOW);
}

void L(){ //Definimos la función que forma la letra L
  digitalWrite(8,LOW);
  digitalWrite(7,LOW);
  digitalWrite(6,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(2,LOW);
}

void A(){ //Definimos la función que forma la letra A
  digitalWrite(8,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(2,HIGH);
}


//Definimos la función "prender" el cuál nos ayudará a prender el dígito utilizado en un display
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

//Definimos la función "letras" para prender las letras de la palabra HOLA.
void letras(int u){ 
  switch(u){
    case 1:
      H();
      break;
    case 2:
      O();
      break;
    case 3:
      L();
      break;
    case 4:
      A();
      break;
    }
}
  


void setup() {
  Serial.begin(9600); //Utilizamos la comunicación serial
  for(int i=2;i<=12;i++){ //Declaramos los pines del 2 al 11 como salidas
    pinMode(i,OUTPUT);
  }
  
  
}

void loop() {
  temp=50; //Definimos el delay como 50 ms para la simulación (en físico esto debe ser de 5 ms)

  //Abrimos un ciclo for  que formará la palabra HOLA, notemos que se iterará 10 veces la palabra, para aumentar su duración o disminuirla solo falta modificar el número de veces que se necesita iterar
  for(int i=1;i<=10;i++){
      digitalWrite(9,HIGH); //Se enciende el pin 9 que satura la señal del transistor conectado a él, lo que permite el paso de señal al display unidades
      letras(4); //Se manda el digito de las unidades a la función prender para que se vea el digito en el display de unidades
      delay(temp); //Se espera un tiempo muy pequeño
      digitalWrite(9,LOW); //Se apaga el pin 9, lo que desatura el transistor conectado a él, lo que apaga el display unidades
      digitalWrite(10,HIGH); //Inmediatamente se activa el pin 10 lo que satura la señal del transistor conectado a él y permite el paso de la señal al display decimas
      letras(3); //Se manda el dígito decimas a la función prender para que se vea el dígito en el display de decimas
      delay(temp); 
      digitalWrite(10,LOW); //Se apaga el pin 10, lo que desatura el transistor conectado a él, lo que apaga el display decimas
      digitalWrite(11,HIGH); //Inmediatamente se activa el pin 11 lo que satura la señal del transistor conectado a él y permite el paso de la señal al display centenas
      letras(2); //Se manda el dígito centenas a la función prender para que se vea el dígito en el display centenas
      delay(temp);
      digitalWrite(11,LOW); //Se apaga el pin 11, lo que desatura el transistor conectado a él, lo que apaga el display centenas
      digitalWrite(12,HIGH); //Inmediatamente se activa el pin 12 lo que satura la señal del transistor conectado a él y permite el paso de la señal al display millares
      letras(1); //Se manda el dígito millares a la función prender para que se vea el dígito en el display millares
      delay(temp);
      digitalWrite(12,LOW); //Se apaga el pin 12, lo que desatura el transistor conectado a él, lo que apaga el display millares y el bucle vuelve a empezar
  }

  //Cuando termine el ciclo for anterior, iniciará un nuevo ciclo que muestra la secuencia desde 0000 hasta 9999 de uno en uno.
  for(int x=0;x<=9999;x++){
      Serial.println(x); //Que el número x se imprima en la consola nos ayuda a verificar que esté funcionando correctamente

      //Separamos el valor de x en digitos mediante divisiones y modulo
      millares=x/1000;
      centenas=(x/100)%10; 
      decimas=(x/10)%10;
      unidades=x%10;
      delay(20);


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
      digitalWrite(11,LOW); //Se apaga el pin 11, lo que desatura el transistor conectado a él, lo que apaga el display centenas
      digitalWrite(12,HIGH); //Inmediatamente se activa el pin 12 lo que satura la señal del transistor conectado a él y permite el paso de la señal al display millares
      prender(millares); //Se manda el dígito millares a la función prender para que se vea el dígito en el display millares
      delay(temp);
      digitalWrite(12,LOW); //Se apaga el pin 12, lo que desatura el transistor conectado a él, lo que apaga el display millares y el bucle vuelve a empezar 
  }




      




}
