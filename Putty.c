#include "Putty.h"



/**
 * @brief Transmits a single character using UART0.
 *
 * This function transmits a single character using the UART0 peripheral.
 * The function waits until the UART0 transmit FIFO is not full before writing
 * the character to the UART0 data register.
 *
 * @param c The character to transmit.
 * @return None
 */
void printChar(uint8_t c){
    while (UART0_FR_R & (1<<5)){}; // Wait until the UART0 transmit FIFO is not full
    UART0_DR_R = c; // Write the character to the UART0 data register to transmit it
}



/**
 * @brief Transmits a string using UART0.
 *
 * This function transmits a null-terminated string using the UART0 peripheral.
 * . The function calls the printChar function to transmit
 * each character in the string. A newline character is transmitted at the end of the string.
 *
 * @param str The null-terminated string to transmit.
 * @return None
 */
void printString(char * str){
    // Loop until the end of the string is reached
    while(*str != 0){
        // Transmit the current character using the printChar function
        printChar(*str);
        // Move to the next character in the string
        str++;
    }
    // Transmit a newline character at the end of the string
   printChar('\r');
   printChar('\n');
   printChar('\r');

}
