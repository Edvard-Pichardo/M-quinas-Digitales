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

  


void setup() {
  Serial.begin(9600); //Utilizamos la comunicación serial
  for(int i=2;i<=12;i++){ //Declaramos los pines del 2 al 11 como salidas
    pinMode(i,OUTPUT);
  }
  
  
}

void loop() {
  temp=50; //Definimos el delay como 50 ms para la simulación (en físico esto debe ser de 5 ms)

  //Abrimos un ciclo for que corra desde 2 hasta 9999, queremos ver cuales números en ese intervalo son primos
  for(int x=2;x<=9999;x++){ 
    //Como el 2 es primo, declaramos que si x=2 entonces que la variable primo sera verdadera
    if(x==2){
      primo=true;
    }
    //Si x>2 entonces abriremos un ciclo for para ver si el número es divisible por algún entero mayor a dos pero menor al número x
    else if(x>2){ 
      for(int i=2;i<x;i++){
        rest=x%i; //Declaramos la variable rest como el resto de x/i
        //Si el resto es cero, entonces el número x es divisible por algún número i, por lo que x no es primo
        if(rest==0){
          primo=false; //Declaramos primo como falso
          break; //Salimos del bucle for con un break
        }
        else{ //De lo contrario, si el resto no es cero para ningún número i entonces el número x es primo
          primo=true; //Declaramos primo como verdadero
        }
      }  
    }
    
    //Fuera del bucle for, abrimos una condicional, si primo es verdadero entonces lo imprimimos en los displays
    if(primo){
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




}















      
    

  

  

  
  
