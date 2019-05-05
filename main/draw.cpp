#include "draw.h"


/**
 * Will Draw icons above buttons on screen
 * @param a_text        Button A Text
 * @param a_textcolor   Button A Text Color
 * @param a_buttoncolor Button A BG Color
 * @param b_text        Button B Text
 * @param b_textcolor   Button B Text Color
 * @param b_buttoncolor Button B BG Color
 * @param c_text        Button C Text
 * @param c_textcolor   Button C Text Color
 * @param c_buttoncolor Button C BG Color
 */
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

/**
 * Draw the relay trip status on the screeen
 * @param relayNum  relay you want to draw
 * @param isTripped true if the relay has tripped
 */
void drawRelayTrip(int relayNum, bool isTripped) {
  M5.Lcd.setCursor (60, 120+20 * relayNum);
  M5.Lcd.setTextFont(2);
  M5.Lcd.setTextColor(TFT_BLACK, WHITE);
  String relayStatus = "";
  if (isTripped) {
    relayStatus =  String("Relay #" + String(relayNum) + " tripped.");
  } else {
    relayStatus =  String("                                                                         ");
  }
  M5.Lcd.print(relayStatus);
}

/**
 * Draw the pulses and feet to screen
 * @param dx the distance object
 */
void DrawPulses(Distance &dx) {
  // This string concatinates text with the number of pulses.
  String pulses =  String("# Pulses: " + (dx.getCounts() == 0 ? "0         " : String(dx.getCounts())));
  M5.Lcd.drawCentreString(pulses, 160, 15, 4); // Draw text centre at position 160, 15 using font 4
  M5.Lcd.drawCentreString(dx.dxToFeetString().c_str(), 160, 40, 7);
  M5.Lcd.drawCentreString("Feet", 160, 40+55, 4);
}
