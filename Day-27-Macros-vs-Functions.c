/* =========================================================
   Q1: Macro vs Function
   File: q01_macro_vs_function.c
   ========================================================= */

#include <stdio.h>

#define ADD_MACRO(a, b) ((a) + (b))

int add_function(int a, int b)
{
    return a + b;
}

int main()
{
    int a = 10;
    int b = 20;

    printf("Macro result    = %d\n", ADD_MACRO(a, b));
    printf("Function result = %d\n", add_function(a, b));

    return 0;
}


/* =========================================================
   Q2: Safe Square Macro
   File: q02_macro_square.c
   ========================================================= */

#include <stdio.h>

#define SQUARE(x) ((x) * (x))

int main()
{
    int n = 6;

    printf("Square = %d\n", SQUARE(n));

    return 0;
}


/* =========================================================
   Q3: Macro Precedence
   File: q03_macro_precedence.c
   ========================================================= */

#include <stdio.h>

#define BAD_SQUARE(x) x * x
#define GOOD_SQUARE(x) ((x) * (x))

int main()
{
    int result1 = BAD_SQUARE(2 + 3);
    int result2 = GOOD_SQUARE(2 + 3);

    printf("Bad macro result  = %d\n", result1);
    printf("Good macro result = %d\n", result2);

    return 0;
}


/* =========================================================
   Q4: Macro Side Effect
   File: q04_macro_side_effect.c
   ========================================================= */

#include <stdio.h>

#define DOUBLE(x) ((x) + (x))

int main()
{
    int a = 5;

    /*
       Avoid using DOUBLE(a++) because the argument
       may be evaluated more than once.
    */

    printf("Result = %d\n", DOUBLE(a));

    return 0;
}


/* =========================================================
   Q5: MAX Macro
   File: q05_max_macro.c
   ========================================================= */

#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main()
{
    int x = 45;
    int y = 30;

    printf("Maximum = %d\n", MAX(x, y));

    return 0;
}


/* =========================================================
   Q6: Function vs Macro
   File: q06_function_vs_macro.c
   ========================================================= */

#include <stdio.h>

#define CUBE_MACRO(x) ((x) * (x) * (x))

int cube_function(int x)
{
    return x * x * x;
}

int main()
{
    int n = 4;

    printf("Macro cube    = %d\n", CUBE_MACRO(n));
    printf("Function cube = %d\n", cube_function(n));

    return 0;
}


/* =========================================================
   Q7: do-while(0) Macro
   File: q07_do_while_macro.c
   ========================================================= */

#include <stdio.h>

#define PRINT_DATA(x)          \
    do                         \
    {                          \
        printf("Value = %d\n", x); \
        printf("Done\n");      \
    } while (0)

int main()
{
    int value = 100;

    PRINT_DATA(value);

    return 0;
}


/* =========================================================
   Q8: Embedded Register Macro
   File: q08_embedded_register_macro.c
   ========================================================= */

#include <stdio.h>

#define SET_BIT(reg, bit)    ((reg) |= (1U << (bit)))
#define CLEAR_BIT(reg, bit)  ((reg) &= ~(1U << (bit)))
#define TOGGLE_BIT(reg, bit) ((reg) ^= (1U << (bit)))
#define CHECK_BIT(reg, bit)  (((reg) >> (bit)) & 1U)

int main()
{
    unsigned int REG = 0;

    SET_BIT(REG, 3);

    printf("After SET   = %u\n", REG);
    printf("Bit 3       = %u\n", CHECK_BIT(REG, 3));

    CLEAR_BIT(REG, 3);

    printf("After CLEAR = %u\n", REG);

    TOGGLE_BIT(REG, 2);

    printf("After TOGGLE = %u\n", REG);

    return 0;
}


/* =========================================================
   Q9: Conditional Debug Macro
   File: q09_debug_macro.c
   ========================================================= */

#include <stdio.h>

#define DEBUG

#ifdef DEBUG
#define DEBUG_PRINT(msg) printf("[DEBUG] %s\n", msg)
#else
#define DEBUG_PRINT(msg)
#endif

int main()
{
    DEBUG_PRINT("System started");
    DEBUG_PRINT("Sensor initialized");

    printf("Main application running\n");

    return 0;
}


/* =========================================================
   Q10: Embedded Configuration Macros
   File: q10_embedded_macro_interview.c
   ========================================================= */

#include <stdio.h>

#define CPU_CLOCK 72000000U
#define UART_BAUD 115200U
#define LED_PIN 5U

#define BIT_MASK(bit) (1U << (bit))

int main()
{
    unsigned int GPIO_REGISTER = 0;

    GPIO_REGISTER |= BIT_MASK(LED_PIN);

    printf("CPU Clock   = %u Hz\n", CPU_CLOCK);
    printf("UART Baud   = %u\n", UART_BAUD);
    printf("LED Pin     = %u\n", LED_PIN);
    printf("GPIO Reg    = %u\n", GPIO_REGISTER);

    return 0;
}
