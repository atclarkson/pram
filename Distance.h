#ifndef DISTANCE_H
#define DISTANCE_H

class Distance {
public:
  // Units Enumeration
  enum  Units {
    feetDec,
    feetInch,
    Meters
  };
private:
  Units unit;
  int counts = 0;
  int calNumber;
public:
  // Default Constructor
  Distance();
  // Set the Cal Number This is the number of pulses in 300'
  void setCalNumber(int);
  // Reset the counts back to zero
  void resetCounts(void);
  // Get the number of counts
  int getCounts(void);
  // increment the counts
  void incrementCounts(void);
  // Default Destructor
  ~Distance();
}

friend Distance& operator++( Distance& );       // Prefix increment

#endif // !DISTANCE_H
