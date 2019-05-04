#ifndef RELAY_H
#define RELAY_H

#include <Arduino.h>

class Relay {

private:
    double dist;
    bool isTripped = false;
public:
  // Default Constructor
  Relay();
  // Set the distance that the relay will trip
  void setDistance(int);
  // get the relay trip distance
  int getDistance(void);
  // Default Destructor
  ~Relay();
};

#endif // !RELAY_H
