# Project 02: Button Input 🔘

## Overview
This project introduces digital input by reading button presses. When you press the button, it toggles the LED on and off. This teaches fundamental concepts of digital input, pull-up resistors, and button debouncing.

## What You'll Learn
- Digital input using `digitalRead()`
- Pull-up resistors (internal and external)
- Button debouncing techniques
- State change detection
- Toggle functionality

## Components Required
- Arduino Uno/Nano (or compatible)
- Push button (tactile switch)
- 10kΩ resistor (optional - can use internal pull-up)
- Breadboard
- Jumper wires
- USB cable

## Circuit Diagram
```
Arduino Uno                    Components
┌─────────────┐
│             │
│         D13 ●───────────── Built-in LED
│             │
│          D2 ●──────┐
│             │      │
│         5V  ●──────┼─────── 10kΩ Resistor ─┐
│             │      │                       │
│         GND ●──────┼───────────────────────┼─── Push Button
│             │      │                       │
└─────────────┘      └───────────────────────┘
```

**Alternative Circuit (using internal pull-up):**
```
Arduino Uno                    Components
┌─────────────┐
│             │
│         D13 ●───────────── Built-in LED
│             │
│          D2 ●───────────── Push Button ──── GND
│             │
│         GND ●
│             │
└─────────────┘
```

## Code Explanation

### Pull-up Resistors
```cpp
pinMode(BUTTON_PIN, INPUT_PULLUP);  // Use internal pull-up resistor
```
- Pull-up resistors ensure the input pin reads HIGH when button is not pressed
- When button is pressed, it connects the pin to GND (LOW)
- Arduino has built-in pull-up resistors we can enable

### Reading Button State
```cpp
buttonState = digitalRead(BUTTON_PIN);
```
- `digitalRead()` returns HIGH or LOW
- With pull-up resistor: unpressed = HIGH, pressed = LOW

### Button Debouncing
```cpp
if (buttonState != lastButtonState) {
  delay(50);  // Small delay for debouncing
  buttonState = digitalRead(BUTTON_PIN);
}
```
- Mechanical buttons can "bounce" creating multiple rapid signals
- Small delay helps filter out these false signals

### Toggle Functionality
```cpp
ledState = !ledState;  // Toggle the LED state
digitalWrite(LED_PIN, ledState);
```
- `!` operator flips boolean value (true becomes false, vice versa)
- Each button press toggles LED on/off

## Upload Instructions
1. Build the circuit according to the diagram
2. Connect Arduino to computer via USB
3. Open Arduino IDE
4. Select board and port in Tools menu
5. Open `button_input.ino`
6. Upload the code

## Expected Behavior
- Press button once: LED turns on, serial prints "LED ON"
- Press button again: LED turns off, serial prints "LED OFF"
- LED state toggles with each button press
- No effect when holding button down

## Troubleshooting
- **LED doesn't respond**: Check circuit connections
- **LED flickers**: Button might be bouncing - increase debounce delay
- **Button reads incorrectly**: Verify pull-up resistor connection
- **No serial output**: Check serial monitor baud rate (9600)

## Circuit Building Tips
1. **Power off** Arduino before building circuit
2. Use the **internal pull-up** for simpler wiring
3. **Test connections** with multimeter if available
4. **Double-check** power and ground connections

## Variations to Try
1. **External LED**: Add LED with resistor to different pin
2. **Multiple buttons**: Control different LEDs with separate buttons
3. **Button combinations**: Detect when multiple buttons pressed
4. **Long press detection**: Different behavior for short vs long presses

## Understanding Pull-up Resistors
- **Without pull-up**: Input pin "floats" and reads random values
- **With pull-up**: Pin is pulled to HIGH (5V) when button not pressed
- **When pressed**: Button connects pin directly to GND (LOW)

## Next Steps
- [Project 03: RGB LED Control](../03-rgb-led-control/) - Learn PWM and color mixing
- Experiment with multiple inputs and outputs
- Try interrupt-based button handling