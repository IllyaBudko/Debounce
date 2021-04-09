#ifndef _DEBOUNCE_H_
#define _DEBOUNCE_H_

#include <stdint.h>
#include "stm32f4xx_hal.h"

void update_button(uint32_t *button_history);

uint8_t is_button_up(uint32_t *button_history);
uint8_t is_button_down(uint32_t *button_history);
uint8_t is_button_pressed(uint32_t *button_history);
uint8_t is_button_released(uint32_t *button_history);

uint32_t read_button(void);

#endif /*_DEBOUNCE_H_*/

