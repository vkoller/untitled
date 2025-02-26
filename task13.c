//
// Created by 1626158 on 24.2.2025.
///* Ex13
/*Write a program that asks user to enter a filename. Then program tries to open the file in textmode for reading.
If opening the file fails the program prints an error message with the filename to stderr and then exits.
If the file is opened the program starts reading integers from the file until reading fails or the file ends.
When reading stops the program prints the count of numbers and the lowest and highest number that was read from the file. Then program closes the file.
For testing make a few text files with integers using your favourite text editor.*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    char filename[30];
    char line[80];
    FILE *your_file;
    int num;
    int count = 0;
    int min = INT_MAX;
    int max = INT_MIN;

    printf("Enter your filename: \n");
    scanf("%29s", filename);

    your_file = fopen(filename, "r");
    if (your_file == NULL) {
        printf("File %s not found\n", filename);
        return 1;
    }

    while (fscanf(your_file, "%d", &num) == 1) {
        count++;
        if (num < min) min = num;
        if (num > max) max = num;
    }

    fclose(your_file);

    if (count >0) {
        printf("Number read: %d \n", count);
        printf("Lowest number: %d\n", min);
        printf("Highest number: %d\n", max);
    } else {
        printf("No valid integers found in the file.\n");
    }

    return 0;
}