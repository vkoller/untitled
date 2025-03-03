//
// Created by 1626158 on 3.3.2025.
//
/*
Write a program that reads data from a text file into an array of structures. The size of the array is 40 elements.
The structure is defined as:
typedef struct menu_item_ {
    char name[50];
    double price;
} menu_item;
The program asks user to enter a filename. Then program tries to open the file in textmode for reading.
If opening the file fails the program prints an error message with the filename to stderr and then exits.
Program reads data from the text file into the array until end of file or the array is full.
Each row of the file contains data of one structure. The members are separated by semicolons.
For example:
Mega double burger with bacon and cheese; 23.50
Belgian style fries with vegan mayo; 5.60
When reading ends the program closes the file and prints the content of the array in formatted columns.
Price is printed into a field of eight characters with two decimals precision followed by the name of the item. Unused elements are not printed.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    typedef struct menu_item_ {
        char name[50];
        double price;
    } menu_item;

    menu_item array[40];

    char filename[20];
    printf("Enter the file name: ");
    fgets(filename, 20, stdin);
    filename[strcspn(filename, "\n")] = '\0'; // deleting newline symbol

    FILE *your_file = fopen(filename, "r");
    if (your_file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return 1;
    }
    int i = 0;
    while (i < 40) { //reading the file into array of 40 elements
        //reading any symbol except from semicolon till ";"
        if (fscanf(your_file, "%49[^;];", array[i].name) != 1) break; //if no data found then break
        if (fscanf(your_file, "%lf", &array[i].price) !=1) break; //if no figures found then break
        i++;
        }

    printf("\nMenu items:\n");
    for (int j = 0; j < i; j++) {
        printf("$%8.2f %s\n", array[j].price, array[j].name);
    }
    fclose(your_file);
    return 0;
    }


