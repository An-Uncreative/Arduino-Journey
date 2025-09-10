# Project 03: RGB LED Control 🌈

## Overview
This project introduces PWM (Pulse Width Modulation) and analog output by controlling an RGB LED. You'll learn how to mix red, green, and blue light to create any color, and implement smooth color transitions and rainbow effects.

## What You'll Learn
- PWM (Pulse Width Modulation) concepts
- Analog output using `analogWrite()`
- Color mixing theory (RGB color model)
- Mathematical functions for smooth transitions
- Function creation and organization

## Components Required
- Arduino Uno/Nano (or compatible)
- RGB LED (common cathode type)
- 3x 220Ω resistors
- Breadboard
- Jumper wires
- USB cable

## Circuit Diagram
```
Arduino Uno                RGB LED (Common Cathode)
┌─────────────┐           ┌─────────────┐
│             │           │      R  G  B│
│         D11 ●─── 220Ω ──┤ Red    │  │ │
│             │           │        │  │ │
│         D10 ●─── 220Ω ──┤ Green  │  │ │
│             │           │           │ │
│          D9 ●─── 220Ω ──┤ Blue      │ │
│             │           │             │
│         GND ●───────────┤ Cathode(-) ─┘
│             │           └─────────────┘
└─────────────┘
```

**Important**: This diagram shows a **common cathode** RGB LED. If you have a **common anode** LED, connect the common pin to 5V instead of GND, and invert the PWM values in code.

## Code Explanation

### PWM Basics
```cpp
analogWrite(RED_PIN, red);    // 0-255 value controls brightness
```
- PWM rapidly switches pin between HIGH and LOW
- Duty cycle (% of time HIGH) controls average voltage
- 0 = always LOW (0V), 255 = always HIGH (5V)
- Values between create intermediate voltages

### Color Mixing
```cpp
setColor(255, 0, 0);     // Pure red
setColor(255, 255, 0);   // Yellow (red + green)
setColor(255, 255, 255); // White (all colors)
```
- RGB LED has three separate LEDs inside
- Mix different intensities to create millions of colors
- Additive color model: adding colors makes brighter

### Mathematical Color Transitions
```cpp
redValue = (sin(i * 0.024) * 127) + 128;
```
- Sine waves create smooth, cyclical color changes
- Phase shifts (2.094, 4.188) offset each color
- Creates natural-looking rainbow transitions

## Upload Instructions
1. Build the circuit carefully, checking LED pin orientation
2. Connect Arduino to computer
3. Open Arduino IDE and select board/port
4. Open `rgb_led_control.ino`
5. Upload the code

## Expected Behavior
1. **Basic Colors Demo**: LED displays pure colors (red, green, blue, yellow, cyan, magenta, white, off)
2. **Rainbow Cycle**: Smooth transition through spectrum of colors
3. **Serial Output**: Color names printed to serial monitor

## Troubleshooting
- **LED doesn't light up**: Check power connections and LED orientation
- **Wrong colors**: Verify which LED leg connects to which pin
- **Dim colors**: Check resistor values (try 150Ω for brighter output)
- **Only one color works**: Check individual pin connections

## RGB LED Types
### Common Cathode (used in this project)
- Longest leg is negative (cathode)
- Connect cathode to GND
- Higher PWM values = brighter colors

### Common Anode (alternative)
- Longest leg is positive (anode)  
- Connect anode to 5V
- Invert PWM values: `analogWrite(pin, 255 - value)`

## Color Theory
| Color | Red | Green | Blue | Hex Code |
|-------|-----|-------|------|----------|
| Red | 255 | 0 | 0 | #FF0000 |
| Green | 0 | 255 | 0 | #00FF00 |
| Blue | 0 | 0 | 255 | #0000FF |
| Yellow | 255 | 255 | 0 | #FFFF00 |
| Cyan | 0 | 255 | 255 | #00FFFF |
| Magenta | 255 | 0 | 255 | #FF00FF |
| White | 255 | 255 | 255 | #FFFFFF |

## Variations to Try
1. **User Control**: Add buttons to manually control each color channel
2. **Potentiometer Control**: Use analog inputs to adjust colors
3. **Music Reactive**: Use microphone to make colors respond to sound
4. **Multiple LEDs**: Control several RGB LEDs independently
5. **Preset Colors**: Create favorite color combinations

## Understanding PWM
- **Frequency**: Arduino PWM runs at ~490Hz on most pins
- **Resolution**: 8-bit (0-255 values) = 256 levels per color
- **Total Colors**: 256³ = 16.7 million possible combinations
- **PWM Pins**: Only certain pins support PWM (marked with ~)

## Advanced Concepts
- **HSV Color Space**: Alternative to RGB using Hue, Saturation, Value
- **Gamma Correction**: Adjusting for human eye sensitivity
- **Color Temperature**: Warm vs cool white light

## Next Steps
- Combine with previous projects (button control, sensors)
- Learn about addressable LED strips (WS2812B/NeoPixels)
- Explore color sensors and automatic color matching