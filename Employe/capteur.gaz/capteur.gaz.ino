int redLed = 12;
int greenLed = 11;
int buzzer = 10;
int smokeA0 = A0;


// Your threshold value
int sensorThres = 400;
char data;

void setup() {
  pinMode(redLed, OUTPUT);
  digitalWrite(redLed, LOW);
  pinMode(greenLed, OUTPUT);
  digitalWrite(greenLed, HIGH);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);

  Serial.begin(9600);
}

void loop() {

  
  int analogSensor = analogRead(smokeA0);

  //Serial.print("Pin A0: ");
  //Serial.println(analogSensor);
  
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  { 
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    tone(buzzer, 1000, 200);
    Serial.write('1');
  }
  
else 
{
digitalWrite(redLed, LOW);
digitalWrite(greenLed, HIGH);
Serial.write('0');
}



 
 
 if(Serial.available())
 {
    data = Serial.read(); 
  }
  delay(100);
 }
 
  
