# 🚀 Galaxy Robust Versatile Rover (Galaxy RVR)

![Rover Image](https://github.com/abdallah3z22/Rover-Vehicle-project/blob/main/media/Galaxy%20RVR%209.jpg)

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
|------------------|------------------------------------------|
| Arduino Board     | Uno / Nano / Mega                        |
| Motors            | 6 × DC Motors                            |
| Wheels            | 12 total (2 per motor)                   |
| Motor Driver      | L298N or similar                         |
| Ultrasonic Sensor | HC-SR04 for distance detection           |
| Temperature Sensor| DHT11 for temperature & humidity         |
| Servo Motor       | SG90 or MG995                            |
| Power Source      | External Battery or Power Bank           |
| Chassis           | Custom-built with Rocker-Bogie mechanism |

---

## ⚙️ Functionalities

- **Movement Control:**  
  Control forward, backward, left, and right using joystick.

- **Servo Control:**  
  Adjust the servo motor angle using a slider.

- **Environmental Monitoring:**  
  View real-time temperature and humidity on the app.

- **Obstacle Detection:**  
  Ultrasonic sensor displays distance, with warnings if out of range.

- **Sound Alerts:**  
  Plays a sound when specific conditions (e.g., digital inputs A0/A1) are met.

- **Connection Status:**  
  Shows whether the rover is connected to the mobile app.

---

## 📲 RemoteXY Interface

The app interface includes:
- A joystick for motor control.
- A slider for servo motor.
- Text display for temperature and humidity.
- Distance value display.
- Sound indicators.
- Visual levels for temperature and humidity.

---

## 🧠 Rocker-Bogie Suspension

The rover uses a **Rocker-Bogie** system — a passive suspension mechanism originally designed by NASA for Mars rovers.  
This allows the rover to:

- Maintain balance over uneven terrain.
- Climb over obstacles efficiently.
- Distribute load across all wheels.
- Reduce shock impact.

---

## 📁 Project Structure

