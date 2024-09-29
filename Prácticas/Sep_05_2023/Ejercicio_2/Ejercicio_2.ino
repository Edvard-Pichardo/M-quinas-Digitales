int but0; //Declaramos una variable entera para el estado del botón 0
int but1; //Declaramos una variable entera para el estado del botón 1
int cont=0; //Declaramos una variable contador y la definimos como 0 
int del=200; //Definimos una variable para el delay y lo fijamos a 200 ms

void setup() {
  pinMode(12,INPUT); //Declaramos los pines 11 y 12 como entradas, en este caso de los dos botones
  pinMode(11,INPUT);

  for(int i=2;i<=7;i++){ //Con un bucle for declaramos los pines del 2 al 7 como salidas, en este caso cada uno asociado a un LED
    pinMode(i,OUTPUT);
  }

}

void loop() {
  but1=digitalRead(12); //Definimos la variable but0 como el estado del pin 12
  but0=digitalRead(11); //Definimos la variable but1 como el estado del pin 11
  delay(del); //Por cuestiones mecanicas del botón, necesitamos dejar un delay pequeño.


  //Abrimos un condicional donde si but0=1 pero but1=0 entonces se enciende un LED.
  if(but0 && !but1){
    if(cont==0){ //Este condicional nos dice que si cont=0 entonces se enciende el LED de la izquierda (el asociado al pin 7) y suma 1 a la variable cont
      digitalWrite(7,HIGH);
      cont++;
      delay(del);
    }
    else if(cont==1){ //De la misma forma, si cont=1 entonces se enciende el siguiente LED a la derecha (el asociado al pin 6) y se le suma 1 a cont, lo mismo para las demas iteraciones
      digitalWrite(6,HIGH);
      cont++;
      delay(del);
    }
    else if(cont==2){
      digitalWrite(5,HIGH);
      cont++;
      delay(del);
    }
    else if(cont==3){
      digitalWrite(4,HIGH);
      cont++;
      delay(del);
    }
    else if(cont==4){
      digitalWrite(3,HIGH);
      cont++;
      delay(del);
    }
    else if(cont==5){
      digitalWrite(2,HIGH);
      delay(del);
    }
    else{
      delay(del);
    }
  }

  //Abrimos un else if donde si but0=0 pero but1=1 entonces se apaga un LED
  else if(but1 && !but0){
    if(cont==0){ //Este condicional nos dice que si cont=0 entonces se apaga el LED de la izquierda (el asociado al pin 7) y resta 1 a la variable cont
      digitalWrite(7,LOW);
      delay(del);
    }
    else if(cont==1){ //De la misma forma, si cont=1 entonces se apaga el LED a su derecha (el asociado al pin 6) y se le resta 1 a cont, lo mismo para las demas iteraciones
      digitalWrite(6,LOW);
      cont--;
      delay(del);
    }
    else if(cont==2){
      digitalWrite(5,LOW);
      cont--;
      delay(del);
    }
    else if(cont==3){
      digitalWrite(4,LOW);
      cont--;
      delay(del);
    }
    else if(cont==4){
      digitalWrite(3,LOW);
      cont--;
      delay(del);
    }
    else if(cont==5){
      digitalWrite(2,LOW);
      cont--;
      delay(del);
    }
    else{
      delay(del);
    }
  }
}
