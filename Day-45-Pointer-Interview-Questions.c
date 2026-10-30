/* =========================================================
   01_pointer_basics.c
   Pointer declaration, address and dereferencing
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int number = 50;

    int *ptr = &number;

    printf("Value       = %d\n", number);
    printf("Address     = %p\n", (void *)&number);
    printf("Pointer     = %p\n", (void *)ptr);
    printf("Dereference = %d\n", *ptr);

    return 0;
}


/* =========================================================
   02_swap_using_pointers.c
   Swap two numbers using pointers
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
    int x = 10;
    int y = 20;

    printf("Before swap: x = %d, y = %d\n", x, y);

    swap(&x, &y);

    printf("After swap: x = %d, y = %d\n", x, y);

    return 0;
}


/* =========================================================
   03_array_traversal_pointer.c
   Traverse an array using pointers
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};

    int *ptr = arr;

    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(ptr + i));
    }

    printf("\n");

    return 0;
}


/* =========================================================
   04_pointer_arithmetic.c
   Pointer arithmetic
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int arr[] = {100, 200, 300, 400};

    int *ptr = arr;

    printf("First element  = %d\n", *ptr);

    ptr++;

    printf("Second element = %d\n", *ptr);

    ptr = ptr + 2;

    printf("Fourth element = %d\n", *ptr);

    return 0;
}


/* =========================================================
   05_double_pointer.c
   Pointer to pointer
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int number = 100;

    int *ptr = &number;

    int **double_ptr = &ptr;

    printf("Number          = %d\n", number);
    printf("Using pointer   = %d\n", *ptr);
    printf("Using double ptr = %d\n", **double_ptr);

    **double_ptr = 200;

    printf("Updated number  = %d\n", number);

    return 0;
}


/* =========================================================
   06_array_pointer_vs_pointer_array.c
   Array of pointers vs pointer to array
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int a = 10, b = 20, c = 30;

    /* Array of pointers */
    int *arr_of_ptr[3] = {&a, &b, &c};

    printf("Array of pointers:\n");

    for (int i = 0; i < 3; i++)
    {
        printf("%d ", *arr_of_ptr[i]);
    }

    printf("\n");

    /* Pointer to an array */
    int arr[3] = {40, 50, 60};

    int (*ptr_to_arr)[3] = &arr;

    printf("Pointer to array:\n");

    for (int i = 0; i < 3; i++)
    {
        printf("%d ", (*ptr_to_arr)[i]);
    }

    printf("\n");

    return 0;
}


/* =========================================================
   07_const_pointer.c
   Pointer to const vs const pointer
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int a = 10;
    int b = 20;
    int c = 30;

    /* Pointer to constant data */
    const int *ptr1 = &a;

    /* Constant pointer */
    int *const ptr2 = &b;

    /* Constant pointer to constant data */
    const int *const ptr3 = &c;

    a = 15;
    ptr1 = &b;

    *ptr2 = 25;

    printf("Pointer to const = %d\n", *ptr1);
    printf("Const pointer = %d\n", *ptr2);
    printf("Const pointer to const = %d\n", *ptr3);

    return 0;
}


/* =========================================================
   08_void_pointer.c
   Generic pointer
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int number = 100;
    float decimal = 12.5f;

    void *ptr;

    ptr = &number;

    printf("Integer value = %d\n", *(int *)ptr);

    ptr = &decimal;

    printf("Float value = %.2f\n", *(float *)ptr);

    return 0;
}


/* =========================================================
   09_function_pointer.c
   Function pointer
   ========================================================= */

#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int multiply(int a, int b)
{
    return a * b;
}

int main(void)
{
    int (*operation)(int, int);

    operation = add;

    printf("Addition = %d\n", operation(10, 5));

    operation = multiply;

    printf("Multiplication = %d\n", operation(10, 5));

    return 0;
}


/* =========================================================
   10_reverse_array_pointers.c
   Reverse an array using two pointers
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};

    int size = sizeof(arr) / sizeof(arr[0]);

    int *left = arr;
    int *right = arr + size - 1;

    while (left < right)
    {
        int temp = *left;

        *left = *right;
        *right = temp;

        left++;
        right--;
    }

    printf("Reversed array:\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
