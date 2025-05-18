#GAM101 Grip Controller Project

Welcome to the repository for my GAM101 Grip Controller Project! This project features a custom controller that uses a hand strength exerciser, a bend sensor, and LEDs, all powered by an Arduino Uno.

As part of this project, I designed my first custom PCB in EasyEDA, combining hardware and software to create a functional and interactive system.

This was my first repository and as so is lacking in what it contains. Later repositories will have fleshed out Devlogs, I apologise for how fragmented this one is.

---

### Parts List

- **Flex Sensor** x 1  
- **LEDs** (Red, Yellow, Green) x 6  
- **330-ohm Resistors** x 6  
- **33k-ohm Resistor** x 1  
- **Jumper Wires**  
- **Arduino Uno** x 1  
- **Breadboard** x 1
- **Hand Grip**

### Tools Used

- **Soldering Iron**  
- **Solder**  
- **Wire Cutters**  
- **Multimeter** (for checking connections and voltages)   
- **Electrical Tape** (used for attaching flex sensor to hand grip)  
- **Tweezers** (for handling small components)  






---

  
### virtual Setup:

The process I took to create my project was to first create a virtual version within tinkercad.

<table>
  <tr>
    <td style="text-align: center;">
      <b>Flex Sensor Setup:</b><br>
      <img src="https://github.com/Luke-Steppens/Grip-Controller/blob/main/Documentation/TinkerCad/Flex_sensor0.png?raw=true" width="270" height="180">
    </td>
    <td style="text-align: center;">
      <b>Sensor + LEDs:</b><br>
      <img src="https://github.com/Luke-Steppens/Grip-Controller/blob/main/Documentation/TinkerCad/Sensor%20and%20LEDs.png?raw=true" width="250" height="180">
    </td>
  </tr>
</table>

### Resistor Setup:

- **For the LEDs:** I used **330-ohm resistors** to keep the current at safe levels and protect the LEDs from burning out.
- **For the Flex Sensor:** A **33k-ohm resistor** is part of a voltage divider with the flex sensor, helping to read the changes in its resistance through the analog input.

--- 

### Recreating the Circuit in EasyEDA

<table>
  <tr>
    <td style="text-align: center;">
      <b>PCB Design for Flex Sensor:</b><br>
      <img src="https://github.com/Luke-Steppens/Grip-Controller/blob/main/Electronics/EasyEDA/PCB_PCB_Flex-Sensor_2025-05-18.png?raw=true" width="180" height="180">
    </td>
    <td style="text-align: center;">
      <b>3D PCB Design View:</b><br>
      <img src="https://github.com/Luke-Steppens/Grip-Controller/blob/main/Documentation/EasyEDA/PCBdesign3D.png?raw=true" width="200" height="180">
    </td>
  </tr>
</table>


<table>
  <tr>
    <td colspan="2" style="text-align: center;">
      <b>Schematic for Flex Sensor:</b><br>
      <img src="https://github.com/Luke-Steppens/Grip-Controller/blob/main/Electronics/EasyEDA/Schematic_Flex-Sensor_2025-05-18.png?raw=true" width="500" height="400">
    </td>
  </tr>
</table>

---

### Assembling and Soldering the Components

In this section, I'll walk you through the process of assembling and soldering the components onto the PCB.

1. **Rearranging the LEDs:** I decided to create a "biting point" in the design, so I rearranged the LEDs. The LEDs are now arranged from the outside in: red – yellow – and in the centre, green. This setup was designed to reflect a more intuitive, organized layout.
2. **Soldering the LEDs:** Once the LEDs were arranged, I soldered them into place, ensuring the connections were secure and that they matched the layout.
3. **Colour-Coding the Jumper Cables:** To make the setup easier, I colour-coded the jumper cables to match the LED arrangement. This helps with the connection and makes it easier to set up later on.
4. **Final Soldering:** After placing all the components, I carefully soldered everything in place, ensuring each joint was solid and that there were no cold joints or bridges.
5.**Attaching the Flex Sensor:** I used black electrical tape to attach the flex sensor to the arch of the hand grip. I then soldered two jumper cables to the sensor for easy connection to the circuit.

<table>
  <tr>
    <td style="text-align: center;">
      <b>Flex Sensor Setup:</b><br>
      <img src="https://github.com/Luke-Steppens/Grip-Controller/blob/main/Media/Photo/IMG_4890.jpg?raw=true" width="550" height="400">
    </td>
  </tr>
</table>



---


### Coding the Circuit


Each flex sensor may give different results depending on the sensor's characteristics and the resistors used in the circuit. To account for sensor noise and fluctuations, a smoothing factor was added to the code. This helps stabilize the sensor's readings and make them more consistent for use in controlling the LEDs. The smoothing factor can be adjusted (from 0.0 to 1.0) to either allow more responsiveness (lower values) or smoother, more stable readings (higher values).



```cpp
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

```

<table>
  <tr>
    <td style="text-align: center;">
      <b>Biting Point GIF:</b><br>
      <img src="https://github.com/Luke-Steppens/Grip-Controller/blob/main/Media/GIF/bitingpoint.gif?raw=true" width="200" height="434">
    </td>
    <td style="text-align: center;">
      <b>Wave GIF:</b><br>
      <img src="https://github.com/Luke-Steppens/Grip-Controller/blob/main/Media/GIF/wave.gif?raw=true" width="200" height="434">
    </td>
  </tr>
</table>


---

### Conclusion

This first project successfully utilizes the flex sensor and LEDs, providing a fun and hands-on test of basic circuitry and soldering techniques. Although not integrated into the game, it serves as a strong foundation for future improvements and more advanced applications.
