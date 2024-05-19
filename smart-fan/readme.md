# Smart Fan

Sweeps the shaft of a RC [servo motor](http://en.wikipedia.org/wiki/Servo_motor#RC_servos) back and forth across 180 degrees.

## Hardware Required

* Arduino Nano Board
* Servo Motor
* Digital Fan
* Jumper wires

## Circuit

Servo motors have three wires: power, ground, and signal. The power wire is typically red, and should be connected to the 5V pin on the Arduino board. The ground wire is typically black or brown and should be connected to a ground pin on the board. The signal pin is typically yellow, orange or white and should be connected to pin 2 on the board.

Digital fan has three wires, sometimes 2: power, ground, and signal. The power wire is typically red, and should be connected to the 5V pin on the Arduino board. The ground wire is typically black or brown and should be connected to a ground pin on the board. The signal wire which can be found on some fans is typically yellow, orange, or white and should be connected to pin 4 on the board. 
**Note**: in the case where the digital fan has only two wires, the power pin which is typically red will be connected to the digital pin 4 of the board while the ground pin will be connected to the ground pin of the arduino board. 

![](images/smart-fan-schematic.png)

(Images developed using Fritzing. For more circuit examples, see the [Fritzing project page](http://fritzing.org/projects/))

## Schematic

images/smart-fan-schematic.png

## See also

* watch video tutorial - https://youtube.com/smart-fan-tutorial
