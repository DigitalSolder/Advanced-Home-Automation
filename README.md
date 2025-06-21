🏠 Advanced Home Automation System with Environmental Sensing
A Smart Home Project using ESP32 on Wokwi

📘 Overview
Welcome to the Advanced Home Automation system—a smart, sensor-driven home controller designed and simulated on the Wokwi platform! 🚀
Powered by the ESP32, this system integrates real-time sensing and automation to enhance comfort, energy efficiency, and user control.

🎯 Project Objectives
⚡ Automate lighting and fan control based on temperature, light intensity, and occupancy.

🌱 Improve energy efficiency by running appliances only when needed.

🖥️ Display real-time data like time, temperature, humidity, and sensor status on an OLED screen.

🛠️ Allow user-defined thresholds via the Serial Monitor with EEPROM-based persistence.

🧠 Key Features
🔍 Sensors
🌡️ DHT22: Measures temperature and humidity.

💡 LDR (Light Dependent Resistor): Detects ambient light levels (analog + digital output).

🚶 PIR Sensor: Senses motion (human presence).

⏰ RTC DS1307: Keeps accurate time, even during resets.

⚙️ Actuators
💡 Relay for Light: Turns on lights if it’s dark and someone is present.

🌬️ Relay for Fan: Activates fan if temperature > threshold and motion is detected.

🔴 Status LED: Glows when low-light is detected (via LDR digital output).

🖥️ User Interface
📟 OLED Display:
Shows:

⏱️ Current Time

🌡️ Temperature & 💧 Humidity

💡 Light Level

🚶 Motion Detection Status

🧑‍💻 Serial Interface:

🛠️ Set custom thresholds for temperature & light.

💾 Saves settings in EEPROM for persistence across resets.

🧠 System Logic
💡 Lights turn on only when:

Light level is below threshold

Motion is detected

🌬️ Fan turns on when:

Temperature is above threshold

Motion is detected

🔴 LED glows when light is below threshold (LDR digital LOW)

📟 OLED shows a live snapshot of:

Sensor readings

System status

Current time (RTC-based)

💡 Applications
This project is perfect for:

🏠 Smart home enthusiasts

🎓 Students exploring IoT & embedded systems

👨‍🔧 Engineers designing intelligent automation systems

It demonstrates:

🌐 IoT integration

🧩 Sensor-actuator fusion

💾 EEPROM storage

📟 Real-time data display
All simulated efficiently using Wokwi!

🔧 Technologies Used
🧠 ESP32 Microcontroller

🧪 DHT22, PIR, LDR

⏰ RTC DS1307

📟 SSD1306 OLED

💬 EEPROM & Serial Monitor

🧪 Wokwi Simulator

🚀 Demo & Simulation
🧪 Click here to run the simulation on Wokwi https://wokwi.com/projects/433739825455756289
