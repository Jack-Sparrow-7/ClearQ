# ClearQ 🍽️

ClearQ is a smart food ordering and billing system designed to streamline the canteen experience in colleges. It separates UPI-based students from the manual billing queue by allowing them to pre-order food via a mobile app built with Flutter. At the counter, students scan their generated QR/barcode, and the hardware system fetches order details from Firebase and prints the bill using a thermal printer.

📦 ESP32 Firmware Architecture
The ESP32 firmware follows a Modular Layered Architecture, inspired by Clean Architecture principles. The codebase is organized into clear functional layers to improve readability, maintainability, and scalability.

🧱 Layers:
Core Logic (/core):
Contains the main business rules (e.g., order processing, bill formatting).

Hardware Drivers (/hardware):
Abstracts interactions with the thermal printer, LCD, and barcode/QR scanner.

Network Layer (/network):
Handles all communication with Firebase (retrieving order details) and internet connection using WiFi.

Utilities (/utils):
Shared constants, helper functions, configuration.

Main Entry (main.cpp file):
Initializes and links all modules in setup() and coordinates execution in loop().

---

## 📱 Features

- Flutter mobile app for food selection and QR generation
- Real-time order sync with Firebase Realtime Database
- ESP32-CAM scans QR or barcode
- LCD displays order details for confirmation
- Thermal printer generates bill instantly
- Eliminates long queues for UPI users

---

## 🧩 Tech Stack

| Component         | Technology                |
|------------------|---------------------------|
| Mobile App       | Flutter + Dart            |
| Backend Database | Firebase Realtime Database|
| Microcontroller  | ESP32-CAM                 |
| Printing         | RP203 / TTL 58mm Thermal  |
|                  | Printer                   |
| Display          | 16x2 LCD                  |

---

## 📐 Architecture

```mermaid
graph TD;
    Flutter_App -->|Sends Order| Firebase
    ESP32 -->|Scans QR| Firebase
    ESP32 -->|Fetch Order| Firebase
    ESP32 -->|Show| LCD
    ESP32 -->|Print| Thermal_Printer
