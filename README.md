#GAM101 Grip Controller Project

Welcome to the repository for my GAM101 Grip Controller Project! This project features a custom controller that uses a hand strength exerciser, a bend sensor, and LEDs, all powered by an Arduino Uno.

As part of this project, I designed my first custom PCB in EasyEDA, combining hardware and software to create a functional and interactive system.

This was my first repository and as so is lacking in what it contains. Later Repos will have fleshed out Devlogs, i apologise for how fragmented this one is.


The process I took to create my project was to first create a virtual version within tinkercad.  


<table>
  <tr>
    <td style="text-align: center;">
      <b>Flex Sensor Setup:</b><br>
      <img src="https://github.com/Luke-Steppens/Grip-Controller/blob/main/Documentation/TinkerCad/Flex_sensor0.png?raw=true" width="250" height="180">
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

- 
