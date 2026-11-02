
/*
=========================================================
DAY 48 - MIXED C + EMBEDDED C INTERVIEW PROGRAMS
=========================================================

Q1. Reverse an integer
Q2. Check palindrome number
Q3. Swap two numbers using pointers
Q4. Find largest element in array
Q5. Count set bits
Q6. Set, clear and toggle a bit
Q7. Check endianness
Q8. Reverse bits of 8-bit number
Q9. Circular buffer implementation
Q10. FSM LED controller

=========================================================
Q1. REVERSE AN INTEGER
=========================================================
*/

#include <stdio.h>

int main(void)
{
    int num = 1234;
    int reverse = 0;

    while (num > 0)
    {
        reverse = reverse * 10 + num % 10;
        num /= 10;
    }

    printf("Reverse = %d\n", reverse);

    return 0;
}

/*
=========================================================
Q2. CHECK PALINDROME NUMBER
=========================================================
*/

/*
#include <stdio.h>

int main(void)
{
    int num = 121;
    int temp = num;
    int reverse = 0;

    while (temp > 0)
    {
        reverse = reverse * 10 + temp % 10;
        temp /= 10;
    }

    if (num == reverse)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    return 0;
}
*/

/*
=========================================================
Q3. SWAP TWO NUMBERS USING POINTERS
=========================================================
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

    printf("x = %d, y = %d\n", x, y);

    return 0;
}
*/

/*
=========================================================
Q4. FIND LARGEST ELEMENT IN ARRAY
=========================================================
*/

/*
#include <stdio.h>

int main(void)
{
    int arr[] = {10, 25, 5, 40, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    printf("Largest = %d\n", max);

    return 0;
}
*/

/*
=========================================================
Q5. COUNT SET BITS
=========================================================
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
=========================================================
Q6. SET, CLEAR AND TOGGLE A BIT
=========================================================
*/

/*
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t reg = 0x0A;
    unsigned int bit = 2;

    reg |= (uint8_t)(1U << bit);
    printf("After SET    = 0x%02X\n", reg);

    reg &= (uint8_t)~(1U << bit);
    printf("After CLEAR  = 0x%02X\n", reg);

    reg ^= (uint8_t)(1U << bit);
    printf("After TOGGLE = 0x%02X\n", reg);

    return 0;
}
*/

/*
=========================================================
Q7. CHECK ENDIANNESS
=========================================================
*/

/*
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint32_t num = 0x12345678;
    uint8_t *ptr = (uint8_t *)&num;

    if (ptr[0] == 0x78)
        printf("Little Endian\n");
    else
        printf("Big Endian\n");

    return 0;
}
*/

/*
=========================================================
Q8. REVERSE BITS OF 8-BIT NUMBER
=========================================================
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

    printf("Reversed = 0x%02X\n", reverse);

    return 0;
}
*/

/*
=========================================================
Q9. CIRCULAR BUFFER IMPLEMENTATION
=========================================================
*/

/*
#include <stdio.h>
#include <stdint.h>

#define SIZE 5

uint8_t buffer[SIZE];
int head = 0;
int tail = 0;
int count = 0;

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
    {
        printf("%d ", data);
    }

    printf("\n");

    return 0;
}
*/

/*
=========================================================
Q10. FSM LED CONTROLLER
=========================================================
*/

/*
#include <stdio.h>

typedef enum
{
    LED_OFF,
    LED_ON
} LED_State;

int main(void)
{
    LED_State state = LED_OFF;

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
