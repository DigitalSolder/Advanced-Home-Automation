# Advanced-Home-Automation
Project Description: Home Automation System with Environmental Sensing
Overview:
This project is a comprehensive home automation system designed and simulated using the Wokwi platform. It leverages an ESP32 microcontroller to monitor and control environmental conditions within a smart home setup. The system integrates temperature and humidity sensing (DHT22), light intensity detection (LDR), motion detection (PIR sensor), and real-time clock functionality (RTC DS1307). Outputs include automated control of lighting and fan relays, as well as a status LED indicator and an OLED display for real-time feedback1.

Project Objectives:

Automate the control of home lighting and fans based on environmental conditions and occupancy.

Enhance energy efficiency by activating devices only when necessary (e.g., turning on lights when it’s dark and someone is present, or activating the fan when temperature exceeds a set threshold and motion is detected).

Provide real-time environmental data and system status to users via an OLED display.

Allow users to adjust temperature and light thresholds dynamically through serial commands, with persistent storage using EEPROM1.

Key Features:

Sensors:

DHT22: Measures ambient temperature and humidity.

LDR (Light Dependent Resistor): Monitors ambient light levels, both analog and digital outputs.

PIR Sensor: Detects human motion.

RTC DS1307: Maintains accurate time for time-stamped data display.

Actuators:

Relay for Light: Automatically switches lighting based on light level and motion.

Relay for Fan: Activates fan when temperature exceeds user-defined threshold and motion is detected.

Status LED: Indicates low light conditions via the LDR’s digital output.

User Interface:

OLED Display: Shows current time, temperature, humidity, light levels, and motion status.

Serial Interface: Users can update temperature and light thresholds, which are saved in EEPROM for persistence across resets.

System Logic:

Lights are turned on only if the room is dark (below the light threshold) and motion is detected.

The fan is activated when the temperature exceeds the set threshold and motion is detected, ensuring comfort only when the room is occupied.

The status LED provides a quick visual cue for low-light conditions.

The OLED display gives a comprehensive snapshot of all sensor readings and system status in real time1.

Applications:
This system is ideal for smart home enthusiasts, students, or engineers seeking to explore automation, IoT, and embedded systems. It demonstrates practical integration of multiple sensors and actuators, real-time data display, and persistent configuration—all within a simulated environment.
