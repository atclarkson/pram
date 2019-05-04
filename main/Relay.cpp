#include "Relay.h"

// Default Constructor
Relay::Relay() {

}
// Set the distance that the relay will trip
void Relay::setDistance(int d) {
  dist = d;
}
// get the relay trip distance
int Relay::getDistance(void) {
  return dist;
}
// Default Destructor
Relay::~Relay() {

}
