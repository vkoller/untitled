//
// Created by 1626158 on 12.3.2025.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store menu items
typedef struct {
    char name[50];
    double price;
} menu_item;

int compare_by_price(const void *a, const void *b) { // sort by price
    double price_a = ((const menu_item *)a)->price;
    double price_b = ((const menu_item *)b)->price;

    if (price_a < price_b) return -1;
    if (price_a > price_b) return 1;
    return 0;
}

int compare_by_name(const void *a, const void *b) { //sort by name
    return strcmp(((const menu_item *)a)->name, ((const menu_item *)b)->name);
}

// Function to read menu items from a file and return their number
int read_menu_from_file(const char *filename, menu_item array[], int max_size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return 0;
    }

    int i = 0; //number of menu items
    while (i < max_size) {
        if (fscanf(file, "%49[^;];", array[i].name) != 1) break; // Read up to 49 characters until a semicolon
        if (fscanf(file, "%lf", &array[i].price) != 1) break;
        i++;
    }
    fclose(file);
    return i;
}

void print_menu(menu_item array[], int size) {
    printf("\nMenu items:\n");
    for (int j = 0; j < size; j++) {
        printf("$%8.2f %s\n", array[j].price, array[j].name);
    }
}

int main() {
    menu_item array[40]; //array with up to 40 menu items

    char filename[20];
    printf("Enter the file name: ");
    fgets(filename, 20, stdin);
    filename[strcspn(filename, "\n")] = '\0'; //removing '\n'

    //finding the size of array, e.g number of menu items
    int size = read_menu_from_file(filename, array, 40);
    if (size == 0) return 1;

    int choice;
    printf("Choose sorting order:\n");
    printf("1 - Sort by price\n");
    printf("2 - Sort by name\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    //sorting the array:
    if (choice == 1) {
        qsort(array, size, sizeof(array[0]), compare_by_price);
    } else if (choice == 2) {
        qsort(array, size, sizeof(array[0]), compare_by_name);
    } else {
        printf("Invalid choice. Printing unsorted list.\n");
    }

    //calling the function to print menu
    print_menu(array, size);
    return 0;
}
