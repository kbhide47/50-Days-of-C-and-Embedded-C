/* =========================================================
   01_block_scope.c
   What is block scope?
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int x = 10;

    printf("Outer x = %d\n", x);

    {
        int y = 20;
        printf("Inner y = %d\n", y);
        printf("Inner x = %d\n", x);
    }

    /* y is not accessible here */

    return 0;
}


/* =========================================================
   02_file_scope.c
   What is file scope?
   ========================================================= */

#include <stdio.h>

int global_value = 100;   // File scope

void display(void)
{
    printf("Global value = %d\n", global_value);
}

int main(void)
{
    display();

    printf("Main can access global_value = %d\n", global_value);

    return 0;
}


/* =========================================================
   03_local_lifetime.c
   Automatic lifetime of local variables
   ========================================================= */

#include <stdio.h>

void test(void)
{
    int count = 0;   // Automatic variable

    count++;

    printf("Count = %d\n", count);
}

int main(void)
{
    test();
    test();
    test();

    return 0;
}


/* =========================================================
   04_static_local_lifetime.c
   Static local variable retains its value
   ========================================================= */

#include <stdio.h>

void test(void)
{
    static int count = 0;

    count++;

    printf("Count = %d\n", count);
}

int main(void)
{
    test();
    test();
    test();

    return 0;
}


/* =========================================================
   05_global_variable.c
   Global variable and file scope
   ========================================================= */

#include <stdio.h>

int temperature = 25;

void increase_temperature(void)
{
    temperature += 5;
}

int main(void)
{
    printf("Initial temperature = %d\n", temperature);

    increase_temperature();

    printf("Updated temperature = %d\n", temperature);

    return 0;
}


/* =========================================================
   06_static_global.c
   File-scope static variable
   ========================================================= */

#include <stdio.h>

static int device_status = 1;

/*
   device_status has internal linkage.
   It can be accessed only within this source file.
*/

void show_status(void)
{
    printf("Device status = %d\n", device_status);
}

int main(void)
{
    show_status();

    return 0;
}


/* =========================================================
   07_extern_variable.c
   extern declaration
   ========================================================= */

#include <stdio.h>

int sensor_value = 75;

void display_sensor(void)
{
    extern int sensor_value;

    printf("Sensor value = %d\n", sensor_value);
}

int main(void)
{
    display_sensor();

    sensor_value = 90;

    display_sensor();

    return 0;
}


/* =========================================================
   08_storage_class_comparison.c
   auto, static, extern, register
   ========================================================= */

#include <stdio.h>

int global_value = 50;

void demo(void)
{
    auto int a = 10;
    static int b = 20;
    register int c = 30;

    extern int global_value;

    printf("auto     = %d\n", a);
    printf("static   = %d\n", b);
    printf("register = %d\n", c);
    printf("extern   = %d\n", global_value);

    b++;
}

int main(void)
{
    demo();
    printf("\nSecond call:\n");
    demo();

    return 0;
}


/* =========================================================
   09_scope_vs_lifetime.c
   Scope and lifetime are different concepts
   ========================================================= */

#include <stdio.h>

void counter(void)
{
    static int count = 0;

    count++;

    /*
       Scope:
       count can be accessed only inside counter().

       Lifetime:
       count exists for the entire execution of the program.
    */

    printf("count = %d\n", count);
}

int main(void)
{
    counter();
    counter();
    counter();

    return 0;
}


/* =========================================================
   10_embedded_storage_example.c
   Storage classes in Embedded C
   ========================================================= */

#include <stdio.h>

static int system_status = 0;

void update_system(void)
{
    static int event_count = 0;

    event_count++;
    system_status = 1;

    printf("Event count  = %d\n", event_count);
    printf("System status = %d\n", system_status);
}

int main(void)
{
    update_system();
    update_system();
    update_system();

    return 0;
}
