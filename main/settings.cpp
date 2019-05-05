#include "settings.h"

void settingsMenu() {
  enterCal();
}

// Sub menu to enter cal number
void enterCal() {
  M5.Lcd.fillScreen(WHITE);
  M5.Lcd.setTextColor(TFT_BLACK);
  int curser = 15;
  M5.Lcd.setCursor (10, curser);
  M5.Lcd.setTextFont(4);
  M5.Lcd.print("Enter Cal Number?");
  drawButtons("EXIT", WHITE, BLACK, "YES", WHITE, 2444 , "NO", WHITE, RED);
}

// sub menu to enter relay 1 trip point in feet
void setRelay1() {
  M5.Lcd.fillScreen(WHITE);
  M5.Lcd.setTextColor(TFT_BLACK);
  int curser = 15;
  M5.Lcd.setCursor (10, curser);
  M5.Lcd.setTextFont(4);
  M5.Lcd.print("Enter Relay 1 Distance?");
  drawButtons("EXIT", WHITE, BLACK, "YES", WHITE, 2444 , "NO", WHITE, RED);
}

// sub menu to enter relay 2 trip point in feet
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
   printValue(value);
  //int curser = 0;

  // int y = 90;
  // int w = 29;
  // int h = 6;
  // M5.Lcd.fillRect(0, y, 320, h, WHITE);
  // M5.Lcd.fillRect(81, y, w, h, GREEN);
  // M5.Lcd.fillRect(113, y, w, h, RED);
  // M5.Lcd.fillRect(145, y, w, h, BLUE);
  // M5.Lcd.fillRect(177, y, w, h, ORANGE);
  // M5.Lcd.fillRect(209, y, w, h, BLACK);
  drawButtons("", WHITE, BLACK, "", WHITE, BLACK , "SAVE", WHITE, GREEN);
  // left arrow
  M5.Lcd.fillTriangle(42,204,64,204,53,223,WHITE);
  // up arrow
  M5.Lcd.fillTriangle(149,223,171,223,160,204,WHITE);
  // while (!(M5.BtnC.wasPressed())) {
  //   if (M5.BtnB.wasPressed()) {
  //     value++;
  //     delay(100);
  //     printValue(value);
  //
  //   }
  //   if (M5.BtnB.pressedFor(2000)) {
  //
  //      value += 10;
  //      printValue(value);
  //
  //  }
  // }

}

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
