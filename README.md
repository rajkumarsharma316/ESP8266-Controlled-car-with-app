🏎️ ESP8266 Wi-Fi Car Controller

This project lets you control an RC car using an ESP8266 (NodeMCU) board over Wi-Fi.
The ESP8266 acts as a Wi-Fi Access Point and hosts a simple HTTP server.
A separate controller app (included as a ZIP file) sends HTTP requests to move, steer, and change speed.

⚙️ Features

Control car wirelessly using Wi-Fi (no internet needed)

Move Forward, Backward, Left, Right, and Stop

Adjust motor speed (0–255)

Control servo steering angle (0–180°)

Lightweight asynchronous web server (fast response)

Includes ready-to-use mobile controller app (ZIP)

📡 How It Works

The ESP8266 creates a Wi-Fi network (ESP8266_Car).

It runs a web server on 192.168.4.1 that listens for commands.

The mobile controller app sends HTTP requests like /forward, /stop, /servo?angle=90, etc.

The ESP8266 controls the motors and servo through an L298N motor driver.

🪛 Hardware Connections
Function	ESP8266 Pin	GPIO	L298N Pin
ENA	D1	5	ENA
IN1	D2	4	IN1
IN2	D3	0	IN2
IN3	D5	14	IN3
IN4	D6	12	IN4
ENB	D7	13	ENB
Servo Signal	D4	2	Servo Input

Note:

Connect L298N GND to ESP8266 GND.

Power L298N with an external 5–12V battery (for motors).

Do not power the motors from the ESP8266 directly.

⚡ Wi-Fi Access Point Info
Setting	Value
SSID	ESP8266_Car
Password	12345678
IP Address	192.168.4.1

After uploading the code, open the Serial Monitor at 115200 baud — you’ll see:

Access Point IP: 192.168.4.1
Web server started

🔗 HTTP Endpoints

You can test these from your phone or browser:

Command	Endpoint	Description
Move Forward	/forward	Move car forward
Move Backward	/backward	Move car backward
Turn Left	/left	Turn left
Turn Right	/right	Turn right
Stop	/stop	Stop motors
Set Speed	/speed?value=200	Set speed (0–255)
Set Servo Angle	/servo?angle=90	Rotate servo (0–180°)

Example:

http://192.168.4.1/forward
http://192.168.4.1/servo?angle=45
http://192.168.4.1/speed?value=255

🧩 Included Files
File	Description
esp8266_car.ino	Main ESP8266 firmware source code
app.zip	Mobile app for controlling the car

📱 Extract app.zip to view or install the mobile controller app.

🔧 Requirements

Install the following Arduino libraries:

ESPAsyncTCP

ESPAsyncWebServer

Servo

Board

Select board: NodeMCU 1.0 (ESP-12E Module)

Upload speed: 115200

Flash size: 4MB (1M SPIFFS)

🛠️ Upload Instructions

Open esp8266_car.ino in Arduino IDE

Connect your ESP8266 board via USB

Select the correct port and board

Upload the sketch

Open Serial Monitor → check for “Web server started”

📱 Control App

A ready-to-use mobile app (in app.zip) can control the car via Wi-Fi.
Just connect your phone to ESP8266_Car Wi-Fi and open the app.
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
