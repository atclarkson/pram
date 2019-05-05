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
bool inRelay1 = false;
bool inRelay2 = false;
bool inCal = false;
bool inEnterNum = false;
bool inSetCal = false;
bool inSetRelay1 = false;
bool inSetRelay2 = false;

int value = 0;

// Instantiate the objects for Distance and Relays
Distance dx;
Relay r1;
Relay r2;

// Setup Program
void setup() {
  // Open Serial Port
  Serial.begin(9600);
  // Start M5
  M5.begin();

  // Initiate the main menu
  mainMenu();

  // Set Defaults.  These should be fille from eeprom at later date
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

//  Main Program loop
void loop() {
  // Poll Buttons and other inputs
  M5.update();

  // Check what mode we're in and set value accoringly
  if(inSetCal) {
    value = dx.getCalNumber();
  } else if (inSetRelay1) {
    value = r1.getDistance();
  } else if (inSetRelay2) {
    value = r2.getDistance();
  }

  // if in the calibration set up mode listen for button presses
  if (inSetCal) {
    // If button B is press increase cal number by 1
    if (M5.BtnB.wasPressed()) {
      value++;
      value = value > 99999 ? 0 : value;
      delay(100);
      dx.setCalNumber(value);
      printValue(value);
    }
    // If button B is held increase cal number by 10
    if (M5.BtnB.pressedFor(2000)) {
      while (M5.BtnB.read()) {
        value += 10;
        value = value > 99999 ? 0 : value;
        dx.setCalNumber(value);
        printValue(value);
      }
    }
    // If button A is pressed decrease cal number by 1
    if (M5.BtnA.wasPressed()) {
      value--;
      value = value < 0 ? 99999 : value;
      delay(100);
      dx.setCalNumber(value);
      printValue(value);
    }
    // If button A is held decrease cal number by 10
    if (M5.BtnA.pressedFor(2000)) {
      while (M5.BtnA.read()) {
        value -= 10;
        value = value < 0 ? 99999 : value;
        dx.setCalNumber(value);
        printValue(value);
      }
    }
  }

  // if in the relay 1 set up mode listen for button presses
  if (inSetRelay1) {
    if (M5.BtnB.wasPressed()) {
      value++;
      value = value > 300 ? 0 : value;
      delay(100);
      r1.setDistance(value);
      printValue(value);
    }
    if (M5.BtnB.pressedFor(2000)) {
      while (M5.BtnB.read()) {
        delay(10);
        value += 1;
        value = value > 300 ? 0 : value;
        r1.setDistance(value);
        printValue(value);
      }
    }
    if (M5.BtnA.wasPressed()) {
      value--;
      value = value < 0 ? 300 : value;
      delay(100);
      r1.setDistance(value);
      printValue(value);
    }
    if (M5.BtnA.pressedFor(2000)) {
      while (M5.BtnA.read()) {
        delay(10);
        value -= 1;
        value = value < 0 ? 300 : value;
        r1.setDistance(value);
        printValue(value);
      }
    }
  }

  // if in the relay 2 set up mode listen for button presses
  if (inSetRelay2) {
    if (M5.BtnB.wasPressed()) {
      value++;
      value = value > 300 ? 0 : value;
      delay(100);
      r2.setDistance(value);
      printValue(value);
    }
    if (M5.BtnB.pressedFor(2000)) {
      while (M5.BtnB.read()) {
        delay(10);
        value += 1;
        value = value > 300 ? 0 : value;
        r2.setDistance(value);
        printValue(value);
      }
    }
    if (M5.BtnA.wasPressed()) {
      value--;
      value = value < 0 ? 300 : value;
      delay(100);
      r2.setDistance(value);
      printValue(value);
    }
    if (M5.BtnA.pressedFor(2000)) {
      while (M5.BtnA.read()) {
        delay(10);
        value -= 1;
        value = value < 0 ? 300 : value;
        r2.setDistance(value);
        printValue(value);
      }
    }
  }
}  // !loop()

/**
 * ISR for Button A
 */
 void buttonAPress() {
   if(inSettings || inCal || inRelay1 || inRelay2) {
     // settings menu button behavior
     mainMenu();
     inSettings = false;
     inCal = false;
     inRelay1 = false;
     inRelay2 = false;
   } else if (inSetCal || inSetRelay1 || inSetRelay2) {
     // Do nothing if in one of the settings routines that uses main loop for user input.

   } else {
     settingsMenu();
     inSettings = true;
     inCal = true;
   }
 }

 /**
  * ISR for Button B
  */
 void buttonBPress() {
   if(inSettings || inCal) {
     // Enternum calls a routine to get a number from user and outputs number as int
     value = dx.getCalNumber();
     enterNum(value);
     inSettings = false;
     inCal = false;
     inSetCal = true;
   } else if (inRelay1) {
     value = r1.getDistance();
     enterNum(value);
     inRelay1 = false;
     inEnterNum = true;
     inSetRelay1 = true;
   } else if (inRelay2) {
     value = r2.getDistance();
     enterNum(value);
     inRelay2 = false;
     inEnterNum = true;
     inSetRelay2 = true;
   } else if (inSetCal || inSetRelay1 || inSetRelay2) {
     // Do nothing if in one of the settings routines that uses main loop for user input.
   } else {
      // Do nothing if in main.  there is no button here.
   }
 }

 /**
  * ISR for Button C
  */
 void buttonCPress() {
   if(inSettings || inCal) {
     // settings menu button behavior
     inRelay1 = true;
     setRelay1();
     inCal = false;
     inSettings = false;
   } else if (inRelay1) {
     inRelay2 = true;
     setRelay2();
     inRelay1 = false;
   } else if (inRelay2) {
     inCal = true;
     enterCal();
     inRelay2 = false;
   } else if (inSetCal) {
     inSetCal = false;
     inCal = true;
     enterCal();
   } else if (inSetRelay1) {
     inSetRelay1 = false;
     inRelay1 = true;
     setRelay1();
   } else if (inSetRelay2) {
     inSetRelay2 = false;
     inRelay2 = true;
     setRelay2();
   } else {
     resetCounter();
   }
 }

/**
 * This runs the distance incrementor and displays the distance on screen
 */
void countSpeed() {
  // if in any settings mode "disable" pulses.  I hate this bool method I did here.
  if (!(inSettings || inCal || inSetCal || inSetRelay1 || inSetRelay2 || inRelay1 || inRelay2)) {
  dx++;
  tripRelays();
  DrawPulses(dx);
}
}

/**
 * reset the distance pulled back to 0.
 */
void resetCounter() {
  M5.Lcd.fillRect(0, 0, 320, 180, WHITE);   // wipe upper half of screen
  dx.reset();                               // reset distance
  tripRelays();                             // run trip relays to reset relays and display
  DrawPulses(dx);                           // draw the pules and distance back to screen
}

/**
 * This will send signal to the relay and update sceen
 */
void tripRelays(){
  // Check if the counts are greater than the preset counts for relay 1
  if (dx.getCounts() >= dx.feetToCounts(r1.getDistance())) { // need to convert distance to counts before comparison
    digitalWrite(relayPin1, LOW);
    drawRelayTrip(1,true);
  } else {
    digitalWrite(relayPin1, HIGH);
    drawRelayTrip(1,false);
  }
  // Check if the counts are greater than the preset counts for relay 2
  if (dx.getCounts() > dx.feetToCounts(r2.getDistance())) {  // need to convert distance to counts before comparison
    digitalWrite(relayPin2, LOW);
    drawRelayTrip(2,true);
  } else {
    digitalWrite(relayPin2, HIGH);
    drawRelayTrip(2,false);
  }
}

/**
 * Displays the main menu
 */
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
