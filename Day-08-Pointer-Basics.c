/* ============================================================
   DAY 8 — POINTER BASICS
   Save each question as a separate .c file
   ============================================================ */


/* ============================================================
   Q1. Declare a pointer and print the address and value
   File: q01_pointer_declaration.c
   ============================================================ */

#include <stdio.h>

int main()
{
    int num = 10;
    int *ptr = &num;

    printf("Value = %d\n", num);
    printf("Address = %p\n", (void *)&num);
    printf("Pointer value = %p\n", (void *)ptr);

    return 0;
}


/* ============================================================
   Q2. Access a variable's value using a pointer
   File: q02_access_value_using_pointer.c
   ============================================================ */

#include <stdio.h>

int main()
{
    int num = 25;
    int *ptr = &num;

    printf("Value using pointer = %d\n", *ptr);

    return 0;
}


/* ============================================================
   Q3. Modify a variable using a pointer
   File: q03_modify_value_using_pointer.c
   ============================================================ */

#include <stdio.h>

int main()
{
    int num = 10;
    int *ptr = &num;

    printf("Before = %d\n", num);

    *ptr = 50;

    printf("After = %d\n", num);

    return 0;
}


/* ============================================================
   Q4. Swap two numbers using pointers
   File: q04_swap_using_pointers.c
   ============================================================ */

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("Before swap: a = %d, b = %d\n", a, b);

    swap(&a, &b);

    printf("After swap: a = %d, b = %d\n", a, b);

    return 0;
}


/* ============================================================
   Q5. Add two numbers using pointers
   File: q05_addition_using_pointers.c
   ============================================================ */

#include <stdio.h>

int main()
{
    int a, b;
    int *p1, *p2;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    p1 = &a;
    p2 = &b;

    printf("Sum = %d\n", *p1 + *p2);

    return 0;
}


/* ============================================================
   Q6. Demonstrate pointer arithmetic
   File: q06_pointer_arithmetic.c
   ============================================================ */

#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30, 40};
    int *ptr = arr;

    printf("First element  = %d\n", *ptr);

    ptr++;
    printf("Second element = %d\n", *ptr);

    ptr++;
    printf("Third element  = %d\n", *ptr);

    ptr--;
    printf("Second element = %d\n", *ptr);

    return 0;
}


/* ============================================================
   Q7. Access array elements using a pointer
   File: q07_array_using_pointer.c
   ============================================================ */

#include <stdio.h>

int main()
{
    int arr[5];
    int *ptr;
    int i;

    printf("Enter 5 elements:\n");

    for(i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }

    ptr = arr;

    printf("Array elements using pointer:\n");

    for(i = 0; i < 5; i++)
    {
        printf("%d ", *(ptr + i));
    }

    printf("\n");

    return 0;
}


/* ============================================================
   Q8. Find maximum element using a pointer
   File: q08_find_max_using_pointer.c
   ============================================================ */

#include <stdio.h>

int main()
{
    int arr[100], n;
    int *ptr;
    int max, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    ptr = arr;
    max = *ptr;

    for(i = 1; i < n; i++)
    {
        if(*(ptr + i) > max)
        {
            max = *(ptr + i);
        }
    }

    printf("Maximum = %d\n", max);

    return 0;
}


/* ============================================================
   Q9. Reverse an array using pointers
   File: q09_reverse_array_using_pointer.c
   ============================================================ */

#include <stdio.h>

int main()
{
    int arr[100], n;
    int *start, *end;
    int temp, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    start = arr;
    end = arr + n - 1;

    while(start < end)
    {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }

    printf("Reversed array: ");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}


/* ============================================================
   Q10. Demonstrate pointer to pointer
   File: q10_pointer_to_pointer.c
   ============================================================ */

#include <stdio.h>

int main()
{
    int num = 100;

    int *ptr = &num;
    int **ptr2 = &ptr;

    printf("Value of num       = %d\n", num);
    printf("Using *ptr         = %d\n", *ptr);
    printf("Using **ptr2       = %d\n", **ptr2);

    return 0;
}
