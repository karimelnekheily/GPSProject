#include "GPS.h"

/*
 * Global variables
 */
char receivedChar;
uint32_t strGPS_counter;
extern char strGPS[];

/**
 * Function declration
 */



/**
 * @brief Receives a single character using UART5.
 *
 * This function receives a single character using the UART5 peripheral on a
 * TM4C123GH6PM microcontroller. The function waits until the UART5 receive
 * FIFO is not empty before reading the character from the UART5 data register.
 * If there are any errors or if the received value is a garbage value, the function
 * returns a null character.
 *
 * @param None
 * @return The received character or a null character if there are any errors.
 */
uint8_t readGPSChar(){
    while (UART5_FR_R & (1<<4)){}; // Wait until the UART5 receive FIFO is not empty
    if((UART5_DR_R & 0xFFFFFF00) != 0){
        // Check if there are any errors or if it's a garbage value
        return '\0';
    }
    return (char)(UART5_DR_R & 0xFF); // Read the received character from the UART5 data register
}


/**
 * @brief Receives a string using UART5.
 *
 * This function receive a NMEA string from the GPS,
 * it uses the global var str_GPS to store that string.
 * it calls the function readGPSChar() to get the string elemnts.
 *
 * @param None
 * @return None
 */
void readGPSString(){
    strGPS_counter = 0; // Initialize the GPS string counter to 0
    receivedChar = readGPSChar(); // Read the first character from the GPS
    while(receivedChar != '$'){ // Keep reading until a '$' character is found
        receivedChar = readGPSChar();
    }
    strGPS[strGPS_counter++] = receivedChar; // Store the '$' character in the GPS string
    receivedChar = readGPSChar(); // Read the next character from the GPS
    while(receivedChar != '$'){ // Keep reading and storing characters until another '$' character is found
        strGPS[strGPS_counter++] = receivedChar;
        receivedChar = readGPSChar();
    }
    strGPS[--strGPS_counter] = '\0'; // Replace the last '$' character with a null terminator to end the GPS string
}



