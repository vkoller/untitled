#include <stdio.h>
//
// Created by 1626158 on 21.1.2025.
//

/*
Ex 3.
That asks number of students and creates an array of that many integers.
Program then initializes the array elements to -1.
Then the program asks user to enter student number in range 1 – nr of students or zero to stop.
If valid non zero number is given the program asks user to enter grade in the range 0-5 or -1 to not enter a grade for the student.
When user stops by entering 0 then program prints student numbers followed by grade or N/A if grade is -1.*/

int main(void) {
    int st_number, st_index = 0; //st_number - number of the students, st_index - array's index
    printf("How many students do you have: ");
    scanf("%d",  &st_number);
    int students[st_number]; //declaring the array
    for (int i = 0; i < st_number; i++) {
        students[i] = -1; //nobody has a grade at the beginning
    }

    while (st_index >= 0 && st_index < st_number) {
        printf("Enter the student's number in range of 1-%d or '0' to stop): \n", st_number);
        int student;
        scanf("%d", &student);
        if (student >0 && student <= st_number) {
            st_index = student-1;
            printf("Grade the student number %d or enter -1 to not grade: \n", student);
            int grade;
            scanf("%d", &grade);
            students[st_index] = grade;
        }else if (student == 0){
            printf("You stopped the program\n");
            break;
        }else {
            printf("You've entered a wrong number, try again, please.\n");
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