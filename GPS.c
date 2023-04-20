#include "GPS.h"
#include <stdio.h>
#include <string.h>
 
/* 
 * Global variables used
 */
char receivedChar;
uint32_t strGPS_counter;
extern char strGPS[];
//global variables for function read_RMC
extern char *utc_time;
extern char *status;
extern char *latitude;
extern char *longitude;
extern char *speed_over_ground;
extern char *date;
char *token; // pointer to hold the current token
char *delim = ","; // delimiter used to split the string
int i = 0; // counter to keep track of the current token position
/**
 * Function declration
 */



/**
* @brief Reads and parses a sentence in the RMC format.
* Tokenizes the sentence using `strtok` with a comma as a delimiter.
* Assigns tokenized values to variables based on their position in the sentence.
*
* @param sectence_RMC A character pointer to the RMC sentence to be parsed.
*/
void read_RMC(char*sectence_RMC) {
    // split the string into tokens based on the delimiter
    token = strtok(sectence_RMC, delim);
    while (token != NULL) {
        switch (i) {
            case 1:
                utc_time = token; // assign the second token to the global variable utc_time
                break;
            case 2:
                status = token; // assign the third token to the global variable status
                break;
            case 3:
                latitude = token; // assign the fourth token to the global variable latitude
                break;
            case 5:
                longitude = token; // assign the sixth token to the global variable longitude
                break;
            case 7:
                speed_over_ground = token; // assign the eighth token to the global variable speed_over_ground
                break;
            case 9:
                date = token; // assign the tenth token to the global variable date
                break;
        }
        i++; // increment the counter
        token = strtok(NULL, delim); // get the next token
    }
}


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



