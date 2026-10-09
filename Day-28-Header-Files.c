/* =========================================================
   Q1: Standard Header File
   File: q01_include_stdio.c
   ========================================================= */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[] = "Embedded C";

    printf("Length = %zu\n", strlen(name));

    return 0;
}


/* =========================================================
   Q2: Custom Header File
   Files: q02_custom_header.c
          message.h
          message.c

   message.h:
   void display_message(void);

   message.c:
   #include <stdio.h>
   #include "message.h"
   void display_message(void)
   {
       printf("Hello from a custom header!\n");
   }
   ========================================================= */

/* q02_custom_header.c */

#include <stdio.h>
#include "message.h"

int main(void)
{
    display_message();

    return 0;
}


/* =========================================================
   Q3: Header Guard
   Files: q03_header_guard.c, math_utils.h

   math_utils.h:
   #ifndef MATH_UTILS_H
   #define MATH_UTILS_H
   int add(int a, int b);
   #endif
   ========================================================= */

/* q03_header_guard.c */

#include <stdio.h>
#include "math_utils.h"

int add(int a, int b)
{
    return a + b;
}

int main(void)
{
    printf("Sum = %d\n", add(10, 20));

    return 0;
}


/* =========================================================
   Q4: #ifndef Configuration
   File: q04_ifndef_guard.c
   ========================================================= */

#include <stdio.h>

#ifndef DEVICE_ID
#define DEVICE_ID 101
#endif

int main(void)
{
    printf("Device ID = %d\n", DEVICE_ID);

    return 0;
}


/* =========================================================
   Q5: Conditional Compilation
   File: q05_conditional_compilation.c
   ========================================================= */

#include <stdio.h>

#define VERSION 2

int main(void)
{
#if VERSION == 1
    printf("Version 1 selected\n");
#elif VERSION == 2
    printf("Version 2 selected\n");
#else
    printf("Unknown version\n");
#endif

    return 0;
}


/* =========================================================
   Q6: Platform Selection
   File: q06_platform_selection.c
   ========================================================= */

#include <stdio.h>

#define PLATFORM_STM32

int main(void)
{
#ifdef PLATFORM_STM32
    printf("STM32 platform selected\n");
#elif defined(PLATFORM_AVR)
    printf("AVR platform selected\n");
#else
    printf("Generic platform selected\n");
#endif

    return 0;
}


/* =========================================================
   Q7: Function Prototype in Header
   Files: q07_header_function_prototype.c, calculator.h

   calculator.h:
   #ifndef CALCULATOR_H
   #define CALCULATOR_H
   int multiply(int a, int b);
   #endif

   ========================================================= */

/* q07_header_function_prototype.c */

#include <stdio.h>
#include "calculator.h"

int multiply(int a, int b)
{
    return a * b;
}

int main(void)
{
    printf("Product = %d\n", multiply(6, 7));

    return 0;
}


/* =========================================================
   Q8: Header Constants
   Files: q08_header_constants.c, device_config.h

   device_config.h:
   #ifndef DEVICE_CONFIG_H
   #define DEVICE_CONFIG_H
   #define UART_BAUD 115200U
   #define BUFFER_SIZE 64U
   #endif
   ========================================================= */

/* q08_header_constants.c */

#include <stdio.h>
#include "device_config.h"

int main(void)
{
    printf("UART Baud = %u\n", UART_BAUD);
    printf("Buffer Size = %u\n", BUFFER_SIZE);

    return 0;
}


/* =========================================================
   Q9: Embedded Configuration Header
   Files: q09_embedded_config_header.c, embedded_config.h

   embedded_config.h:
   #ifndef EMBEDDED_CONFIG_H
   #define EMBEDDED_CONFIG_H
   #define CPU_CLOCK_HZ 72000000U
   #define LED_PIN 5U
   #define DEBUG_ENABLED 1
   #endif
   ========================================================= */

/* q09_embedded_config_header.c */

#include <stdio.h>
#include "embedded_config.h"

int main(void)
{
    printf("CPU Clock = %u Hz\n", CPU_CLOCK_HZ);
    printf("LED Pin = %u\n", LED_PIN);

#if DEBUG_ENABLED
    printf("Debugging enabled\n");
#endif

    return 0;
}


/* =========================================================
   Q10: Embedded Driver Interface
   Files: q10_embedded_driver_header.c, led_driver.h

   led_driver.h:
   #ifndef LED_DRIVER_H
   #define LED_DRIVER_H
   void led_init(void);
   void led_on(void);
   void led_off(void);
   #endif

   In real firmware, implementations usually reside in
   led_driver.c and control actual hardware.
   ========================================================= */

/* q10_embedded_driver_header.c */

#include <stdio.h>
#include "led_driver.h"

/* Simulation implementations; no real hardware control. */

void led_init(void)
{
    printf("LED initialized\n");
}

void led_on(void)
{
    printf("LED ON\n");
}

void led_off(void)
{
    printf("LED OFF\n");
}

int main(void)
{
    led_init();
    led_on();
    led_off();

    return 0;
}
