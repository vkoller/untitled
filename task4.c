//
// Created by 1626158 on 24.1.2025.
//Write a function called read_integer that takes no parameters and returns an integer.
//The function reads a single integer.
//If the reading fails the function prints “invalid input” and tries to read an integer again.
//When an integer is successfully read the function returns the integer

#include <stdio.h>

int read_integer() {
    int input;                                              // the variable for input from the user
    do {
        printf("Enter a positive integer or a negative to exit: ");
        scanf("%d", &input);
        printf("The value entered is: %d\n", input);  // we don't need it actually, it's for just for testing
        if (input == 0) {                                   // if user entered a letter or symbol, it returns 0
            while (getchar() != '\n');                      // cleaning
            printf("Invalid input\n");
        } else if (input < 0) {                             // if it's a negative number we stop the program
            break;
        }
    } while (input < 1);                                   // cycle will stop
        return input;
    }


void main() {
    int number = read_integer();                            // call the function and assign its return to "number"
    int count = 0;
    float sum;
    while (number > 0) {                                    // if the user didn't stop the game the cycle goes on
        sum += number * 1.0;                                // make the number of float type
        /*printf("The sum is %.2f\n", sum);*/
        count++;
        /*printf("The number of counts is: %d\n", count);*/
        number = read_integer();                            // call the function again to update the "number"
    }

        float average = sum / count;                        //calculate the average
        printf("Average is %.3f\n", average);
    }




