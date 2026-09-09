/*
============================================================
DAY 2: CONDITIONAL STATEMENTS
Topics: if, if-else, else-if ladder, nested if, switch
============================================================
*/


/* =========================================================
Q1. Check whether a year is a Leap Year
========================================================= */

#include <stdio.h>

int main() {
    int year;

    printf("Enter a year: ");
    scanf("%d", &year);

    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
        printf("%d is a Leap Year\n", year);
    else
        printf("%d is not a Leap Year\n", year);

    return 0;
}


/* =========================================================
Q2. Calculate Grade Based on Marks
=========================================================

#include <stdio.h>

int main() {
    float marks;

    printf("Enter marks: ");
    scanf("%f", &marks);

    if (marks < 0 || marks > 100)
        printf("Invalid marks\n");
    else if (marks >= 90)
        printf("Grade: A+\n");
    else if (marks >= 80)
        printf("Grade: A\n");
    else if (marks >= 70)
        printf("Grade: B\n");
    else if (marks >= 60)
        printf("Grade: C\n");
    else if (marks >= 40)
        printf("Grade: D\n");
    else
        printf("Grade: Fail\n");

    return 0;
}


/* =========================================================
Q3. Check whether a Triangle is Valid
=========================================================

#include <stdio.h>

int main() {
    int a, b, c;

    printf("Enter three sides: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a + b > c && a + c > b && b + c > a)
        printf("Valid Triangle\n");
    else
        printf("Invalid Triangle\n");

    return 0;
}


/* =========================================================
Q4. Calculate Electricity Bill
Rates:
First 100 units  -> Rs. 5/unit
Next 100 units   -> Rs. 7/unit
Above 200 units  -> Rs. 10/unit
=========================================================

#include <stdio.h>

int main() {
    int units;
    float bill;

    printf("Enter electricity units: ");
    scanf("%d", &units);

    if (units <= 100)
        bill = units * 5;
    else if (units <= 200)
        bill = (100 * 5) + ((units - 100) * 7);
    else
        bill = (100 * 5) + (100 * 7) + ((units - 200) * 10);

    printf("Electricity Bill = Rs. %.2f\n", bill);

    return 0;
}


/* =========================================================
Q5. Find Number of Days in a Month
=========================================================

#include <stdio.h>

int main() {
    int month, year;

    printf("Enter month (1-12): ");
    scanf("%d", &month);

    printf("Enter year: ");
    scanf("%d", &year);

    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("31 days\n");
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            printf("30 days\n");
            break;

        case 2:
            if ((year % 400 == 0) ||
                (year % 4 == 0 && year % 100 != 0))
                printf("29 days\n");
            else
                printf("28 days\n");
            break;

        default:
            printf("Invalid month\n");
    }

    return 0;
}


/* =========================================================
Q6. Simple Calculator Using Switch
=========================================================

#include <stdio.h>

int main() {
    float num1, num2;
    char operation;

    printf("Enter first number: ");
    scanf("%f", &num1);

    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &operation);

    printf("Enter second number: ");
    scanf("%f", &num2);

    switch (operation) {
        case '+':
            printf("Result = %.2f\n", num1 + num2);
            break;

        case '-':
            printf("Result = %.2f\n", num1 - num2);
            break;

        case '*':
            printf("Result = %.2f\n", num1 * num2);
            break;

        case '/':
            if (num2 != 0)
                printf("Result = %.2f\n", num1 / num2);
            else
                printf("Error: Cannot divide by zero\n");
            break;

        default:
            printf("Invalid operator\n");
    }

    return 0;
}


/* =========================================================
Q7. Check Character Type
Check whether the character is:
Alphabet / Digit / Special Character
=========================================================

#include <stdio.h>

int main() {
    char ch;

    printf("Enter a character: ");
    scanf("%c", &ch);

    if ((ch >= 'A' && ch <= 'Z') ||
        (ch >= 'a' && ch <= 'z'))
        printf("Alphabet\n");

    else if (ch >= '0' && ch <= '9')
        printf("Digit\n");

    else
        printf("Special Character\n");

    return 0;
}


/* =========================================================
Q8. Check Triangle Type
=========================================================

#include <stdio.h>

int main() {
    int a, b, c;

    printf("Enter three sides: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a + b <= c || a + c <= b || b + c <= a)
        printf("Invalid Triangle\n");

    else if (a == b && b == c)
        printf("Equilateral Triangle\n");

    else if (a == b || b == c || a == c)
        printf("Isosceles Triangle\n");

    else
        printf("Scalene Triangle\n");

    return 0;
}


/* =========================================================
Q9. Calculate Profit or Loss
=========================================================

#include <stdio.h>

int main() {
    float costPrice, sellingPrice;

    printf("Enter Cost Price: ");
    scanf("%f", &costPrice);

    printf("Enter Selling Price: ");
    scanf("%f", &sellingPrice);

    if (sellingPrice > costPrice)
        printf("Profit = Rs. %.2f\n", sellingPrice - costPrice);

    else if (costPrice > sellingPrice)
        printf("Loss = Rs. %.2f\n", costPrice - sellingPrice);

    else
        printf("No Profit No Loss\n");

    return 0;
}


/* =========================================================
Q10. Check Eligibility for Voting
=========================================================

#include <stdio.h>

int main() {
    int age;

    printf("Enter your age: ");
    scanf("%d", &age);

    if (age >= 18)
        printf("Eligible to vote\n");
    else
        printf("Not eligible to vote\n");

    return 0;
}

============================================================
IMPORTANT:
Each program contains its own main() function.

To run individual programs, uncomment one program at a time,
or save each question as a separate .c file.
============================================================
*/
