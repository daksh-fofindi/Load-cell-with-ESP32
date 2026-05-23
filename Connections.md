# ESP32 Weighing Machine Connections

This document contains all hardware connections for the ESP32 Weighing Machine project using:

* ESP32
* HX711 Load Cell Amplifier
* Load Cell
* 16x2 I2C LCD Display

---

# 1. HX711 to ESP32 Connections

| HX711 Pin | ESP32 Pin |
| --------- | --------- |
| VCC       | 3.3V      |
| GND       | GND       |
| DT        | GPIO34    |
| SCK       | GPIO18    |

---

# 2. I2C LCD to ESP32 Connections

| LCD Pin | ESP32 Pin |
| ------- | --------- |
| VCC     | 5V        |
| GND     | GND       |
| SDA     | GPIO21    |
| SCL     | GPIO22    |

---

# 3. Load Cell to HX711 Connections

| Load Cell Wire | HX711 Pin |
| -------------- | --------- |
| Red            | E+        |
| Black          | E-        |
| White          | A-        |
| Green          | A+        |

---

# 4. ESP32 Built-in LED

| Function     | ESP32 Pin |
| ------------ | --------- |
| Built-in LED | GPIO2     |

If GPIO2 does not work on your ESP32 board, try:

* GPIO5
* GPIO22

---

# 5. Power Connections

| Device | Voltage   |
| ------ | --------- |
| ESP32  | USB Power |
| HX711  | 3.3V      |
| LCD    | 5V        |

Important:

* All GND connections must be connected together.
* Use stable USB power for accurate readings.

---

# 6. Complete Connection Summary

## HX711

```text
HX711 VCC  -> ESP32 3.3V
HX711 GND  -> ESP32 GND
HX711 DT   -> ESP32 GPIO34
HX711 SCK  -> ESP32 GPIO18
```

---

## I2C LCD

```text
LCD VCC -> ESP32 5V
LCD GND -> ESP32 GND
LCD SDA -> ESP32 GPIO21
LCD SCL -> ESP32 GPIO22
```

---

## Load Cell

```text
Red    -> E+
Black  -> E-
White  -> A-
Green  -> A+
```

---

# 7. Troubleshooting

## LCD Not Displaying

Try changing LCD address in code:

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

* Wrong load cell wiring
* Incorrect calibration factor
* Load cell mounted incorrectly
* Weak pressure on sensor

---

## Unstable Readings

Possible reasons:

* Loose wires
* USB noise
* Vibrations
* Bad grounding
* Unstable power supply

---

# 8. Notes

* GPIO34 is input-only and perfect for HX711 DT.
* GPIO18 is used for HX711 clock signal.
* ESP32 I2C default pins are GPIO21 (SDA) and GPIO22 (SCL).
* HX711 should preferably use 3.3V with ESP32.

---

# Author

Daksh Fofindi
ESP32 Weighing M
