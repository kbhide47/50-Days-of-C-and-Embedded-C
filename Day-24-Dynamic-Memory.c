/* =========================================================
   DAY 24 — DYNAMIC MEMORY ALLOCATION
   ========================================================= */


/* =========================================================
   Q1. Allocate memory using malloc()
   File: q01_malloc_basic.c
   ========================================================= */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *ptr;

    ptr = malloc(sizeof(int));

    if (ptr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    *ptr = 100;

    printf("Value = %d\n", *ptr);

    free(ptr);
    ptr = NULL;

    return 0;
}


/* =========================================================
   Q2. Allocate memory for an array using malloc()
   File: q02_malloc_array.c
   ========================================================= */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n = 5;

    int *arr = malloc(n * sizeof(*arr));

    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = (i + 1) * 10;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    free(arr);
    arr = NULL;

    return 0;
}


/* =========================================================
   Q3. Allocate memory using calloc()
   File: q03_calloc_basic.c
   ========================================================= */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n = 5;

    int *arr = calloc(n, sizeof(*arr));

    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Initial values:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    free(arr);
    arr = NULL;

    return 0;
}


/* =========================================================
   Q4. malloc() vs calloc()
   File: q04_malloc_vs_calloc.c
   ========================================================= */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *a = malloc(5 * sizeof(*a));
    int *b = calloc(5, sizeof(*b));

    if (a == NULL || b == NULL)
    {
        printf("Memory allocation failed\n");

        free(a);
        free(b);

        return 1;
    }

    /*
       calloc() initializes allocated bytes to zero.

       malloc() does not initialize the allocated memory.
       Therefore, do not rely on malloc() memory containing
       any particular value.
    */

    printf("calloc first element = %d\n", b[0]);

    free(a);
    free(b);

    a = NULL;
    b = NULL;

    return 0;
}


/* =========================================================
   Q5. Resize memory using realloc()
   File: q05_realloc_basic.c
   ========================================================= */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *arr = malloc(3 * sizeof(*arr));

    if (arr == NULL)
    {
        return 1;
    }

    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;

    int *temp = realloc(arr, 5 * sizeof(*arr));

    if (temp == NULL)
    {
        free(arr);
        return 1;
    }

    arr = temp;

    arr[3] = 40;
    arr[4] = 50;

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    free(arr);
    arr = NULL;

    return 0;
}


/* =========================================================
   Q6. Free allocated memory
   File: q06_free_memory.c
   ========================================================= */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *ptr = malloc(sizeof(*ptr));

    if (ptr == NULL)
    {
        return 1;
    }

    *ptr = 500;

    printf("Value = %d\n", *ptr);

    free(ptr);

    /*
       Good practice:
       Set pointer to NULL after freeing.
    */

    ptr = NULL;

    return 0;
}


/* =========================================================
   Q7. Check malloc() failure
   File: q07_check_malloc_failure.c
   ========================================================= */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t n = 10;

    int *buffer = malloc(n * sizeof(*buffer));

    if (buffer == NULL)
    {
        printf("ERROR: Unable to allocate memory\n");
        return 1;
    }

    printf("Memory allocated successfully\n");

    free(buffer);
    buffer = NULL;

    return 0;
}


/* =========================================================
   Q8. Memory leak example
   File: q08_memory_leak_example.c
   ========================================================= */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *ptr = malloc(10 * sizeof(*ptr));

    if (ptr == NULL)
    {
        return 1;
    }

    ptr[0] = 100;

    printf("Value = %d\n", ptr[0]);

    /*
       Correct:
       Release memory before program exits.
    */

    free(ptr);
    ptr = NULL;

    return 0;
}


/* =========================================================
   Q9. Dynamic string
   File: q09_dynamic_string.c
   ========================================================= */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    const char *source = "Embedded C";

    size_t length = strlen(source);

    char *str = malloc(length + 1);

    if (str == NULL)
    {
        return 1;
    }

    memcpy(str, source, length + 1);

    printf("String = %s\n", str);

    free(str);
    str = NULL;

    return 0;
}


/* =========================================================
   Q10. Embedded memory best practice
   File: q10_embedded_memory_best_practice.c
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

#define BUFFER_SIZE 16U

static uint8_t rx_buffer[BUFFER_SIZE];

int main(void)
{
    /*
       In many embedded applications, a fixed-size
       static buffer is preferred over dynamic allocation.

       Benefits:
       - Predictable memory usage
       - No heap fragmentation
       - No allocation failure during runtime
       - Easier real-time analysis
    */

    for (uint8_t i = 0; i < BUFFER_SIZE; i++)
    {
        rx_buffer[i] = i;
    }

    printf("RX buffer:\n");

    for (uint8_t i = 0; i < BUFFER_SIZE; i++)
    {
        printf("%02X ", rx_buffer[i]);
    }

    printf("\n");

    return 0;
}
