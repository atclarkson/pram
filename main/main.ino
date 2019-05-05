/*    File: main.ino
 *    Name: Adam T Clarkson
 *    Date: May 4 2019
 *    Course: CSCI 201 Computer Science II
 *    Desc: Program for Stack M5 Dev Unit to control two relays (outputs) based on distance pulses input.
 */

#include <M5Stack.h>
#include <M5ez.h>
#include <ezTime.h>
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
bool inSetRelay1 = false;
bool inSetRelay2 = false;
bool inCal = false;
bool inEnterNum = false;

int value = 0;

Distance dx;
Relay r1;
Relay r2;


void setup() {
  // Open Serial Port
  Serial.begin(9600);
  // Start M5
  #include <themes/default.h>
  #include <themes/dark.h>
  ezt::setDebug(INFO);
  ez.begin();
//  M5.begin();
  mainMenu();

  r1.setDistance(100);
  r2.setDistance(200);

  // Set pin mode for output
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  // Bring the relay pins high by default
  digitalWrite(relayPin1, HIGH);
  digitalWrite(relayPin2, HIGH);
  // Setup Interupts
  // Interupt for speed signal
  attachInterrupt(digitalPinToInterrupt(interruptPin), countSpeed, HIGH);
  // Interupt for Buttons
  attachInterrupt(digitalPinToInterrupt(buttonA), buttonAPress, RISING);
  attachInterrupt(digitalPinToInterrupt(buttonB), buttonBPress, RISING);
  attachInterrupt(digitalPinToInterrupt(buttonC), buttonCPress, RISING);


}

void loop() {

}


 void buttonAPress() {
   if(inSettings || inCal || inSetRelay1 || inSetRelay2) {
     // settings menu button behavior
     mainMenu();
     inSettings = false;
     inCal = false;
     inSetRelay1 = false;
     inSetRelay2 = false;
   } else if (inEnterNum) {

   } else {
     settingsMenu();
     inSettings = true;
     inCal = true;
   }
 }

 void buttonBPress() {
   if(inSettings || inCal) {
     // Enternum calls a routine to get a number from user and outputs number as int
     value = dx.getCalNumber();
     dx.setCalNumber(enterNum(value));
     inSettings = false;
     inCal = false;
     inEnterNum = true;
   } else if (inSetRelay1) {
     value = r1.getDistance();
     r1.setDistance(enterNum(value));
     inSetRelay1 = false;
     inEnterNum = true;
   } else if (inSetRelay2) {
     value = r2.getDistance();
     r2.setDistance(enterNum(value));
     inSetRelay2 = false;
     inEnterNum = true;
   } else if (inEnterNum) {

   } else {

   }
 }
 void buttonCPress() {
   if(inSettings || inCal) {
     // settings menu button behavior
     inSetRelay1 = true;
     setRelay1();
     inCal = false;
     inSettings = false;
   } else if (inSetRelay1) {
     inSetRelay2 = true;
     setRelay2();
     inSetRelay1 = false;
   } else if (inSetRelay2) {
     inCal = true;
     enterCal();
     inSetRelay2 = false;
   } else if (inEnterNum) {

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
  M5.Lcd.fillRect(0, 0, 320, 180, WHITE);
  dx.reset();
  tripRelays();
  DrawPulses(dx);
}

void tripRelays(){
     if (dx.getCounts() >= dx.feetToCounts(r1.getDistance())) {
    digitalWrite(relayPin1, LOW);
    drawRelayTrip(1,true);
  } else {
    digitalWrite(relayPin1, HIGH);
    drawRelayTrip(1,false);
  }
    if (dx.getCounts() > dx.feetToCounts(r2.getDistance())) {
    digitalWrite(relayPin2, LOW);
    drawRelayTrip(2,true);
  } else {
    digitalWrite(relayPin2, HIGH);
    drawRelayTrip(2,false);
  }
}

void mainMenu() {
  // Setup the sceen
  M5.Lcd.fillScreen(WHITE);
  M5.Lcd.setTextColor(TFT_BLACK);
  // Draw button images
  M5.Lcd.fillRoundRect(223,194,85,39,4,RED);
  M5.Lcd.drawCentreString("Reset", 265, 205, 4); // Draw text centre at position 120, 30 using font 4
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.fillRoundRect(11,194,85,39,4,BLACK);
  M5.Lcd.drawCentreString("Setup", 53, 205, 4); // Draw text centre at position 120, 30 using font 4
}
