/*
============================================================
DAY 5: FUNCTIONS & RECURSION
10 Questions + Answers

Topics:
- Function declaration
- Function definition
- Function call
- Arguments and return values
- Recursion
============================================================
*/


/* =========================================================
Q1. Find factorial of a number using a function
========================================================= */

#include <stdio.h>

unsigned long long factorial(int n) {
    unsigned long long result = 1;

    for (int i = 1; i <= n; i++) {
        result *= i;
    }

    return result;
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0)
        printf("Factorial is not defined for negative numbers\n");
    else
        printf("Factorial = %llu\n", factorial(n));

    return 0;
}


/* =========================================================
Q2. Check whether a number is prime using a function
=========================================================

#include <stdio.h>

int isPrime(int n) {
    if (n <= 1)
        return 0;

    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (isPrime(n))
        printf("%d is Prime\n", n);
    else
        printf("%d is Not Prime\n", n);

    return 0;
}


/* =========================================================
Q3. Find the maximum of two numbers using a function
=========================================================

#include <stdio.h>

int findMax(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int main() {
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("Maximum = %d\n", findMax(a, b));

    return 0;
}


/* =========================================================
Q4. Calculate power of a number using a function
Example: 2^5 = 32
=========================================================

#include <stdio.h>

long long power(int base, int exponent) {
    long long result = 1;

    for (int i = 1; i <= exponent; i++) {
        result *= base;
    }

    return result;
}

int main() {
    int base, exponent;

    printf("Enter base and exponent: ");
    scanf("%d %d", &base, &exponent);

    if (exponent < 0)
        printf("Negative exponents are not handled in this program\n");
    else
        printf("Result = %lld\n", power(base, exponent));

    return 0;
}


/* =========================================================
Q5. Find GCD of two numbers using a function
=========================================================

#include <stdio.h>

int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int main() {
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("GCD = %d\n", findGCD(a, b));

    return 0;
}


/* =========================================================
Q6. Find LCM of two numbers using functions
Formula:
LCM = (a * b) / GCD
=========================================================

#include <stdio.h>

int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int findLCM(int a, int b) {
    return (a * b) / findGCD(a, b);
}

int main() {
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    if (a == 0 || b == 0)
        printf("LCM = 0\n");
    else
        printf("LCM = %d\n", findLCM(a, b));

    return 0;
}


/* =========================================================
Q7. Swap two numbers using a function and pointers

Important for Embedded C interviews:
C normally passes arguments by value, so pointers allow
the function to modify the original variables.
=========================================================

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    swap(&a, &b);

    printf("After swapping: a = %d, b = %d\n", a, b);

    return 0;
}


/* =========================================================
Q8. Find sum of digits using recursion
Example: 1234 = 1 + 2 + 3 + 4 = 10
=========================================================

#include <stdio.h>

int sumOfDigits(int n) {
    if (n == 0)
        return 0;

    return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0)
        n = -n;

    printf("Sum of digits = %d\n", sumOfDigits(n));

    return 0;
}


/* =========================================================
Q9. Find factorial using recursion
=========================================================

#include <stdio.h>

unsigned long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;

    return n * factorial(n - 1);
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0)
        printf("Factorial is not defined for negative numbers\n");
    else
        printf("Factorial = %llu\n", factorial(n));

    return 0;
}


/* =========================================================
Q10. Print Fibonacci series using recursion
=========================================================

#include <stdio.h>

unsigned long long fibonacci(int n) {
    if (n <= 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Enter a positive number\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        printf("%llu ", fibonacci(i));
    }

    return 0;
}


/*
============================================================
INTERVIEW REVISION
============================================================

1. What is a function?

   A function is a reusable block of code designed to
   perform a specific task.

2. What is the difference between declaration and definition?

   Declaration tells the compiler about the function.

   Definition contains the actual implementation.

3. What is a function prototype?

   Example:
   int add(int, int);

4. What is recursion?

   A function calling itself until it reaches a base case.

5. What is the base case?

   The condition that stops recursive calls.

6. What is pass by value?

   A copy of the variable is passed to the function.
   Changes do not affect the original variable.

7. How can we modify the original variable in C?

   By passing its address using pointers.

8. Embedded C interview point:

   Functions improve:
   - Code modularity
   - Code reuse
   - Readability
   - Testing
   - Maintainability

============================================================
GITHUB STRUCTURE
============================================================

Day-05-Functions/
│
├── q01_factorial_function.c
├── q02_prime_function.c
├── q03_maximum_function.c
├── q04_power_function.c
├── q05_gcd_function.c
├── q06_lcm_function.c
├── q07_swap_using_pointers.c
├── q08_recursive_sum_digits.c
├── q09_recursive_factorial.c
└── q10_recursive_fibonacci.c

============================================================
DAY 5 COMPLETE
============================================================
*/
