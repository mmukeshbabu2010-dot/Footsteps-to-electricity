# Footstep Power Generation & Energy Harvesting System

An embedded energy harvesting prototype that converts mechanical footstep energy into electrical energy using a piezoelectric sensor array, rectifies and filters the harvested voltage, and monitors system metrics using an Arduino microcontroller and a 16x2 I2C LCD display.

---

## Technical Specifications & Component List

### Core Electronics & Processing
- **Microcontroller:** Arduino UNO R3 (ATmega328P) with USB Interface
- **Display:** 16x2 Blue Character LCD (JHD162A) with PCF8574 I2C Backpack
- **Prototyping Platform:** GL-12 Solderless Breadboard (830 Point)
- **Power Source:** 9V High-Capacity Battery + Heavy-Duty Snap Connector
- **Power Control:** SPST Start/Stop Toggle Switch

### Energy Harvesting & Conditioning Circuit
- **Transducer Array:** 10x Piezoelectric Discs (35mm, Parallel/Series Array)
- **AC-to-DC Rectifier:** Full-Wave Bridge Rectifier (4x 1N4007 Diodes)
- **Filter Stage:** 100µF / 25V Electrolytic Capacitor
- **Signal Stabilization:** 10kΩ Pull-down Resistor (Pin A0 Protection)

### Output Switching & Indicators
- **Transistor Driver:** BC547 NPN Bipolar Junction Transistor
- **Status Indicator:** Blue LED (Testing & Detection Flash)
- **Current Limiting & Base Resistors:** 2x 1kΩ Resistors

### Physical Frame Structure
- **Support Plates:** 2x Acrylic / Wooden Sheets (12x12 Inches)
- **Damping Mechanism:** 4x Compression Springs / High-Density Foam Blocks

---

## Circuit Connection Matrix

| Component | Component Pin | Connected Pin / Module | Purpose |
| :--- | :--- | :--- | :--- |
| **I2C LCD** | VCC | Arduino 5V Rail | Power Display |
| **I2C LCD** | GND | Common GND Rail | Power Display |
| **I2C LCD** | SDA | Arduino Pin A4 | I2C Data Line |
| **I2C LCD** | SCL | Arduino Pin A5 | I2C Clock Line |
| **Piezo DC Out** | Positive (+) | Arduino Pin A0 | Voltage Sensing |
| **Piezo DC Out** | Negative (-) | Common GND Rail | Circuit Ground |
| **BC547** | Base (B) | Arduino Pin 13 (via 1kΩ) | Pulse Trigger |
| **BC547** | Collector (C) | Common GND Rail | Transistor Switch |
| **BC547** | Emitter (E) | Blue LED Cathode (-) | LED Driving |
| **9V Battery** | V+ (Red) | Toggle Switch Pin 1 | System Power Input |
| **Toggle Switch** | Pin 2 | Arduino VIN Pin | Switched Power |

---

## Setup & Deployment Instructions

1. **Hardware Fabrication:**
   - Mount the 10 piezoelectric discs in a parallel array onto the bottom 12x12 inch base plate.
   - Attach spring/sponge corner supports and place the top pressure plate over the array.
   - Construct the 4-diode bridge rectifier and 100µF smoothing capacitor network on the GL-12 breadboard.

2. **Firmware Installation:**
   - Open `sketch.ino` in the Arduino IDE.
   - Install the `LiquidCrystal_I2C` library via **Tools > Manage Libraries**.
   - Connect the Arduino UNO R3 via USB, select Board **Arduino Uno**, choose the correct COM port, and click **Upload**.

3. **Virtual Simulation:**
   - Load `sketch.ino` alongside `diagram.json` in [Wokwi](https://wokwi.com) or open `index.html` in any web browser to simulate footsteps interactively.
