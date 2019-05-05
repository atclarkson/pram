#ifndef SETTINGS_H
#define SETTINGS_H

#include <Arduino.h>
#include <M5Stack.h>
#include "draw.h"

void settingsMenu();
void enterCal();
void setRelay1();
void setRelay2();
int enterNum(int);
void printValue(int value);

#endif // !SETTINGS_H
