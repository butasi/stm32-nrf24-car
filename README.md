# STM32 NRF24 4WD RC Car

## Overview  
Wireless RC car built using STM32 + NRF24L01.

Split into two parts:
- **Transmitter** → reads joystick/buttons and sends data  
- **Receiver (car)** → receives data and drives motors  

Now upgraded to **4WD**, so it’s faster and has more torque.

---

## Project Structure
├── CAR-RECEIVER-G4/    # Car (STM32G4) └── F107RTC6.NRF24.TRANSMITTER/ #Controller (STM32F1)
---

## Hardware
- STM32 microcontrollers  
- NRF24L01 (2.4GHz)  
- Motor drivers (TB6612FNG / L298N)  
- 4x DC motors (4WD)  
- Battery  

---

## Features
- Wireless control over NRF24  
- Real-time throttle + steering  
- **4WD drivetrain (front + rear motors)**  
- Faster response + more power than 2WD  
- Modular transmitter ↔ receiver setup  

### Safety
- **Motor stop failsafe**
  - If signal is lost → all motors stop immediately  
  - Prevents runaway car  

---

## How to Open
1. Open STM32CubeIDE  
2. File → Open Projects from File System  
3. Select:
   - `CAR-RECEIVER-G4`  
   - `F107RTC6.NRF24.TRANSMITTER`  

---

## Notes
- `.ioc` files included (CubeMX configs)  
- `Debug/` and `Release/` ignored  
- NRF24 needs stable **3.3V** (add capacitor or it *will* misbehave)  

---

## Future Work
- Telemetry (car → transmitter)  
- Better packet handling / reliability  
- BLE / Wi-Fi control experiments  
- Sensors (IMU, encoders, etc.)