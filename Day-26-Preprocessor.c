/* =========================================================
   Q1: #define Constant
   File: q01_define_constant.c
   ========================================================= */

#include <stdio.h>

#define MAX_SPEED 120

int main()
{
    printf("Maximum Speed = %d km/h\n", MAX_SPEED);

    return 0;
}


/* =========================================================
   Q2: Function-like Macro
   File: q02_macro_square.c
   ========================================================= */

#include <stdio.h>

#define SQUARE(x) ((x) * (x))

int main()
{
    int n = 5;

    printf("Square = %d\n", SQUARE(n));

    return 0;
}


/* =========================================================
   Q3: MAX Macro
   File: q03_macro_max.c
   ========================================================= */

#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main()
{
    int a = 25;
    int b = 40;

    printf("Maximum = %d\n", MAX(a, b));

    return 0;
}


/* =========================================================
   Q4: Multi-line Macro
   File: q04_multiline_macro.c
   ========================================================= */

#include <stdio.h>

#define PRINT_INFO(name, age)       \
    do                              \
    {                               \
        printf("Name: %s\n", name); \
        printf("Age: %d\n", age);   \
    } while (0)

int main()
{
    PRINT_INFO("Kasturi", 21);

    return 0;
}


/* =========================================================
   Q5: #ifdef Debug
   File: q05_ifdef_debug.c
   ========================================================= */

#include <stdio.h>

#define DEBUG

int main()
{
#ifdef DEBUG
    printf("Debug mode is ON\n");
#endif

    printf("Program is running...\n");

    return 0;
}


/* =========================================================
   Q6: #ifndef Configuration
   File: q06_ifndef_config.c
   ========================================================= */

#include <stdio.h>

#ifndef BAUD_RATE
#define BAUD_RATE 9600
#endif

int main()
{
    printf("UART Baud Rate = %d\n", BAUD_RATE);

    return 0;
}


/* =========================================================
   Q7: Predefined Macros
   File: q07_predefined_macros.c
   ========================================================= */

#include <stdio.h>

int main()
{
    printf("File: %s\n", __FILE__);
    printf("Line: %d\n", __LINE__);
    printf("Date: %s\n", __DATE__);
    printf("Time: %s\n", __TIME__);

    return 0;
}


/* =========================================================
   Q8: Stringification Operator #
   File: q08_stringification_macro.c
   ========================================================= */

#include <stdio.h>

#define TO_STRING(x) #x

int main()
{
    printf("%s\n", TO_STRING(Embedded C));

    return 0;
}


/* =========================================================
   Q9: Token Pasting Operator ##
   File: q09_token_pasting_macro.c
   ========================================================= */

#include <stdio.h>

#define CREATE_VARIABLE(name, number) name##number

int main()
{
    int sensor1 = 100;
    int sensor2 = 200;

    printf("Sensor 1 = %d\n", CREATE_VARIABLE(sensor, 1));
    printf("Sensor 2 = %d\n", CREATE_VARIABLE(sensor, 2));

    return 0;
}


/* =========================================================
   Q10: Embedded Debug Macro
   File: q10_embedded_debug_macro.c
   ========================================================= */

#include <stdio.h>

#define DEBUG

#ifdef DEBUG
#define DEBUG_PRINT(message) printf("[DEBUG] %s\n", message)
#else
#define DEBUG_PRINT(message)
#endif

int main()
{
    DEBUG_PRINT("System initialized");
    DEBUG_PRINT("UART initialized");
    DEBUG_PRINT("Sensor reading started");

    printf("Main program running...\n");

    return 0;
}
