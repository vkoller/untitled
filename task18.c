//
// Created by 1626158 on 4.3.2025.
//
/*Write a program that asks user to enter a number in the range from 0 to 15 or a negative number to stop.
 *If user enters a number between 0 and 15 the program generates a random number and prints it in hexadecimal.
 *Then program shifts the number to the right by the amount user entered
 *and uses bitwise and to clear all other bits except bits 0-5 and prints the result in hexadecimal with two digits and leading zeros.
Note: bit numbering starts from 0*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char input[6];
    int shift; //number for shifting to the right
    unsigned int random_number;

    srand(time(NULL)); //starting seed

    while (1) {
        printf("Enter a number (0-15) or a negative number to stop: ");
        fgets(input, 6, stdin);

        input[strcspn(input, "\n")] = '\0'; //deleting '\n'

        if (strcmp(input, "stop") == 0) { //comparing to 'stop'
            break;
        }

        // converting 'input' to number into 'shift': (sscanf(input, "%d", &shift)
        if (sscanf(input, "%d", &shift) != 1) { //if it didn't happen
            printf("Invalid input! Please enter a number or 'stop'.\n");
            continue;
        }


        if (shift < 0) {
            break;
        }

        if (shift >= 0 && shift <= 15) {
            random_number = rand() % 256;  // getting a random number from 0 to 255
            printf("Random number: 0x%X\n", random_number); //printing the number in hexadecimal

            // shifting to the right and cleaning 2 older bits by  (& 00111111)
            unsigned int result = (random_number >> shift) & 0x3F;

            // prints the result in hexadecimal with two digits and leading zeros
            printf("Processed result: 0x%02X\n", result);
        } else {
            printf("Invalid input! Please enter a number between 0 and 15.\n");
        }
    }

    return 0;
}
