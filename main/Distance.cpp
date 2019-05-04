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
