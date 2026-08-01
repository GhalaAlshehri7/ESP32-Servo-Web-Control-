# ESP32 Servo Control via Web Page

## Project Description
This project controls a servo motor through a web page hosted by an ESP32 operating in Access Point (AP) mode.

## Features
- ESP32 works as a WiFi Access Point.
- Web page with two buttons:
  - Open
  - Close
- Open:
  - Servo moves to 90°.
  - Green LED turns ON.
  - Red LED turns OFF.
- Close:
  - Servo returns to 0°.
  - Red LED turns ON.
  - Green LED turns OFF.

## Components
- ESP32
- Servo Motor
- Green LED
- Red LED
- 2 × 220Ω Resistors

## Files
- `sketch.ino` → Arduino code.
- `screenshots/` → Circuit and simulation images.

## Note
The ESP32 successfully creates a WiFi Access Point and displays the IP address `192.168.4.1` in the Serial Monitor.

The web interface requires the Wokwi Private Gateway feature to be accessed inside the simulator. The same code works on a physical ESP32 board by connecting to the ESP32 WiFi network and opening `http://192.168.4.1`.
