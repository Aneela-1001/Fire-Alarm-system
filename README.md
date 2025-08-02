Fire Alarm System using Arduino and MQ-2 Smoke Sensor
A fully functional, switch-controlled fire alarm system built using an Arduino Uno,MQ-2 smoke/gas sensor, and multiple input/output peripherals. This project is designed for educational, prototyping, and safety awareness purposes, providing real-time smoke detection and visual/audible alerts.
 
 Overview

This project simulates a real-world fire alarm system using affordable electronic components. The system monitors air quality for smoke or combustible gas using the MQ-2 sensor. When hazardous levels are detected, or when triggered manually via a **test switch**, the system activates a **buzzer alarm** and displays a warning through **LED indicators**. The system is manually resettable and includes a **power switch** for overall control.

The project includes:
- Hardware setup on breadboard
- Arduino-based firmware
- Video demonstration with screenshots
- Complete project report with schematic diagram

 Features
- Real-time smoke and gas detection
- Manual control via Power, Test, and Reset switches
-  Buzzer and dual LED indicators (Normal/Fire)
-  Test mode for demonstration without real smoke
-  Reset functionality to silence the alarm
-  Screenshots and video evidence of working prototype
-  Detailed report and schematic included

Hardware Components

| Component          | Quantity | Description                                |
|--------------------|----------|--------------------------------------------|
| Arduino Uno        | 1        | Main microcontroller                        |
| MQ-2 Gas Sensor    | 1        | Smoke and gas detection                     |
| Buzzer             | 1        | Audible alert system                        |
| Green LED          | 1        | Indicates safe/normal conditions            |
| Red LED            | 1        | Indicates fire alert                        |
| Power Switch       | 1        | Turns system ON/OFF                         |
| Test Switch        | 1        | Manually simulates fire detection           |
| Reset Switch       | 1        | Stops alarm and resets the system           |
| Resistors (220Ω)   | 3        | LED and switch current limiting             |
| Breadboard         | 1        | Circuit prototyping                         |
| Jumper Wires       | -        | Electrical connections                      |
| Power Supply       | 1        | USB or 9V battery (via adapter)             |

 Functional Description

- Normal Mode: Green LED ON, system actively monitoring.
- Fire Detection Mode: Triggered by real smoke (via MQ-2) or test button.
  - Red LED ON
  - Buzzer ON
  - Green LED OFF
- Reset Mode: When reset switch is pressed:
  - Red LED OFF
  - Buzzer OFF
  - Green LED ON
  Power Switch: Shuts down or activates the entire system.

This design allows easy simulation,testing, and **real-world demonstration.

#Arduino Code

The firmware reads analog values from the MQ-2 sensor and digital input from test/reset switches. Logic conditions trigger alarm indicators accordingly.

> 🔹 See [`fire_alarm_code.ino`](./fire_alarm_code.ino) for full source code.
 Demonstration ▶️ Video

>  [`FIRE_ALARM.mp4`](./FIRE_ALARM.mp4)




