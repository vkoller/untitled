//
// Created by 1626158 on 29.1.2025.
//Ex5
//Write a function read_range that takes two integer parameters and returns an integer.
//The function asks user to enter a number in the range given as parameters

#include <stdio.h>

int read_integers(int low, int high) {
    int num = 0;
    do {
        printf("Enter a number between %d and %d : \n", low, high);
        if (scanf("%d", &num) !=1) {                             //check if the number was successfully read
            printf("You've entered a symbol. ");
            while (getchar() != '\n');
            continue;
        }
        if (num < low || num > high) {                                 //check if the number is in the range
            printf("You entered a number out of range. ");
            while (getchar() != '\n');
            continue;
        }
    } while (num < low || num > high);
    printf("The result is %d.\n", num);
        return num;

}
void main() {
    printf("Let's play!\nRoll a die and enter your result.\n\n");
    // printf("The function returns %d\n", read_integers(1, 6));
    int i = 0; // number of tries

    const int die = 6;                                              // choose the number of die's sides
    while (i < 3) {                                                  // the player can roll a die 3 times
        int result = read_integers(1, die);                 // call the function with arg from 1 to die's sides number

        if (result < die) {
          printf("I got %d. I win!\n", result + 1);             // program cheats, adding 1
          i++;
        }
        if (result == die) {
            printf("I got %d. It is a tie!\n", result);         // program cheats, showing the same result
            i++;
        }
        // printf("i=%d\n", i);
    }
    printf("Better luck next time. Bye!\n");
}