// Program obliczający temperature oleju z czujnika NTC gdzie potem wyświetla tą wartośc na ekranie OLED.
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

//These  values are in the datasheet
#define RT0 47000  // Ω
#define B 3800     //  K
//--------------------------------------


#define VCC 5  //Supply  voltage
// #define R 9000  //R=10KΩ
#define R 316671  //R=10KΩ

//Variables
float RT, VR, ln, TX, T0, VRT, Rt;

float c1 = 0.9420172326e-03, c2 = 1.981060906e-04, c3 = 2.174732559e-07;

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Address 0x3C for 128x64 display
  display.clearDisplay();  // Clear the display buffer
  digitalWrite(4, HIGH);
  T0 = 25 + 273.15;  //Temperature  T0 from datasheet, conversion from Celsius to kelvin

}

void loop() {

VRT = analogRead(A0); //Acquisition analog value of VRT
VRT = (5.00 / 1023.00) * VRT; //Conversion to voltage
VR = VCC - VRT;
RT = VRT * R / VR; //Resistance of RT

Rt = (R * ((1) / ((VCC / VR) - 1)));
ln = log(RT);

TX = (1.0 / (c1 + c2 * ln + c3 * ln * ln * ln)); //Temperature from thermistor

TX = TX - 273.15;

display.clearDisplay(); // Clear the display buffer

//FLASHING START
if (TX >= 100) {
// If temperature is 100 degrees or higher, set the background and letters to flash
if (millis() % 1000 < 500) {
display.setTextColor(SSD1306_BLACK);
display.fillScreen(SSD1306_WHITE);
} else {
display.setTextColor(SSD1306_WHITE);
display.fillScreen(SSD1306_BLACK);
}//FLASHING STOP
} else {
// If temperature is less than 100 degrees, set the background to black and letters to white
display.fillScreen(SSD1306_BLACK);
display.setTextColor(SSD1306_WHITE);
}

// Set font and position for the value
display.setTextSize(2);
display.setCursor(15,5);
display.println("Oil temp");
display.setTextSize(3);
display.setCursor(50,30);
display.println(round(TX)); // Display the rounded value
Serial.println(TX);

display.display(); // Update the display
delay(300); // Delay for 0,3 second
}












