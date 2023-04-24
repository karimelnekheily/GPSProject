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
void GPIO_PF_init(void);         //Enables the clock for Port F and waits for it to be ready. Unlocks Port F and disables the analog function for pins PF0 to PF4


#endif /* INIT_H_ */
