//
// Created by 1626158 on 3.3.2025.
//
/*Write a program that asks user to enter numbers or to enter end to stop entering numbers.
If user enters any other text except end the program prints an error message and discards the input.
The program must store the numbers in a linked list where each node is dynamically allocated.
typedef struct node {
    int number;
    struct node *next;
} nnode;
When user enters end the program prints all entered numbers, frees the allocated memory and then ends.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //for using isdigit(*str)

int is_number(char *str) { //checking if the string is a number
    while (*str) { //checking every symbol
        if (!isdigit(*str) && *str != '-') return 0; //if symbol is not a digit or '-' the string is not a number
        str++;
    }
    return 1; //the string is a number
}

int main(void) {
    typedef struct node {
        int number;
        struct node *next;
    } nnode;
    //creating pointers to beginning and the end of the list:
    nnode *head = NULL, *tail = NULL;

    char input[10];

    while (1) {
        printf("Please enter a number or 'end' to exit: ");
        fgets(input, 10, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "end") == 0) break;

        if (is_number(input)) {
            //creating a new node
            nnode *new_node = (nnode *)malloc(sizeof(nnode));
            if (new_node == NULL) {
                fprintf(stderr, "Memory allocation failed!\n");
                return 1;
            }
            new_node->number = atoi(input); //converting to a number
            new_node->next = NULL;

            //adding the new node to the list
            if (head == NULL) { //if the list is empty
                head = new_node; // the new node is the first
                tail = head; //it is also the last element because it is the only one
            } else { //if it's not empty
                tail->next = new_node; //the current last element takes pointers to new_node
                tail = new_node; //the new last element takes values of new_node
            }
        } else {
          printf("Please enter a valid number or 'end' to stop!\n");
        }
    }
    //
    printf("Entered numbers:\n");
    nnode *current = head;
    while (current != NULL) {
        printf("%d\n", current->number);
        current = current->next;
    }

    //
    current = head;
    while (current != NULL) {
        nnode *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

