START PROGRAM main()
SETUP()
  INSTANTIATE Distance
  INSTANTIATE M5Stack object
  INSTANTIATE Setup settings
  SET INTERUPT on Pulse
    Distance.incrementDistance()
  CALL welcomeScreen()
  WAIT 1500ms
  // show menu to setup or run
LOOP()
  CALL selectionMenu(Setup, Run)
  if Setup
    // show menu to calibrate or set relays
    CALL selectionMenu(Calibrate, SetRelays)
    if Calibrate
      // Show the menu to allow user to enter cal or drive cal
      CALL selectionMenu(ManCal, DriveCal)
        if ManCal
          // user can manually enter the cal number if they know it.
          // example get cal number from M3 Sled Monitor or Factory defined
          // number from DJ Radar gun
          USER INPUT Distance.setCalNumber()
        else if DriveCal
          // call the method to drive off the calibration
          CALL Distance.driveCal()
        else
          // Go back to previous screen
          CALL selectionMenu(Calibrate, SetRelays)
        end if
    else if SetRelays
      USER INPUT selet Preset to modify (DEFINE i)
      USER INPUT relay number to set (DEFINE j)
      USER INPUT relayDist (DEFINE relayDist)
      CALL settings.presets.at(i).setRelay(j, relayDist)
    else
      // go back to setup run screen
      CALL selectionMenu(Setup, Run)
    end if
  else if Run
    CALL pull()
  else
    //  Turn Unit off
    CALL M5Stack.PowerOFF()
  end if
STOP

// Shows welcome verbiage and startup info
welcomeScreen()
// This is really just making it pretty.
// Draw some stuff on the screen
return


// selections menu with 3 buttons up down select
//
selectionMenu(Process, [Process], [Process], [Process])
  // draw sceen
  // buttons move highlighted text
return selection

// A function that handles that actual pulling
// Once the user "stages" the sled the unit will enter pull()
pull()
  RESET the distance counter to 0
  LOAD setlected relay presets
  WAIT until pulses come in.
  DISPLAY converted speed and distance on screeen
  // check if the distance is greater or equal to trip point and not tripped and that it is not 0
  for loop through preset relays, iterator is i
    if distance >= preset[i] and NOT preset[i].isTripped and preset[i]
      FLASH RED on screen
      DISPLAY "RELAY " + i on screen
      SET preset[i].pin = HIGH
  if distance.getPulseTimer > 3000  // if time between pulses is greater than 3 seconds
    // Pull is Over
    Display on sceen each relay and if it isTripped
    reset all relays back to default
return
