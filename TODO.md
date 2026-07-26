# TODO: Digital Lab Final Project - Bluetooth Communication (ATmega64)

## Phase 1: Hardware Setup in Proteus (Precise Wiring)
- [ ] Add the ATmega64 microcontroller (`U1`) to the schematic.
- [ ] **Power & Reference:** Connect `AVCC` (Pin 64) and `AREF` (Pin 62) appropriately if required by your specific Proteus settings (often handled automatically, but verify).
- [ ] **Temperature Sensor (LM35):** - Connect `VOUT` (Pin 2) of LM35 to `ADC0` / `PF0` (Pin 61).
- [ ] **Character LCD (LM044L):**
  - Connect Data Pins `D0-D7` to `PA0-PA7` (Pins 51 to 44).
  - Connect `RS` to `PG0/WR` (Pin 33).
  - Connect `RW` to `PG1/RD` (Pin 34).
  - Connect `E` to `PG2/ALE` (Pin 43).
- [ ] **LEDs (D4, D3, D2, D1):**
  - Connect 4 Red LEDs with 330Ω series resistors (`R8`, `R7`, `R6`, `R5`).
  - Wire them to `PB4`, `PB5`, `PB6`, and `PB7` (Pins 14 to 17) respectively.
- [ ] **Buzzer:**
  - Connect `buzzer` control line to `PC0` (Pin 35).
  - Drive a 12V Buzzer (`BUZ1`) using a 2N6796 MOSFET (`Q1`) with a 100Ω gate resistor (`R13`).
- [ ] **Relays:**
  - Connect `RELAY1` control line to `PC1` (Pin 36) and `RELAY2` control line to `PC2` (Pin 37).
  - Drive two 12V Relays (`RL1`, `RL2`) using 2N2222 BJTs (`Q2`, `Q3`) with 1kΩ base resistors (`R14`, `R15`).
  - Ensure flyback diodes (`D5`, `D6`) are placed in parallel with the relay coils.
- [ ] **Bluetooth/Serial Module (COMPIM):**
  - Connect COMPIM `RXD` (Pin 2) and `TXD` (Pin 3) using labels `RX_UC` and `TX_UC` to the microcontroller's `PE0/RXD0` (Pin 2) and `PE1/TXD0` (Pin 3).
  - Set Physical Port (e.g., COM30), Physical Baud Rate to 9600, Virtual Baud Rate to 9600, Data Bits to 8, Parity to NONE, and Stop Bits to 1.
- [ ] **Virtual Terminals:**
  - Add Terminal 1 (`RECEIVE_DATA_FROM_BLUETOOTH`): Connect `RXD` to `RX_UC`.
  - Add Terminal 2 (`RECEIVE_DATA_FROM_MICROCONTROLLER`): Connect `RXD` to `TX_UC`.
  - Configure both terminals to 9600 Baud Rate, 8 Data Bits, No Parity, 1 Stop Bit, and Normal RX/TX Polarity.

## Phase 2: Software Configuration (CodeVision AVR)
- [ ] Set the microcontroller clock frequency to 1 MHz.
- [ ] Include the `<mega64a.h>` library (and `<delay.h>`, `<stdbool.h>` if needed).
- [ ] Configure Data Direction Registers (DDR):
  - PORTA: All Outputs (LCD Data).
  - PORTG (Pins 0, 1, 2): Outputs (LCD Control).
  - PORTB (Pins 4, 5, 6, 7): Outputs (LEDs).
  - PORTC (Pins 0, 1, 2): Outputs (Buzzer, Relay 1, Relay 2).
- [ ] Initialize the ADC module to read from channel 0 (`PF0`).
- [ ] Initialize USART0 for serial communication at 9600 baud rate.
- [ ] Initialize the Alphanumeric LCD module.
- [ ] **CRITICAL:** Ensure the final C code contains absolutely zero comments.

## Phase 3: Android Application Integration & Logic
- [ ] Install the "Arduino Bluetooth Control" application.
- [ ] **Sensor Reading:** Continuously read the LM35 temperature.
- [ ] **LCD Display:** Display the temperature and the exact state (ON/OFF) of all 4 LEDs, 2 Relays, and the Buzzer on the LCD.
- [ ] **Independent Control:** Map Switches 1 to 7 in the app's "Switches" page to independently toggle the 4 LEDs, 2 Relays, and Buzzer.
- [ ] **Simultaneous Control:** Map the app's "LED/Lamp" page to turn ON/OFF both relays at the exact same time.
- [ ] **Unit Toggle:** Map Switch 8 (sw8) to change the LCD temperature unit between Celsius and Fahrenheit.
- [ ] **Blink Mode:** Map Switch 9 (sw9) to trigger a blinking mode for all 4 LEDs.
- [ ] **Serial Transmission:** Transmit the measured temperature and the state of the two relays via serial every 500 milliseconds (to be viewed in the app's "Terminal" page).

## Phase 4: Documentation and Deliverables
- [ ] Take screenshots of the Proteus simulation at different operational stages.
- [ ] Name all screenshots strictly using the format `exercise_name.png`.
- [ ] Write a step-by-step typed report in Microsoft Word according to the provided tutorial structure.
- [ ] Validate that variables and functions are well-named, as grading emphasizes algorithm logic and base code quality.
- [ ] Prepare the final ZIP file containing: The Word report, the Proteus simulation file (`.pdsprj`), and the comment-free CodeVision source files (`.c`, `.prj`, etc.).