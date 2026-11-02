/* =========================================================
   01_malloc.c
   ========================================================= */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *ptr = malloc(sizeof *ptr);

    if (ptr == NULL)
    {
        printf("Allocation failed\n");
        return 1;
    }

    *ptr = 100;

    printf("Value = %d\n", *ptr);

    free(ptr);

    return 0;
}


/* =========================================================
   02_calloc.c
   ========================================================= */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *ptr = calloc(5, sizeof *ptr);

    if (ptr == NULL)
    {
        printf("Allocation failed\n");
        return 1;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", ptr[i]);
    }

    printf("\n");

    free(ptr);

    return 0;
}


/* =========================================================
   03_realloc.c
   ========================================================= */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *ptr = malloc(3 * sizeof *ptr);

    if (ptr == NULL)
    {
        return 1;
    }

    ptr[0] = 10;
    ptr[1] = 20;
    ptr[2] = 30;

    int *temp = realloc(ptr, 5 * sizeof *ptr);

    if (temp == NULL)
    {
        free(ptr);
        return 1;
    }

    ptr = temp;

    ptr[3] = 40;
    ptr[4] = 50;

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", ptr[i]);
    }

    printf("\n");

    free(ptr);

    return 0;
}


/* =========================================================
   04_free_memory.c
   ========================================================= */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *ptr = malloc(sizeof *ptr);

    if (ptr == NULL)
    {
        return 1;
    }

    *ptr = 500;

    printf("Before free = %d\n", *ptr);

    free(ptr);
    ptr = NULL;

    printf("Memory released\n");

    return 0;
}


/* =========================================================
   05_memory_leak.c
   Demonstrate a memory leak
   ========================================================= */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *ptr = malloc(sizeof *ptr);

    if (ptr == NULL)
    {
        return 1;
    }

    *ptr = 100;

    printf("Value = %d\n", *ptr);

    /*
       Memory leak demonstration:
       free(ptr) is intentionally omitted.

       Do not use this pattern in real programs.
    */

    return 0;
}


/* =========================================================
   06_dangling_pointer.c
   Safe demonstration of dangling pointer prevention
   ========================================================= */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *ptr = malloc(sizeof *ptr);

    if (ptr == NULL)
    {
        return 1;
    }

    *ptr = 200;

    printf("Value = %d\n", *ptr);

    free(ptr);

    /*
       After free(), ptr is dangling.
       Do not dereference it.
    */

    ptr = NULL;

    printf("Pointer reset to NULL\n");

    return 0;
}


/* =========================================================
   07_memory_allocation_array.c
   Dynamic array allocation
   ========================================================= */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n = 5;

    int *arr = malloc(n * sizeof *arr);

    if (arr == NULL)
    {
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

    return 0;
}


/* =========================================================
   08_dynamic_2d_array.c
   Dynamic 2D array using pointer-to-pointer
   ========================================================= */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int rows = 3;
    int cols = 4;

    int **matrix = malloc(rows * sizeof *matrix);

    if (matrix == NULL)
    {
        return 1;
    }

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = malloc(cols * sizeof *matrix[i]);

        if (matrix[i] == NULL)
        {
            for (int j = 0; j < i; j++)
            {
                free(matrix[j]);
            }

            free(matrix);
            return 1;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = i + j;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }

        printf("\n");
    }

    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }

    free(matrix);

    return 0;
}


/* =========================================================
   09_safe_memory_allocation.c
   Safe memory allocation
   ========================================================= */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
    size_t n = 10;

    if (n > SIZE_MAX / sizeof(int))
    {
        printf("Size overflow\n");
        return 1;
    }

    int *ptr = malloc(n * sizeof *ptr);

    if (ptr == NULL)
    {
        printf("Allocation failed\n");
        return 1;
    }

    for (size_t i = 0; i < n; i++)
    {
        ptr[i] = (int)i;
    }

    printf("Last element = %d\n", ptr[9]);

    free(ptr);

    return 0;
}


/* =========================================================
   10_memory_interview.c
   Mixed memory interview problem
   ========================================================= */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *ptr = malloc(3 * sizeof *ptr);

    if (ptr == NULL)
    {
        return 1;
    }

    ptr[0] = 10;
    ptr[1] = 20;
    ptr[2] = 30;

    int sum = 0;

    for (int i = 0; i < 3; i++)
    {
        sum += ptr[i];
    }

    printf("Sum = %d\n", sum);

    free(ptr);
    ptr = NULL;

    return 0;
}
