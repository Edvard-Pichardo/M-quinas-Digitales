char valor;
void setup() {
  Serial.begin(9600);
  for(int i=4;i<=13;i++){
    pinMode(i,OUTPUT);
  }

}

void loop() {
  if(Serial.available()){
    valor=Serial.read();
  }
  if(valor=='1'){
    for(int i=4;i<=13;i++){
    digitalWrite(i,HIGH);
    } 
  }
  
  else{
    for(int i=4;i<=13;i++){
      digitalWrite(i,LOW);
    } 
  }
} 
