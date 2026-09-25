/* =========================================================
   Q1: q01_dangling_pointer.c
   Avoid dangling pointer
   ========================================================= */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *ptr = malloc(sizeof(int));

    if (ptr == NULL)
        return 1;

    *ptr = 100;

    printf("Value = %d\n", *ptr);

    free(ptr);
    ptr = NULL;   // Prevent dangling pointer

    if (ptr == NULL)
        printf("Pointer is now NULL\n");

    return 0;
}


/* =========================================================
   Q2: q02_null_pointer_check.c
   Safe NULL pointer handling
   ========================================================= */

#include <stdio.h>

void print_value(int *ptr)
{
    if (ptr == NULL)
    {
        printf("NULL pointer received\n");
        return;
    }

    printf("Value = %d\n", *ptr);
}

int main(void)
{
    int value = 50;
    int *ptr = &value;

    print_value(ptr);
    print_value(NULL);

    return 0;
}


/* =========================================================
   Q3: q03_wild_pointer.c
   Wild pointer = uninitialized pointer
   Fixed using initialization
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int value = 25;

    /* Never do:
       int *ptr;
       *ptr = 25;
    */

    int *ptr = &value;

    printf("Value = %d\n", *ptr);

    return 0;
}


/* =========================================================
   Q4: q04_use_after_free.c
   Prevent use-after-free
   ========================================================= */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *ptr = malloc(sizeof(int));

    if (ptr == NULL)
        return 1;

    *ptr = 100;

    printf("Before free = %d\n", *ptr);

    free(ptr);
    ptr = NULL;

    if (ptr == NULL)
        printf("Memory released safely\n");

    return 0;
}


/* =========================================================
   Q5: q05_double_free.c
   Prevent double-free
   ========================================================= */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *ptr = malloc(sizeof(int));

    if (ptr == NULL)
        return 1;

    *ptr = 200;

    printf("Value = %d\n", *ptr);

    free(ptr);
    ptr = NULL;

    /* Safe: pointer is NULL, so we don't free it again */
    if (ptr != NULL)
        free(ptr);

    printf("No double-free occurred\n");

    return 0;
}


/* =========================================================
   Q6: q06_memory_leak.c
   Find and fix memory leak
   ========================================================= */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *ptr = malloc(5 * sizeof(int));

    if (ptr == NULL)
        return 1;

    for (int i = 0; i < 5; i++)
        ptr[i] = i + 1;

    for (int i = 0; i < 5; i++)
        printf("%d ", ptr[i]);

    printf("\n");

    /* Important: release allocated memory */
    free(ptr);
    ptr = NULL;

    return 0;
}


/* =========================================================
   Q7: q07_sizeof_array_vs_pointer.c
   sizeof() with array and pointer
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr;

    printf("Array size = %zu bytes\n", sizeof(arr));
    printf("Pointer size = %zu bytes\n", sizeof(ptr));

    printf("Number of elements = %zu\n",
           sizeof(arr) / sizeof(arr[0]));

    return 0;
}


/* =========================================================
   Q8: q08_stack_vs_heap.c
   Demonstrate stack and heap variables
   ========================================================= */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int stack_variable = 10;

    int *heap_variable = malloc(sizeof(int));

    if (heap_variable == NULL)
        return 1;

    *heap_variable = 20;

    printf("Stack variable = %d\n", stack_variable);
    printf("Heap variable  = %d\n", *heap_variable);

    free(heap_variable);
    heap_variable = NULL;

    return 0;
}


/* =========================================================
   Q9: q09_static_global_local_memory.c
   Local, static and global variables
   ========================================================= */

#include <stdio.h>

int global_variable = 100;

void test(void)
{
    int local_variable = 10;
    static int static_variable = 20;

    printf("Local  = %d\n", local_variable);
    printf("Static = %d\n", static_variable);
    printf("Global = %d\n", global_variable);

    static_variable++;
}

int main(void)
{
    test();
    test();
    test();

    return 0;
}


/* =========================================================
   Q10: q10_safe_memory_cleanup.c
   Safe allocation and cleanup pattern
   ========================================================= */

#include <stdio.h>
#include <stdlib.h>

void cleanup(int **ptr)
{
    if (ptr != NULL && *ptr != NULL)
    {
        free(*ptr);
        *ptr = NULL;
    }
}

int main(void)
{
    int *data = malloc(5 * sizeof(int));

    if (data == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < 5; i++)
        data[i] = (i + 1) * 10;

    for (int i = 0; i < 5; i++)
        printf("%d ", data[i]);

    printf("\n");

    cleanup(&data);

    if (data == NULL)
        printf("Memory cleaned safely\n");

    return 0;
}
