#include "draw.h"

void drawButtons(String a_text, uint16_t a_textcolor,uint16_t a_buttoncolor, String b_text, uint16_t b_textcolor,uint16_t b_buttoncolor,String c_text, uint16_t c_textcolor,uint16_t c_buttoncolor) {
  // Draw button images
  M5.Lcd.setTextColor(a_textcolor);
  M5.Lcd.fillRoundRect(11,194,85,39,4,a_buttoncolor);
  M5.Lcd.drawCentreString(a_text, 53, 205, 4); // Draw text centre at position 120, 30 using font 4
  M5.Lcd.setTextColor(b_textcolor);
  M5.Lcd.fillRoundRect(117,194,85,39,4,b_buttoncolor);
  M5.Lcd.drawCentreString(b_text, 159, 205, 4); // Draw text centre at position 120, 30 using font 4
  M5.Lcd.setTextColor(c_textcolor);
  M5.Lcd.fillRoundRect(223,194,85,39,4,c_buttoncolor);
  M5.Lcd.drawCentreString(c_text, 265, 205, 4); // Draw text centre at position 120, 30 using font 4

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

void DrawPulses(Distance &dx) {
   M5.Lcd.setCursor (60, 15);
   M5.Lcd.setTextFont(4);        // Select font 0 which is the Adafruit font
  // The new larger fonts do not need to use the .setCursor call, coords are embedded
  M5.Lcd.setTextColor(TFT_BLACK, WHITE); // Do not plot the background colour
  String pulses =  String("# Pulses: " + (dx.getCounts() == 0 ? "0         " : String(dx.getCounts())));
  M5.Lcd.print(pulses); // Draw text centre at position 120, 30 using font 4
  M5.Lcd.setCursor (60, 40);
  M5.Lcd.print(dx.dxToFeetString().c_str());
  M5.Lcd.setCursor (60, 40+25);
  String calcP =  String("# Pulses: " + (dx.feetToCounts(dx.countsToFeet()) == 0 ? "0         " : String(dx.feetToCounts(dx.countsToFeet()))));
  M5.Lcd.print(calcP); // Draw text centre at position 120, 30 using font 4
}
