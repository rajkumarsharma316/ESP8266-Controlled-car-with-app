# 🏎️ ESP8266 Wi-Fi Car Controller

[![Platform: Arduino](https://img.shields.io/badge/Platform-Arduino-blue.svg)](https://www.arduino.cc/)
[![Board: ESP8266](https://img.shields.io/badge/Board-ESP8266-orange.svg)](https://arduino-esp8266.readthedocs.io/)
[![IoT](https://img.shields.io/badge/Category-IoT-green.svg)](https://github.com/topics/iot)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![App](https://img.shields.io/badge/App-Flutter-blueviolet.svg)](https://github.com/YourUsername/YourAppRepo)

A Wi-Fi-controlled RC car using an **ESP8266 (NodeMCU)** and an **L298N motor driver**.  
The ESP8266 hosts a small HTTP server, and a **mobile app** (included as `app.zip`) sends commands to move, steer, and control speed — completely offline.

---

## ⚙️ Features
✅ Drive wirelessly via Wi-Fi  
✅ Control: **Forward / Backward / Left / Right / Stop**  
✅ Adjustable speed presets: **100 / 150 / 200 / 255**  
✅ Servo steering: **0° – 180°**  
✅ Works as its own access point  
- **SSID:** `ESP8266_Car`  
- **Password:** `12345678`  
- **IP Address:** `192.168.4.1`

---

## 🔗 HTTP Endpoints

| Command | Example |
|----------|----------|
| Move Forward | `/forward` |
| Move Backward | `/backward` |
| Turn Left | `/left` |
| Turn Right | `/right` |
| Stop | `/stop` |
| Set Speed | `/speed?value=200` |
| Set Servo Angle | `/servo?angle=90` |

Example calls:
http://192.168.4.1/forward

http://192.168.4.1/speed?value=255

http://192.168.4.1/servo?angle=45

---

## 🧩 Files in This Repository

| File | Description |
|------|-------------|
| `esp8266_car.ino` | Main ESP8266 firmware source code |
| `app.zip` | Mobile controller app (Flutter) |

📱 **Flutter App Repository:**  
👉 [View the App Repository](https://github.com/rajkumarsharma316/ESP-Controller-app)

---

## 🪛 Hardware Connections

| Function | ESP8266 Pin | GPIO | L298N Pin |
|-----------|--------------|------|-----------|
| ENA | D1 | GPIO5 | ENA |
| IN1 | D2 | GPIO4 | IN1 |
| IN2 | D3 | GPIO0 | IN2 |
| IN3 | D5 | GPIO14 | IN3 |
| IN4 | D6 | GPIO12 | IN4 |
| ENB | D7 | GPIO13 | ENB |
| Servo Signal | D4 | GPIO2 | Servo Input |

> 🔋 Power the L298N from a 5–12 V battery (not directly from the ESP8266).  
> Make sure all grounds are connected.

---

## 🛠️ Setup Instructions

1. Open **Arduino IDE**  
2. Install libraries:  
   - `ESPAsyncTCP`  
   - `ESPAsyncWebServer`  
   - `Servo`
3. Select board: **NodeMCU 1.0 (ESP-12E Module)**  
4. Upload the code to your ESP8266  
5. Open the **Serial Monitor** at `115200 baud` — you’ll see:  
Access Point IP: 192.168.4.1
Web server started

---

## 🧠 How It Works

1. The ESP8266 starts a Wi-Fi Access Point (`ESP8266_Car`).  
2. It hosts an HTTP server on `192.168.4.1`.  
3. The mobile app sends commands like `/forward` or `/servo?angle=90`.  
4. The ESP8266 drives the motors through the L298N driver and adjusts the servo angle.

---

## 🧑‍💻 Author

Created by **Raj Kumar Sharma**  
ESP8266 IoT Car Controller · MIT License © 2025  

---

### ⭐ Support
If you like this project, give it a **star** ⭐ on GitHub!  
It helps others discover the project and supports future updates 🚀
