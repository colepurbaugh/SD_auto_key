# What you need
* Teensy 3.6
* fat32 micro SD card
* three buttons
* three leds

# Directions
* create a text file in the root directory of SD card named "config.txt"
* each keyboard key has a coresponding number
* "+" symbol for key press
* "-" symbol for key release
* "~" symbol for delay
* place each command one by one in the config.txt file seperated by returns
* "e" symbol for the end of the program

# Example
* +1      //press the "a" key
* ~1000   //wait 1 second
* -1      //release the "a" key
* e       //end the program
