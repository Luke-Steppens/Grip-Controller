


int sensorpin = A0;  // sensor pin
int sensor;             // sensor readings
int smoothedValue = 0;
float smoothingFactor = 0.9; // change this value 0.0 to 1.0 for more or less smoothing

void setup() {
  
  Serial.begin(9600);
}

void loop() {
  
  
  sensor = analogRead(sensorpin); // reads sensor value
  smoothedValue = (smoothingFactor * smoothedValue) + ((1 - smoothingFactor) * sensor); // This stops the values jumping around in the serial monitor making them easier to read and use
  
  Serial.println(smoothedValue); // print smoothed sensor value
  delay(50); // delay the monitor recieving data too fast making it hard to read (100ms was too slow)
}
