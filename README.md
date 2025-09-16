# 🚀 Galaxy Robust Versatile Rover (Galaxy RVR)

![Rover Image](https://github.com/abdallah3z22/Rover-Vehicle-project/blob/main/media/Galaxy%20RVR%209.jpg)
## 🎥 Project Video

You can watch the demo video here:  
[Project Demo Video](https://drive.google.com/file/d/1LpjWG3qay0_qdufBdIlzgO6Jy-xcpyDJ/view?usp=drivesdk)

---

## 📌 Project Overview

This project is a fully functional rover vehicle controlled remotely using the **RemoteXY** mobile application and an **Arduino** board.  
The system includes:

- Real-time temperature and humidity sensing using **DHT11**.
- Obstacle distance measurement via **Ultrasonic Sensor** (HC-SR04).
- Movement control using a **joystick interface**.
- Servo motor control via slider.
- Sound alerts triggered by specific sensor states.
- Rocker-Bogie suspension system for rough terrain.
- 6 DC motors and 12 wheels for enhanced mobility and load balance.

---

## 🔩 Hardware Specifications

| Component         | Description                              |
|-------------------|------------------------------------------|
| Arduino Board     | Uno                                      |
| Motors            | 6 × DC Motors                            |
| Wheels            | 12 total (2 per motor)                   |
| Motor Driver      | L298N or similar                         |
| Ultrasonic Sensor | HC-SR04 for distance detection           |
| Temperature Sensor| DHT11 for temperature & humidity         |
| Servo Motor       | SG90 or MG995                            |
| Power Source      | External Battery or Power Bank           |
| Chassis           | Custom-built with Rocker-Bogie mechanism |

---

## ⚙️ Rocker-Bogie System & Applications

### 🛞 What is the Rocker-Bogie System?

The rover is equipped with a **Rocker-Bogie suspension system**, a passive mechanical design famously used in NASA's Mars rovers.  
It enables:

- Smooth navigation over uneven terrain and rocky surfaces.
- Continuous ground contact across all wheels for stability.
- Climbing over obstacles up to twice the wheel diameter.
- Balanced weight distribution without complex electronics or shock absorbers.

With **6 DC motors** driving **12 wheels**, the system offers excellent mobility and adaptability in outdoor or rugged environments.

---

### 🌍 Suggested Applications

 **Archaeological and Tourism Site Exploration:**  
   Enables non-invasive monitoring of sensitive or restricted areas, such as Egypt’s *Siwa Oasis* and *Western Desert* archaeological zones.

 **Smart Agriculture in Arid Regions:**  
   Assists in crop management by autonomously surveying fields, measuring soil moisture and temperature, and transmitting alerts to farmers via the app.

 **Disaster Response Operations:**  
   Safely assesses hazardous environments, such as gas leaks or fire-prone zones, prior to human intervention — enhancing safety protocols.

---

## 📲 App Interface

The app interface includes:
- A joystick for motor control.
- A slider for servo motor.
- Text display for temperature and humidity.
- Distance value display.
- Sound indicators.
- Visual levels for temperature and humidity.

