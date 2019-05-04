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

  M5.Lcd.setTextColor(TFT_BLACK);
  int curser = 15;
  M5.Lcd.drawCentreString("88888", 160, 40, 7);
  drawButtons("<", WHITE, BLACK, "^", WHITE, BLACK , "SAVE", WHITE, GREEN);
}
