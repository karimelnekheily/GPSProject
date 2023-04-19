#include "tivaConfig.h"
/**
 * Global Variables
 */
char strGPS[80];


/**
 * main function
 */
int main(){

    setCLkFreq(16); // set freq to 16Mhz
    UART0_init();
    UART5_init();

    while(1){

    }
}

