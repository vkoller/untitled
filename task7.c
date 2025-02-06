//
// Created by 1626158 on 31.1.2025.
// //Write a function named read_positive. The function takes a pointer to int as a parameter and returns a bool.
// bool read_positive(int *value);
// The function asks (=prints) user to enter a positive number.
// If user enters a valid number and the number is positive the function stores the number using the pointer and returns true.
// If reading number fails or number is not positive function returns false without making changes to the value using pointer.

#include <stdio.h>
#include <stdbool.h>


bool read_positive(int *pnumber) {
    int number = 0;
    int times = 0;          //how many mistakes was done
    *pnumber = number;
    // printf("Initially number is: %d\n", *pnumber); //for debagging

    do {//requesting an input from player at least once
        printf("Enter a number: ");
        if (scanf("%d", &number) != 1) {    //if it's a symbol
            printf("Invalid input\n");
            while (getchar() != '\n');
            times++;                                //number of mistakes grows
            // printf("Times is: %d\n", times);     //debagging
        }else if (number < 0) {                 //if it's not a symbol, but negative
            printf("Negative number\n");
            times++;                                //number of mistakes grows
            // printf("Times is: %d\n", times);
        } else {
            *pnumber = number;      //writing the value of number to pointer pnumber
            return true;            //the loop stops and function return true to main
        }
    }while (times < 3);     //the loop stops after 3 mistakes

    // printf("Number is: %d\n", *pnumber);    //test
    return false;
}

int main(void) {
    int pnumber;        //variable for pointer for variable "number"
    bool vastaus = read_positive(&pnumber); //call the function and send the address of pointer as the argument for function

    while (vastaus) {       //loop works until function returns true
            // printf("vastaus = %d\n", vastaus);      //testing
            // printf("The number is: %d\n", pnumber); //testing
            int matrix_number = (pnumber * 2) + 20;          //the number created by the "Matrix"
            printf("My number is %d\n", matrix_number);
            vastaus = read_positive(&pnumber);      //getting new value for "number"
    }

    //when function returns false, loop stops and game is over
    printf("You've entered wrong input 3 times and failed\n");
    return 0;
}



