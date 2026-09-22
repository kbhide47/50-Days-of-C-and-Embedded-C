/* ============================================================
   DAY 11 — DOUBLE POINTERS + FUNCTION POINTERS
   Save each question as a separate .c file
   ============================================================ */


/* ============================================================
   Q1. Demonstrate a basic double pointer
   File: q01_basic_double_pointer.c
   ============================================================ */

#include <stdio.h>

int main()
{
    int num = 100;

    int *ptr = &num;
    int **ptr2 = &ptr;

    printf("num       = %d\n", num);
    printf("*ptr      = %d\n", *ptr);
    printf("**ptr2    = %d\n", **ptr2);

    return 0;
}


/* ============================================================
   Q2. Modify a value using a double pointer
   File: q02_modify_value_double_pointer.c
   ============================================================ */

#include <stdio.h>

int main()
{
    int num = 10;

    int *ptr = &num;
    int **ptr2 = &ptr;

    printf("Before = %d\n", num);

    **ptr2 = 50;

    printf("After = %d\n", num);

    return 0;
}


/* ============================================================
   Q3. Modify a pointer using a function
   File: q03_modify_pointer_using_function.c
   ============================================================ */

#include <stdio.h>

void changePointer(int **ptr, int *newAddress)
{
    *ptr = newAddress;
}

int main()
{
    int a = 10;
    int b = 20;

    int *ptr = &a;

    printf("Before = %d\n", *ptr);

    changePointer(&ptr, &b);

    printf("After = %d\n", *ptr);

    return 0;
}


/* ============================================================
   Q4. Swap two pointers
   File: q04_swap_pointers.c
   ============================================================ */

#include <stdio.h>

void swapPointers(int **p1, int **p2)
{
    int *temp;

    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main()
{
    int a = 10;
    int b = 20;

    int *p1 = &a;
    int *p2 = &b;

    printf("Before:\n");
    printf("*p1 = %d\n", *p1);
    printf("*p2 = %d\n", *p2);

    swapPointers(&p1, &p2);

    printf("\nAfter:\n");
    printf("*p1 = %d\n", *p1);
    printf("*p2 = %d\n", *p2);

    return 0;
}


/* ============================================================
   Q5. Access an array using a pointer to pointer
   File: q05_pointer_to_pointer_array.c
   ============================================================ */

#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30, 40, 50};

    int *ptr = arr;
    int **ptr2 = &ptr;

    int i;

    for(i = 0; i < 5; i++)
    {
        printf("%d ", **ptr2);
        (*ptr2)++;
    }

    printf("\n");

    return 0;
}


/* ============================================================
   Q6. Basic function pointer
   File: q06_function_pointer_basic.c
   ============================================================ */

#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int main()
{
    int (*funcPtr)(int, int);

    funcPtr = add;

    printf("Result = %d\n", funcPtr(10, 20));

    return 0;
}


/* ============================================================
   Q7. Calculator using a function pointer
   File: q07_function_pointer_calculator.c
   ============================================================ */

#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int main()
{
    int a, b, choice;
    int (*operation)(int, int);

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");

    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            operation = add;
            break;

        case 2:
            operation = subtract;
            break;

        case 3:
            operation = multiply;
            break;

        default:
            printf("Invalid choice\n");
            return 0;
    }

    printf("Result = %d\n", operation(a, b));

    return 0;
}


/* ============================================================
   Q8. Callback function using a function pointer
   File: q08_callback_function.c
   ============================================================ */

#include <stdio.h>

void processData(int value)
{
    printf("Processing data: %d\n", value);
}

void execute(void (*callback)(int), int data)
{
    callback(data);
}

int main()
{
    execute(processData, 100);

    return 0;
}


/* ============================================================
   Q9. Array of function pointers
   File: q09_array_of_function_pointers.c
   ============================================================ */

#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int main()
{
    int (*operations[3])(int, int) = {
        add,
        subtract,
        multiply
    };

    int a = 20;
    int b = 5;

    printf("Addition    = %d\n", operations[0](a, b));
    printf("Subtraction = %d\n", operations[1](a, b));
    printf("Multiplication = %d\n", operations[2](a, b));

    return 0;
}


/* ============================================================
   Q10. Menu-driven program using function pointers
   File: q10_function_pointer_with_menu.c
   ============================================================ */

#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divideNumbers(int a, int b)
{
    if(b == 0)
        return 0;

    return a / b;
}

int main()
{
    int a, b, choice;
    int (*operation)(int, int);

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("\n1. Add");
    printf("\n2. Subtract");
    printf("\n3. Multiply");
    printf("\n4. Divide");

    printf("\nEnter choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            operation = add;
            break;

        case 2:
            operation = subtract;
            break;

        case 3:
            operation = multiply;
            break;

        case 4:
            operation = divideNumbers;
            break;

        default:
            printf("Invalid choice\n");
            return 0;
    }

    printf("Result = %d\n", operation(a, b));

    return 0;
}
