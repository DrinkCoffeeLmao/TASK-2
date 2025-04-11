# TASK-2
## Aim
To control a two-wheel drive mechanism using 'W','A','S','D' keys
## Materials
- `2 DC motors(not servo)`
- `Arduino Uno R3`
- `Connecting wires`
- `Motor Drive`
- `10V Battery`
## Thought process
The basic key mappings are universal. I was given 2 DC motors with a batter  and motor drive. I should map the keys in such a way that if it's 
- **forward**, **both** the motors should turn **anti-clockwise**
- vice versa for **reverse**
- **left** motor alone should spin to make a **right** turn
- **Right** motor alone should spin to make a **left** turn
and the keys should be mapped accordingly

## Circuit connections
|Device|Pins|
|:-----|:---|
|MD10C(Motor Drive)|DIR>13   PWM>~11|
|                  |GND>GND A&B>Motor|
|:-----------------|:----------------|
 The power pins were connected to the respective terminals of the batter. The connections were made sure so that the terminals don't touch each other to and melt the arduino board or burst the batter ;)

## Code explanation
- `left` variable denotes the left motor connected to a wheel, whereas `right` variable denotes the right motor.
- `left1` denotes the pin connected to control the direction of rotation of **left** the wheel, `left2` refers to the pin that controls the speed of the **left** motor.
- `right1` denotes the pin connected to control the direction of rotation of **right** the wheel, `left2` refers to the pin that controls the speed of the **right** motor.
- `check` variable stores the Serial.read() value and checks it with the if conditions put forth in the below code.
### void setup
pinModes have been mapped appropriately and set baud rate to 9600
###void loop
- Storing `Serial.read()` value in `check`. Serial.read() gets the keyboard input directly and processes it.
- The `if` condition statements have been implemented to enable power supply and direction to the respective motors. It is generally advisable to put all the statements inside a `if(Serial.available()>0)`, but since it's a small code, de-buggin is relatively easier.
- The `digitalWrite()` sets the **direction** of spin for the motor. `HIGH` denotes anti-clockwise spine and `LOW` denotes clockwise spin.
- The `analogWrite()` sets the **RPM** of the motor. The speed ranges from 0 to 255.
- `delay()` is implemented because the code will be executed so fast that the motor practically does not spin, so a delay of 0.5 seconds is implemented.

*Forward*- Both motors are set to spin anti-clockwise at high speed.
*Backward*- Both motors are set to spin clockwise at high speed.
*Rightwards*- **Left** motors is set to spin anti-clockwise at high speed
*Leftwards*- **Right** motor is set to spin anti-clockwise at high speed
*No input*- No motor spins, i.e, stops.

