# LED Control Program for STM32 IDE

This STM32 program demonstrates how to control three individual LEDs using the led_handler library, which consists of two files (led_handler.h and led_handler.c). The program initializes three LEDs with different GPIO pins and on/off time intervals and continuously updates their status in the main loop.

## Table of Contents
- Setup
- Usage
- Functionality
- Libraries
- Notes
- Setup

## Hardware Connections
1.  Connect the three LEDs to the respective GPIO pins (PA10, PA11, and PA12, or other pins as specified in your code).
2.  Connect the other terminal of each LED to the common ground.


## Software Requirements
1.  This program is designed to run on an STM32 microcontroller.
2.  Ensure you have the STM32 IDE installed on your computer.

## Project Files
The program uses the following files:
| main.c  | led_handler.h | led_handler.c |
| ------------- | ------------- | ------------- |
|This is the main file that contains the setup() and loop() functions for the program.| This header file contains the declarations of the functions and structures for LED handling.| This source file contains the definitions and implementations of the functions declared in led_handler.h.|

## Usage
Setting Up the Project:
1.  Open the STM32 IDE.
2.  Create a new project or import the existing project files (main.c, led_handler.h, and led_handler.c).
3.  Make sure to configure the project settings according to your STM32 board model.

### Uploading the Code
1.  Connect your STM32 board to your computer using a USB cable.
2.  Compile the project and resolve any errors or warnings.
3.  Upload the program to the STM32 board.

### Running the Program
1.  Once the code is uploaded, the program will begin executing on the STM32 board.
2.  The program initializes three LEDs with different GPIO pins and on/off time intervals.
3.  The loop() function continuously updates the status of the LEDs by calling the runLed function for each LED.

## Functionality
### LED Initialization:
> [!TIP]
> The initLed function initializes an LED object by setting its GPIO pin and on/off intervals.
> In the setup() function, three LEDs are initialized with different configurations.

### LED Control
> [!TIP]
> The runLed function is called in the loop() function to control each LED's on/off state based on the current time.
> The function uses the LED's on/off intervals to determine whether the LED should be turned on or off.

### Libraries
led_handler Library:
> [!TIP]
> The code uses the led_handler library for controlling the LEDs.
> The library consists of the led_handler.h header file and the led_handler.c source file.

### Notes
> [!WARNING]
> Ensure the GPIO pins and hardware connections match those specified in the program.
> Adjust the on/off intervals in the setup() function if necessary.
> Monitor the serial console or use a debugger to track program execution and debug as needed.
