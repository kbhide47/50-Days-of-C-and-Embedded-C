/* =========================================================
   01_external_linkage.c
   External linkage
   ========================================================= */

#include <stdio.h>

int sensor_value = 100;

void display_sensor(void)
{
    printf("Sensor value = %d\n", sensor_value);
}

int main(void)
{
    display_sensor();

    return 0;
}


/* =========================================================
   02_internal_linkage.c
   Internal linkage using static
   ========================================================= */

#include <stdio.h>

static int device_status = 1;

static void display_status(void)
{
    printf("Device status = %d\n", device_status);
}

int main(void)
{
    display_status();

    return 0;
}


/* =========================================================
   03_no_linkage.c
   Local variables have no linkage
   ========================================================= */

#include <stdio.h>

void function_a(void)
{
    int value = 10;

    printf("Function A value = %d\n", value);
}

void function_b(void)
{
    int value = 20;

    printf("Function B value = %d\n", value);
}

int main(void)
{
    function_a();
    function_b();

    return 0;
}


/* =========================================================
   04_extern_declaration.c
   extern declaration
   ========================================================= */

#include <stdio.h>

int temperature = 25;

void update_temperature(void)
{
    extern int temperature;

    temperature += 10;
}

int main(void)
{
    printf("Before = %d\n", temperature);

    update_temperature();

    printf("After = %d\n", temperature);

    return 0;
}


/* =========================================================
   05_static_function.c
   Static function has internal linkage
   ========================================================= */

#include <stdio.h>

static void calculate(void)
{
    printf("Static function executed.\n");
}

int main(void)
{
    calculate();

    return 0;
}


/* =========================================================
   06_global_vs_static_global.c
   Global vs static global
   ========================================================= */

#include <stdio.h>

int public_value = 100;
static int private_value = 200;

int main(void)
{
    printf("Public value  = %d\n", public_value);
    printf("Private value = %d\n", private_value);

    return 0;
}


/* =========================================================
   07_same_name_static.c
   Two static variables can have the same name
   ========================================================= */

#include <stdio.h>

static int module_value = 10;

void module_a(void)
{
    printf("Module A value = %d\n", module_value);
}

static int module_value_b = 20;

void module_b(void)
{
    printf("Module B value = %d\n", module_value_b);
}

int main(void)
{
    module_a();
    module_b();

    return 0;
}


/* =========================================================
   08_header_extern_pattern.c
   Header + extern concept
   ========================================================= */

/*
   In a real project:

   sensor.h
   --------------------------------
   extern int sensor_value;
   void read_sensor(void);
   --------------------------------

   sensor.c
   --------------------------------
   int sensor_value = 100;

   void read_sensor(void)
   {
       sensor_value++;
   }
   --------------------------------

   main.c
   --------------------------------
   #include "sensor.h"

   int main(void)
   {
       read_sensor();
   }
   --------------------------------

   The following single-file program demonstrates
   the same concept.
*/

#include <stdio.h>

int sensor_value = 100;

void read_sensor(void)
{
    sensor_value++;
}

int main(void)
{
    printf("Before = %d\n", sensor_value);

    read_sensor();

    printf("After = %d\n", sensor_value);

    return 0;
}


/* =========================================================
   09_module_private_public.c
   Public and private module data
   ========================================================= */

#include <stdio.h>

int system_state = 0;          // Public/external linkage
static int error_count = 0;    // Private/internal linkage

void system_start(void)
{
    system_state = 1;
}

void record_error(void)
{
    error_count++;
}

int get_error_count(void)
{
    return error_count;
}

int main(void)
{
    system_start();

    record_error();
    record_error();

    printf("System state = %d\n", system_state);
    printf("Error count  = %d\n", get_error_count());

    return 0;
}


/* =========================================================
   10_embedded_driver_module.c
   Embedded driver-style organization
   ========================================================= */

#include <stdio.h>

static int gpio_state = 0;

void GPIO_Init(void)
{
    gpio_state = 0;
}

void GPIO_Write(int state)
{
    gpio_state = state;
}

int GPIO_Read(void)
{
    return gpio_state;
}

int main(void)
{
    GPIO_Init();

    GPIO_Write(1);

    printf("GPIO state = %d\n", GPIO_Read());

    GPIO_Write(0);

    printf("GPIO state = %d\n", GPIO_Read());

    return 0;
}
