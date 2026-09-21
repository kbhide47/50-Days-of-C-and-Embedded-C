/* ============================================================
   DAY 10 — POINTERS + FUNCTIONS
   Save each question as a separate .c file
   ============================================================ */


/* ============================================================
   Q1. Pass a pointer to a function and modify a variable
   File: q01_pass_pointer_to_function.c
   ============================================================ */

#include <stdio.h>

void changeValue(int *ptr)
{
    *ptr = 100;
}

int main()
{
    int num = 10;

    printf("Before = %d\n", num);

    changeValue(&num);

    printf("After = %d\n", num);

    return 0;
}


/* ============================================================
   Q2. Swap two numbers using a function and pointers
   File: q02_swap_using_function.c
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

    printf("Before: a = %d, b = %d\n", a, b);

    swap(&a, &b);

    printf("After: a = %d, b = %d\n", a, b);

    return 0;
}


/* ============================================================
   Q3. Increment a variable using a pointer
   File: q03_increment_using_pointer.c
   ============================================================ */

#include <stdio.h>

void increment(int *num)
{
    (*num)++;
}

int main()
{
    int num = 10;

    printf("Before = %d\n", num);

    increment(&num);

    printf("After = %d\n", num);

    return 0;
}


/* ============================================================
   Q4. Return multiple values from a function using pointers
   File: q04_return_multiple_values.c
   ============================================================ */

#include <stdio.h>

void calculate(int a, int b, int *sum, int *difference)
{
    *sum = a + b;
    *difference = a - b;
}

int main()
{
    int a, b;
    int sum, difference;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    calculate(a, b, &sum, &difference);

    printf("Sum = %d\n", sum);
    printf("Difference = %d\n", difference);

    return 0;
}


/* ============================================================
   Q5. Find sum of array elements using a function
   File: q05_sum_array_function.c
   ============================================================ */

#include <stdio.h>

int arraySum(int *arr, int n)
{
    int sum = 0;
    int i;

    for(i = 0; i < n; i++)
    {
        sum += *(arr + i);
    }

    return sum;
}

int main()
{
    int arr[100], n;
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Sum = %d\n", arraySum(arr, n));

    return 0;
}


/* ============================================================
   Q6. Find maximum element using a function and pointer
   File: q06_max_array_function.c
   ============================================================ */

#include <stdio.h>

int findMax(int *arr, int n)
{
    int max = arr[0];
    int i;

    for(i = 1; i < n; i++)
    {
        if(*(arr + i) > max)
        {
            max = *(arr + i);
        }
    }

    return max;
}

int main()
{
    int arr[100], n;
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Maximum = %d\n", findMax(arr, n));

    return 0;
}


/* ============================================================
   Q7. Reverse an array using a function
   File: q07_reverse_array_function.c
   ============================================================ */

#include <stdio.h>

void reverseArray(int *arr, int n)
{
    int *start = arr;
    int *end = arr + n - 1;
    int temp;

    while(start < end)
    {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main()
{
    int arr[100], n;
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    reverseArray(arr, n);

    printf("Reversed array: ");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}


/* ============================================================
   Q8. Find string length using a function and pointer
   File: q08_string_length_function.c
   ============================================================ */

#include <stdio.h>

int stringLength(char *str)
{
    int length = 0;

    while(*str != '\0' && *str != '\n')
    {
        length++;
        str++;
    }

    return length;
}

int main()
{
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Length = %d\n", stringLength(str));

    return 0;
}


/* ============================================================
   Q9. Modify structure data using a pointer
   File: q09_modify_structure_using_pointer.c
   ============================================================ */

#include <stdio.h>

struct Sensor
{
    int temperature;
    int humidity;
};

void updateSensor(struct Sensor *s)
{
    s->temperature = 30;
    s->humidity = 60;
}

int main()
{
    struct Sensor sensor = {25, 50};

    printf("Before:\n");
    printf("Temperature = %d\n", sensor.temperature);
    printf("Humidity = %d\n", sensor.humidity);

    updateSensor(&sensor);

    printf("\nAfter:\n");
    printf("Temperature = %d\n", sensor.temperature);
    printf("Humidity = %d\n", sensor.humidity);

    return 0;
}


/* ============================================================
   Q10. Basic function pointer
   File: q10_function_pointer_basic.c
   ============================================================ */

#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int main()
{
    int (*operation)(int, int);

    operation = add;

    printf("Result = %d\n", operation(10, 20));

    return 0;
}
