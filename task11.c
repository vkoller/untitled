//
// Created by 1626158 on 11.2.2025.
//
/*
Write a function called replace_char that takes two strings as parameters
and returns an integer. The first string is the string to modify and
the second is a string containing two characters.
The function finds every occurrence of the first character of the second string
and replaces them with the second character.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int replace_char(char *str, const char *repl) {
    int num = 0;
    int len = strlen(str);
    if (strlen(repl) == 2) {
        for (int k = 0; k < len; k++) {
            if (str[k] == repl[0]) {
                str[k] = repl[1];
                // printf("%s\n", str);
                ++num;
            }
        }
    }

    return num;
}

void main() {
    char str[256]; // string to be checked
    char repl[4]; // string to be used in replacement , I allocate 4 bytes, 2 - for characters, 1 for '\n' and 1 for '0'
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    if (repl[strlen(str) - 1] == '\n') { //clearing the '\n'
        repl[strlen(str) - 1] = '\0';
    }

    printf("Enter 2 characters for replacement task: ");
    fgets(repl, sizeof(repl), stdin);

    printf("Repl length is: %llu\n", strlen(repl));
    if (repl[strlen(repl) - 1] == '\n') { //clearing the '\n'
        repl[strlen(repl) - 1] = '\0';
    }

    if (strchr(str, '\n') == NULL) { //if user enters more than 2 characters '\n' will not be found
        while (getchar() != '\n'); //in this case we have to clear the stdin
    }

    int number = replace_char(str, repl);
    if (number > 0) {
        printf("Replacement task was successful!\nNew string is: %s\n", str);
        printf("Number of changes: %d\n", number);
    } else
        printf("String was not modified.\n");
}