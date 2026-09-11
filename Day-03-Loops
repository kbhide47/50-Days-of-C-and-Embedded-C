/*
============================================================
DAY 3: LOOPS
10 Questions + Answers
Topics:
for loop, while loop, do-while loop
break, continue
============================================================
*/


/* =========================================================
Q1. Print numbers from 1 to N
========================================================= */

#include <stdio.h>

int main() {
    int n;

    printf("Enter N: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        printf("%d ", i);

    return 0;
}


/* =========================================================
Q2. Find the sum of numbers from 1 to N
=========================================================

#include <stdio.h>

int main() {
    int n, sum = 0;

    printf("Enter N: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        sum += i;

    printf("Sum = %d\n", sum);

    return 0;
}


/* =========================================================
Q3. Print multiplication table of a number
=========================================================

#include <stdio.h>

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    for (int i = 1; i <= 10; i++)
        printf("%d x %d = %d\n", n, i, n * i);

    return 0;
}


/* =========================================================
Q4. Find factorial of a number
=========================================================

#include <stdio.h>

int main() {
    int n;
    unsigned long long factorial = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial is not defined for negative numbers\n");
        return 0;
    }

    for (int i = 1; i <= n; i++)
        factorial *= i;

    printf("Factorial = %llu\n", factorial);

    return 0;
}


/* =========================================================
Q5. Reverse a number
=========================================================

#include <stdio.h>

int main() {
    int n, reverse = 0, digit;

    printf("Enter a number: ");
    scanf("%d", &n);

    while (n != 0) {
        digit = n % 10;
        reverse = reverse * 10 + digit;
        n /= 10;
    }

    printf("Reverse = %d\n", reverse);

    return 0;
}


/* =========================================================
Q6. Count the number of digits
=========================================================

#include <stdio.h>

int main() {
    int n, count = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n == 0) {
        count = 1;
    } else {
        if (n < 0)
            n = -n;

        while (n != 0) {
            n /= 10;
            count++;
        }
    }

    printf("Number of digits = %d\n", count);

    return 0;
}


/* =========================================================
Q7. Find the sum of digits
=========================================================

#include <stdio.h>

int main() {
    int n, sum = 0, digit;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0)
        n = -n;

    while (n != 0) {
        digit = n % 10;
        sum += digit;
        n /= 10;
    }

    printf("Sum of digits = %d\n", sum);

    return 0;
}


/* =========================================================
Q8. Check whether a number is a palindrome
Example: 121 -> Palindrome
=========================================================

#include <stdio.h>

int main() {
    int n, original, reverse = 0, digit;

    printf("Enter a number: ");
    scanf("%d", &n);

    original = n;

    while (n != 0) {
        digit = n % 10;
        reverse = reverse * 10 + digit;
        n /= 10;
    }

    if (original == reverse)
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");

    return 0;
}


/* =========================================================
Q9. Check whether a number is prime
=========================================================

#include <stdio.h>

int main() {
    int n, isPrime = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n <= 1) {
        isPrime = 0;
    } else {
        for (int i = 2; i <= n / i; i++) {
            if (n % i == 0) {
                isPrime = 0;
                break;
            }
        }
    }

    if (isPrime)
        printf("Prime number\n");
    else
        printf("Not a prime number\n");

    return 0;
}


/* =========================================================
Q10. Print Fibonacci Series
Example: 0 1 1 2 3 5 8...
=========================================================

#include <stdio.h>

int main() {
    int n;
    unsigned long long a = 0, b = 1, next;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Enter a positive number\n");
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        printf("%llu ", a);

        next = a + b;
        a = b;
        b = next;
    }

    return 0;
}


/*
============================================================
INTERVIEW REVISION
============================================================

1. What is the difference between for and while?

   for    -> Generally used when the number of iterations
             is known.

   while  -> Generally used when the termination condition
             is more important than the iteration count.

2. What is a do-while loop?

   A do-while loop executes its body at least once because
   the condition is checked after execution.

3. What does break do?

   It immediately terminates the loop.

4. What does continue do?

   It skips the remaining statements of the current
   iteration and moves to the next iteration.

5. Why are loops important in Embedded C?

   Loops are frequently used for repetitive operations such
   as polling GPIO, processing buffers, checking flags,
   handling communication data, and running control logic.

============================================================
GITHUB STRUCTURE
============================================================

Day-03-Loops/
│
├── q01_print_1_to_n.c
├── q02_sum_1_to_n.c
├── q03_multiplication_table.c
├── q04_factorial.c
├── q05_reverse_number.c
├── q06_count_digits.c
├── q07_sum_of_digits.c
├── q08_palindrome.c
├── q09_prime_number.c
└── q10_fibonacci.c

============================================================
*/
