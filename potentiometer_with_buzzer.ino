int red=2;
int green=3;
int buzz=4;
void setup(){
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);

 pinMode(A3, INPUT);
 Serial.begin(9600);
 
}

void loop(){
 float data = analogRead(A3);
 Serial.println(data);

 if(data ==0){
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
 }
 if(data < 500 && data > 0){
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
 }

 if(data > 500){
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
 }
 if(data > 1000){
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  
 }

 delay(100);
}









