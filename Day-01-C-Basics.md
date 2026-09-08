/*
Day 1: C Basics
10 Basic C Programming Questions
*/

// ==================================================
// Q1. Swap Two Numbers
// ==================================================
#include <stdio.h>

int main() {
    int a, b, temp;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    temp = a;
    a = b;
    b = temp;

    printf("After swapping: a = %d, b = %d\n", a, b);

    return 0;
}

/*
==================================================
Q2. Find the Largest of Two Numbers
==================================================

#include <stdio.h>

int main() {
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    if (a > b)
        printf("%d is largest\n", a);
    else if (b > a)
        printf("%d is largest\n", b);
    else
        printf("Both numbers are equal\n");

    return 0;
}


==================================================
Q3. Find the Largest of Three Numbers
==================================================

#include <stdio.h>

int main() {
    int a, b, c;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a >= b && a >= c)
        printf("%d is largest\n", a);
    else if (b >= a && b >= c)
        printf("%d is largest\n", b);
    else
        printf("%d is largest\n", c);

    return 0;
}


==================================================
Q4. Check Even or Odd
==================================================

#include <stdio.h>

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num % 2 == 0)
        printf("Even\n");
    else
        printf("Odd\n");

    return 0;
}


==================================================
Q5. Check Positive, Negative, or Zero
==================================================

#include <stdio.h>

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num > 0)
        printf("Positive\n");
    else if (num < 0)
        printf("Negative\n");
    else
        printf("Zero\n");

    return 0;
}


==================================================
Q6. Print ASCII Value of a Character
==================================================

#include <stdio.h>

int main() {
    char ch;

    printf("Enter a character: ");
    scanf("%c", &ch);

    printf("ASCII value of %c = %d\n", ch, ch);

    return 0;
}


==================================================
Q7. Simple Calculator
==================================================

#include <stdio.h>

int main() {
    float a, b;
    char op;

    printf("Enter expression (example: 5 + 3): ");
    scanf("%f %c %f", &a, &op, &b);

    if (op == '+')
        printf("Result = %.2f\n", a + b);
    else if (op == '-')
        printf("Result = %.2f\n", a - b);
    else if (op == '*')
        printf("Result = %.2f\n", a * b);
    else if (op == '/') {
        if (b != 0)
            printf("Result = %.2f\n", a / b);
        else
            printf("Division by zero is not possible\n");
    }
    else
        printf("Invalid operator\n");

    return 0;
}


==================================================
Q8. Calculate Simple Interest
==================================================

#include <stdio.h>

int main() {
    float principal, rate, time, simpleInterest;

    printf("Enter principal amount: ");
    scanf("%f", &principal);

    printf("Enter rate: ");
    scanf("%f", &rate);

    printf("Enter time: ");
    scanf("%f", &time);

    simpleInterest = (principal * rate * time) / 100;

    printf("Simple Interest = %.2f\n", simpleInterest);

    return 0;
}


==================================================
Q9. Convert Celsius to Fahrenheit
==================================================

#include <stdio.h>

int main() {
    float celsius, fahrenheit;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = (celsius * 9 / 5) + 32;

    printf("Temperature in Fahrenheit = %.2f\n", fahrenheit);

    return 0;
}


==================================================
Q10. Check Vowel or Consonant
==================================================

#include <stdio.h>

int main() {
    char ch;

    printf("Enter a character: ");
    scanf(" %c", &ch);

    if ((ch >= 'A' && ch <= 'Z') ||
        (ch >= 'a' && ch <= 'z')) {

        if (ch == 'a' || ch == 'e' || ch == 'i' ||
            ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' ||
            ch == 'O' || ch == 'U')
            printf("%c is a Vowel\n", ch);
        else
            printf("%c is a Consonant\n", ch);
    }
    else {
        printf("Invalid input. Please enter an alphabet.\n");
    }

    return 0;
}
*/
