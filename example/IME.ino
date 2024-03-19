/*
#include "led_handler.h": Includes led_handler.h library.
#include "led_handler.c": Includes led_handler.c library.
*/
#include "led_handler.h"
#include "led_handler.c"

ledObj_t LED_1, LED_2, LED_3;

void setup() 
{
  /* Initializes the serial communication connection of the program. (Baud Rate) */
  Serial.begin(115200);
  /* Initializes three individual LEDs and determines the GPIO pin and on/off state times of each. */
  initLed(&LED_1, 12, 100, 150);
  initLed(&LED_2, 11, 500, 550);
  initLed(&LED_3, 10, 700, 750);
}

void loop() 
{
  /* Updates the status of the LEDs by calling the runLed function for each LED. */
  runLed(&LED_1, millis());
  runLed(&LED_2, millis());
  runLed(&LED_3, millis());
}
