/* =========================================================
   DAY 18 — BITWISE INTERVIEW PROBLEMS
   ========================================================= */


/* =========================================================
   Q1. Set a specific register bit
   File: q01_set_register_bit.c
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t reg = 0x00;

    /* Set bit 3 */
    reg |= (uint8_t)(1U << 3);

    printf("Register = 0x%02X\n", reg);

    return 0;
}


/* =========================================================
   Q2. Clear a specific register bit
   File: q02_clear_register_bit.c
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t reg = 0xFF;

    /* Clear bit 4 */
    reg &= (uint8_t)~(1U << 4);

    printf("Register = 0x%02X\n", reg);

    return 0;
}


/* =========================================================
   Q3. Check whether a register bit is set
   File: q03_check_register_bit.c
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t reg = 0x20;

    /* Check bit 5 */
    if (reg & (uint8_t)(1U << 5))
        printf("Bit 5 is SET\n");
    else
        printf("Bit 5 is CLEAR\n");

    return 0;
}


/* =========================================================
   Q4. Toggle a register bit
   File: q04_toggle_register_bit.c
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t reg = 0x08;

    /* Toggle bit 3 */
    reg ^= (uint8_t)(1U << 3);

    printf("Register = 0x%02X\n", reg);

    return 0;
}


/* =========================================================
   Q5. Extract a bit field
   Extract bits 2-4 from an 8-bit register
   File: q05_extract_bit_field.c
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t reg = 0x3C;

    /*
       Bits 2, 3 and 4 are required.

       Mask = 00011100
            = 0x1C
    */

    uint8_t field = (uint8_t)((reg >> 2) & 0x07U);

    printf("Extracted field = %u\n", field);

    return 0;
}


/* =========================================================
   Q6. Replace a bit field
   Replace bits 2-4 with value 5
   File: q06_replace_bit_field.c
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t reg = 0xFF;
    uint8_t value = 5;

    /*
       Clear bits 2-4 first.
       Then insert the new value.
    */

    reg &= (uint8_t)~(0x07U << 2);

    reg |= (uint8_t)((value & 0x07U) << 2);

    printf("Register = 0x%02X\n", reg);

    return 0;
}


/* =========================================================
   Q7. Swap two numbers without a temporary variable
   File: q07_swap_without_temp.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    unsigned int a = 10;
    unsigned int b = 20;

    printf("Before: a = %u, b = %u\n", a, b);

    a ^= b;
    b ^= a;
    a ^= b;

    printf("After: a = %u, b = %u\n", a, b);

    return 0;
}


/* =========================================================
   Q8. Reverse all bits of an 8-bit number
   File: q08_reverse_bits.c
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t number = 0x16;
    uint8_t reversed = 0;

    for (int i = 0; i < 8; i++)
    {
        reversed <<= 1;
        reversed |= (uint8_t)(number & 1U);
        number >>= 1;
    }

    printf("Reversed = 0x%02X\n", reversed);

    return 0;
}


/* =========================================================
   Q9. Count set bits using Brian Kernighan's algorithm
   File: q09_count_set_bits_optimized.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    unsigned int number = 29;
    unsigned int count = 0;

    while (number != 0U)
    {
        number &= (number - 1U);
        count++;
    }

    printf("Set bits = %u\n", count);

    return 0;
}


/* =========================================================
   Q10. Simulate a control register
   Bit 0 = ENABLE
   Bit 1 = INTERRUPT
   Bit 2 = ERROR
   Bit 3 = RESET
   File: q10_register_control.c
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

#define ENABLE_BIT       (1U << 0)
#define INTERRUPT_BIT    (1U << 1)
#define ERROR_BIT        (1U << 2)
#define RESET_BIT        (1U << 3)

int main(void)
{
    uint8_t control_reg = 0;

    /* Enable device */
    control_reg |= ENABLE_BIT;

    /* Enable interrupt */
    control_reg |= INTERRUPT_BIT;

    printf("Register = 0x%02X\n", control_reg);

    /* Check ERROR bit */
    if (control_reg & ERROR_BIT)
        printf("ERROR = ON\n");
    else
        printf("ERROR = OFF\n");

    /* Set RESET */
    control_reg |= RESET_BIT;

    printf("After RESET = 0x%02X\n", control_reg);

    /* Disable interrupt */
    control_reg &= (uint8_t)~INTERRUPT_BIT;

    printf("After disabling interrupt = 0x%02X\n",
           control_reg);

    return 0;
}
