//Purple code = 6D1DC9  0,170,240 (GRB)
//Orange code = FF9100 51,255,0  (GRB)

#include <Adafruit_DotStar.h>
#include <Adafruit_DotStar.h>
// Because conditional #includes don't work w/Arduino sketches...
#include <SPI.h>         // COMMENT OUT THIS LINE FOR GEMMA OR TRINKET
#define NUMPIXELS 144 // Number of LEDs in strip

// Here's how to control the LEDs from any two pins:
#define DATAPIN    11
#define CLOCKPIN   13
// Variables for DIO Pins
#define PIN_A     6    //On or Off
#define PIN_B     5    //On or Off
//Color & length codes
#define PURPLE    0,175,255
#define ORANGE    51,255,0
#define WHITE    255,255,255
#define GREEN     255,0,0
#define head 0
#define height1 -48
#define height2 -96
#define height3 -144



Adafruit_DotStar strip = Adafruit_DotStar(
  NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);
// The last parameter is optional -- this is the color data order of the
// DotStar strip, which has changed over time in different production runs.
// Your code just uses R,G,B colors, the library then reassigns as needed.
// Default is DOTSTAR_BRG, so change this if you have an earlier strip.

void setup() {
  pinMode(PIN_A, INPUT);
  pinMode(PIN_B, INPUT);
  strip.begin(); // Initialize pins for output
  strip.show();  // Turn all LEDs off ASAP
  strip.setPixelColor(head, WHITE); // 'On' pixel at head
  strip.setPixelColor(height3, 0);     // 'Off' pixel at tail
  strip.show();                     // Refresh strip      
  // 'On' color (starts WHITE)
}



void loop() {
  //Blue alliance & arm heights
  if(PIN_A == HIGH && PIN_B == HIGH ) //Purple a.k.a Blue Alliance
  strip.setPixelColor(head, PURPLE); // 'On' pixel at head
  strip.setPixelColor(height3, 0);     // 'Off' pixel at tail
  strip.show();                     // Refresh strip
  delay(0.1);                 // Pause 
  
  if(PIN_A == HIGH && PIN_B == LOW) //Orange a.k.a Red Alliance
  strip.setPixelColor(head, ORANGE); // 'On' pixel at head
  strip.setPixelColor(height3, 0);     // 'Off' pixel at tail
  strip.show();                     // Refresh strip
  delay(0.1);                 // Pause 
  
  //Climbing transmission
  if(PIN_A == LOW && PIN_B == LOW ) //Neutral
  strip.setPixelColor(head, WHITE); // 'On' pixel at head
  strip.setPixelColor(height3, 0);     // 'Off' pixel at tail
  strip.show();                     // Refresh strip
  delay(281.25);                 // Pause 
  strip.setPixelColor(head, WHITE); // 'On' pixel at head
  strip.setPixelColor(height3, 0);     // 'Off' pixel at tail
  strip.show();                     // Refresh strip
  delay(281.25);                 // Pause 
  strip.setPixelColor(head, WHITE); // 'On' pixel at head
  strip.setPixelColor(height3, 0);     // 'Off' pixel at tail
  strip.show();                     // Refresh strip
  delay(281.25);                 // Pause 
  strip.setPixelColor(head, WHITE); // 'On' pixel at head
  strip.setPixelColor(height3, 0);     // 'Off' pixel at tail
  strip.show();                     // Refresh strip
  delay(281.25);                 // Pause 
  strip.setPixelColor(head, WHITE); // 'On' pixel at head
  strip.setPixelColor(height3, 0);     // 'Off' pixel at tail
  strip.show();                     // Refresh strip
  delay(281.25);                 // Pause 
  //Gripper is closed
  
  if(PIN_A == LOW && PIN_B == HIGH) //Closed
  strip.setPixelColor(head, WHITE); // 'On' pixel at head
  strip.setPixelColor(height3, 0);     // 'Off' pixel at tail
  strip.show();                     // Refresh strip
  delay(2250);                 // Pause 
  
}
