#include "settings.h"

void settingsMenu() {
  enterCal();
}

void enterCal() {
  M5.Lcd.fillScreen(WHITE);
  M5.Lcd.setTextColor(TFT_BLACK);
  int curser = 15;
  M5.Lcd.setCursor (10, curser);
  M5.Lcd.setTextFont(4);
  M5.Lcd.print("Enter Cal Number?");
  drawButtons("EXIT", WHITE, BLACK, "YES", WHITE, 2444 , "NO", WHITE, RED);
}

void setRelay1() {
  M5.Lcd.fillScreen(WHITE);
  M5.Lcd.setTextColor(TFT_BLACK);
  int curser = 15;
  M5.Lcd.setCursor (10, curser);
  M5.Lcd.setTextFont(4);
  M5.Lcd.print("Enter Relay 1 Distance?");
  drawButtons("EXIT", WHITE, BLACK, "YES", WHITE, 2444 , "NO", WHITE, RED);
}

void setRelay2() {
  M5.Lcd.fillScreen(WHITE);
  M5.Lcd.setTextColor(TFT_BLACK);
  int curser = 15;
  M5.Lcd.setCursor (10, curser);
  M5.Lcd.setTextFont(4);
  M5.Lcd.print("Enter Relay 2 Distance?");
  drawButtons("EXIT", WHITE, BLACK, "YES", WHITE, 2444 , "NO", WHITE, RED);
}

int enterNum(int value) {
  String printValue;
  if (value > 9999) {
    printValue = value;
  } else if (value > 999) {
    printValue =  String("0" + value);
  } else if (value > 99) {
    printValue =  String("00" + value);
  } else if (value > 9) {
    printValue =  String("000" + value);
  } else {
    printValue =  String("0000" + value);
  }
  M5.Lcd.setTextColor(TFT_BLACK);
  int curser = 15;
  M5.Lcd.drawCentreString(printValue, 160, 40, 7);
  drawButtons("<", WHITE, BLACK, "^", WHITE, BLACK , "SAVE", WHITE, GREEN);
}
