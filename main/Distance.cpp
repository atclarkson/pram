#include "Distance.h"

// Default Constructor
Distance::Distance() {
  reset();
}
// Set the Cal Number This is the number of pulses in 300'
void Distance::setCalNumber(int cal) {
  calNumber = cal;
}
// Reset the counts back to zero
void Distance::reset(void) {
  counts = 0;
}
// Get the number of counts
int Distance::getCounts(void) {
  return counts;
}
// Get the number of counts
int Distance::getCalNumber(void){
  return calNumber;
}
// increment the counts
void Distance::incrementCounts(void) {
  counts++;
}
// calculate the distance in feet
double Distance::countsToFeet(void) {
  double temp = (double)calFactor/(double)calNumber * (double)counts;
  return temp;
}
// convert feet to counts
int Distance::feetToCounts(double f) {
  return f * ((double)calNumber/(double)calFactor);
}
// Distance to String
String Distance::dxToFeetString(void) {
  char feet[30];
  char str_temp[10];
  /* 4 is mininum width, 2 is precision; float value is copied onto str_temp*/
  dtostrf(countsToFeet(), 6, 2, str_temp);
  sprintf(feet,"%s", str_temp);
  return feet;
}

// Default Destructor
Distance::~Distance() {

}

// Define prefix increment operator.
Distance& Distance::operator++()
{
   incrementCounts();
   return *this;
}

// Define postfix increment operator.
Distance Distance::operator++(int)
{
   Distance temp = *this;
   ++*this;
   return temp;
}
