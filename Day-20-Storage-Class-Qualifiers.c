/* =========================================================
   DAY 20 — volatile, const, static, extern
   ========================================================= */


/* =========================================================
   Q1. Basic volatile variable
   File: q01_volatile_basic.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    volatile int flag = 0;

    flag = 1;

    printf("Flag = %d\n", flag);

    return 0;
}


/* =========================================================
   Q2. Volatile hardware-register simulation
   File: q02_volatile_register.c
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    volatile uint8_t STATUS_REG = 0x01;

    if (STATUS_REG & 0x01U)
        printf("Hardware status bit is SET\n");
    else
        printf("Hardware status bit is CLEAR\n");

    return 0;
}


/* =========================================================
   Q3. Volatile flag
   File: q03_volatile_flag.c
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

volatile uint8_t interrupt_flag = 0;

int main(void)
{
    interrupt_flag = 1;

    if (interrupt_flag)
        printf("Interrupt event detected\n");

    return 0;
}


/* =========================================================
   Q4. Const variable
   File: q04_const_variable.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    const int max_temperature = 100;

    printf("Maximum temperature = %d\n",
           max_temperature);

    /*
       This would be invalid:

       max_temperature = 120;
    */

    return 0;
}


/* =========================================================
   Q5. Const pointer variations
   File: q05_const_pointer.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int a = 10;
    int b = 20;

    /* Pointer to constant data */
    const int *ptr = &a;

    printf("Value = %d\n", *ptr);

    /* Pointer itself can change */
    ptr = &b;

    printf("Value = %d\n", *ptr);

    return 0;
}


/* =========================================================
   Q6. Static local variable
   File: q06_static_local.c
   ========================================================= */

#include <stdio.h>

void counter(void)
{
    static int count = 0;

    count++;

    printf("Count = %d\n", count);
}

int main(void)
{
    counter();
    counter();
    counter();

    return 0;
}


/* =========================================================
   Q7. Static global variable
   File: q07_static_global.c
   ========================================================= */

#include <stdio.h>

static int device_status = 1;

void display_status(void)
{
    printf("Device status = %d\n",
           device_status);
}

int main(void)
{
    display_status();

    return 0;
}


/* =========================================================
   Q8. extern variable
   File: q08_extern_variable.c
   ========================================================= */

#include <stdio.h>

int system_status = 100;

void display_status(void)
{
    extern int system_status;

    printf("System status = %d\n",
           system_status);
}

int main(void)
{
    display_status();

    return 0;
}


/* =========================================================
   Q9. Static function
   File: q09_static_function.c
   ========================================================= */

#include <stdio.h>

static void initialize_device(void)
{
    printf("Device initialized\n");
}

int main(void)
{
    initialize_device();

    return 0;
}


/* =========================================================
   Q10. Embedded-style volatile flag
   File: q10_embedded_volatile_flag.c
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

volatile uint8_t data_ready = 0;

void simulate_interrupt(void)
{
    /* Simulates an interrupt setting a flag */
    data_ready = 1;
}

int main(void)
{
    simulate_interrupt();

    if (data_ready)
    {
        printf("New data received\n");

        data_ready = 0;
    }

    return 0;
}
