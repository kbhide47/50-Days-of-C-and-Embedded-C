/*
============================================================
DAY 4: PATTERNS & LOGIC BUILDING
10 Questions + Answers
Topics:
Nested loops, rows, columns, pattern logic
============================================================
*/


/* =========================================================
Q1. Print a square star pattern

Example for n = 4:

* * * *
* * * *
* * * *
* * * *
========================================================= */

#include <stdio.h>

int main() {
    int n;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}


/* =========================================================
Q2. Print a right-angled triangle

Example for n = 4:

*
* *
* * *
* * * *
=========================================================

#include <stdio.h>

int main() {
    int n;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}


/* =========================================================
Q3. Print an inverted right-angled triangle

Example:

* * * *
* * *
* *
*
=========================================================

#include <stdio.h>

int main() {
    int n;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}


/* =========================================================
Q4. Print number triangle

Example:

1
1 2
1 2 3
1 2 3 4
=========================================================

#include <stdio.h>

int main() {
    int n;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    return 0;
}


/* =========================================================
Q5. Print repeated number triangle

Example:

1
2 2
3 3 3
4 4 4 4
=========================================================

#include <stdio.h>

int main() {
    int n;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", i);
        }
        printf("\n");
    }

    return 0;
}


/* =========================================================
Q6. Print Floyd's Triangle

Example:

1
2 3
4 5 6
7 8 9 10
=========================================================

#include <stdio.h>

int main() {
    int n;
    int number = 1;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", number);
            number++;
        }
        printf("\n");
    }

    return 0;
}


/* =========================================================
Q7. Print a pyramid pattern

Example:

   *
  * *
 * * *
* * * *
=========================================================

#include <stdio.h>

int main() {
    int n;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {

        // Print spaces
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }

        // Print stars
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }

        printf("\n");
    }

    return 0;
}


/* =========================================================
Q8. Print an inverted pyramid

Example:

* * * *
 * * *
  * *
   *
=========================================================

#include <stdio.h>

int main() {
    int n;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    for (int i = n; i >= 1; i--) {

        // Print spaces
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }

        // Print stars
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }

        printf("\n");
    }

    return 0;
}


/* =========================================================
Q9. Print a hollow square

Example:

* * * *
*     *
*     *
* * * *
=========================================================

#include <stdio.h>

int main() {
    int n;

    printf("Enter size: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= n; j++) {

            if (i == 1 || i == n ||
                j == 1 || j == n)
                printf("* ");
            else
                printf("  ");
        }

        printf("\n");
    }

    return 0;
}


/* =========================================================
Q10. Print a diamond pattern

Example:

   *
  * *
 * * *
* * * *
 * * *
  * *
   *
=========================================================

#include <stdio.h>

int main() {
    int n;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    // Upper half
    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= n - i; j++)
            printf(" ");

        for (int j = 1; j <= i; j++)
            printf("* ");

        printf("\n");
    }

    // Lower half
    for (int i = n - 1; i >= 1; i--) {

        for (int j = 1; j <= n - i; j++)
            printf(" ");

        for (int j = 1; j <= i; j++)
            printf("* ");

        printf("\n");
    }

    return 0;
}


/*
============================================================
INTERVIEW REVISION
============================================================

1. What is a nested loop?

   A loop inside another loop is called a nested loop.

2. How many times does the inner loop execute?

   It depends on the outer loop's current iteration and the
   condition of the inner loop.

3. Why are nested loops useful?

   They are useful for matrices, 2D arrays, patterns,
   tables, and repetitive hardware-related operations.

4. What is the main skill developed through pattern problems?

   Logical thinking and understanding how loops control
   rows, columns, and repeated operations.

5. Embedded relevance:

   Nested-loop logic is useful when working with:
   - 2D arrays
   - Sensor/data tables
   - Buffer processing
   - Matrix operations
   - Display control
   - Repetitive hardware operations

============================================================
GITHUB STRUCTURE
============================================================

Day-04-Patterns/
│
├── q01_square_pattern.c
├── q02_right_triangle.c
├── q03_inverted_triangle.c
├── q04_number_triangle.c
├── q05_repeated_number_triangle.c
├── q06_floyds_triangle.c
├── q07_pyramid.c
├── q08_inverted_pyramid.c
├── q09_hollow_square.c
└── q10_diamond.c

============================================================
DAY 4 COMPLETE
============================================================
*/
