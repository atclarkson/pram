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
// increment the counts
void Distance::incrementCounts(void) {
  counts++;
}
// calculate the distance in feet
float countsToFeet(void) {
  return calNumber / calFactor * counts;
}
// Distance to String
String dxToString(void);

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
