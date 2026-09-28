/* =========================================================
   DAY 17 — BIT MANIPULATION
   ========================================================= */


/* =========================================================
   Q1. Check whether a particular bit is set
   File: q01_check_bit.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    unsigned int number = 10;
    unsigned int bit = 1;

    if (number & (1U << bit))
        printf("Bit %u is SET\n", bit);
    else
        printf("Bit %u is CLEAR\n", bit);

    return 0;
}


/* =========================================================
   Q2. Set a particular bit
   File: q02_set_bit.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    unsigned int number = 8;
    unsigned int bit = 1;

    number |= (1U << bit);

    printf("Result = %u\n", number);

    return 0;
}


/* =========================================================
   Q3. Clear a particular bit
   File: q03_clear_bit.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    unsigned int number = 15;
    unsigned int bit = 2;

    number &= ~(1U << bit);

    printf("Result = %u\n", number);

    return 0;
}


/* =========================================================
   Q4. Toggle a particular bit
   File: q04_toggle_bit.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    unsigned int number = 10;
    unsigned int bit = 1;

    number ^= (1U << bit);

    printf("Result = %u\n", number);

    return 0;
}


/* =========================================================
   Q5. Update a bit to either 0 or 1
   File: q05_update_bit.c
   ========================================================= */

#include <stdio.h>

void update_bit(unsigned int *number,
                unsigned int bit,
                unsigned int value)
{
    if (value)
        *number |= (1U << bit);
    else
        *number &= ~(1U << bit);
}

int main(void)
{
    unsigned int number = 8;

    update_bit(&number, 1, 1);

    printf("After setting bit = %u\n", number);

    update_bit(&number, 3, 0);

    printf("After clearing bit = %u\n", number);

    return 0;
}


/* =========================================================
   Q6. Extract bits 2 to 4 from a number
   File: q06_extract_bits.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    unsigned int number = 0x3C;

    /*
       Mask for bits 2, 3 and 4:

       00011100
       0x1C
    */

    unsigned int result = (number >> 2) & 0x07;

    printf("Extracted value = %u\n", result);

    return 0;
}


/* =========================================================
   Q7. Set multiple bits using a mask
   File: q07_set_multiple_bits.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    unsigned int number = 0x00;
    unsigned int mask = 0x0F;

    number |= mask;

    printf("Result = 0x%02X\n", number);

    return 0;
}


/* =========================================================
   Q8. Clear multiple bits using a mask
   File: q08_clear_multiple_bits.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    unsigned int number = 0xFF;
    unsigned int mask = 0x0F;

    number &= ~mask;

    printf("Result = 0x%02X\n", number);

    return 0;
}


/* =========================================================
   Q9. Count number of set bits
   File: q09_count_set_bits.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    unsigned int number = 29;
    unsigned int count = 0;

    while (number != 0)
    {
        count += number & 1U;
        number >>= 1;
    }

    printf("Number of set bits = %u\n", count);

    return 0;
}


/* =========================================================
   Q10. Check whether a number is a power of 2
   File: q10_power_of_two.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    unsigned int number = 16;

    if (number != 0 && (number & (number - 1U)) == 0)
        printf("Power of 2\n");
    else
        printf("Not a power of 2\n");

    return 0;
}
