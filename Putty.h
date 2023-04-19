/*
 * Putty.h
 *
 * putty is the program used to display the tiva UART0 output to pc
 */

#ifndef PUTTY_H_
#define PUTTY_H_

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "inc/tm4c123gh6pm.h"

void printChar(uint8_t c);
void printString(char * str);



#endif /* PUTTY_H_ */
