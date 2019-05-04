#include "settings.h"

void settingsMenu() {
  M5.Lcd.fillScreen(WHITE);
  M5.Lcd.setTextColor(TFT_BLACK);
  int curser = 15;
  bool inSettings = true;

  enterCal();





  drawButtons("EXIT", WHITE, BLACK, "YES", WHITE, GREEN, "NO", WHITE, RED);
}

void enterCal() {
  M5.Lcd.fillScreen(WHITE);
  M5.Lcd.setTextColor(TFT_BLACK);
  int curser = 15;
    M5.Lcd.setCursor (10, curser);
    M5.Lcd.setTextFont(4);
    M5.Lcd.print("Enter Cal Number?");
}

void setRelay1() {
  M5.Lcd.fillScreen(WHITE);
  M5.Lcd.setTextColor(TFT_BLACK);
  int curser = 15;
  M5.Lcd.setCursor (10, curser);
  M5.Lcd.setTextFont(4);
  M5.Lcd.print("Enter Relay 1 Distance?");
}

void setRelay2() {
  M5.Lcd.fillScreen(WHITE);
  M5.Lcd.setTextColor(TFT_BLACK);
  int curser = 15;
  M5.Lcd.setCursor (10, curser);
  M5.Lcd.setTextFont(4);
  M5.Lcd.print("Enter Relay 2 Distance?");
}
