/* =========================================================
   Q1: q01_bitwise_and.c
   Bitwise AND
   ========================================================= */

#include <stdio.h>

int main(void)
{
    unsigned int a = 12;  // 1100
    unsigned int b = 10;  // 1010

    unsigned int result = a & b;

    printf("a & b = %u\n", result);

    return 0;
}


/* =========================================================
   Q2: q02_bitwise_or.c
   Bitwise OR
   ========================================================= */

#include <stdio.h>

int main(void)
{
    unsigned int a = 12;  // 1100
    unsigned int b = 10;  // 1010

    unsigned int result = a | b;

    printf("a | b = %u\n", result);

    return 0;
}


/* =========================================================
   Q3: q03_bitwise_xor.c
   Bitwise XOR
   ========================================================= */

#include <stdio.h>

int main(void)
{
    unsigned int a = 12;  // 1100
    unsigned int b = 10;  // 1010

    unsigned int result = a ^ b;

    printf("a ^ b = %u\n", result);

    return 0;
}


/* =========================================================
   Q4: q04_bitwise_not.c
   Bitwise NOT
   ========================================================= */

#include <stdio.h>

int main(void)
{
    unsigned char a = 5;

    unsigned char result = (unsigned char)(~a);

    printf("~a = %u\n", result);

    return 0;
}


/* =========================================================
   Q5: q05_left_shift.c
   Left shift
   ========================================================= */

#include <stdio.h>

int main(void)
{
    unsigned int number = 5;

    unsigned int result = number << 2;

    printf("5 << 2 = %u\n", result);

    return 0;
}


/* =========================================================
   Q6: q06_right_shift.c
   Right shift
   ========================================================= */

#include <stdio.h>

int main(void)
{
    unsigned int number = 20;

    unsigned int result = number >> 2;

    printf("20 >> 2 = %u\n", result);

    return 0;
}


/* =========================================================
   Q7: q07_check_even_odd_bitwise.c
   Check even/odd using bitwise AND
   ========================================================= */

#include <stdio.h>

int main(void)
{
    unsigned int number;

    printf("Enter a number: ");
    scanf("%u", &number);

    if (number & 1U)
        printf("Odd number\n");
    else
        printf("Even number\n");

    return 0;
}


/* =========================================================
   Q8: q08_set_bit.c
   Set a specific bit
   ========================================================= */

#include <stdio.h>

int main(void)
{
    unsigned int number = 8;
    unsigned int bit = 1;

    number = number | (1U << bit);

    printf("After setting bit %u = %u\n", bit, number);

    return 0;
}


/* =========================================================
   Q9: q09_clear_bit.c
   Clear a specific bit
   ========================================================= */

#include <stdio.h>

int main(void)
{
    unsigned int number = 15;
    unsigned int bit = 2;

    number = number & ~(1U << bit);

    printf("After clearing bit %u = %u\n", bit, number);

    return 0;
}


/* =========================================================
   Q10: q10_toggle_bit.c
   Toggle a specific bit
   ========================================================= */

#include <stdio.h>

int main(void)
{
    unsigned int number = 8;
    unsigned int bit = 3;

    number = number ^ (1U << bit);

    printf("After toggling bit %u = %u\n", bit, number);

    return 0;
}
