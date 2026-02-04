# Arduino Line Follower Robot (IR + L298N)

## Overview
Autonomous line-following robot using an Arduino microcontroller, dual IR sensors for line detection, and an L298N motor driver to control DC motors.

## Hardware
- Arduino (Uno or compatible)
- 2× IR line sensors (Left + Right)
- L298N motor driver
- 2× DC motors + chassis + battery pack

## Control Logic
- Both sensors detect white → move forward
- Left detects line → turn left
- Right detects line → turn right
- Both detect line → stop / junction handling (configurable)

## Repository Structure
- `firmware/line_follower.ino` — Arduino code
- `report/` — project report PDF
- `docs/` — project photos / diagrams

## How to Run
1. Open `firmware/line_follower.ino` in Arduino IDE
2. Select your Arduino board and COM port
3. Wire sensors + L298N (pins are defined in the code)
4. Upload to Arduino

## Notes
- IR sensor logic may invert depending on module (swap HIGH/LOW checks if needed).
- Motor speed is controlled via PWM on ENA/ENB.
