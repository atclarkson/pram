#ifndef DRAW_H
#define DRAW_H

#include <Arduino.h>
#include <M5Stack.h>
#include "Distance.h"

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
void drawButtons(String a_text, uint16_t a_textcolor,uint16_t a_buttoncolor, String b_text, uint16_t b_textcolor,uint16_t b_buttoncolor,String c_text, uint16_t c_textcolor,uint16_t c_buttoncolor);

/**
 * Draw the relay trip status on the screeen
 * @param relayNum  relay you want to draw
 * @param isTripped true if the relay has tripped
 */
void drawRelayTrip(int relayNum, bool isTripped);

/**
 * Draw the pulses and feet to screen
 * @param dx the distance object
 */
void DrawPulses(Distance &dx);
#endif // !DRAW_H
