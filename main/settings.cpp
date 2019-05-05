#include "settings.h"

/**
 * Initiate Setting Menu
 */
void settingsMenu() {
  enterCal();
}

/**
 * Sub menu to enter cal number
 */
void enterCal() {
  M5.Lcd.fillScreen(WHITE);
  M5.Lcd.setTextColor(TFT_BLACK);
  int curser = 15;
  M5.Lcd.setCursor (10, curser);
  M5.Lcd.setTextFont(4);
  M5.Lcd.print("Enter Cal Number?");
  drawButtons("EXIT", WHITE, BLACK, "YES", WHITE, 2444 , "NO", WHITE, RED);
}

/**
 * sub menu to enter relay 1 trip point in feet
 */
void setRelay1() {
  M5.Lcd.fillScreen(WHITE);
  M5.Lcd.setTextColor(TFT_BLACK);
  int curser = 15;
  M5.Lcd.setCursor (10, curser);
  M5.Lcd.setTextFont(4);
  M5.Lcd.print("Enter Relay 1 Distance?");
  drawButtons("EXIT", WHITE, BLACK, "YES", WHITE, 2444 , "NO", WHITE, RED);
}

/**
 * sub menu to enter relay 2 trip point in feet
 */
void setRelay2() {
  M5.Lcd.fillScreen(WHITE);
  M5.Lcd.setTextColor(TFT_BLACK);
  int curser = 15;
  M5.Lcd.setCursor (10, curser);
  M5.Lcd.setTextFont(4);
  M5.Lcd.print("Enter Relay 2 Distance?");
  drawButtons("EXIT", WHITE, BLACK, "YES", WHITE, 2444 , "NO", WHITE, RED);
}

/**
 * Initiate the user prompt for data entry
 * @param  value takes in a value of the current settings
 * @return       Returns and int value of new modified settings
 */
int enterNum(int value) {
   printValue(value);
  drawButtons("", WHITE, BLACK, "", WHITE, BLACK , "SAVE", WHITE, GREEN);
  // down arrow
  M5.Lcd.fillTriangle(42,204,64,204,53,223,WHITE);
  // up arrow
  M5.Lcd.fillTriangle(149,223,171,223,160,204,WHITE);

}

/**
 * Prints the value with leading zeros to always take up 5 digits.
 * @param value value to be printed
 */
void printValue(int value) {
  String printValue = "";
  if (value > 9999) {
    printValue = value;
  } else if (value > 999) {
    printValue =  String("0" + (String)value);
  } else if (value > 99) {
    printValue =  String("00" + (String)value);
  } else if (value > 9) {
    printValue =  String("000" + (String)value);
  } else {
    printValue =  String("0000" + (String)value);
  }
  M5.Lcd.setTextColor(TFT_BLACK, WHITE);

  M5.Lcd.drawCentreString(printValue, 160, 40, 7);
}
