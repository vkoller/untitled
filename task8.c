//
// Created by 1626158 on 6.2.2025.
//Write a function called print_numbers that takes two parameters:
//pointer to constant integers and number of integers to print.
// void print_numbers(const int *array, int count);

// The function prints the numbers on separate lines in eight characters wide field.
// Write a program that defines an array of
// 15 integers and fills the array with random numbers and then uses the function to print the array contents

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_numbers(const int *parray, int count) {
    for (int i = 0; i < count; i++) {
        printf("Number  %8d\n", parray[i]);
    }
}

int main() {
    int count = 15;
    int array[count];       //declare an array

    int limit = 115;        //upper limit for random numbers
    srand(time(NULL));  //creation of a seed using time

    for (int i = 0; i < count; i++)
        array[i] = 1 + rand() % limit;

    // printf("Size of array: %d\n", sizeof(array)/sizeof(int)); //test

    print_numbers(array, count);   //call function with arg as array and number of elements
    return 0;
}