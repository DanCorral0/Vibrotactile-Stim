# Vibrotactile-Stim

HARDWARE DEPENDENCIES - For our current implementation the following parts were used:

- Arduino UNO Rev3 (MicroController): https://store-usa.arduino.cc/products/arduino-uno-rev3/?gclid=CjwKCAiAksyNBhAPEiwAlDBeLFOKCqU3ffst-6lXjEdiCEpbE7KmqxMRILMXjiv_MBeOx_-FpIC3hBoCul0QAvD_BwE
- 10mm Linear Resonant Actuator (175 Hz Motor): https://catalogue.precisionmicrodrives.com/product/c10-100-10mm-linear-resonant-actuator-4mm-type
- Adafruit DRV2605L Haptic Controller Breakout (Motor Driver): https://learn.adafruit.com/adafruit-drv2605-haptic-controller-breakout
- A301 FORCE SENSOR 9.5MM DIA.4500N (Load Cell): https://www.digikey.com/en/products/detail/tekscan/A301-100/14565594?utm_adgroup=Force%20Sensors&utm_source=google&utm_medium=cpc&utm_campaign=Shopping_Product_Sensors%2C%20Transducers_NEW&utm_term=&utm_content=Force%20Sensors&gclid=CjwKCAjwh5qLBhALEiwAioodswO0Z4EjX9qRsTAx7xNJu2ZoTiaDnjn_LTEzMNw25-Tr4x5A2aPNhBoCQZ8QAvD_BwE
- LCD Screen 16x2: https://www.adafruit.com/product/1447
- Potentiometer: https://www.mouser.com/ProductDetail/Adafruit/356?qs=GURawfaeGuDs98j2KTyaqg%3D%3D&mgh=1&gclid=CjwKCAiAksyNBhAPEiwAlDBeLOGlZO1N_6oRQz8-6ZS3EH0TxHD81sQQKu0_0-L-vvgUxm1hbeb7yRoCUx0QAvD_BwE
- Finger Straightener: https://www.walmart.com/ip/American-Heritage-Industries-Finger-Straightener-Corrector-Mallet-Finger-Rheumatoid-Arthritis-Joint-Issues-Pressing-Device-Pain-Easy-Splint/256659831
- 10k Resistor
- Sodering Equipment
- BNC Connector

SOFTWARE DEPENDENCIES - For our current implementation the following programs were used:

- Arduino IDE 1.8.16: https://www.arduino.cc/en/software
- Adafruit DRV2605 Library: https://www.arduino.cc/reference/en/libraries/adafruit-drv2605-library/
- LiquidCrystal Library: https://www.arduino.cc/en/Reference/LiquidCrystal
- Wire Library: https://www.arduino.cc/en/reference/wire

INSTRUCTIONAL TUTORIAL VIDEO - https://youtu.be/4vuaaAn_hQ4

LIGHTNING VIDEO - https://www.youtube.com/watch?v=8L6QtHLk0Bw

STEPS TO REPLICATE WORK -

1. Include all Arduino Libraries as listed above
2. Download Arduino Code needed to control device
3. Put attatched Motor and Cell in Finger Splint and lodge in the Finger Straightener
4. Plug Device into laptop and run

PSYCHOMETRIC TEST STEPS -

1. Run PsychometricTestCode.ino
2. Place participant's pointer finger in finger clamp
3. Tighten to desired pressure
4. Ensure minimal noise and visual cues to not skew data
5. Open the serial monitor to view vibration level
6. Reupload Code to board
7. Participant is to let researcher know when they first feel a buzz
8. Researcher records at what level buzz was felt
9. Repeat 10 times for each level (light, medium, tight)

NEUROMETRIC TEST STEPS:

NOTE: If you want to collect/view Neurometric (brain) results, you will need an external machine capable of using a BNC connector as well as the necessary equipment to read brain functionality, and of course the proper supervision
