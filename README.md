# PRAM - Pulling Relay Module
## Author
Adam Clarkson - *Initial work*

## The Problem
- Sled operators have no way of reliably tripping relays at predetermined distances as they travel down the track.  
- Many times there will need to be multiple relays that need to be tripped at different distances.
- Many times these distances will change between classes of pulls.
  - **example:** Antique tractors may have no trips, Pickup trucks may need a trip at 100ft and 200ft and Super Mods may need a trip at 50ft, 100ft, 200ft and 250ft.
- Currently many operators have rigged up pully systems and limit switches that will trip relays mechanically as they traverse the track.
  - These are prone to failure and are not easily changed between classes.

## Overview
Using a hardware device composed of a microprocessor, an LCD screen, buttons, input lines and output lines I will provide a solution to all the problems listed above.

## Requirements
- user must be able to input a predetermined calibration number (number of pulses in a constant distance).
- user must be able to set 2 relay trip points
- user will get feedback via LCD display of distance and relay trips

## Extras and future enhancements
Some things to keep in mind as this project is being built there may be some things that can be added easily or at the very least some of the ground work can be layes now.
- ability to change Units (ft.00, ft/in, meters)
- Graph the pull at the end
- log all graphs to a database or CSV for later data manipulation


## Hardware
- [M5Stack](https://m5stack.com/)
  - "A Modular 5x5cm Stackable ESP32 Development Kit"
- Speed input from existing [radar](https://www.agritronixcorp.com/dickey-john_rvsiii_radar_gun.html?category_id=30) or [gear tooth sensor](https://www.agritronixcorp.com/geartooth_speed_sensor_kit.html?category_id=30) in form of square wave pulses
- 4 Output lines to relays

## Acknowledgments
