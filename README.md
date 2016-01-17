# Project-ITT
Games &amp; Interaction - ITT - Arduino Controlled NeoPixel Matrix w/ FastLED library

Hi there,

I this guide I will explain you how to setup a NeoPixel Matrix with an Arduino board(Yùn). 
We will use various components and software to show-off the capabilities! I have added comments in the Arduino Sketch file to make it understandable. Make sure you download the 'sketches' zip-file down below.

Things you need:

    - Any Arduino Controller ( I have used the Yùn)
    - (Micro) USB-cable
    - TMP36GZ Temperature Sensor
    - Panel Mount Rotary Potentiometer Breadboard Friendly
    - breadboard
    - Capacitor 1000μF
    - Set of breadboard jumper wires
    - WS2812 LED RGB 16*16 NeoPixel Matrix 5V (or something similar) // for reference: github.com/FastLED/FastLED/wiki/Overview
    - Lots of Patience

INSTRUCTIONS (all the links are down below):

- First you have to make sure that you are using the RIGHT parts for this build.

- You have to install the Arduino IDE and the necessary libraries for the NeoPixel Matrix.

- Make sure that you have enough storage on your Arduino or add a SD-card for extra storage // tutorial and instructions below

- Download the diagram below and make sure you connect everything exactly as pictured. I recommend you to read the manuals first to get a basic understanding.

- When you have everything setup correctly, open the sketch file 'Matrix_Test' and change the variables to match your Arduino board. Upload the file to your Arduino. The Matrix should be lit right now. If not, check the errors.

- Now you can move on to the last step. Head to the Solderlabs website and download the zip-file for your specific Matrix model. If you scroll-down in the download section you will find more options. (http://www.solderlab.de/index.php/downloads/category/4-glediator)

- Now comes the tricky part. You have to install the latest version of JDK (Java Development Kit) and the RXTX library. Make sure you copy the files to the according paths (instructions are in the zip-file). Take note that you probably have multiple java versions installed on your computer. Just copy them to newest version. If you don't know which one it is, just click windows start > search: 'CMD' and type the following line 'java -version' and hit enter.
- Now open the sketch 'ArduinoYun_Glediator_TempSensor_PotMeter'.
  Change the following lines to match your hardware:
  'define NUM_LEDS 256 // total LEDS' --
  'define DATA_PIN 6 // data pin of the Matrix' --
  'define CHIPSET WS2812 // your Matrix model'
- Verify the code and upload it to your Arduino. For the Arduino part you are officially done!
- Open up the Glediator Interface. Make sure you go to options first in the top menu-bar and change the Matrix Size and Output Options to match yours (Output Mode must be 'Glediator Protocol'). If you dont know the correct 'Pixel Order'  or 'Color Order', dont worry! It will work anyways but it might not display correctly. You can go trough these settings a couple times afterwards if everything worked out. Check the image down below for reference. 
- Now click on 'Serial Open' in the Output Options window to start the connection between Glediator and the Arduino.
- The Matrix should be displaying the same visuals as the one in the middle column of the Glediator Interface. Just a quick tip: Glediator works like a VJ-program. You have the left and right column to set the visuals you want to mix, and the middle column is the output where you can play with the transistion or blend of the left and right column.
- The PotentioMeter is programmed in way that it responds relatively to the amount of pixels and turning them off in the chain they are hooked up. Twist the knob to see the result. Beware of the LED-snake :)
- We have also added a temperature sensor. It is programmed with a base temperature of 20 degrees and value above will change the brightness of the pixels (up to 25 degrees for the max. brightness).

EXTRA: CUSTOM LOOPS
- Now it's time to upload your own animated GIF's. For the best result, create something in the same resolution of your Matrix (e.g. 16 x 16 pixels) with 256 colors as output. That will give you the most accurate output.

LINKS IN CHRONOLOGICAL ORDER:

First of all I Would suggest you to read the article in the link below and the 'Suggested Reading topics' you will find in the top section as well, to get a basic understanding of circuits. It will make the process easier and much more fun!
https://learn.sparkfun.com/tutorials/voltage-dividers

Manuals and information for things used in this build:

    Arduino Yun - https://www.arduino.cc/en/Guide/ArduinoYun
    Resisistors - https://learn.adafruit.com/adafruit-arduino-lesson-2-leds/resistors
    Capacitors - http://electronics.howstuffworks.com/capacitor.htm
    NeoPixels/NeoMatrix - https://learn.adafruit.com/downloads/pdf/adafruit-neopixel-uberguide.pdf
    RGB Pixels - https://github.com/FastLED/FastLED/wiki/Pixel-reference

Arduino IDE Software:
https://www.arduino.cc/en/Main/Software

Adafruits NeoPixel and NeoMatrix libaries:
https://learn.adafruit.com/adafruit-neopixel-uberguide/neomatrix-library

FastLED library:
https://github.com/FastLED/FastLED/releases

Glediator Software:
http://www.solderlab.de/index.php/downloads/category/4-glediator

RXTX for Java library:
http://fizzed.com/oss/rxtx-for-java

(Optional) Arduino Yun DiskSpace Expander:
https://www.arduino.cc/en/Tutorial/ExpandingYunDiskSpace

<p>How to use the Glediator Interface:</p>

![alt tag](https://imagizer.imageshack.us/v2/889x500q90/907/I8w2vZ.jpg)

If you really want to get into Arduino I would suggest you to buy 'Exploring Arduino' by Jeremy Blum. I have used it throughout the process for guidance and information. It is comprehensive, but also plain English and that is something I don´t see very often. Especially for people like me who jumped in with zero understanding of electronic circuits. It is worth your money!

If you have any questions or feedback, feel free to contact me.
Good luck with your project!

// Yassine Raddahi
