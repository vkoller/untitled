//
// Created by 1626158 on 4.3.2025.
//
/*Write a password generator function that takes three parameters:
 *character pointer, integer (size of the array), a const char pointer (a word) and returns a bool.
 *The function generates password and stores it in the array and returns true.
 *The length of the generated password is the 𝑙𝑒𝑛𝑔𝑡ℎ 𝑜𝑓 𝑤𝑜𝑟𝑑 ×2+1 characters.
 *If the password does not fit in the string function returns false and does not modify the string.
The password must contain the word given as a parameter so that password starts with a random printable character
and every other letter is a letter from the word and every other is a random printable character.
The password ends with a random printable character. Note that printable characters are not limited to alphanumerical characters.
Write a program that asks user to enter a word to place in the password or to enter “stop” to stop the program.
The size of the string to read the word into must be 32. If user does not enter stop the program generates a password using the generator function.
If a password is generated successfully the program prints it otherwise an error message is printed. Then the program asks for another word.
For example:
User enters: metropolia
Program prints: #m%eGtqrHo&p2o+lBimaY
You don’t need to use colours. They are just a visual aid. The random characters will naturally be different on your program.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define MAX_SIZE 100  // the max size for password
#define WORD_SIZE 32   // the max size for user's word

// password generating
bool generate_password(char *password, int size, const char *word) {
    int word_len = strlen(word);
    int pass_len = word_len * 2 + 1;  // lenght of password

    if ((pass_len + 1) > size) {  // +1 for '\0'
        return false; // if it doesn't fit
    }

    // generating the password:
    for (int i = 0; i < pass_len; i++) {
        if (i % 2 == 0) { //every even character
            password[i] = (char)(rand() % 94 + 33);  // random (from '!' to '~')
        } else { //every odd character
            password[i] = word[i / 2];  // a character from user's word
        }
    }

    password[pass_len] = '\0';  // the last character must be '\0'
    return true;
}

int main() {
    char word[WORD_SIZE];
    char password[MAX_SIZE];

    srand(time(NULL));  // getting seed for random

    while (1) {
        printf("Enter your word or 'stop' for exit: ");
        fgets(word, WORD_SIZE, stdin);
        word[strcspn(word, "\n")] = '\0';

        if (strcmp(word, "stop") == 0) {
            break;
        }

        // calling the function
        if (generate_password(password, MAX_SIZE, word)) {
            printf("Your password is: %s\n", password);
        } else {
            printf("There is no enough space for password!\n");
        }
    }

    return 0;
}
