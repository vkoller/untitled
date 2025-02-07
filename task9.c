//
// Created by 1626158 on 7.2.2025.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int print_numbers(const unsigned int *parray, unsigned int what) {
    int i = 0;      //index of element from the array
    int result = -1;
    while (parray[i] != 0) {           //we are searching till '0' is reached
        // printf("%d\n", parray[i]); //test
        if (parray[i] == what) {        // if the element is equal to 'what' function returns it's index
         result = i;
            break;
        }
        ++i;
        }
    return result;  //if element wasn't found result remains -1
    }


int check_input() { //check if the input was correct
    int input;
    do{
        printf("Please enter a number or '0' to stop:");
        if (scanf("%d", &input) != 1) {
            printf("It wasn't a number, try again\n");
            while (getchar() != '\n');
        }else if (input < 0 ) {
            printf("Please enter a positive number\n");
        }else
            return input;

    }while (1);
}

int main() {
    int array[20]; //declare an array

    int limit = 20; //upper limit for random numbers
    srand(time(NULL)); //creation of a seed using time

    for (int i = 0; i < 19; i++)
        array[i] = 1 + rand() % limit;  //starting from 1 to limit
    array[19] = 0;

    // printf("Size of array: %d\n", sizeof(array)/sizeof(array[0])); //test
    for (int i = 0; i <= 19; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }

    int query = check_input();
    while (query != 0) {
        int index = print_numbers(array, query);
        if (index == -1) {
            printf("Not found\n");

        }else
            printf("Your query's index is: %d\n", index);
        query = check_input();
    }
    printf("You've stopped the program'\n");

}