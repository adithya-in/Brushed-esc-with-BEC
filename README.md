# Brushed ESC — Low cost High-Power Motor Driver

A **bare-minimum brushed ESC** designed for **high-power RC airplane and drone applications**, built with a **single MOSFET topology** for simplicity, efficiency, and reliability.

> Most commercial brushed ESCs are overpriced, overcomplicated, and still lack proper current ratings.  
> This design fixes that — clean, cheap, powerful, and open-source.

---

## ⚙️ Features

- **Input Voltage:** up to **55 V**
- **Continuous Current:** up to **49 A**
- **MOSFET:** IRFZ44N (logic-level)
- **Freewheel Diode:** 1N5819 Schottky
- **Integrated 5 V / 2 A BEC** (K7805-2000R3L)
- **PWM Control** via MCU or Reciever(3.3 V / 5 V logic compatible)
- **Single-direction drive** — ideal for aircraft and drones
- **Compact and low-cost** layout
- **Through-hole or SMD build options**

---

## Why This ESC?

Typical brushed ESCs include mcu with firmware and H-bridge drivers for bidirectional control — features that are **not needed for RC airplane propulsion**.  

This ESC:
- Uses only **one N-channel MOSFET** → higher current capacity, lower heat.
- Drops unnecessary **direction logic and MCU firmware** → simpler, cheaper, and more reliable.
- Adds a built-in **BEC regulator** → no external 5 V supply needed for flight controllers or receivers.

---


