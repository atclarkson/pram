#include "settings.h"

void settingsMenu() {
  M5.Lcd.fillScreen(WHITE);
  M5.Lcd.setTextColor(TFT_BLACK);
  drawButtons("1", WHITE, GREEN, "2", BLACK, YELLOW, "3", WHITE, RED);
}
