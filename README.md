# Touch Piano Screen Based On Capacitance Transducers

## Project Overview

### Technical Concept
A microcontroller-based electronic piano that utilizes capacitive sensing technology to replace traditional mechanical keys. The system employs RC time constant measurements to detect touch inputs with variable sensitivity, enabling:
- Contactless note triggering
- Pressure-sensitive volume control (future implementation)
- Compact form factor with minimal moving parts

### System Architecture
-
  ```mermaid
  graph TD
      A[Capacitive Touch Pads] --> B[RC Circuit]
      B --> C[Arduino Nano]
      C --> D[PWM Tone Generation]
      D --> E[Passive Buzzer]
      C --> F[LED Feedback]

## Key Specifications

| Parameter           | Specification         | Measurement Method     |
|---------------------|------------------------|-------------------------|
| Input Range         | 1–174 ms               | RC time constant        |
| Output Resolution   | 7,908 units            | 10-bit ADC              |
| Sensitivity         | 394.4 units/ms         | Linear regression       |
| Frequency Response  | 5.7–997.6 rad/s        | Bode analysis           |
| Power Consumption   | <100mA @ 5V            | Current probe           |

---

## Technical Implementation

### Sensing System
- 7× copper PCB pads (20mm² each)  
- 1MΩ current-limiting resistors  
- CapacitiveSensor library for Arduino

### Control Unit
- ATmega328P microcontroller  
- Custom PCB layout  
- 16MHz clock frequency

### Audio Output
- Passive piezoelectric buzzer  
- PWM-generated tones (C4–B4 frequency range)  
- 8Ω impedance

### Power Management
- 18650 Li-ion cell (3.7V nominal)  
- TP4056 charging module  
- MT3608 boost converter (to 5V)

---

## Performance Characteristics

### Transfer Function:
-
    ```math
          H(s) = \frac{1}{\tau s + 1}, \quad \tau \in [0.001, 0.174] \text{ s}

### Bandwidth Variation

- **Untouched:** 997.6 rad/s (159 Hz)  
- **Fully pressed:** 5.7 rad/s (0.9 Hz)

---

## Statistical Analysis

| Metric                | Value             |
|------------------------|------------------|
| Resolution             | 7,908 units       |
| Sensitivity            | 394.4 units/ms    |
| Std. Deviation         | 3.12×10⁶          |
| Signal-to-Noise Ratio  | 42 dB             |

---

## Development Progress

### Research Phase
- Capacitive sensing literature review  
- Component selection analysis

### Prototyping
- Breadboard validation  
- Initial code development

### Production
- PCB design (Eagle)  
- SMT assembly process

### Validation
- Unit testing (per key)  
- Frequency response verification  
- Power consumption measurements

---

## Future Work

### Potential Implementations
- Pressure-sensitive volume control
- Multi-touch detection
- Octave expansion (14+ keys)
- Battery optimization for >24h runtime
