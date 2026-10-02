/* =========================================================
   DAY 21 — POINTERS & POINTER ARITHMETIC
   ========================================================= */


/* =========================================================
   Q1. Pointer basics
   File: q01_pointer_basics.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int value = 50;
    int *ptr = &value;

    printf("Value       = %d\n", value);
    printf("Using ptr   = %d\n", *ptr);
    printf("Address     = %p\n", (void *)ptr);

    return 0;
}


/* =========================================================
   Q2. Pointer arithmetic
   File: q02_pointer_arithmetic.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int arr[] = {10, 20, 30, 40};

    int *ptr = arr;

    printf("First  = %d\n", *ptr);

    ptr++;

    printf("Second = %d\n", *ptr);

    ptr++;

    printf("Third  = %d\n", *ptr);

    return 0;
}


/* =========================================================
   Q3. Pointer increment
   File: q03_pointer_increment.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int arr[] = {10, 20, 30};

    int *ptr = arr;

    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", *ptr);
        ptr++;
    }

    return 0;
}


/* =========================================================
   Q4. Access array using pointer
   File: q04_array_using_pointer.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int arr[] = {5, 10, 15, 20, 25};

    int *ptr = arr;

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(ptr + i));
    }

    printf("\n");

    return 0;
}


/* =========================================================
   Q5. Pointer difference
   File: q05_pointer_difference.c
   ========================================================= */

#include <stdio.h>
#include <stddef.h>

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};

    int *p1 = &arr[1];
    int *p2 = &arr[4];

    ptrdiff_t difference = p2 - p1;

    printf("Pointer difference = %td\n", difference);

    return 0;
}


/* =========================================================
   Q6. Pointer to pointer
   File: q06_pointer_to_pointer.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int value = 100;

    int *ptr = &value;
    int **pptr = &ptr;

    printf("Value = %d\n", value);
    printf("Using ptr = %d\n", *ptr);
    printf("Using pptr = %d\n", **pptr);

    return 0;
}


/* =========================================================
   Q7. Swap using pointers
   File: q07_swap_using_pointers.c
   ========================================================= */

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

int main(void)
{
    int a = 10;
    int b = 20;

    printf("Before: a = %d, b = %d\n", a, b);

    swap(&a, &b);

    printf("After : a = %d, b = %d\n", a, b);

    return 0;
}


/* =========================================================
   Q8. Basic function pointer
   File: q08_function_pointer_basic.c
   ========================================================= */

#include <stdio.h>

void display(void)
{
    printf("Function called through pointer\n");
}

int main(void)
{
    void (*function_ptr)(void);

    function_ptr = display;

    function_ptr();

    return 0;
}


/* =========================================================
   Q9. Pointer to structure
   File: q09_pointer_to_structure.c
   ========================================================= */

#include <stdio.h>

struct Sensor
{
    int id;
    float temperature;
};

int main(void)
{
    struct Sensor sensor = {101, 28.5f};

    struct Sensor *ptr = &sensor;

    printf("ID = %d\n", ptr->id);
    printf("Temperature = %.2f\n",
           ptr->temperature);

    return 0;
}


/* =========================================================
   Q10. Embedded-style buffer pointer
   File: q10_embedded_buffer_pointer.c
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t buffer[] = {
        0xAA,
        0x10,
        0x25,
        0x55
    };

    uint8_t *ptr = buffer;

    printf("Buffer data:\n");

    for (int i = 0; i < 4; i++)
    {
        printf("0x%02X ", *(ptr + i));
    }

    printf("\n");

    return 0;
}
