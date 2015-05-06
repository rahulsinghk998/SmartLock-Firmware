int motor1 = 10; int motor2 = 11;

void setupMotors(){
  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
}

void motorOut(int power1){ // currently pow doesn't do much, but it will range between -255 to 255

  Serial.println(power1);

  int motor1Val; int motor2Val;
  if (power1 > 10){motor1Val = HIGH; motor2Val=LOW; Serial.println("forwards");}
  if (power1 < -10){motor1Val = LOW; motor2Val=HIGH; Serial.println("backwards");}
  if ((power1 < 11) and (power1 > -11)){motor1Val = LOW; motor2Val=LOW; Serial.println("stop");}
  
  digitalWrite(motor1,motor1Val);
  digitalWrite(motor2,motor2Val);
   Serial.println("sent Value");
}
