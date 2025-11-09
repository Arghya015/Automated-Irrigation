# 🌾 Smart Agriculture System (Arduino UNO)

An **IoT-based smart agriculture system** that automates watering using sensors for soil moisture, light, and rain detection.  
It activates a **relay-controlled pump** only in the **evening**, when **soil is dry** and **no rain is detected**.  

---

## 🚀 Features

-  **Soil Moisture Sensor** — detects when the soil is dry  
-  **LDR Sensor (Digital)** — ensures watering happens only in the **evening**  
-  **Rain Sensor** — prevents watering when it's raining  
- 💡 **LED Indicators**  
  - Green LED → Pump ON  
  - Red LED → Danger / Pump OFF  
-  **Relay + Pump** — automatic water control (Active HIGH type)

---

## 🧰 Components Used

| Component | Quantity | Description |
|------------|-----------|-------------|
| Arduino UNO | 1 | Microcontroller |
| Soil Moisture Sensor | 1 | Analog (A0) |
| Rain Sensor | 1 | Analog (A1) |
| LDR Module | 1 | Digital (D0 → Pin 6) |
| Relay Module | 1 | Active HIGH type (Pin 9) |
| Pump | 1 | 3.7V or 5V motor |
| LEDs (Green, Red) | 2 | Status indicators |
| Jumper Wires | — | For connections |
| Power Source | 1 | 5V / USB |

---

## ⚙️ Pin Connections

| Component | Arduino Pin | Notes |
|------------|--------------|-------|
| Soil Moisture Sensor | A0 | Analog output |
| Rain Sensor | A1 | Analog output |
| LDR (D0) | D6 | Digital output |
| Green LED | D7 | Pump ON indicator |
| Red LED | D8 | Danger / OFF indicator |
| Relay Signal | D9 | Active HIGH input |
| Relay VCC | 5V | Power |
| Relay GND | GND | Common ground |

---

## 🧠 Working Principle

1. The system constantly monitors **soil moisture**, **light intensity**, and **rain detection**.  
2. If:
   - Soil is **dry**,  
   - It is **evening (LDR = LOW)**,  
   - It is **not raining**,  
   then the relay turns **ON** the pump.  
3. The **Green LED** turns ON when the pump is active.  
4. The **Red LED** lights up if any condition fails.

---

## 🔋 Power Setup

- Arduino UNO powered via USB or 5V adapter  
- Relay and pump powered via 5V (common ground with Arduino)  
- If pump requires >5V, use **external supply + transistor driver circuit**

---

## 🧩 Future Enhancements

- Add ESP8266 / ESP32 for Blynk IoT monitoring  
- Display sensor values on LCD or OLED  
- Control and monitor from smartphone  
- Send data to ThingSpeak or Firebase  

---


