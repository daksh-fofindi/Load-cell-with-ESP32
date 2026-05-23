Author - Daksh Fofindi (Daksh Aerospace)

# If you liked my work please follow me on below social media profiles

youtube - https://m.youtube.com/@dakshfofindi907/videos?view=0&sort=dd&shelf_id=2
<br>
Website - http://www.dakshaerospace.in/
<br>
instagram - https://www.instagram.com/dakshfofindi/
<br>
X - https://x.com/dakshfofindi
<br>
LinkedIn - https://in.linkedin.com/in/dakshfofindi

---
# Weighing Machine with ESP32, HX711 and I2C LCD

## Project Overview

This project is a real-time digital weighing machine built using:

* ESP32
* HX711 Load Cell Amplifier
* Load Cell
* 16x2 I2C LCD Display

The system measures weight in grams and displays it on an LCD screen.
It also includes an airplane-style double blink LED indicator using the ESP32 built-in LED.

---

# Features

* Real-time weight measurement
* Fast refresh rate
* Weight display in grams
* I2C LCD interface
* HX711 load cell amplification
* Automatic tare (zero calibration)
* Negative noise filtering
* Airplane-style LED blinking
* Serial Monitor debugging output

---

# Components Required

| Component               | Quantity |
| ----------------------- | -------- |
| ESP32 Development Board | 1        |
| HX711 Module            | 1        |
| Load Cell               | 1        |
| 16x2 I2C LCD            | 1        |
| Jumper Wires            | Multiple |
| USB Cable               | 1        |

---

# Circuit Connections

## HX711 to ESP32

| HX711 Pin | ESP32 Pin |
| --------- | --------- |
| VCC       | 3.3V      |
| GND       | GND       |
| DT        | GPIO34    |
| SCK       | GPIO18    |

---

## I2C LCD to ESP32

| LCD Pin | ESP32 Pin |
| ------- | --------- |
| VCC     | 5V        |
| GND     | GND       |
| SDA     | GPIO21    |
| SCL     | GPIO22    |

---

## Load Cell to HX711

| Load Cell Wire | HX711 Pin |
| -------------- | --------- |
| Red            | E+        |
| Black          | E-        |
| White          | A-        |
| Green          | A+        |

If readings are incorrect or very low:

* swap A+ and A-

---

# Libraries Required

Install these libraries from Arduino IDE Library Manager:

* HX711
* LiquidCrystal_I2C
* Wire

---

# Working Principle

1. The load cell senses force/weight.
2. HX711 amplifies the tiny analog signal.
3. ESP32 reads digital data from HX711.
4. Calibration factor converts raw data into grams.
5. LCD displays the measured weight.
6. Built-in LED performs airplane-style double blinking.

---

# Calibration

The calibration factor must be adjusted for accurate readings.

Locate:

```cpp
float calibration_factor = -1000.0;
```

Try values such as:

* -1000
* -5000
* -10000

until the displayed weight matches a known object.

If readings go negative:

* use positive calibration values instead.

---

# Serial Monitor Output

The Serial Monitor displays real-time readings for debugging:

```text
Weight: 152.4 g
```

Baud Rate:

```text
115200
```

---

# Airplane LED Blink Pattern

The built-in ESP32 LED performs:

* blink blink
* pause
* blink blink

similar to aircraft navigation lights.

---

# Common Issues

## LCD Not Working

Try changing LCD address:

```cpp
LiquidCrystal_I2C lcd(0x27, 16, 2);
```

to:

```cpp
LiquidCrystal_I2C lcd(0x3F, 16, 2);
```

---

## Weight Always Zero

Possible reasons:

* wrong load cell wiring
* incorrect calibration factor
* improper load cell mounting
* weak pressure on load cell

---

## Random Readings

Possible reasons:

* unstable power supply
* loose wires
* vibrations
* improper grounding

---

# Future Improvements

* Add battery support
* Add Bluetooth/WiFi monitoring
* Add data logging
* Add buzzer alarms
* Add weight threshold detection
* Add web dashboard

---

# Author

Created by Daksh Fofindi
Electronics and Aer
