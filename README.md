# STM32 NRF24 Car Project

## Overview

Wireless RC car built using STM32 and NRF24L01 modules.

The system is split into two parts:

* **Transmitter** → Sends control data (joystick/buttons)
* **Receiver (Car)** → Drives motors based on received data

---

## Project Structure

```
.
├── CAR-RECEIVER-G4/              # STM32CubeIDE project (car)
└── F107RTC6.NRF24.TRANSMITTER/  # STM32CubeIDE project (controller)
```

---

## Hardware

* STM32 microcontrollers
* NRF24L01 (2.4GHz)
* Motor driver (e.g. TB6612FNG / L298N)
* Power supply (battery)

---

## Features

* Wireless control over NRF24
* Real-time throttle and steering
* Modular transmitter ↔ receiver design

---

## How to Open

1. Open STM32CubeIDE
2. Go to: `File → Open Projects from File System`
3. Select either:

   * `CAR-RECEIVER-G4`
   * `F107RTC6.NRF24.TRANSMITTER`

---

## Notes

* `.ioc` files are included for CubeMX configuration
* Build folders (`Debug/`, `Release/`) are ignored
* NRF24 requires stable 3.3V supply (use capacitor)

---

## Future Work

* Telemetry (car → transmitter)
* Signal loss failsafe
* BLE / Wi-Fi control experiments

---

