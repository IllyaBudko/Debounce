#include "debounce.h"

#define PRESSED_MASK  0x000000FFUL
#define RELEASED_MASK 0xFF000000UL

void update_button(uint32_t *button_history)
{
  *button_history = *button_history << 1;
  *button_history |= read_button();
}

uint8_t is_button_up(uint32_t *button_history)
{
  return (*button_history == 0xFFFFFFFFUL);
}

uint8_t is_button_down(uint32_t *button_history)
{
  return (*button_history == 0x00000000UL);
}

uint8_t is_button_pressed(uint32_t *button_history)
{
  uint8_t pressed = 0;
  if((*button_history & PRESSED_MASK) == 0x0000000FUL)
  {
    pressed = 1;
    *button_history = 0xFFFFFFFFUL;
  }
  return pressed;
}

uint8_t is_button_released(uint32_t *button_history)
{
    uint8_t released = 0;
  if((*button_history & PRESSED_MASK) == 0xF0000000UL)
  {
    released = 1;
    *button_history = 0x00000000UL;
  }
  return released;
}

uint32_t read_button(void)
{
  return (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_9));
}

