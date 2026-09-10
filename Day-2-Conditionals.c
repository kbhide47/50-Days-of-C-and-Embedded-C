/*
============================================================
DAY 2: CONDITIONAL STATEMENTS
10 Questions + Answers
Topics:
if, if-else, else-if, nested if, switch-case,
logical operators, relational operators
============================================================
*/


/* =========================================================
Q1. Check whether a number is divisible by both 5 and 11
========================================================= */

#include <stdio.h>

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n % 5 == 0 && n % 11 == 0)
        printf("Divisible by both 5 and 11\n");
    else
        printf("Not divisible by both 5 and 11\n");

    return 0;
}


/* =========================================================
Q2. Find the largest among three numbers
=========================================================

#include <stdio.h>

int main() {
    int a, b, c;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a >= b && a >= c)
        printf("Largest = %d\n", a);
    else if (b >= a && b >= c)
        printf("Largest = %d\n", b);
    else
        printf("Largest = %d\n", c);

    return 0;
}


/* =========================================================
Q3. Check whether a number is a multiple of 3, 5, both,
or neither
=========================================================

#include <stdio.h>

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n % 3 == 0 && n % 5 == 0)
        printf("Multiple of both 3 and 5\n");
    else if (n % 3 == 0)
        printf("Multiple of 3\n");
    else if (n % 5 == 0)
        printf("Multiple of 5\n");
    else
        printf("Multiple of neither 3 nor 5\n");

    return 0;
}


/* =========================================================
Q4. Check whether a character is uppercase, lowercase,
digit, or special character
=========================================================

#include <stdio.h>

int main() {
    char ch;

    printf("Enter a character: ");
    scanf(" %c", &ch);

    if (ch >= 'A' && ch <= 'Z')
        printf("Uppercase alphabet\n");
    else if (ch >= 'a' && ch <= 'z')
        printf("Lowercase alphabet\n");
    else if (ch >= '0' && ch <= '9')
        printf("Digit\n");
    else
        printf("Special character\n");

    return 0;
}


/* =========================================================
Q5. Check whether three sides form a valid triangle
=========================================================

#include <stdio.h>

int main() {
    int a, b, c;

    printf("Enter three sides: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a + b > c && a + c > b && b + c > a)
        printf("Valid triangle\n");
    else
        printf("Invalid triangle\n");

    return 0;
}


/* =========================================================
Q6. Determine the type of triangle
=========================================================

#include <stdio.h>

int main() {
    int a, b, c;

    printf("Enter three sides: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a + b <= c || a + c <= b || b + c <= a)
        printf("Invalid triangle\n");
    else if (a == b && b == c)
        printf("Equilateral triangle\n");
    else if (a == b || b == c || a == c)
        printf("Isosceles triangle\n");
    else
        printf("Scalene triangle\n");

    return 0;
}


/* =========================================================
Q7. Check whether a year is a leap year
=========================================================

#include <stdio.h>

int main() {
    int year;

    printf("Enter year: ");
    scanf("%d", &year);

    if ((year % 400 == 0) ||
        (year % 4 == 0 && year % 100 != 0))
        printf("Leap year\n");
    else
        printf("Not a leap year\n");

    return 0;
}


/* =========================================================
Q8. Simple calculator using switch-case
=========================================================

#include <stdio.h>

int main() {
    float a, b;
    char op;

    printf("Enter expression (example: 10 + 5): ");
    scanf("%f %c %f", &a, &op, &b);

    switch (op) {

        case '+':
            printf("Result = %.2f\n", a + b);
            break;

        case '-':
            printf("Result = %.2f\n", a - b);
            break;

        case '*':
            printf("Result = %.2f\n", a * b);
            break;

        case '/':
            if (b != 0)
                printf("Result = %.2f\n", a / b);
            else
                printf("Cannot divide by zero\n");
            break;

        default:
            printf("Invalid operator\n");
    }

    return 0;
}


/* =========================================================
Q9. Calculate electricity bill
=========================================================

#include <stdio.h>

int main() {
    int units;
    float bill;

    printf("Enter units consumed: ");
    scanf("%d", &units);

    if (units <= 100)
        bill = units * 5;
    else if (units <= 200)
        bill = (100 * 5) + (units - 100) * 7;
    else
        bill = (100 * 5) + (100 * 7) + (units - 200) * 10;

    printf("Electricity Bill = Rs. %.2f\n", bill);

    return 0;
}


/* =========================================================
Q10. Menu-driven program using switch-case
=========================================================

#include <stdio.h>

int main() {
    int choice, n;

    printf("1. Check Even/Odd\n");
    printf("2. Check Positive/Negative\n");
    printf("3. Check Divisible by 5\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter a number: ");
    scanf("%d", &n);

    switch (choice) {

        case 1:
            if (n % 2 == 0)
                printf("Even\n");
            else
                printf("Odd\n");
            break;

        case 2:
            if (n > 0)
                printf("Positive\n");
            else if (n < 0)
                printf("Negative\n");
            else
                printf("Zero\n");
            break;

        case 3:
            if (n % 5 == 0)
                printf("Divisible by 5\n");
            else
                printf("Not divisible by 5\n");
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}


/*
============================================================
INTERVIEW REVISION
============================================================

1. Difference between = and ==

   =  -> Assignment operator
   == -> Comparison operator

2. Difference between && and ||

   && -> Both conditions must be true
   || -> At least one condition must be true

3. When should switch-case be used?

   switch-case is useful when one expression needs to be
   compared against multiple constant values.

4. Can switch use float?

   No. switch expressions should be of integral/enum type
   (such as int or char), not float.

5. Why is break used in switch?

   break prevents execution from continuing into the next
   case (fall-through).

============================================================
GITHUB TASK
============================================================

Day-02-Conditionals/
│
├── q01_divisible_5_11.c
├── q02_largest_three.c
├── q03_multiple_3_5.c
├── q04_character_type.c
├── q05_valid_triangle.c
├── q06_triangle_type.c
├── q07_leap_year.c
├── q08_calculator_switch.c
├── q09_electricity_bill.c
└── q10_menu_driven.c

============================================================
*/
