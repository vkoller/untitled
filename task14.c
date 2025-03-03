/*The program reads lines from the file into the array until the file ends or the array is full (100 lines read). Then program closes the file.
Then program converts all letters to upper case (see toupper() – function).
Then program opens the file for writing in text mode and writes all read lines to file and closes the file*///


#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINES 100
#define MAX_LENGTH 80

int main() {
    char filename[20];
    char lines[MAX_LINES][MAX_LENGTH+1]; //100 lines, each 80 char+'0' in the end
    FILE *your_file;
    int line_num = 0;

    printf("Enter the name of your file : \n");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0'; // - deleting \n

    your_file = fopen(filename, "r");
    if (your_file == NULL) {
        fprintf(stderr, "File %s not found\n", filename);
        return 1;
    }
        while (line_num < MAX_LINES) {
            if (fgets(lines[line_num], MAX_LENGTH + 1, your_file) == NULL)
                break;
            lines[line_num][strcspn(lines[line_num], "\n")] = '\0';
            line_num++;

        }

    fclose(your_file);

    for (int i = 0; i < line_num; i++) {
        for (int j = 0; lines[i][j] != '\0'; j++) {
            lines[i][j] = toupper((unsigned char)lines[i][j]);
        }
    }
    your_file = fopen(filename, "a");
    fprintf(your_file,"\n\nUppercase letters are : \n");
    for (int i = 0; i < line_num; i++) {
        fprintf(your_file,"%s\n", lines[i]);
    }

    fclose(your_file);

}
