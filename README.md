# 🔋 Battery Thermal Management System using Thermoelectric Cooling

This project is focused on designing a thermal management system for lithium-ion battery packs using a **thermoelectric cooling system (TEC)**, **forced air cooling**, and **Arduino-based control**. It ensures the battery pack operates within safe temperature limits to extend lifespan and improve efficiency.

---

## 📌 Features

- Real-time temperature monitoring with LM35
- Automatic control of TEC and fan using Arduino
- Compact and cost-effective solution
- Visual indicators for different operating states (Green, Red)

---

## 🧠 How It Works

- **Green** → Normal operation (safe temperature)
- **Red** → Critical overheat, immediate action required

---

## ⚙️ Tech Stack

- Arduino Uno
- LM35 Temperature Sensor
- Thermoelectric Cooler
- Fans and Heat Sink
- C/C++ for embedded logic

---

## 📁 Project Structure
<pre>
battery-thermal-management/
├── README.md                    # Project overview and instructions
├── docs/
│   └── battery_project_report.pdf  # Detailed project report (PDF)
├── arduino-code/
│   └── battery_cooling_system.ino  # Arduino code for temperature control
</pre>


## 🔧 Arduino Code

The core Arduino logic that controls the fan, TEC, heating, and buzzer based on LM35 temperature readings is available in:

- [`arduino-code/battery_cooling_system.ino`](./arduino-code/battery_cooling_system.ino)

It includes:
- Wi-Fi + MQTT (Adafruit IO)
- Smart control logic based on temperature
- Alert system with buzzer and LED

## 📄 Documentation

- [Project Report (PDF)](./docs/battery_project_report.pdf)


## 🚀 Future Improvements

- 🔋 **Battery Health Monitoring**: Integrate voltage, current, and charge cycle tracking for a complete BMS.
- 🌡️ **Multiple Sensor Support**: Add more LM35 sensors for better thermal mapping of battery packs.
- 📟 **OLED/Display Integration**: Show real-time temperature and system status on a small display.
- 📡 **IoT Dashboard**: Expand Adafruit IO integration for historical data logging and graphs.
- 📶 **Wireless Alerts**: Add SMS/Email alerts via services like Twilio or IFTTT.
- 🔒 **Safety Features**: Add cutoff relays or MOSFETs in case of overheating.
- 🧠 **ML-based Optimization**: Predict thermal behavior based on usage patterns and ambient conditions.


## 🙌 Credits

Developed as part of the undergraduate project in Electrical & Electronics Engineering, BMS Institute of Technology and Management.




