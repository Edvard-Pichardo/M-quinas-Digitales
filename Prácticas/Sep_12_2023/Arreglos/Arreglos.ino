
byte led[5]={2,3,4,5,6}; //Asi se define un arreglo, se le asigna un espacio en memoria y se le asignan variables
byte led2[2][3]={{1,2,3},{3,4,1}};
byte led3[2][2][2]={{{1,2},{2,1}},{{2,3},{2,9}}};

void setup() {
  Serial.begin(9600);
}

void loop() {
  for(int i=0;i<=1;i++){
    for(int j=0; j<=2;j++){
       led2[i][j]=j*2+(i+1);
    Serial.println(led2[i][j]);
    delay(500);
    }
  }

  for(int i=0;i<=1;i++){
    led[i]=i*2;
    Serial.println(led[i]);
    delay(500);
    }
  
}
