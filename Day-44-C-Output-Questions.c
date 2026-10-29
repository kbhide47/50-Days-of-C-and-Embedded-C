/* =========================================================
   01_operator_precedence.c
   Predict the output.
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int result = 2 + 3 * 4 - 6 / 2;

    printf("%d\n", result);

    return 0;
}


/* =========================================================
   02_integer_division.c
   Integer division and remainder
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int a = 17;
    int b = 5;

    printf("Division = %d\n", a / b);
    printf("Remainder = %d\n", a % b);

    return 0;
}


/* =========================================================
   03_loop_continue.c
   Loop with continue
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int i;

    for (i = 1; i <= 5; i++)
    {
        if (i == 3)
        {
            continue;
        }

        printf("%d ", i);
    }

    printf("\n");

    return 0;
}


/* =========================================================
   04_array_indexing.c
   Array indexing
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};

    printf("%d\n", arr[2]);
    printf("%d\n", arr[0] + arr[4]);

    return 0;
}


/* =========================================================
   05_static_variable.c
   Static local variable
   ========================================================= */

#include <stdio.h>

void counter(void)
{
    static int count = 0;

    count++;

    printf("%d ", count);
}

int main(void)
{
    counter();
    counter();
    counter();

    printf("\n");

    return 0;
}


/* =========================================================
   06_pre_post_increment.c
   Pre-increment and post-increment
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int x = 5;

    printf("%d\n", ++x);
    printf("%d\n", x++);
    printf("%d\n", x);

    return 0;
}


/* =========================================================
   07_short_circuit.c
   Logical short-circuit evaluation
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int x = 0;

    if (x++ == 0 && ++x == 2)
    {
        printf("Condition is true\n");
    }

    printf("x = %d\n", x);

    return 0;
}


/* =========================================================
   08_switch_fallthrough.c
   Switch fall-through
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int choice = 2;

    switch (choice)
    {
        case 1:
            printf("One ");
            break;

        case 2:
            printf("Two ");

        case 3:
            printf("Three ");
            break;

        default:
            printf("Other ");
    }

    printf("\n");

    return 0;
}


/* =========================================================
   09_pointer_output.c
   Pointer modifies a variable
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int value = 10;
    int *ptr = &value;

    *ptr = *ptr + 5;

    printf("value = %d\n", value);
    printf("*ptr = %d\n", *ptr);

    return 0;
}


/* =========================================================
   10_recursive_output.c
   Recursion and return values
   ========================================================= */

#include <stdio.h>

int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return n + sum(n - 1);
}

int main(void)
{
    printf("%d\n", sum(4));

    return 0;
}
