/* =========================================================
   DAY 19 — BITWISE PRACTICE
   ========================================================= */


/* =========================================================
   Q1. Convert decimal number to binary
   File: q01_decimal_to_binary.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    unsigned int number = 25;
    int i;

    printf("Binary of %u = ", number);

    for (i = 7; i >= 0; i--)
    {
        printf("%u", (number >> i) & 1U);
    }

    printf("\n");

    return 0;
}


/* =========================================================
   Q2. Convert an 8-bit binary number to decimal
   File: q02_binary_to_decimal.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    unsigned int binary = 10110101;
    unsigned int decimal = 0;
    int position = 0;

    while (binary != 0)
    {
        unsigned int bit = binary % 10;

        decimal += bit << position;

        binary /= 10;
        position++;
    }

    printf("Decimal = %u\n", decimal);

    return 0;
}


/* =========================================================
   Q3. Display hexadecimal value in binary
   File: q03_hex_to_binary.c
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t value = 0x5A;

    printf("Binary = ");

    for (int i = 7; i >= 0; i--)
    {
        printf("%u", (value >> i) & 1U);
    }

    printf("\n");

    return 0;
}


/* =========================================================
   Q4. Swap upper and lower nibbles
   File: q04_swap_nibbles.c
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t number = 0xAB;

    uint8_t result =
        (uint8_t)((number << 4) | (number >> 4));

    printf("Before = 0x%02X\n", number);
    printf("After  = 0x%02X\n", result);

    return 0;
}


/* =========================================================
   Q5. Check nth bit
   File: q05_check_nth_bit.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    unsigned int number = 18;
    unsigned int n = 4;

    if (number & (1U << n))
        printf("Bit %u is SET\n", n);
    else
        printf("Bit %u is CLEAR\n", n);

    return 0;
}


/* =========================================================
   Q6. Set lower four bits
   File: q06_set_lower_four_bits.c
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t number = 0xA0;

    number |= 0x0F;

    printf("Result = 0x%02X\n", number);

    return 0;
}


/* =========================================================
   Q7. Clear lower four bits
   File: q07_clear_lower_four_bits.c
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t number = 0xAF;

    number &= 0xF0;

    printf("Result = 0x%02X\n", number);

    return 0;
}


/* =========================================================
   Q8. Rotate an 8-bit number left by one position
   File: q08_rotate_left_8bit.c
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t number = 0x81;

    uint8_t result =
        (uint8_t)((number << 1) | (number >> 7));

    printf("Before = 0x%02X\n", number);
    printf("After  = 0x%02X\n", result);

    return 0;
}


/* =========================================================
   Q9. Find the number occurring an odd number of times
   File: q09_find_odd_occurring_number.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int arr[] = {2, 3, 2, 4, 3, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = 0;

    for (int i = 0; i < n; i++)
    {
        result ^= arr[i];
    }

    printf("Odd occurring number = %d\n", result);

    return 0;
}


/* =========================================================
   Q10. Bitwise output question
   File: q10_bitwise_output_question.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    unsigned int x = 5;
    unsigned int y = 3;

    printf("x & y = %u\n", x & y);
    printf("x | y = %u\n", x | y);
    printf("x ^ y = %u\n", x ^ y);
    printf("x << 1 = %u\n", x << 1);
    printf("x >> 1 = %u\n", x >> 1);

    return 0;
}
