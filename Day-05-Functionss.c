/*
============================================================
DAY 5: FUNCTIONS
10 Interview-Oriented C Questions + Answers

Focus:
- Function declaration
- Function definition
- Parameters and return values
- Call by value
- Pointers with functions
- Recursion
============================================================
*/


/* =========================================================
Q1. Write a function to add two numbers.
========================================================= */

#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int main()
{
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("Sum = %d\n", add(a, b));

    return 0;
}


/* =========================================================
Q2. Write a function to check whether a number is even.
=========================================================

#include <stdio.h>

int isEven(int n)
{
    return (n % 2 == 0);
}

int main()
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (isEven(n))
        printf("Even\n");
    else
        printf("Odd\n");

    return 0;
}


/* =========================================================
Q3. Write a function to find the largest of three numbers.
=========================================================

#include <stdio.h>

int largest(int a, int b, int c)
{
    if (a >= b && a >= c)
        return a;
    else if (b >= a && b >= c)
        return b;
    else
        return c;
}

int main()
{
    int a, b, c;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    printf("Largest = %d\n", largest(a, b, c));

    return 0;
}


/* =========================================================
Q4. Write a function to calculate factorial.
=========================================================

#include <stdio.h>

unsigned long long factorial(int n)
{
    unsigned long long result = 1;

    for (int i = 1; i <= n; i++)
        result *= i;

    return result;
}

int main()
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0)
        printf("Invalid input\n");
    else
        printf("Factorial = %llu\n", factorial(n));

    return 0;
}


/* =========================================================
Q5. Write a function to check whether a number is prime.
=========================================================

#include <stdio.h>

int isPrime(int n)
{
    if (n <= 1)
        return 0;

    for (int i = 2; i <= n / i; i++)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int main()
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (isPrime(n))
        printf("Prime number\n");
    else
        printf("Not a prime number\n");

    return 0;
}


/* =========================================================
Q6. Swap two numbers using a function.

IMPORTANT:
Use pointers so that the original variables are modified.
=========================================================

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("Before swapping: a = %d, b = %d\n", a, b);

    swap(&a, &b);

    printf("After swapping: a = %d, b = %d\n", a, b);

    return 0;
}


/* =========================================================
Q7. Write a function to find GCD of two numbers.
=========================================================

#include <stdio.h>

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int main()
{
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("GCD = %d\n", gcd(a, b));

    return 0;
}


/* =========================================================
Q8. Write a recursive function to calculate factorial.
=========================================================

#include <stdio.h>

unsigned long long factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return n * factorial(n - 1);
}

int main()
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0)
        printf("Invalid input\n");
    else
        printf("Factorial = %llu\n", factorial(n));

    return 0;
}


/* =========================================================
Q9. Write a recursive function to find the sum of numbers
from 1 to N.

Example:
N = 5
Result = 15
=========================================================

#include <stdio.h>

int sum(int n)
{
    if (n == 0)
        return 0;

    return n + sum(n - 1);
}

int main()
{
    int n;

    printf("Enter N: ");
    scanf("%d", &n);

    if (n < 0)
        printf("Invalid input\n");
    else
        printf("Sum = %d\n", sum(n));

    return 0;
}


/* =========================================================
Q10. Write a function to count set bits in an integer.

Embedded interview-oriented question.
=========================================================

#include <stdio.h>

int countSetBits(unsigned int n)
{
    int count = 0;

    while (n != 0)
    {
        count += n & 1U;
        n >>= 1;
    }

    return count;
}

int main()
{
    unsigned int n;

    printf("Enter an unsigned integer: ");
    scanf("%u", &n);

    printf("Number of set bits = %d\n", countSetBits(n));

    return 0;
}


/*
============================================================
INTERVIEW QUESTIONS TO REVISE
============================================================

1. What is a function?

A reusable block of code that performs a specific task.

2. What is a function prototype?

It tells the compiler the function's name, return type,
and parameters before the function is called.

Example:
int add(int, int);

3. What is the difference between parameter and argument?

Parameter -> Variable defined in the function.
Argument  -> Actual value passed during the function call.

4. Does C support pass by reference?

No. C uses pass by value.

Pointers can be used to achieve reference-like behavior
by passing the address of a variable.

5. Why do we use pointers with functions?

To allow a function to modify the original variable and
to efficiently work with arrays, structures, and memory.

6. What is recursion?

A function calling itself.

7. What is a base case?

The condition that stops recursive calls.

8. Embedded C relevance:

Functions are heavily used for modular firmware such as:

    init_gpio();
    read_sensor();
    uart_send();
    timer_init();
    adc_read();

============================================================
GITHUB STRUCTURE
============================================================

Day-05-Functions/
│
├── q01_add_function.c
├── q02_even_function.c
├── q03_largest_function.c
├── q04_factorial_function.c
├── q05_prime_function.c
├── q06_swap_pointers.c
├── q07_gcd_function.c
├── q08_recursive_factorial.c
├── q09_recursive_sum.c
└── q10_count_set_bits.c

============================================================
DAY 5 COMPLETE
============================================================
*/
