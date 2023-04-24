/*
 * init.h
 *
 *  Created on: 19 Apr 2023
 *      Author: eslam
 */

#ifndef INIT_H_
#define INIT_H_

void UART0_init(void);           // Function to initialise UART0 and GPIO for PA0 and PA1
void UART5_init(void);           // Function to initialise UART5 and GPIO for PE4 and PE5
void setCLkFreq(uint8_t f);      // Function to set a needed clock frequency
GPIO_PF_init(void);              // Function to initialise PF

#endif /* INIT_H_ */
