#include "debounce.h"

void update_button(uint32_t *button_history,GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
  *button_history = *button_history << 1;
  *button_history |= read_button(GPIOx,GPIO_Pin);
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
  if((*button_history & TUNING_MASK) == PRESSED_MASK)
  {
    pressed = 1;
    *button_history = 0xFFFFFFFFUL;
  }
  return pressed;
}

uint8_t is_button_released(uint32_t *button_history)
{
    uint8_t released = 0;
  if((*button_history & TUNING_MASK) == RELEASED_MASK)
  {
    released = 1;
    *button_history = 0x00000000UL;
  }
  return released;
}

uint8_t read_button(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
{
  return (HAL_GPIO_ReadPin(GPIOx, GPIO_Pin));
}

