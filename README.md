## Implementation of button debounce code according to Embed With Elliot: Debounce Your Noisy Buttons, Part II

If you are interested in how the debounce code works, read more at:
https://hackaday.com/2015/12/10/embed-with-elliot-debounce-your-noisy-buttons-part-ii/

This implementaton provides the following functionalities:

__void update_button(uint32_t *button_history);__

>*Function that needs to be periodically called to update button history, either
in a polling loop or in a timer interrupt*

__uint8_t is_button_up(uint32_t *button_history);__

>*Function that check for stable up position of button*

__uint8_t is_button_down(uint32_t *button_history);__

>*Function that checks for stable down position of button*

__uint8_t is_button_pressed(uint32_t *button_history);__

>*Function that checks for a pressed button transition*

__uint8_t is_button_released(uint32_t *button_history);__

>*Function that check for a released button transition*

____weak uint8_t read_button(void);__

>*Weak function that reads the button pin state, it is 
used in update_button(uint32_t *button_history)*