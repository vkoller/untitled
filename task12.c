//
// Created by 1626158 on 24.2.2025.
//

/*
Write a function count_words that takes two strings as a parameter and returns an integer.
The function counts the number of times the second string occurs in the first string and returns the count.
Use strstr() from standard library to find the strings.
Note that if the string is found you need to advance past the current occurrence before searching again.
Hint: use a pointer to the string and use pointer arithmetic to advance it past the current match.
Prototype of the function:
int count_words(const char* str, const char *word);
Write a program that asks user to enter a string and a word.
Then program calls count_words and prints the return value.
If the word was “stop” the program stops otherwise it asks user to enter a string and a word again.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int count_words(const char *string, const char *word) {
    int count = 0;
    const char *temp = string;

    /*if (*word == '\0') {    //if user doesn't enter anything
        printf("You haven't entered any symbol to search\n");
        return 0;
    }*/

    while ((temp = strstr(temp,word)) != NULL) {         //while true
        count++;
        temp += strlen(word);   //shifting the pointer right to substring's lenght

    }
    return count;
};

int main() {
    char string[100];
    char word[30];

    while (1) {
            do {
                printf("Enter a string: ");
                fgets(string, 100, stdin);
                if (string[strlen(string)-1] == '\n') {
                    string[strlen(string)-1] = '\0';
                }
                if (*string == '\0') {
                    printf("You haven't entered anything, try again please. \n");
                }

            } while (*string == '\0');

            do {
                printf("Enter a word you want to find or 'stop' for exit: ");
                fgets(word, 30, stdin);

                if (word[strlen(word)-1] == '\n') {
                    word[strlen(word)-1] = '\0';
                }

                if (*word == '\0') {
                    printf("You haven't entered any symbol to search, try again please. \n");
                }



            } while (*word == '\0');
        if (strcmp(word, "stop") == 0) {
            printf("You have stopped the program, see you again.\n");
            break;
        }

            int result = count_words(string, word);
            printf("The number of word <%s> in the string <%s> is: %d\n", word, string, result);

    };

};
