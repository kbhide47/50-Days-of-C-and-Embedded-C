
/*
===========================================================
DAY 50 - FINAL C + EMBEDDED C REVISION
===========================================================

Q1. Reverse an array
Q2. Find frequency of elements
Q3. Check palindrome string
Q4. Find second largest element
Q5. Count set bits
Q6. Set, clear, toggle and check bit
Q7. Swap using pointers
Q8. Reverse 8-bit binary
Q9. Circular buffer
Q10. LED state machine

===========================================================
Q1. REVERSE AN ARRAY
===========================================================
*/

#include <stdio.h>

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

/*
===========================================================
Q2. FREQUENCY OF ELEMENTS
===========================================================
*/

/*
#include <stdio.h>

int main(void)
{
    int arr[] = {1, 2, 2, 3, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        int already_counted = 0;

        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                already_counted = 1;
                break;
            }
        }

        if (!already_counted)
        {
            int count = 0;

            for (int j = 0; j < n; j++)
            {
                if (arr[i] == arr[j])
                    count++;
            }

            printf("%d occurs %d times\n", arr[i], count);
        }
    }

    return 0;
}
*/

/*
===========================================================
Q3. PALINDROME STRING
===========================================================
*/

/*
#include <stdio.h>

int main(void)
{
    char str[] = "MADAM";
    int len = 0;
    int palindrome = 1;

    while (str[len] != '\0')
        len++;

    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - 1 - i])
        {
            palindrome = 0;
            break;
        }
    }

    printf("%s\n", palindrome ? "Palindrome" : "Not Palindrome");

    return 0;
}
*/

/*
===========================================================
Q4. SECOND LARGEST ELEMENT
===========================================================
*/

/*
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int arr[] = {10, 20, 40, 30, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int largest = INT_MIN;
    int second = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            second = largest;
            largest = arr[i];
        }
        else if (arr[i] > second && arr[i] != largest)
        {
            second = arr[i];
        }
    }

    if (second == INT_MIN)
        printf("Second largest not found\n");
    else
        printf("Second largest = %d\n", second);

    return 0;
}
*/

/*
===========================================================
Q5. COUNT SET BITS
===========================================================
*/

/*
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t num = 0x0F;
    int count = 0;

    while (num != 0)
    {
        count += num & 1U;
        num >>= 1;
    }

    printf("Set bits = %d\n", count);

    return 0;
}
*/

/*
===========================================================
Q6. SET, CLEAR, TOGGLE AND CHECK BIT
===========================================================
*/

/*
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t reg = 0x05;
    unsigned int bit = 1;

    reg |= (uint8_t)(1U << bit);
    printf("SET = 0x%02X\n", reg);

    reg &= (uint8_t)~(1U << bit);
    printf("CLEAR = 0x%02X\n", reg);

    reg ^= (uint8_t)(1U << bit);
    printf("TOGGLE = 0x%02X\n", reg);

    if (reg & (1U << bit))
        printf("Bit is SET\n");
    else
        printf("Bit is CLEAR\n");

    return 0;
}
*/

/*
===========================================================
Q7. SWAP USING POINTERS
===========================================================
*/

/*
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

    swap(&x, &y);

    printf("%d %d\n", x, y);

    return 0;
}
*/

/*
===========================================================
Q8. REVERSE 8-BIT NUMBER
===========================================================
*/

/*
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t num = 0x12;
    uint8_t reverse = 0;

    for (int i = 0; i < 8; i++)
    {
        reverse <<= 1;
        reverse |= num & 1U;
        num >>= 1;
    }

    printf("Reverse = 0x%02X\n", reverse);

    return 0;
}
*/

/*
===========================================================
Q9. CIRCULAR BUFFER
===========================================================
*/

/*
#include <stdio.h>
#include <stdint.h>

#define SIZE 5

uint8_t buffer[SIZE];
int head = 0, tail = 0, count = 0;

int enqueue(uint8_t data)
{
    if (count == SIZE)
        return 0;

    buffer[head] = data;
    head = (head + 1) % SIZE;
    count++;

    return 1;
}

int dequeue(uint8_t *data)
{
    if (count == 0)
        return 0;

    *data = buffer[tail];
    tail = (tail + 1) % SIZE;
    count--;

    return 1;
}

int main(void)
{
    uint8_t data;

    enqueue(10);
    enqueue(20);
    enqueue(30);

    while (dequeue(&data))
        printf("%d ", data);

    return 0;
}
*/

/*
===========================================================
Q10. LED STATE MACHINE
===========================================================
*/

/*
#include <stdio.h>

typedef enum
{
    LED_OFF,
    LED_ON
} State;

int main(void)
{
    State state = LED_OFF;

    for (int i = 0; i < 4; i++)
    {
        switch (state)
        {
            case LED_OFF:
                printf("LED OFF\n");
                state = LED_ON;
                break;

            case LED_ON:
                printf("LED ON\n");
                state = LED_OFF;
                break;
        }
    }

    return 0;
}
*/
