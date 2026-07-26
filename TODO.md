# TODO: Digital Lab Final Project - Bluetooth Communication (ATmega64)

## Phase 1: Hardware Setup in Proteus (Precise Wiring Based on User Images)
- [x] Add the ATmega64 microcontroller (`U1`) and set Clock Frequency to 1 MHz.
- [x] **Temperature Sensor (LM35):** Connect `VOUT` (Pin 2) to `ADC0` / `PF0` (Pin 61).
- [x] **Character LCD (LM044L - 4-bit mode):**
  - Connect `RS` to `PA0` (Pin 51).
  - Connect `RW` to `PA1` (Pin 50).
  - Connect `E` to `PA2` (Pin 49).
  - Connect Data Pins `D4-D7` to `PA4-PA7` (Pins 47 to 44).
- [x] **LEDs (D1, D2, D3, D4):**
  - Connect 4 Red LEDs with 330Ω series resistors (`R5`, `R6`, `R7`, `R8`).
  - Wire them to `PB0`, `PB1`, `PB2`, and `PB3` (Pins 10 to 13) respectively.
- [x] **Buzzer:** Connect `buzzer` label to `PC0` (Pin 35).
- [x] **Relays:** Connect `RELAY1` to `PC1` (Pin 36) and `RELAY2` to `PC2` (Pin 37).
- [x] **Bluetooth/Serial Module (COMPIM):**
  - Connect COMPIM `RXD` and `TXD` using labels `RX_UC` and `TX_UC` to `PE0/RXD0` and `PE1/TXD0`.
  - Set Baud Rate to 9600.
- [x] **Virtual Terminals:** Connect `RECEIVE_DATA_FROM_BLUETOOTH` and `RECEIVE_DATA_FROM_MICROCONTROLLER` with 9600 Baud Rate.

## Phase 2: Software Configuration (CodeVision AVR CodeWizard)
- [ ] Set Chip to ATmega64A and Clock to 1 MHz.
- [ ] Configure Ports:
  - PORTA: Bits 0, 1, 2, 4, 5, 6, 7 as Outputs.
  - PORTB: Bits 0, 1, 2, 3 as Outputs.
  - PORTC: Bits 0, 1, 2 as Outputs.
- [ ] Enable ADC on AVCC reference.
- [ ] Enable USART0 (Receiver & Transmitter) at 9600 Baud.
- [ ] Enable Alphanumeric LCD on PORTA (20 Characters).

## Phase 3: Android Application Integration & Logic
- [ ] Continuously read LM35 temperature.
- [ ] Display temperature and exact state (ON/OFF) of all 4 LEDs, 2 Relays, and Buzzer on LCD.
- [ ] Map app Switches 1-7 to independently toggle the 4 LEDs (PB0-PB3), 2 Relays, and Buzzer.
- [ ] Map "LED/Lamp" page to toggle both relays simultaneously.
- [ ] Map Switch 8 to toggle temperature unit (C/F).
- [ ] Map Switch 9 to trigger a blink mode for the 4 LEDs.
- [ ] Transmit temperature and relay states via serial every 500ms.

## Phase 4: Documentation and Deliverables
- [ ] Take Proteus simulation screenshots (format: `exercise_name.png`).
- [ ] Write a step-by-step typed Word report matching the tutorial format.
- [ ] Package Word report, Proteus `.pdsprj`, and zero-comment CodeVision source files.