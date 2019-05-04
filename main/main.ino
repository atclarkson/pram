/*    File: main.ino
 *    Name: Adam T Clarkson
 *    Date: May 4 2019
 *    Course: CSCI 201 Computer Science II
 *    Desc: Program for Stack M5 Dev Unit to control two relays (outputs) based on distance pulses input.
 */

#include <M5Stack.h>
#include "Distance.h"

// Global Variables - Pin Locations
const byte relayPin1 = 5;
const byte relayPin2 = 13;
const byte interruptPin = 17;  // Distance Pulses
const byte buttonA = 39;
const byte buttonB = 38;
const byte buttonC = 37;
const byte speaker = 25;
Distance dx;

void setup() {
  // Open Serial Port
  Serial.begin(9600);
  // Start M5
  M5.begin();
  // Setup the sceen
  M5.Lcd.fillScreen(TFT_BLACK);
  M5.Lcd.fillScreen(WHITE);
  M5.Lcd.setTextColor(TFT_BLACK);
  // Draw button images
  M5.Lcd.fillRoundRect(223,194,85,39,4,RED);
  M5.Lcd.drawCentreString("Reset", 265, 205, 4); // Draw text centre at position 120, 30 using font 4

  // Set pin mode for output
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  // Bring the relay pins high by default
  digitalWrite(relayPin1, HIGH);
  digitalWrite(relayPin2, HIGH);
  // Setup Interupts
  // Interupt for speed signal
  attachInterrupt(digitalPinToInterrupt(interruptPin), countSpeed, RISING);
  // Interupt for Button C
  attachInterrupt(digitalPinToInterrupt(37), resetCounter, CHANGE);
}

void loop() {

}


void countSpeed() {
  dx++;
  tripRelays();
  DrawPulses();
}


void resetCounter() {
  dx.reset();
  tripRelays();
  DrawPulses();
}

void tripRelays(){
     if (dx.getCounts() > 1000) {
    digitalWrite(relayPin1, LOW);
    drawRelayTrip(1,true);
  } else {
    digitalWrite(relayPin1, HIGH);
    drawRelayTrip(1,false);
  }
    if (dx.getCounts() > 2000) {
    digitalWrite(relayPin2, LOW);
    drawRelayTrip(2,true);
  } else {
    digitalWrite(relayPin2, HIGH);
    drawRelayTrip(2,false);
  }
}

void drawRelayTrip(int relayNum, bool isTripped) {
  M5.Lcd.setCursor (60, (relayNum + 1) * 25 + 25);
  M5.Lcd.setTextFont(4);        // Select font 0 which is the Adafruit font
  M5.Lcd.setTextColor(TFT_BLACK, WHITE); // Do not plot the background colour
  String relayStatus = "";
  if (isTripped) {
    relayStatus =  String("Relay #" + String(relayNum) + " tripped.");
  } else {
    relayStatus =  String("                                                                         ");
  }
  M5.Lcd.print(relayStatus); // Draw text centre at position 120, 30 using font 4
}

void DrawPulses() {
   M5.Lcd.setCursor (60, 15);
   M5.Lcd.setTextFont(4);        // Select font 0 which is the Adafruit font
  // The new larger fonts do not need to use the .setCursor call, coords are embedded
  M5.Lcd.setTextColor(TFT_BLACK, WHITE); // Do not plot the background colour
  String pulses =  String("# Pulses: " + (dx.getCounts() == 0 ? "0         " : String(dx.getCounts())));
  M5.Lcd.print(pulses); // Draw text centre at position 120, 30 using font 4
  M5.Lcd.setCursor (60, 40);
  M5.Lcd.print(dx.dxToFeetString().c_str());
}
