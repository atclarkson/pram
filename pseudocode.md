START PROGRAM main()
SETUP()
  INSTANTIATE Distance
  INSTANTIATE M5Stack object
  INSTANTIATE all processes
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
      CALL setRelays()
    else
      // go back to setup run screen
      CALL selectionMenu(Setup, Run)
    end if
  else if Run
    CALL run()
  else
    //  Turn Unit off
    CALL M5Stack.PowerOFF()
  end if
STOP

// Shows welcome verbiage and startup info
welcomeScreen()
// This is really just making it pretty.
// Draw some stuff on the screen


// selections menu with 3 buttons up down select
//
selectionMenu(Process, [Process], [Process], [Process])
  draw sceen
  buttons move highlighted text
return selection

run()
setRelays()


<<OBJECTS>>

Distance
  - DEFINE calNumber

  + Calibration() // constructor
    Check EEPROM for calNumber
    setCalNumber()

  + setCalNumber(int)
    SET calNumber

  + driveCal()
    selectionMenu(Start)
