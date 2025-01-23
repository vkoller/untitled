#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//
// Created by 1626158 on 21.1.2025.
//


/*
Ex
2.
Write a program that defines two floating point arrays of 12 elements each.
The program then asks user to enter tax percentage and yearly income limit up to which the percentage applies to and
the(greater) tax percentage that will be applied to income that is over the limit.
Then program asks user to enter salary of each month and stores the values in the array.
After user has entered all monthly salaries, the program calculates tax for each month.
The program prints all salaries with two decimal precision and the amount of tax for each month.
*/

int main(void) {
    float salary[12], monthly_tax[12];
    float income_limit, st_tax, max_tax, total_income = 0;
    printf("Enter your yearly income limit: ");
    scanf("%f", &income_limit);
    printf("Enter your tax rate for standart income (for example, 0.13): ");
    scanf("%f", &st_tax);
    printf("Enter your monthly tax rate for higher income (for example, 0.25): ");
    scanf("%f", &max_tax);

    for (int i = 0; i < 12; i++) {
        printf("Enter your salary of %d month:  ", i+1);
        scanf("%f", &salary[i]);

        total_income += salary[i];
        if (total_income < income_limit) {
            monthly_tax[i] = (salary[i] * st_tax);
        } else {
            monthly_tax[i] = (salary[i] * max_tax);
        }
    }
    printf("%5s%15s%15s\n", "Month", "Salary", "Tax");
    for (int i = 0; i < 12; i++) {
        printf("%5d%17.2f%15.2f\n", i+1, salary[i], monthly_tax[i]);
    }
}
