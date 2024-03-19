/*
#include "led_handler.h": Includes the led_handler.h library.
*/
#include "led_handler.h"

/*
*@brief initLed: Function used to initialize the object of the LED.
*@param[LED_X]: LED object structre.
*@param[pin]: Specifies the GPIO pin number to which the LED is connected.
*@param[on_state_int]: The duration of the LED's on state is in milliseconds.
*@param[off_state_int]: The duration of the LED's off state is in milliseconds.
*@return none
*/
void initLed(ledObj_t * LED_X, uint8_t pin, uint32_t on_state_int, uint32_t off_state_int)
{
  /* Allows a specific GPIO pin to be assigned to the led_pin property of a LED object. */
  LED_X->led_pin = pin;
  /* Determines the output mode on the GPIO pin to which a LED is connected. */
  pinMode(LED_X->led_pin, OUTPUT);
  /* Assigns the time interval that determines the duration of an LED's on state to the LED object. */
  LED_X->on_state_interval = on_state_int;
  /* Assigns the time interval that determines the duration of an LED's off state to the LED object. */
  LED_X->off_state_interval = off_state_int;
  /* Sets the state of an LED object as the initial state. */
  LED_X->state = LED_STARTUP_STATE;
  /* Resets the previous time of an LED object. */
  LED_X->prev_millis = 0;
}

/*
*@brief runLed: Contains the definition of a function that manages the operation of LEDs.
*@param[LED_X]: LED object structre
*@param[millis]: Current tick in millisecond.
*@return none
*/
void runLed(ledObj_t* LED_X, uint32_t millis)
{
  /* It checks the status of an LED object and takes action accordingly. */
  switch(LED_X->state)
  {
    /* Represents the off state of an LED. */
    case OFF_STATE:
    /* Controls an action to be taken after a certain period of time in the LED's off state. This condition is satisfied when the LED off-state time reaches a certain value. */
      if(millis - LED_X->prev_millis >= LED_X->off_state_interval)
      {
        /* Replaces the previous timestamp of the LED with the current timestamp.*/
        LED_X->prev_millis = millis;
        /* Turns off the LED on a specific GPIO pin. */
        digitalWrite(LED_X->led_pin, LOW);
        /* Sets the state of an LED to "OFF". */
        LED_X->state = OFF_STATE;
      }
      break;
    /* Represents the on state of an LED. */
    case ON_STATE:
    /* Controls an action to be taken after a certain period of time in the LED's on state. This condition is satisfied when the LED on-state time reaches a certain value. */
      if(millis - LED_X->prev_millis >= LED_X->on_state_interval)
      {
        /* Replaces the previous timestamp of the LED with the current timestamp. */
        LED_X->prev_millis = millis;
        /* Turns on the LED on a specific GPIO pin. */
        digitalWrite(LED_X->led_pin, HIGH);
        /*  Sets the state of an LED to "ON". */
        LED_X->state = ON_STATE;
      }
      break;
  }
}
