[![Top language: C++](https://img.shields.io/github/languages/top/jalalakbar47/Fire-alert-system?style=flat-square)](https://github.com/jalalakbar47/Fire-alert-system)
[![License: MIT](https://img.shields.io/github/license/jalalakbar47/Fire-alert-system?style=flat-square)](https://github.com/jalalakbar47/Fire-alert-system/blob/main/LICENSE)
[![GitHub stars](https://img.shields.io/github/stars/jalalakbar47/Fire-alert-system?style=flat-square)](https://github.com/jalalakbar47/Fire-alert-system/stargazers)
[![GitHub forks](https://img.shields.io/github/forks/jalalakbar47/Fire-alert-system?style=flat-square)](https://github.com/jalalakbar47/Fire-alert-system/forks)
[![Open issues](https://img.shields.io/github/issues/jalalakbar47/Fire-alert-system?style=flat-square)](https://github.com/jalalakbar47/Fire-alert-system/issues)
[![Last commit](https://img.shields.io/github/last-commit/jalalakbar47/Fire-alert-system?style=flat-square)](https://github.com/jalalakbar47/Fire-alert-system/commits/main)
[![Workflow status](https://img.shields.io/github/actions/workflow/status/jalalakbar47/Fire-alert-system/copilot-swe-agent%2Fcopilot?style=flat-square&label=workflow)](https://github.com/jalalakbar47/Fire-alert-system/actions/workflows/copilot-swe-agent/copilot)

# 🔥 Fire & Smoke Alarm System with SMS Notification (Wi-Fi | Arduino UNO R4)

A smart DIY system to detect fire and smoke using gas/flame sensors, trigger an alarm, and send instant SMS alerts to your phone using Wi-Fi and a cloud API — **no GSM module required**.

> 📡 Built using **Arduino UNO R4 Wi-Fi**, **MQ-2 gas sensor**, **Flame sensor**, and the **Circuit Digest SMS API**.

---

## 📚 Table of Contents

- [📌 Overview](#-overview)
- [⚙️ How It Works](#-how-it-works)
- [🔩 Components Required](#-components-required)
- [🧠 Software & SMS Integration](#-software--sms-integration)
- [🔌 Wiring Diagram](#-wiring-diagram)
- [▶️ Usage](#-usage)
- [📄 License](#-license)

---

## 📌 Overview

This project enables quick fire or smoke detection using two sensors (MQ-2 and flame) connected to an **Arduino UNO R4 Wi-Fi** board.

- 🧯 Triggers a **buzzer** and **LEDs** locally.
- 📤 Sends real-time **SMS alerts** using a **cloud SMS API** — without GSM hardware.
- 🏠 A smart, affordable, and effective safety upgrade for homes and offices.

---

🎯 Features
- Real-time fire/smoke detection
- SMS alerts using cloud API (no GSM module needed)
- Wi-Fi enabled (Arduino UNO R4 Wi-Fi)
- Easy integration and deployment
  
---

## ⚙️ How It Works

1. **Wi-Fi Connection**  
   Arduino connects to a local Wi-Fi network using stored credentials.

2. **Detection**  
   - `MQ-2` detects smoke or gas.
   - `Flame sensor` detects infrared light from fire.

3. **Alert Trigger**  
   - If sensor readings exceed the threshold:
     - 🔴 Red LED turns ON
     - 🟢 Green LED turns OFF
     - 🔊 Buzzer activates
     - 🔗 Arduino sends HTTP request to the SMS API

4. **SMS Delivery**  
   - API sends alert to your phone (e.g. "FIRE EMERGENCY at House")  
   - 📨 Free and fast message delivery via Circuit Digest API

---

## 🔩 Components Required

| Qty | Component                          |
|-----|------------------------------------|
| 1   | Arduino UNO R4 Wi-Fi               |
| 1   | MQ-2 Smoke/Gas Sensor              |
| 1   | Flame Sensor (Infrared)            |
| 2   | LEDs (Red & Green)                 |
| 2   | 220 Ω Resistors                    |
| 1   | 5V Active Buzzer                   |
| 1   | Breadboard & Jumper Wires          |
| 1   | USB or 5V DC Power Supply          |
| -   | Wi-Fi Network                      |
| -   | Circuit Digest SMS API Key         |

---

## 🧠 Software & SMS Integration

- Programmed using **Arduino IDE**
- Uses `WiFiS3.h` and `Arduino_LED_Matrix.h` libraries
- Replace the placeholders in code:
  - `ssid`, `password` – your Wi-Fi credentials
  - `phoneNo`, `apiKey` – from Circuit Digest account
  - `templateID`, `var1`, `var2` – customize your SMS template

---

## 🔌 Wiring Diagram

| Component      | Arduino Pin |
|----------------|-------------|
| MQ-2 Sensor    | A0          |
| Flame Sensor   | D6          |
| Green LED      | D3          |
| Red LED        | D5          |
| Buzzer         | D4          |

---

## ▶️ Usage

1. 🔌 Connect the components on a breadboard as per the diagram.
2. 📝 Open the `.ino` file in Arduino IDE and upload it to your board.
3. 🌐 Ensure the device connects to Wi-Fi.
4. 🚨 When fire/smoke is detected:
   - Red LED turns on
   - Buzzer sounds
   - SMS is sent to your phone via API

---

## 📄 License

This project is licensed under the [MIT License](LICENSE).
