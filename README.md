# Project_Traksha: 'A Motion Vigilance for Railways'

This repository contains the code and documentation for **Project_Traksha**, a sensor-based system for real-time obstacle detection on railway tracks. This project was submitted in partial fulfillment for the award of the degree of Bachelor of Engineering in Electronics and Communication from Visvesvaraya Technological University.

* **Institution:** Sri Sairam College of Engineering, Bengaluru
* **Team:** Ponmudi E, Sathiya S, Srinivas N, Supritha V
* **Guide:** Dr. A Poonguzhali

---

## 🎯 Project Goal

The primary goal of this project is to address the critical challenge of railway accidents caused by track obstructions, especially in low-visibility conditions.

This prototype system uses a combination of sensors to detect both the **presence** and **movement** of an obstacle, and then wirelessly triggers an alert on the train.

## ⚙️ How It Works (Architecture)

The system is built in two main parts:

1.  **Obstacle Detection Unit (Pillar):**
    * This unit is placed beside the railway track.
    * It uses an **Ultrasonic sensor** to measure the distance to any object.
    * It uses a **PIR sensor** to detect any motion.
    * An **ESP32 microcontroller** reads data from both sensors.

2.  **Train Alert System (Onboard):**
    * This unit is installed on the train.
    * It consists of a second **ESP32**, an **LED** for visual alerts, and a **Buzzer** for audio alerts.

**Logic:**
If the Pillar's ultrasonic sensor detects an object within a set distance (e.g., < 10cm) **AND** the PIR sensor detects motion, the Pillar's ESP32 sends a wireless alert signal. The Train's ESP32 receives this signal and immediately activates the LED and buzzer to warn the operator.

## 🛠️ Hardware Components

* **Microcontroller:** 2x ESP WROOM32
* **Sensors:**
    * 1x Ultrasonic Sensor (HC-SR04)
    * 1x PIR Motion Sensor
* **Alerts:**
    * 1x Active Buzzer
    * 1x LED
* **Power:**
    * 2x 9V Battery
    * 2x LM7805 Voltage Regulator
* **Other:** Jumper Wires, Resistors, Breadboards

## 💻 Software

* **IDE:** Arduino IDE
* **Programming Language:** C/C++