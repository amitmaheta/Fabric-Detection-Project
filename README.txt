
# Fabric Detection Project - README

This project is focused on detecting fabric smoothness and wrinkles using a combination of IR and Ultrasonic sensors.

### 📂 V1/
- **Code.txt**: Arduino code for Version 1
  - Detects presence of fabric using IR and ultrasonic sensors
  - Outputs raw sensor values
- **V1.mp4**: Demonstration of Version 1 output on hardware

### 📂 V2/
- **Code.txt**: Arduino code for Version 2
  - Adds logic to distinguish between smooth and wrinkled fabric
  - Implements thresholding based on sensor variation
- **V2.mp4**: Demonstration of Version 2 output showing wrinkled vs smooth detection

### 📂 Practical/
- **Practical.mp4**: Real-world test of the complete project prototype on actual fabric

### 📄 Schematic_PCB-design.pdf
- Schematic and layout for the sensor + Arduino-based circuit
- Designed to be fabricated using EasyEDA

### 📄 Fabric_Detection_Calculation.pdf
- Contains formulas and threshold logic used to classify smooth vs wrinkled surfaces based on:
  - IR value variation
  - Distance fluctuation
  - Example:
    - If IR variation > 50 and Distance variation > 1.5 cm → Wrinkled
    - Else → Smooth

---

## ⚙️ Hardware Used
- Arduino Uno
- IR Emitter
- IR Receiver
- HC-SR04 Ultrasonic Sensor
- Breadboard + Jumper wires

---

## 🔌 Wiring Summary
- **IR Emitter**: D7 → anode, cathode → GND
- **IR Receiver**: A0 ← phototransistor To GND
- **Ultrasonic**: TRIG → D9, ECHO → D10
- **Power**: All VCCs → 5V, GNDs → GND

---

## ✅ Project Outcome
- **Version 1**: Basic fabric presence detection
- **Version 2**: Fabric texture classification (Smooth vs Wrinkled)
- **Practical**: Validated working prototype with real fabric

---

Made by Amitkumar Mehta 
