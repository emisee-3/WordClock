# WordClock

This repository contains the code to set the time and run the word clock in the Wenkstraße and in the Kranichsteiner Straße.

To set the realtime clock run the script RTC_Set.ino on the Arduino. 
TODO: find out why it is off by a few seconds

To run the clocks after the time of the RTC is set select the correct file for the clock. Make sure to keep the folder structure to include all necessary dependencies.
For debugging, set 'debugging' to 1, this enables the serial connection. Before the clock runs unconnected to a computer, this needs to be deactivated. Without a seial port connection, a programm which opens the seial connection stops working.
If the timing of the clock is off it can be adjusted with 'secDelay'. This delays the lookup of the time to make sure that the minutes can advance.
The lookup periode can be adjusted by setting 'lookupPeriode'. It always needs to be multiples of 60. Options that make sense are 60 and 300.

If there is a time offset make sure the RTC battery is still working. In the Wenkstraße the power supply connection to the Arduino is a bit shaky which can result in the time being stuck. Change the cable position to ensure stable power supply.
