int green=2;
int red=3;
int yellow=4;

int pot_pin = A3;
float pot_data; 

void setup() {
 pinMode(2,OUTPUT);  
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);

 pinMode(pot_pin,INPUT);

 Serial.begin(9600);
}

void test_led(int count){
  Serial.println(count);
  if(count == 1){
    digitalWrite(red,HIGH);
    digitalWrite(yellow,LOW);
    digitalWrite(green,LOW);
  }

  if(count == 2){
    digitalWrite(red,HIGH);
    digitalWrite(yellow,HIGH);
    digitalWrite(green,LOW);
  }
  if(count == 3){
    digitalWrite(red,HIGH);
    digitalWrite(yellow,HIGH);
    digitalWrite(green,HIGH);
  }
//  digitalWrite(green,LOW); 
//  digitalWrite(red,LOW);
//  digitalWrite(yellow,LOW);

//  digitalWrite(green,HIGH); 
//  digitalWrite(red,HIGH);
//  digitalWrite(yellow,HIGH);
}

float pot_read(int pin){
  float data;
  data = analogRead(pot_pin);
  Serial.println(data);
  return data;
}

int count_affan_led(float data){
  Serial.println(data);
  // Data can be between 0 to 1023
  if(data< 350){
    return 1;
  }
  if (data>350 && data < 700){
    return 2;
  }
  if (data > 700){
    return 3;
  }
}

void loop() {
  delay(1000);
  pot_data = pot_read(pot_pin);  

  int led_count;
  led_count = count_affan_led(pot_data);
  test_led(led_count);
}
