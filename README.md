# Dimmable LED Controller

## Description
This project allows you to control the brightness of two LEDs using a potentiometer. A button is used to turn the LEDs on and off. The current brightness level is displayed in the Serial Monitor.

This project demonstrates basic usage of digital and analog inputs/outputs in Arduino, including PWM and button edge detection.

## Components
- Arduino (e.g., Uno)
- 2 LEDs
- Resistors (e.g., 220Ω or 330Ω)
- Potentiometer
- Push button
- Jumper wires
- Breadboard (optional)

## Features
- Brightness control using potentiometer (PWM)
- Button toggles LEDs ON/OFF
- Serial Monitor displays current brightness
- Optimized Serial output (prints only when value changes)

## How to use
1. Connect the circuit according to the pin configuration in the code.
2. Upload the code to Arduino.
3. Open Serial Monitor at 9600 baud.
4. Use the potentiometer to adjust brightness.
5. Use the button to toggle LEDs.

## What I learned
- PWM control in Arduino
- Working with analog inputs
- Button edge detection
- Optimizing Serial communication

## Circuit Diagram

![Arduino LED Circuit](arduino_led_circuit.png)

**Description:**
- Two LEDs connected to PWM pins with 330Ω resistors.
- Potentiometer connected to an analog input.
- Push button connected to a digital pin with pull-down/up resistors.
- GND and 5V connections as needed.

## Project structure

- `code.ino` - Main Arduino code.
- `README.md` - This documentation.
- `arduino_led_circuit.png` - Circuit diagram image.
