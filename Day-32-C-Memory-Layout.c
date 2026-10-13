/* =========================================================
   Q1: Local vs Global Variables
   File: q01_local_global_variables.c
   ========================================================= */

#include <stdio.h>

int global_value = 100;

void display(void)
{
    int local_value = 20;

    printf("Global = %d\n", global_value);
    printf("Local = %d\n", local_value);
}

int main(void)
{
    display();
    printf("Global in main = %d\n", global_value);

    return 0;
}


/* =========================================================
   Q2: Stack Memory
   File: q02_stack_memory.c
   ========================================================= */

#include <stdio.h>

void function(void)
{
    int local = 50;

    printf("Local value = %d\n", local);
    printf("Local address = %p\n", (void *)&local);
}

int main(void)
{
    function();

    return 0;
}


/* =========================================================
   Q3: Heap Memory
   File: q03_heap_memory.c
   ========================================================= */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *ptr = malloc(sizeof(*ptr));

    if (ptr == NULL)
    {
        printf("Allocation failed\n");
        return 1;
    }

    *ptr = 100;

    printf("Value = %d\n", *ptr);

    free(ptr);
    ptr = NULL;

    return 0;
}


/* =========================================================
   Q4: Initialized vs Uninitialized Globals
   File: q04_initialized_uninitialized.c
   ========================================================= */

#include <stdio.h>

int initialized_global = 25;
int uninitialized_global;
static int zero_initialized_global;

int main(void)
{
    printf("Initialized = %d\n", initialized_global);
    printf("Uninitialized = %d\n", uninitialized_global);
    printf("Static global = %d\n", zero_initialized_global);

    return 0;
}


/* =========================================================
   Q5: Static Local Variable
   File: q05_static_variable_memory.c
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
   Q6: Constant Variable
   File: q06_const_variable.c
   ========================================================= */

#include <stdio.h>

const int calibration_value = 250;

int main(void)
{
    printf("Calibration = %d\n", calibration_value);
    printf("Address = %p\n",
           (const void *)&calibration_value);

    return 0;
}


/* =========================================================
   Q7: Function Address
   File: q07_function_address.c
   ========================================================= */

#include <stdio.h>

void task(void)
{
    printf("Task executed\n");
}

int main(void)
{
    void (*function_ptr)(void) = task;

    printf("Function called through pointer:\n");
    function_ptr();

    return 0;
}


/* =========================================================
   Q8: Inspect Variable Addresses
   File: q08_memory_addresses.c
   ========================================================= */

#include <stdio.h>
#include <stdlib.h>

int global_data = 10;
int zero_global;

int main(void)
{
    int local_data = 20;
    static int static_data = 30;

    int *heap_data = malloc(sizeof(*heap_data));

    if (heap_data == NULL)
        return 1;

    *heap_data = 40;

    printf("Global address  = %p\n", (void *)&global_data);
    printf("Zero global     = %p\n", (void *)&zero_global);
    printf("Static address  = %p\n", (void *)&static_data);
    printf("Local address   = %p\n", (void *)&local_data);
    printf("Heap allocation = %p\n", (void *)heap_data);

    free(heap_data);

    return 0;
}


/* =========================================================
   Q9: Stack vs Heap
   File: q09_stack_vs_heap.c
   ========================================================= */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int stack_value = 10;
    int *heap_value = malloc(sizeof(*heap_value));

    if (heap_value == NULL)
        return 1;

    *heap_value = 20;

    printf("Local value = %d\n", stack_value);
    printf("Dynamic value = %d\n", *heap_value);

    free(heap_value);
    heap_value = NULL;

    return 0;
}


/* =========================================================
   Q10: Embedded Memory Layout
   File: q10_embedded_memory_layout.c
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

int initialized_data = 100;
int zero_initialized_data;

static uint8_t sensor_buffer[16];

const uint16_t device_id = 1234U;

void sensor_init(void)
{
    sensor_buffer[0] = 1U;
    sensor_buffer[1] = 2U;
}

int main(void)
{
    sensor_init();

    printf("Initialized data = %d\n", initialized_data);
    printf("Zero-initialized data = %d\n",
           zero_initialized_data);
    printf("Sensor buffer first byte = %u\n",
           (unsigned int)sensor_buffer[0]);
    printf("Device ID = %u\n", (unsigned int)device_id);

    return 0;
}
