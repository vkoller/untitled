#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*int main(void) {
    printf("Hello, World!\n");
    return 0;
}*/
/*Write a function that prints an ascending sequence of numbers.
 Function receives two parameters: first
 parameter is the first number of the sequence and second parameter is the last number in the sequence.
 Program must print each number on a separate line and print one empty line at the end of the sequence
*/

/*
void sequence(int num1, int num2) {
    int i = num1;
    while (i <= num2) {
        printf("%d\n", i);
        i ++;
    }
    printf("\n");
}
*/


/*
int readint(void) {
    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);
    return number;
}



int main(void) {
    int element = readint();
    int counter = 0;
    float summ;
    while (element > 0) {
        summ += element;
        counter ++;
        element = readint();
    }
    float result = summ / counter;
    printf("Summ: %.4f\n", result);
    }
    */

/*
void sequence(int num1, int num2) {
    int startnum;
    int endnum;
    if (num1 < num2) {
        startnum = num1;
        endnum = num2;

    } else {
        startnum = num2;
        endnum = num1;
    }
    while (startnum <= endnum) {
        printf("%d\n", startnum);
        startnum++;
    }
    printf("\n");
}

int main() {
    sequence(10, 5);
}
*/

/*
int main(void) {
    int grades [100];
    int count;
    int i;

    printf("Please enter number students to initialize: ");
    scanf("%d", &count);
    for (i = 0; i < count; i++) {
        printf("Please enter grade for student number %d: ", i);
        scanf("%d", &grades[i]);
        printf("Student: %d \tGrade: %d\n", i, grades[i]);
    }
    return 0;
}
*/

/*
int main(void) {
    float bus_price, taxi_price, money;
    printf("Enter the price of a bus ticket: ");
    scanf("%f", &bus_price);
    printf("Enter the price of a taxi trip: ");
    scanf("%f", &taxi_price);
    printf("Enter the amount of money you've had: ");
    scanf("%f", &money);

    while (money >= taxi_price || money >= bus_price) {
        float travel_price;
        char * chosen;
        if (money >= taxi_price && money >= bus_price) {
            printf("Would you take a bus (type 1) or a taxi (type 2): ");
            int choice;
            scanf("%d", &choice);

            if (choice == 1) {
                travel_price = bus_price;
                chosen = "bus";
                } else {
                travel_price = taxi_price;
                chosen = "taxi";
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
*/

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

/*
int main(void) {
    float salary[12], monthly_tax[12];
    float income_limit, st_tax, max_tax, total_income = 0;
    printf("Enter your yearly income limit: ");
    scanf("%f", &income_limit);
    printf("Enter your tax rate for standart income: ");
    scanf("%f", &st_tax);
    printf("Enter your monthly tax rate for higher income: ");
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
        printf("%5d%15.2f%15.2f\n", i+1, salary[i], monthly_tax[i]);
    }
}*/

/*
Ex 3.
That asks number of students and creates an array of that many integers.
Program then initializes the array elements to -1.
Then the program asks user to enter student number in range 1 – nr of students or zero to stop.
If valid non zero number is given the program asks user to enter grade in the range 0-5 or -1 to not enter a grade for the student.
When user stops by entering 0 then program prints student numbers followed by grade or N/A if grade is -1.*/

int main(void) {
    int st_number, st_index = 0;
    printf("How many students do you have: ");
    scanf("%d",  &st_number);
    int students[st_number-1];
    for (int i = 0; i < st_number; i++) {
        students[i] = -1;
    }

    while (st_index >= 0 && st_index < st_number) {
        printf("Enter the student's number in range of 1-%d or '0' to stop): \n", st_number);
        int student;
        scanf("%d", &student);
        if (student >0) {
            st_index = student-1;
            printf("Grade the student number %d or enter -1 to not grade: \n", student);
            int grade;
            scanf("%d", &grade);
            // if (grade != -1) {
            students[st_index] = grade;
            // }else {
            //     printf("Student number %d wasn't graded!\n", student);
            // }
        }else {
            printf("You stoped the program\n");
            break;
        }

    }
    printf("%5s%15s\n", "Student", "Grade");
    for (int i = 0; i < st_number; i++) {
        printf("%5d", i+1);
        if (students[i]<0) {
            printf("%17s\n", "N/A");
        } else {
            printf("%17d\n", students[i]);
        }

    }
    return 0;
}