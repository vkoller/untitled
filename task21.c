//
// Created by 1626158 on 12.3.2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

//
unsigned char calculate_checksum(const char *str, size_t length) {
    unsigned char checksum = 0;
    for (size_t i = 0; i < length; i++) {
        checksum ^= (unsigned char)str[i];
    }
    return checksum;
}

int main() {
    char filename[256];
    printf("Enter the file name: ");
    scanf("%255s", filename);

    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {

        line[strcspn(line, "\r\n")] = 0; //deleting new line symbols

        // check the first symbol
        if (line[0] != '$') {
            continue;
        }

        // search for *
        char *asterisk = strchr(line, '*');
        if (!asterisk || *(asterisk + 1) == '\0' || *(asterisk + 2) == '\0') {
            printf("[FAIL] %s (wrong format)\n", line);
            continue;
        }

        // getting checksum as 2 symbols after '*')
        unsigned int given_checksum;
        if (sscanf(asterisk + 1, "%2x", &given_checksum) != 1) {
            printf("[FAIL] %s (fail to read checksum)\n", line);
            continue;
        }

        // calculate the checksum
        size_t data_length = asterisk - (line + 1);
        unsigned char calculated_checksum = calculate_checksum(line + 1, data_length);

        //
        if (calculated_checksum == given_checksum) {
            printf("[ OK ] %s\n", line);
        } else {
            printf("[FAIL] %s (expected %02X, got %02X)\n", line, given_checksum, calculated_checksum);
        }
    }

    fclose(file);
    return 0;
}
