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

The rover is designed with a **Rocker-Bogie suspension system**, the same mechanism used in NASA’s Mars rovers.  
This mechanical design allows the rover to:

- Navigate rough and uneven terrain smoothly.
- Maintain wheel contact with the ground at all times.
- Climb over obstacles (rocks, inclines) up to twice the wheel diameter.
- Balance itself without requiring active suspension or springs.

With **6 independent motors and 12 wheels**, this rover ensures high stability, load distribution, and movement flexibility — making it ideal for off-road environments.

---

### 🌍 Suggested Applications

- **🗿 Archaeological and Tourism Site Exploration**  
  Navigate through ancient ruins or rough landscapes while collecting environmental data without disturbing fragile structures.

- **🌱 Smart Agriculture in Arid Regions**  
  Monitor soil and climate conditions remotely in hard-to-reach farming areas to support irrigation and crop decisions.

- **🚨 Disaster Response Operations**  
  Deploy the rover in unsafe or collapsed areas after earthquakes or floods to detect obstacles and provide real-time environmental monitoring.

---

## 📲 App Interface

The app interface includes:
- A joystick for motor control.
- A slider for servo motor.
- Text display for temperature and humidity.
- Distance value display.
- Sound indicators.
- Visual levels for temperature and humidity.

