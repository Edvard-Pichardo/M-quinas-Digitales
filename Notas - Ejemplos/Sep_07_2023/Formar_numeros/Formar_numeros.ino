int temp; //Definimos una variable ebtera para el delay

void setup() {
  for(int i=2;i<=8;i++){ //A través de un ciclo for definimos los pines del 2 al 8 como salidas
    pinMode(i,OUTPUT);
  }
}

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


void loop() {
  temp=1000; //Definimos el delay como 1 s

  //Mostrar número
  cero();
  delay(temp);
  uno();
  delay(temp);
  dos();
  delay(temp);
  tres();
  delay(temp);
  cuatro();
  delay(temp);
  cinco();
  delay(temp);
  seis();
  delay(temp);
  siete();
  delay(temp);
  ocho();
  delay(temp);
  nueve();
  delay(temp);
  ocho();
  delay(temp);
  siete();
  delay(temp);
  seis();
  delay(temp);
  cinco();
  delay(temp);
  cuatro();
  delay(temp);
  tres();
  delay(temp);
  dos();
  delay(temp);
  uno();
  delay(temp);
}
