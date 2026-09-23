/* ============================================================
   DAY 12 — DYNAMIC MEMORY ALLOCATION
   Save each question as a separate .c file
   ============================================================ */


/* ============================================================
   Q1. Allocate memory for one integer using malloc()
   File: q01_malloc_basic.c
   ============================================================ */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;

    ptr = malloc(sizeof(int));

    if(ptr == NULL)
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


/* ============================================================
   Q2. Allocate memory for an array using malloc()
   File: q02_malloc_array.c
   ============================================================ */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    arr = malloc(n * sizeof(int));

    if(arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Array: ");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    free(arr);
    arr = NULL;

    return 0;
}


/* ============================================================
   Q3. Allocate memory using calloc()
   File: q03_calloc_basic.c
   ============================================================ */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    arr = calloc(n, sizeof(int));

    if(arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Initial values:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    free(arr);
    arr = NULL;

    return 0;
}


/* ============================================================
   Q4. Demonstrate malloc() and calloc()
   File: q04_malloc_vs_calloc.c
   ============================================================ */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *m;
    int *c;
    int n = 5;
    int i;

    m = malloc(n * sizeof(int));
    c = calloc(n, sizeof(int));

    if(m == NULL || c == NULL)
    {
        printf("Memory allocation failed\n");

        free(m);
        free(c);

        return 1;
    }

    printf("calloc values:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", c[i]);
    }

    printf("\n");

    /*
       malloc() does NOT initialize allocated memory.
       calloc() initializes allocated memory to zero.
    */

    free(m);
    free(c);

    m = NULL;
    c = NULL;

    return 0;
}


/* ============================================================
   Q5. Resize memory using realloc()
   File: q05_realloc_array.c
   ============================================================ */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;
    int n, new_n, i;
    int *temp;

    printf("Enter initial size: ");
    scanf("%d", &n);

    arr = malloc(n * sizeof(int));

    if(arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter new size: ");
    scanf("%d", &new_n);

    temp = realloc(arr, new_n * sizeof(int));

    if(temp == NULL)
    {
        printf("Reallocation failed\n");
        free(arr);
        return 1;
    }

    arr = temp;

    if(new_n > n)
    {
        printf("Enter additional elements:\n");

        for(i = n; i < new_n; i++)
        {
            scanf("%d", &arr[i]);
        }
    }

    printf("Final array: ");

    for(i = 0; i < new_n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    free(arr);
    arr = NULL;

    return 0;
}


/* ============================================================
   Q6. Allocate and properly free memory
   File: q06_free_memory.c
   ============================================================ */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;

    ptr = malloc(5 * sizeof(int));

    if(ptr == NULL)
    {
        printf("Allocation failed\n");
        return 1;
    }

    printf("Memory allocated successfully\n");

    free(ptr);

    ptr = NULL;

    printf("Memory released successfully\n");

    return 0;
}


/* ============================================================
   Q7. Check malloc() result against NULL
   File: q07_null_pointer_check.c
   ============================================================ */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;

    ptr = malloc(10 * sizeof(int));

    if(ptr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Memory allocation successful\n");

    free(ptr);
    ptr = NULL;

    return 0;
}


/* ============================================================
   Q8. Create a dynamic string
   File: q08_dynamic_string.c
   ============================================================ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[100];
    char *str;

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    str = malloc((strlen(input) + 1) * sizeof(char));

    if(str == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    strcpy(str, input);

    printf("Dynamic string = %s\n", str);

    free(str);
    str = NULL;

    return 0;
}


/* ============================================================
   Q9. Create a dynamic 2D array
   File: q09_dynamic_2d_array.c
   ============================================================ */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **matrix;
    int rows, cols;
    int i, j;

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    matrix = malloc(rows * sizeof(int *));

    if(matrix == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    for(i = 0; i < rows; i++)
    {
        matrix[i] = malloc(cols * sizeof(int));

        if(matrix[i] == NULL)
        {
            printf("Memory allocation failed\n");

            for(j = 0; j < i; j++)
            {
                free(matrix[j]);
            }

            free(matrix);
            return 1;
        }
    }

    printf("Enter matrix elements:\n");

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Matrix:\n");

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }

        printf("\n");
    }

    for(i = 0; i < rows; i++)
    {
        free(matrix[i]);
        matrix[i] = NULL;
    }

    free(matrix);
    matrix = NULL;

    return 0;
}


/* ============================================================
   Q10. Identify a memory leak
   File: q10_memory_leak_example.c
   ============================================================ */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;

    ptr = malloc(10 * sizeof(int));

    if(ptr == NULL)
    {
        printf("Allocation failed\n");
        return 1;
    }

    ptr[0] = 100;

    printf("Value = %d\n", ptr[0]);

    /*
       If free(ptr) is omitted here,
       the allocated memory becomes unreachable
       when the program continues.

       Correct practice:
    */

    free(ptr);
    ptr = NULL;

    return 0;
}
