# BatteryMINDer
Enable BatteryMINDer to charge individual batteries by switching between them in sequence

## Purpose
I have a single [BatteryMINDer(r)](http://www.batteryminders.com/batteryminder-plus-charger-model-12117-12v-1-33-amp-charger-maintainer-desulfator/) and 4 lead acid batteries. It's not recommended to connect the batteries in parallel if they are not all the same capacity. The idea is to allow the charger to switch between batteries in sequence. Because this requires physical contacts (i.e. relays) the time between switching should be frequent enough not to let the battery sulfate, but infrequent enough to not wear out the relays as they do have a limit to the number of times they switch.

## Solution
Using an Arduino or clone and 4 relays I have the ability to control the relays and create a custom program based upon my needs.
 
## Approach
Use ideas, principles, and concepts from DevOps develop a minimum viable product to meet my needs and as I learn (via feedback) add features as necessary.

## Adafruit Trinket Differences
1. To program the Adafruit Trinket there are some special considerations with respect to [USB Pins](https://learn.adafruit.com/introducing-trinket/pinouts#usb-pins).
`GPIO #3` - this is connected to PB3 on the Attiny85. This pin is used for USB programming, but its also an analog input known as Analog A3 
This pin has a 1.5K pullup to 3.3V built into the Trinket, for USB comm so it may be difficult to use for analog or digital input.
If you have anything connected to `GPIO #3` like a relay in this case, you cannot program the Trinket. Disconnect the relay before programming.
2. There are some differences to program the Trinket; specifically [how to enter the bootloader](https://learn.adafruit.com/introducing-trinket/starting-the-bootloader).

### Trinket Programming Reminders
1. Disconnect `GPIO #3` before programming.
2. In the Arduino IDE set Tools > Board: Adafruit Trinket 8MHz
3. In the Arduino IDE set Tools > Programmer: USBTinyISP
4. Press the reset button on the Trinket before compile/upload sequence
