//
// Created by 1626158 on 21.1.2025.
//
#include <stdio.h>

int main(void) {
    float bus_price, taxi_price, money;
    printf("Enter the price of a bus ticket:");
    scanf("%f", &bus_price);
    printf("Enter the price of a taxi trip: ");
    scanf("%f", &taxi_price);
    printf("Enter the amount of money you've had: ");
    scanf("%f", &money);

    while (money >= taxi_price || money >= bus_price) {
        float travel_price;
        char * chosen;
        if (money >= taxi_price && money >= bus_price) {
            printf("Would you take a bus (type 1) or a taxi (type 2):");
            int choice;
            scanf("%d", &choice);

            if (choice == 1) {
                travel_price = bus_price;
                chosen = "bus";
            } else if (choice == 2) {
                travel_price = taxi_price;
                chosen = "taxi";
            }else {
                printf("It seems like you've entered a wrong number, try again please.\t");
                continue;
            }
        } else if (money >= taxi_price) {
            travel_price = taxi_price;
            chosen = "taxi";
        } else if (money >= bus_price) {
            travel_price = bus_price;
            chosen = "bus";
        } else {
            break;
        }
        money -= travel_price;
        printf("Your choice is: %s\tYou have %.2f euros left\n", chosen, money);
    }
    printf("You haven't enough money for any transport. Have a nice walk:)\n");
}
