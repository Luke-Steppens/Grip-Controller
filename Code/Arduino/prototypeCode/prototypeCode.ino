int sensorpin = A1;  // sensor pin
int sensor;          // sensor readings
int smoothedValue;
float smoothingFactor = 0.1;  // change this value 0.0 to 1.0 for more or less smoothing

int lowVal = 1023;
int highVal = 0;

int led1 = 13;  // red led
int led2 = 12;  // yellow led
int led3 = 11;  // green led
int led4 = 10;  // green led
int led5 = 9;   // yellow led
int led6 = 8;   // red led

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);  // all led's set to output
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(sensorpin, INPUT);

  Serial.begin(9600);  // starts serial communication
  smoothedValue = analogRead(sensorpin);
  }

void loop() {

  sensor = analogRead(sensorpin);                                                        // reads sensor value
  smoothedValue = (smoothingFactor * smoothedValue) + ((1 - smoothingFactor) * sensor);  // This stops the values jumping around in the serial monitor making them easier to read and use

  // Serial.println(smoothedValue);  // print smoothed sensor value
  delay(50);                      // delay the monitor receiving data too fast making it hard to read (100ms was too slow)

  // sensor = analogRead(sensorpin);
  // Serial.println(sensor);  // reads pin with sensor then prints the output value


  if (smoothedValue < lowVal) {
    lowVal = smoothedValue;
  }
  if (smoothedValue > highVal) {
    highVal = smoothedValue;
  }

  int finalValue = map(smoothedValue, lowVal, highVal, 0, 100);
  Serial.println(finalValue);
  
  if ((finalValue >= 0 && finalValue <= 40) || (finalValue >= 85 && finalValue <= 100)) 
  {
  digitalWrite(led1, HIGH); //red
  digitalWrite(led6, HIGH);
  }
  else
  {
  // Turn off LEDs if not in the specified range
  digitalWrite(led1, LOW);
  digitalWrite(led6, LOW);
  }

  if ((finalValue >= 41 && finalValue <= 56) || (finalValue >= 69 && finalValue <= 84))
  {
  digitalWrite(led2, HIGH);  // yellow
  digitalWrite(led5, HIGH);
  }
  else
  {
  digitalWrite(led2, LOW);
  digitalWrite(led5, LOW);
  }

  if ((finalValue >=57 && finalValue <= 62) || (finalValue >= 62 && finalValue <= 68))
  {
  digitalWrite(led3, HIGH);  //green
  digitalWrite(led4, HIGH);
  }
  else
  {
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  }
}
