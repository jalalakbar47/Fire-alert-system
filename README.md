
Fire & Smoke Alarm System with SMS Notification (Arduino UNO R4)

A DIY project to detect fire and smoke, trigger an alarm, and instantly send SMS alerts via Wi‑Fi & cloud API (no GSM module required).

## Table of Contents
- [Overview](#overview)
- [How It Works](#how-it-works)
- [Components Required](#components-required)
- [Wiring Diagram](#wiring-diagram)
- [Software & SMS Integration](#software--sms-integration)
- [Usage](#usage)
- [License](#license)


---

Overview

This project enables quick detection of fire or smoke using two sensors connected to an Arduino UNO R4 Wi-Fi board. It triggers a buzzer and LEDs locally and sends real-time SMS alerts to a designated number using a cloud SMS API—without the need for GSM hardware. It’s an affordable and effective safety upgrade for homes or offices.

---

How It Works

1. Wi‑Fi Connection: Arduino connects to a local Wi‑Fi network using stored credentials.
2. Detection:
 . MQ‑2 sensor measures smoke or combustible gas levels.
 . Flame sensor detects infrared light from fire.
3. Alert Trigger:
 .If smoke or flame exceeds the threshold, Arduino activates a buzzer and red LED, turns off green LED.
 .It sends an HTTP request to the SMS API with your phone number and alert message.
4. SMS Delivery: The cloud SMS API processes and sends the alert to your mobile network — fast, reliable, and free .
---

Components Required

1.Arduino UNO R4 Wi‑Fi
2. MQ‑2 Smoke Sensor (gas/smoke detection)
3. Flame Sensor (infrared fire detection)
4. 5 V Active Buzzer
5. Red & Green LEDs + 220 Ω resistors
6. Breadboard & jumper wires
7. USB or 5 V DC power supply
8. Wi‑Fi network & Circuit Digest SMS API Key 

---

Wiring Diagram

Component	Connected to

1. MQ‑2 analog out	A0 of Arduino
2. Flame digital out	D6
3. Buzzer	D4
4. Green LED	D3 (via 220 Ω)
5. Red LED	D5 (via 220 Ω)
6. Arduino is powered via USB or DC jack. Breadboard supports component arrangement .

---

Software & SMS Integration

1. Libraries:
 .WiFiS3.h for Wi‑Fi networking
 .Arduino_LED_Matrix.h for onboard LED animations (optional for enhanced UX) 

2. SMS API:
 .Use Circuit Digest Cloud SMS API.
 .Select SMS template (e.g., Device Status Alert ID = 101).
 .Assign template variables (var1, var2) in your code—for instance, var1 = “House”, var2 = “FIRE EMERGENCY!” .

3. HTTP Request:
  Arduino sends alert as JSON via POST (or GET) with API key, recipient number, and message variables.

---

Usage

1. Upload the code to your Arduino via the Arduino IDE.
2. Power the system from USB or wall adapter.
3. Green LED indicates normal operation.
4. Smoke or flame triggers red LED, buzzer, and SMS to your phone.
5. Monitor sensor values via Serial or optional LED matrix display.

##6. Customize:

Adjust SMOKE_THRESHOLD based on your environment.

Change message content via var1 and var2.

Swap SMS template if preferred.

---

## License
This project is shared for educational and hobbyist use only. Please attribute Circuit Digest when using or adapting. No commercial use allowed without permission.
