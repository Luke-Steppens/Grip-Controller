int sensorpin = A0;  // sensor pin
int sensor;             // sensor readings
int smoothedValue = 0;
float smoothingFactor = 0.9; // change this value 0.0 to 1.0 for more or less smoothing

int led1 = 13;  // green led
int led2 = 12;  // green led
int led3 = 11;  // yellow led
int led4 = 10;  // yellow led
int led5 = 9;   // red led
int led6 = 8;   // red led

void setup() 
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);  // all led's set to output
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);

  Serial.begin(9600);  // starts serial communication
}

void loop() 
{
  sensor = analogRead(sensorpin); // reads sensor value
  smoothedValue = (smoothingFactor * smoothedValue) + ((1 - smoothingFactor) * sensor); // This stops the values jumping around in the serial monitor making them easier to read and use
  
  Serial.println(smoothedValue); // print smoothed sensor value
  delay(50); // delay the monitor receiving data too fast making it hard to read (100ms was too slow)

  sensor = analogRead(sensorpin);
  Serial.println(sensor);  // reads pin with sensor then prints the output value
  
  if (sensor > 900)  // All leds on
  {
    digitalWrite(led1, HIGH);
    delay(50);
    digitalWrite(led2, HIGH);
    delay(50);
    digitalWrite(led3, HIGH);
    delay(50);
    digitalWrite(led4, HIGH);
    delay(50);
    digitalWrite(led5, HIGH);
    delay(50);
    digitalWrite(led6, HIGH);
    delay(50);
  } 
  else if (sensor > 890)  // led 6 off
  {
    digitalWrite(led1, HIGH);
    delay(50);
    digitalWrite(led2, HIGH);
    delay(50);
    digitalWrite(led3, HIGH);
    delay(50);
    digitalWrite(led4, HIGH);
    delay(50);
    digitalWrite(led5, HIGH);
    delay(50);
    digitalWrite(led6, LOW);
    delay(50);
  } 
  else if (sensor > 880)  // led 6 and 5 off
  {
    digitalWrite(led1, HIGH);
    delay(50);
    digitalWrite(led2, HIGH);
    delay(50);
    digitalWrite(led3, HIGH);
    delay(50);
    digitalWrite(led4, HIGH);
    delay(50);
    digitalWrite(led5, LOW);
    delay(50);
    digitalWrite(led6, LOW);
    delay(50);
  } 
  else if (sensor > 870)  // led 6,5 and 4 off
  {
    digitalWrite(led1, HIGH);
    delay(50);
    digitalWrite(led2, HIGH);
    delay(50);
    digitalWrite(led3, HIGH);
    delay(50);
    digitalWrite(led4, LOW);
    delay(50);
    digitalWrite(led5, LOW);
    delay(50);
    digitalWrite(led6, LOW);
    delay(50);
  } 
  else if (sensor > 860)  // led 6,5,4 and 3 off
  {
    digitalWrite(led1, HIGH);
    delay(50);
    digitalWrite(led2, HIGH);
    delay(50);
    digitalWrite(led3, LOW);
    delay(50);
    digitalWrite(led4, LOW);
    delay(50);
    digitalWrite(led5, LOW);
    delay(50);
    digitalWrite(led6, LOW);
    delay(50);
  } 
  else if (sensor > 850)  // led 6,5,4,3 and 2 off
  {
    digitalWrite(led1, HIGH);
    delay(50);
    digitalWrite(led2, LOW);
    delay(50);
    digitalWrite(led3, LOW);
    delay(50);
    digitalWrite(led4, LOW);
    delay(50);
    digitalWrite(led5, LOW);
    delay(50);
    digitalWrite(led6, LOW);
    delay(50);
  } 
  else   // all led's off
  {
    digitalWrite(led1, LOW);
    delay(50);
    digitalWrite(led2, LOW);
    delay(50);
    digitalWrite(led3, LOW);
    delay(50);
    digitalWrite(led4, LOW);
    delay(50);
    digitalWrite(led5, LOW);
    delay(50);
    digitalWrite(led6, LOW);
    delay(50);
  }
}
