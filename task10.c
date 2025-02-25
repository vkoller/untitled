//
// Created by 1626158 on 10.2.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Write a program that asks user to enter a string.
Program must use fgets to read user input and remove the linefeed at the end of the string.
Then program prints the length of the string and checks if the string is “stop”.
If it is the program stops else program asks user to enter a new string (and prints the length etc.).*/

char* read_string(const char *prompt) {
    char *input = malloc(256 * sizeof(char));
    printf("%s", prompt);
    fgets(input, 256, stdin);
    return input;
}

void main() {
    char *your_string;
    // printf("Enter a string: \n");
    // fgets(your_string, 256, stdin);
    char *stop = "stop";
    do {
        your_string = read_string("Enter a string: \n");
        int length = strlen(your_string);
        if (your_string[length - 1] == '\n') {
            your_string[length - 1] = '\0';
        }
        printf("Your string is: %s\n", your_string);
        printf("Your string length is %d\n", length);
    }while (strcmp(your_string, stop)!=0);
}