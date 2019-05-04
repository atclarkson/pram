#ifndef DISTANCE_H
#define DISTANCE_H

#include <iostream>
#include <sstream>
#include <iomanip>

class Distance {

private:
  Units unit;
  int counts = 0;
  int calNumber = 5000;
  int calFactor = 300;  //  Means that there are calNumber per calFactor
public:
  // Default Constructor
  Distance();
  // Set the Cal Number This is the number of pulses in 300'
  void setCalNumber(int);
  // Reset the counts back to zero
  void reset(void);
  // Get the number of counts
  int getCounts(void);
  // increment the counts
  void incrementCounts(void);
  // calculate the distance in feet
  float countsToFeet(void);
  // Distance to String
  String dxToString(void);

  // Default Destructor
  ~Distance();
  Distance& operator++();      // Prefix increment
  Distance operator++(int);     // Postfix increment operator.
};



#endif // !DISTANCE_H
