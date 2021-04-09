#ifndef _DEBOUNCE_H_
#define _DEBOUNCE_H_

#include <stdint.h>
#include "stm32f4xx_hal.h"

/**
  *Library implementation of button debounce based on 
  *Embed with Elliot: Debounce your Noisy Buttons, Part II
  *https://hackaday.com/2015/12/10/embed-with-elliot-debounce-your-noisy-buttons-part-ii/
  *
  *Read there for tuning advise
  */

/**
  * @brief  Mask for tuning timing in is_button_pressed() function.
  *         Less leading zeros give the button more time to stabilize.
  *         The trade off is that the less leading zeros there are
  *         the more time it takes to detect the press but gives 
  *         a more accurate reading
  */
#define PRESSED_MASK  0x0000FFFFUL

/**
  * @brief  Mask for tuning timing in is_button_released() function.
  *         Less trailing zeros give the button more time to stabilize.
  *         The trade off is that the less trailing zeros there are
  *         the more time it takes to detect the press but gives 
  *         a more accurate reading
  */
#define RELEASED_MASK 0xFFFF0000UL

/**
  * @brief  Mask for button history comparison in is_button_pressed() function
  *         and is_button_released(). zero bits are dont care bits
  */
#define TUNING_MASK 0xF000000FUL



/**
  * @brief  Updates button history periodically
  * @param  uint32_t *button_history, pointer to variable where button history is stored
  * @retval None
  */
void update_button(uint32_t *button_history);

/**
  * @brief  Checks upward position of button
  *         If the button is not pressed and there is a pull up resistor on the button pin
  *         then the button is in the UP position
  * @param  pointer to variable where button history is stored
  * @retval 1(true), 0(false)
  */
uint8_t is_button_up(uint32_t *button_history);

/**
  * @brief  Checks downward position of button
  *         If the button is pressed and there is a pull up resistor on the button pin
  *         then the button is in the DOWN position
  * @param  pointer to variable where button history is stored
  * @retval 1(true), 0(false)
  */
uint8_t is_button_down(uint32_t *button_history);

/**
  * @brief  Checks button press transition according to PRESSED_MASK
  * @param  pointer to variable where button history is stored
  * @retval 1(true), 0(false)
  */
uint8_t is_button_pressed(uint32_t *button_history);

/**
  * @brief  Checks button release transition according to RELEASED_MASK
  * @param  pointer to variable where button history is stored
  * @retval 1(true), 0(false)
  */
uint8_t is_button_released(uint32_t *button_history);


/**
  * @brief  Reads button state
  *         Weak function, needs to be implemented in user code
  *         for use with other mcu, needs to return state of button
  * @param  None
  * @retval 1(pin high state), 0(pin low state)
  */
__weak uint8_t read_button(void);

#endif /*_DEBOUNCE_H_*/

