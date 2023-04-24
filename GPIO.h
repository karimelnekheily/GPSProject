#ifndef GPIO_H_
#define GPIO_H_

bool sw1_input(void); //reads the input from switch 1 (PF4) and returns 1 if the switch is not pushed and 0 if it is pushed.
bool sw2_input(void); //reads the input from switch 2 (PF0) and returns 1 if the switch is not pushed and 0 if it is pushed.
void RGP_output(unsigned char data);//This function outputs the given data to the RGB LEDs. It resets the RGB LEDs and then turns on the needed LEDs based on the given data.
#endif
