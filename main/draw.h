#ifndef DRAW_H
#define DRAW_H

#include <Arduino.h>
#include <M5Stack.h>
#include "Distance.h"

void drawButtons(String a_text, uint16_t a_textcolor,uint16_t a_buttoncolor, String b_text, uint16_t b_textcolor,uint16_t b_buttoncolor,String c_text, uint16_t c_textcolor,uint16_t c_buttoncolor);
void drawRelayTrip(int relayNum, bool isTripped);
void DrawPulses(Distance &dx);
#endif // !DRAW_H
