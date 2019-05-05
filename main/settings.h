#ifndef SETTINGS_H
#define SETTINGS_H

#include <Arduino.h>
#include <M5Stack.h>
#include "draw.h"


/**
 * Initiate Setting Menu
 */
void settingsMenu();

/**
 * Sub menu to enter cal number
 */
void enterCal();

/**
 * sub menu to enter relay 1 trip point in feet
 */
void setRelay1();

/**
 * sub menu to enter relay 2 trip point in feet
 */
void setRelay2();

/**
 * Initiate the user prompt for data entry
 * @param  value takes in a value of the current settings
 * @return       Returns and int value of new modified settings
 */
int enterNum(int);

/**
 * Prints the value with leading zeros to always take up 5 digits.
 * @param value value to be printed
 */
void printValue(int value);

#endif // !SETTINGS_H
