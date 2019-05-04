/*    File: main.ino
 *    Name: Adam T Clarkson
 *    Date: May 4 2019
 *    Course: CSCI 201 Computer Science II
 *    Desc: Program for Stack M5 Dev Unit to control two relays (outputs) based on distance pulses input.
 */

#include <M5Stack.h>
#include "Distance.h"
#include "Relay.h"
#include "settings.h"
#include "draw.h"

// Global Variables - Pin Locations
const byte relayPin1 = 5;
const byte relayPin2 = 13;
const byte interruptPin = 17;  // Distance Pulses
const byte buttonA = 39;
const byte buttonB = 38;
const byte buttonC = 37;
const byte speaker = 25;
bool inSettings =  false;
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
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.fillRoundRect(11,194,85,39,4,BLACK);
  M5.Lcd.drawCentreString("Setup", 53, 205, 4); // Draw text centre at position 120, 30 using font 4
  // Set pin mode for output
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  // Bring the relay pins high by default
  digitalWrite(relayPin1, HIGH);
  digitalWrite(relayPin2, HIGH);
  // Setup Interupts
  // Interupt for speed signal
  attachInterrupt(digitalPinToInterrupt(interruptPin), countSpeed, RISING);
  // Interupt for Buttons
  attachInterrupt(digitalPinToInterrupt(buttonA), buttonAPress, CHANGE);
  attachInterrupt(digitalPinToInterrupt(buttonB), buttonBPress, CHANGE);
  attachInterrupt(digitalPinToInterrupt(buttonC), buttonCPress, CHANGE);

}

void loop() {

}

 void buttonAPress() {
   if(inSettings) {
     // settings menu button behavior

   } else {
     settingsMenu();
     inSettings = true;
   }
 }
 void buttonBPress() {
   if(inSettings) {
     // settings menu button behavior

   } else {

   }
 }
 void buttonCPress() {
   if(inSettings) {
     // settings menu button behavior

   } else {
     resetCounter();
   }
 }
void countSpeed() {
  dx++;
  tripRelays();
  DrawPulses(dx);
}


void resetCounter() {
  dx.reset();
  tripRelays();
  DrawPulses(dx);
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
