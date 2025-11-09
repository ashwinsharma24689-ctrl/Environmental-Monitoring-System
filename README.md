# Environmental Monitoring System – Arduino (SH1107 + DHT22)

This project monitors **temperature, humidity, gas concentration, and air quality** using Arduino.
Values are displayed on a **128×128 SH1107 OLED** via the U8g2 library, and a buzzer provides alerts when readings exceed safe thresholds.

---

## 📌 Features
- Real-time temperature and humidity sensing (DHT22)
- Gas concentration measurement (Analog sensor)
- Digital air-quality detection
- SH1107 OLED data display using U8g2
- Buzzer alerts for unsafe conditions
- Compact and low-power system

---

## 🛠 Hardware Requirements
| Component | Description |
|----------|-------------|
| Arduino Uno / Nano | Microcontroller |
| SH1107 OLED (128×128) | Display |
| DHT22 | Temperature + Humidity |
| MQ-type gas sensor | Analog input |
| Digital air quality sensor | airpin input |
| Buzzer | Alert |
| Jumper wires | Connections |

---

## 🔌 Pin Connections
| Module | Arduino Pin |
|--------|-------------|
| DHT22 Data | D2 |
| Air quality (digital) | D8 |
| Gas concentration (analog) | A0 |
| Buzzer | D4 |
| OLED SDA | A4 |
| OLED SCL | A5 |

OLED Address → `0x3C`

---

## 📦 Required Libraries
Install via Arduino Library Manager:

- `U8g2`
- `DHT sensor library`
- `Wire`

---
## 🌐 Online Simulator

You can view and test this project in the online simulator using the link below:

🔗 **Simulator Link:**  
[▶️ Open Simulator](https://wokwi.com/projects/441061123617910785)
