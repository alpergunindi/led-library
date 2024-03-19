/*
#ifndef LED_HANDLER_H: Header guard prevents the file from being included repeatedly; If the LED_HANDLER_H symbol is not defined, the code is processed.
#include <Arduino.h>: Includes Arduino library.
#define OFF_STATE 0: Represents the off state of the LED.
#define ON_STATE  1: Represents the on state of the LED.
#define LED_STARTUP_STATE OFF_STATE: Initial state of the LED, it starts off.
*/
#ifndef LED_HANDLER_H
#define LED_HANDLER_H
#include <Arduino.h>
#define OFF_STATE 0
#define ON_STATE  1

#define LED_STARTUP_STATE OFF_STATE
/*
This function creates a structure that defines an LED object.
This structure contains the state of an LED, previous time information,
the pin number of the LED, the times the LED will remain on and off.
*/
typedef struct
{
  uint8_t state;
  uint32_t prev_millis;
  uint8_t led_pin;
  uint32_t on_state_interval;
  uint32_t off_state_interval;
} ledObj_t;

/*
*@brief initLed: Function used to initialize the initial state of the LED.
*@param[LED_X]: LED object structre.
*@param[pin]: Specifies the GPIO pin number to which the LED is connected.
*@param[on_state_int]: The duration of the LED's on state is in milliseconds.
*@param[off_state_int]: The duration of the LED's off state is in milliseconds.
*@param[millis]:Determines how long the LED will remain active.
*@return none
*/
void initLed(ledObj_t * LED_X, uint8_t pin, uint32_t on_state_int, uint32_t off_state_int);

/*
*@brief runLed: Contains the definition of a function that manages the operation of LEDs.
*@param[LED_X]: LED object structre..
*@param[millis]:Determines how long the LED will remain active.
*/
void runLed(ledObj_t* LED_X, uint32_t millis);

#endif
