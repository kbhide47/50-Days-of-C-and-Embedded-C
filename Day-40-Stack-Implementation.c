/* =========================================================
   01_basic_stack.c
   Basic Stack
   ========================================================= */

#include <stdio.h>

#define SIZE 5

int main(void)
{
    int stack[SIZE] = {10, 20, 30};
    int top = 2;

    printf("Stack: ");

    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }

    printf("\n");

    return 0;
}


/* =========================================================
   02_push.c
   Push = Insert an element into stack
   ========================================================= */

#include <stdio.h>

#define SIZE 5

int main(void)
{
    int stack[SIZE];
    int top = -1;
    int data = 10;

    if (top == SIZE - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = data;

        printf("Pushed: %d\n", stack[top]);
    }

    return 0;
}


/* =========================================================
   03_pop.c
   Pop = Remove top element
   ========================================================= */

#include <stdio.h>

#define SIZE 5

int main(void)
{
    int stack[SIZE] = {10, 20, 30};
    int top = 2;

    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Popped: %d\n", stack[top]);
        top--;
    }

    return 0;
}


/* =========================================================
   04_stack_full.c
   Checking Stack Overflow condition
   ========================================================= */

#include <stdio.h>

#define SIZE 5

int main(void)
{
    int stack[SIZE];
    int top = SIZE - 1;

    (void)stack;

    if (top == SIZE - 1)
    {
        printf("Stack is FULL\n");
    }
    else
    {
        printf("Space available\n");
    }

    return 0;
}


/* =========================================================
   05_stack_empty.c
   Checking Stack Underflow condition
   ========================================================= */

#include <stdio.h>

#define SIZE 5

int main(void)
{
    int stack[SIZE];
    int top = -1;

    (void)stack;

    if (top == -1)
    {
        printf("Stack is EMPTY\n");
    }
    else
    {
        printf("Stack contains data\n");
    }

    return 0;
}


/* =========================================================
   06_stack_peek.c
   Peek = Read top element without removing it
   ========================================================= */

#include <stdio.h>

#define SIZE 5

int main(void)
{
    int stack[SIZE] = {100, 200, 300};
    int top = 2;

    if (top == -1)
    {
        printf("Stack Empty\n");
    }
    else
    {
        printf("Top element: %d\n", stack[top]);
    }

    return 0;
}


/* =========================================================
   07_stack_display.c
   Display stack from TOP to BOTTOM
   ========================================================= */

#include <stdio.h>

#define SIZE 5

int main(void)
{
    int stack[SIZE] = {10, 20, 30, 40};
    int top = 3;

    if (top == -1)
    {
        printf("Stack Empty\n");
    }
    else
    {
        printf("Stack:\n");

        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }

    return 0;
}


/* =========================================================
   08_stack_array.c
   Complete Stack using Array
   ========================================================= */

#include <stdio.h>

#define SIZE 5

int main(void)
{
    int stack[SIZE];
    int top = -1;

    /* PUSH */
    stack[++top] = 10;
    stack[++top] = 20;
    stack[++top] = 30;

    printf("After Push:\n");

    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }

    /* POP */
    printf("\nPopped: %d\n", stack[top--]);

    printf("\nAfter Pop:\n");

    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }

    return 0;
}


/* =========================================================
   09_stack_expression.c
   Check balanced parentheses using Stack
   ========================================================= */

#include <stdio.h>

#define SIZE 50

int main(void)
{
    char stack[SIZE];
    int top = -1;

    const char expression[] = "(A+B)*(C+D)";
    int balanced = 1;

    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '(')
        {
            if (top == SIZE - 1)
            {
                balanced = 0;
                break;
            }

            stack[++top] = '(';
        }
        else if (expression[i] == ')')
        {
            if (top == -1)
            {
                balanced = 0;
                break;
            }

            top--;
        }
    }

    if (top != -1)
    {
        balanced = 0;
    }

    if (balanced)
    {
        printf("Parentheses are balanced\n");
    }
    else
    {
        printf("Parentheses are NOT balanced\n");
    }

    return 0;
}


/* =========================================================
   10_embedded_stack_driver.c
   Embedded C Style Stack Driver
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

#define STACK_SIZE 8U

typedef struct
{
    uint8_t data[STACK_SIZE];
    uint8_t top;
} Stack;

static Stack system_stack;

void Stack_Init(void)
{
    system_stack.top = 0U;
}

uint8_t Stack_IsEmpty(void)
{
    return (system_stack.top == 0U);
}

uint8_t Stack_IsFull(void)
{
    return (system_stack.top == STACK_SIZE);
}

uint8_t Stack_Push(uint8_t data)
{
    if (Stack_IsFull())
    {
        return 0U;
    }

    system_stack.data[system_stack.top] = data;
    system_stack.top++;

    return 1U;
}

uint8_t Stack_Pop(uint8_t *data)
{
    if (Stack_IsEmpty())
    {
        return 0U;
    }

    system_stack.top--;
    *data = system_stack.data[system_stack.top];

    return 1U;
}

uint8_t Stack_Peek(uint8_t *data)
{
    if (Stack_IsEmpty())
    {
        return 0U;
    }

    *data = system_stack.data[system_stack.top - 1U];

    return 1U;
}

int main(void)
{
    uint8_t data;

    Stack_Init();

    Stack_Push(10U);
    Stack_Push(20U);
    Stack_Push(30U);

    if (Stack_Peek(&data))
    {
        printf("Top: %u\n", (unsigned)data);
    }

    printf("Popping:\n");

    while (Stack_Pop(&data))
    {
        printf("%u\n", (unsigned)data);
    }

    return 0;
}
