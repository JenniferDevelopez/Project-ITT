#include <FastLED.h>
#include <SPI.h>
#include <SD.h>

#define NUM_LEDS 256
#define DATA_PIN 6
#define CHIPSET WS2812
#define CMD_NEW_DATA 1
#define BAUD_RATE 9600

CRGB leds[NUM_LEDS];

int sensorPin = 0;    /// -- Sensor

int potPin = 1;       /// -- Potmeter
int potVal = 0;

int fsrPin = 5;      /// -- FSR
int fsrVal = 0;

////////////////////////////////////////////////////////// SETUP ///
///////////////////////////////////////////////////////////////////

void setup() {
  
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(BAUD_RATE);

  pinMode(potPin, INPUT);
  pinMode(fsrPin, INPUT);
}

// Glediator takes Serial input
int serialGlediator () {
  while (!Serial.available()) {}
  return Serial.read();
}


////////////////////////////////////////////////////////// LOOP ///
//////////////////////////////////////////////////////////////////

void loop() {

  int potVal = analogRead(potPin);
  int sensVal = analogRead(sensorPin);
  int numLedsToLight = map(potVal, 0, 692, 0, NUM_LEDS);

  // initialize NeoPixels Communication with GLEDiator Interface
  while (serialGlediator () != CMD_NEW_DATA) {}
  Serial.readBytes((char*)leds, NUM_LEDS*3);
 
  // this loop turns the NeoPixels black in relation to the Potmeter delta.
  for(int led = 0; led < numLedsToLight; led++) { 
      leds[led] = CRGB::Black;
  }

  // FastLED Magic!
  FastLED.show();

  // converting sensor value to voltage (5v)
  // change the variables accordingly the voltage you use
  float voltage = sensVal * 5.0;
  voltage /= 1024.0;
  
  // calculate temperature
  //converting from 10 mv per degree with 500 mV offset
  float temperature = (voltage - 0.5) * 100;

  // Brightness controller
  // Base temperatur is set to 20 with a max output of 250 (at 25.1 degrees)
  float rangeTemp = (temperature-20)*50;
  if (rangeTemp >255){ rangeTemp = 255;}
  FastLED.setBrightness( rangeTemp );
  
/*
  // Serial Monitor Output [ ... ]
  Serial.print(temperature); 
  Serial.println(" degrees C");
  
  Serial.print("Potmeter read: ");
  Serial.println(potVal);
  
  Serial.println("\n");
  delay(300);
  */
}


