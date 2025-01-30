//
// Created by 1626158 on 29.1.2025.
//Write a program that prints a menu and asks user to select an operation. The operations are: Roll D6 Roll D10 Quit
//Input must be validated and a descriptive error message must be printed if
// input is invalid. Rolling D6 prints a random number in the range of 1 – 6 and rolling D10 prints a random number in the range of 1 – 10.
// If user does not select quit the program prints the menu again
// Use functions to structure your program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_D6() {
    int num = 0;
    int limit = 6;                  //create the upper limit for random number
    num = 1 + rand() % limit;       //create a "random" value starting from 1 to limit
    return num;
}
int roll_D10() {
    int num = 0;
    int limit = 10;                  //create the upper limit for random number
    num = 1 + rand() % limit;       //create a "random" value starting from 1 to limit
    return num;
}

int menu() {                //function prints menu, checks if input was correct and returns the choice to main
    int choice;
    while (1) {
        printf("Chose an option from menu:\n1. Roll a 6-sides die - enter 1\n2. Roll a 10-sides die - enter 2.\n3. To quit the game enter 3\n");
        if (scanf("%d", &choice) != 1) {
            printf("You've entered a symbol instead of number. Try again, please. \n");
            while (getchar() != '\n');
        }else if (choice < 1 || choice > 3) {
            printf("Please chose a number only from 1 to 3. ");
            while (getchar() != '\n');
        }else
            return choice;
    }
}

int main() {
    srand(time(NULL));          // creates seed with current time to get more random value inside functions roll6 and roll10
    int option;
    while (1) {                     // endless loop, while true
        option = menu();            // getting result from menu()
        switch (option) {
            case 1:
                printf("\nYour number is %d\n", roll_D6());
                break;
            case 2:
                printf("\nYour number is %d\n", roll_D10());
                break;
            case 3:
                printf("Good bye! See you again!");
                return 0;
            default:
                printf("Please choose ...");        //if player didn't choose anything - didn't work yet
        }
    }
}
