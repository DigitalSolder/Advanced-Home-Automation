🌟 **Advanced Home Automation System with Environmental Sensing** project:

---

# 🏠 Advanced Home Automation System with Environmental Sensing

**A Smart Home Project using ESP32, OLED Display, and Multiple Sensors (Simulated on Wokwi)**

---

## 📘 Overview

This project is a **smart sensor-driven home automation system** built using the **ESP32** and simulated on **Wokwi**.
It automatically manages home lighting and fan control based on **real-time sensor data** including temperature, light intensity, and motion detection. It also provides **live feedback** on an OLED display and allows **user-defined thresholds via Serial Monitor**.

---

## 🎯 Project Objectives

* ⚡ **Automate lights and fan** based on environmental and occupancy data.
* 🌱 **Conserve energy** by activating devices only when needed.
* 📟 **Display real-time data** like temperature, humidity, time, and motion status on an OLED.
* 💾 **Support custom thresholds** with persistence using EEPROM.

---

## 🧠 Key Features

### 🔍 Sensors

* 🌡️ **DHT22** – Temperature and humidity sensing
* 💡 **LDR (Light Dependent Resistor)** – Detects ambient light (analog & digital output)
* 🚶 **PIR Sensor** – Detects human motion
* ⏰ **RTC DS1307** – Keeps track of current time (battery-backed)

---

### ⚙️ Actuators & Indicators

* 💡 **Relay 1 (Light Control)** – Turns on light when room is dark **and** motion is detected
* 🌬️ **Relay 2 (Fan Control)** – Turns on fan if **temperature > threshold** and motion is detected
* 🔴 **Status LED** – Lights up if **low-light condition** is detected (LDR digital = LOW)

---

### 🖥️ User Interface

#### 📟 **OLED Display (SSD1306)**

Displays:

* 🕒 Current time (via RTC)
* 🌡️ Temperature & 💧 Humidity
* 💡 Light level
* 🚶 Motion detection status

#### 💬 **Serial Interface**

* 📌 Allows setting **custom thresholds** for:

  * Temperature (for fan)
  * Light intensity (for lights)
* 💾 Settings are saved in **EEPROM** for persistence across resets

---

## 🧠 System Logic Flow

### 💡 Light ON Conditions:

* Ambient light below threshold (LDR)
* Motion detected (PIR)

### 🌬️ Fan ON Conditions:

* Temperature above user-set threshold
* Motion detected

### 🔴 LED Indicator:

* Turns ON when LDR digital output is LOW (dark environment)

### 📟 OLED Display Output:

* Real-time sensor values
* Current system status
* Clock from RTC module

---

## 🧰 Components Used

| Component         | Function                       |
| ----------------- | ------------------------------ |
| ESP32             | Main microcontroller           |
| DHT22             | Temperature & humidity sensor  |
| LDR               | Light level sensor             |
| PIR Sensor        | Motion detection               |
| RTC DS1307        | Real-time clock                |
| OLED SSD1306      | Display for sensor/status data |
| Relay Module (x2) | Controls light and fan         |
| EEPROM (internal) | Saves user-defined thresholds  |

---

## 💡 Applications

* 🏠 Home Automation Projects
* 👨‍💻 IoT & Embedded Systems Learning
* 🎓 Academic Demonstrations
* ⚙️ Smart Environment Simulations

Demonstrates:

* 🌐 IoT + sensor integration
* ⚙️ Automated decision-making
* 💾 Persistent data storage
* 📟 Real-time user interface

---

## 🔧 Technologies Used

* **ESP32** microcontroller
* **DHT22**, **PIR**, **LDR** sensors
* **RTC DS1307** (I²C)
* **SSD1306 OLED** display
* **EEPROM** and **Serial Monitor** interaction
* **Wokwi** simulation platform

---

## 🧪 Demo & Simulation

🎮 **Try it Live on Wokwi**:
https://wokwi.com/projects/433739825455756289

