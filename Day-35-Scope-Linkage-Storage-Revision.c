/* =========================================================
   01_auto_storage.c
   auto storage class
   ========================================================= */

#include <stdio.h>

void test(void)
{
    auto int x = 10;

    printf("x = %d\n", x);
}

int main(void)
{
    test();
    test();

    return 0;
}


/* =========================================================
   02_static_local.c
   Static local variable
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
    counter();

    return 0;
}


/* =========================================================
   03_static_global.c
   Static global variable
   ========================================================= */

#include <stdio.h>

static int device_state = 0;

void set_device_state(int state)
{
    device_state = state;
}

void show_device_state(void)
{
    printf("Device state = %d\n", device_state);
}

int main(void)
{
    show_device_state();

    set_device_state(1);

    show_device_state();

    return 0;
}


/* =========================================================
   04_extern_variable.c
   extern variable
   ========================================================= */

#include <stdio.h>

int system_status = 0;

void update_status(void)
{
    extern int system_status;

    system_status = 1;
}

int main(void)
{
    printf("Before = %d\n", system_status);

    update_status();

    printf("After = %d\n", system_status);

    return 0;
}


/* =========================================================
   05_register_storage.c
   register storage class
   ========================================================= */

#include <stdio.h>

int main(void)
{
    register int counter;

    for (counter = 0; counter < 5; counter++)
    {
        printf("%d\n", counter);
    }

    return 0;
}


/* =========================================================
   06_scope_lifetime.c
   Scope vs lifetime
   ========================================================= */

#include <stdio.h>

void test(void)
{
    static int count = 0;

    /*
       Scope:
       count can be accessed only inside test().

       Lifetime:
       count exists throughout the entire program.
    */

    count++;

    printf("count = %d\n", count);
}

int main(void)
{
    test();
    test();
    test();

    return 0;
}


/* =========================================================
   07_linkage_types.c
   External, internal and no linkage
   ========================================================= */

#include <stdio.h>

int external_value = 10;       // External linkage
static int internal_value = 20; // Internal linkage

void test(void)
{
    int local_value = 30;      // No linkage

    printf("External = %d\n", external_value);
    printf("Internal = %d\n", internal_value);
    printf("Local    = %d\n", local_value);
}

int main(void)
{
    test();

    return 0;
}


/* =========================================================
   08_declaration_definition.c
   Declaration vs definition
   ========================================================= */

#include <stdio.h>

int value = 100;   // Definition

extern int value;  // Declaration

int main(void)
{
    printf("Value = %d\n", value);

    return 0;
}


/* =========================================================
   09_static_function.c
   Static function
   ========================================================= */

#include <stdio.h>

static void private_function(void)
{
    printf("Private static function called.\n");
}

void public_function(void)
{
    printf("Public function called.\n");

    private_function();
}

int main(void)
{
    public_function();

    return 0;
}


/* =========================================================
   10_interview_revision.c
   Mixed interview problem
   ========================================================= */

#include <stdio.h>

int global_value = 100;

static int private_value = 200;

void test(void)
{
    static int count = 0;
    int local_value = 50;

    count++;

    printf("Global  = %d\n", global_value);
    printf("Private = %d\n", private_value);
    printf("Static  = %d\n", count);
    printf("Local   = %d\n", local_value);
}

int main(void)
{
    test();
    printf("\nSecond call:\n");
    test();

    return 0;
}
