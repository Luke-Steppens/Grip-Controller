#GAM101 Grip Controller Project

Welcome to the repository for my GAM101 Grip Controller Project! This project features a custom controller that uses a hand strength exerciser, a bend sensor, and LEDs, all powered by an Arduino Uno.

As part of this project, I designed my first custom PCB in EasyEDA, combining hardware and software to create a functional and interactive system.

This was my first repository and as so is lacking in what it contains. Later Repos will have fleshed out Devlogs, i apologise for how fragmented this one is.


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

---





