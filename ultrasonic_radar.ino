/*
 Author - affanparvezkhan@gmail.com
 Here we are defining the LEDs and the hardware PINs they are connected to, on the board.

*/

int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6 = 7;
int led7 = 8;

/*
  Here we are defining the variables that will be used by the ultrasonic sensor.
  Sending signal on trig will cause sensor to send sound wave.
  Sensor will return the value on echo.
*/
int chintu_echo = 12;
int chintu_trig = 13;
float distance, duration;

/*
  Setup function is executed at the beginning of any arduino program.
  We need to tell arduino which PINs will be active.
  We need to tell arduino which PINs will be used for INPUT and which for OUTPUT.
  Arduino will only activate those PINs. If we add a new sensor or LED tomorrow,
  we will have to also activate that PIN.
*/
void setup() {

  // For activation of LEDs as OUTPUT
  pinMode(led5, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led2, OUTPUT);  

  // For activation of ultrasonic sensor as both echo as INPUT and trig as OUTPUT.
  pinMode(chintu_echo, INPUT);
  pinMode(chintu_trig, OUTPUT);

  // Used to activate serial monitor. Also needs to be activated by going to Tools > Serial Monitor.
  Serial.begin(9600);
}

/*
  Returns the distance sound travels in decimal.
  Value is generally between 1 to 1100.
*/
float chintu_radar(){
  digitalWrite(chintu_trig, LOW);  
	delayMicroseconds(2);  
	digitalWrite(chintu_trig, HIGH);  
	delayMicroseconds(10);  
	digitalWrite(chintu_trig, LOW); 

  duration = pulseIn(chintu_echo, HIGH);  

  distance = (duration*.0343)/2;  
  Serial.print("Distance: ");  
	Serial.println(distance);  
  delay(1000); 
  return distance;

}


/*
  This function will be called by arduino very fast + back to back till end of time.
  A delay inside will help manage the speed.
*/
void loop() {

  distance = chintu_radar();
  chintu_turn_on_led(distance);
 

}

void test_led(){
  
  // digitalWrite(led1, HIGH);
  // digitalWrite(led5, HIGH);
  // digitalWrite(led3, HIGH);
  // digitalWrite(led4, HIGH);
  // digitalWrite(led2, HIGH);
  // digitalWrite(led7, HIGH);
  // digitalWrite(led6, HIGH);
  // delay(1000);

  // digitalWrite(led1, LOW);
  // digitalWrite(led7, LOW);
  // digitalWrite(led5, LOW);
  // digitalWrite(led6, LOW);
  // digitalWrite(led4, LOW);
  // digitalWrite(led3, LOW);
  // digitalWrite(led2, LOW);
  // delay(1000);   
}

void chintu_turn_on_led(int distance){

  int number_of_led;

  number_of_led = chintu_calculate(distance);
  Serial.print("Decision = ");
  Serial.println(number_of_led);

  for(int i = 2; i<=number_of_led; i++){
    Serial.println(i);
    digitalWrite(i, HIGH);
  }
  delay(1000);
  for(int i = 2; i<=number_of_led; i++){
    Serial.println(i);
    digitalWrite(i, LOW);
  }

}

int chintu_calculate(float distance){
  /*
    This function will get distance from 0 to 200 and sometimes 1100+.

    IF distance is  1-10  -> single LED (1)
    IF distance is 10-20  -> double LED (1+2)
    IF distance is 20-30  -> triple LED (1+2+3)
    IF distance is 30-40  -> four   LED (1+2+3+4)
    ..
    IF distance is more than 1000 -> LAST LED (7)

    Maths logic - 
    Sensor sending values from 1 to 200 mostly (1-5)
      logic:
        200 -> 1+2+3+4+5
        150 -> 1+2+3+4
        100 -> 1+2+3
        50  -> 1+2
        49  -> 1
    Sometimes 200-500 (upto LED 6)
    Sometimes 1000+ (upto LED 7)

  */
  int decision;

  if(distance < 50){
    decision = 1;
    return decision;
  }
  
  if(distance > 50 && distance < 100){
    decision = 2;
    return decision;
  }

  if(distance > 100 && distance < 150){
    decision = 3;
    return decision;
  }
  
  if(distance > 150 && distance < 200){
    decision = 4;
    return decision;
  }

  if(distance > 200 && distance < 300){
    decision = 5;
    return decision;
  }
  if(distance > 300 && distance < 1000){
    decision = 6;
    return decision;
  }

  if(distance > 1000){
    decision = 7;
    return decision;
  }

}
