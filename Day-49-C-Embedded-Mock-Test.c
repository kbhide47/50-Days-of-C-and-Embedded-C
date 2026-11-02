
/*
===========================================================
DAY 49 - C + EMBEDDED C MOCK INTERVIEW TEST
===========================================================

Q1. Find second largest element
Q2. Remove duplicate elements from array
Q3. Reverse string without library function
Q4. Count vowels in string
Q5. Find missing number in array
Q6. Check whether number is power of 2
Q7. Swap two numbers without temporary variable
Q8. Reverse bits of 8-bit number
Q9. Structure for sensor data
Q10. Simulate LED using FSM

===========================================================
Q1. SECOND LARGEST ELEMENT
===========================================================
*/

#include <stdio.h>
#include <limits.h>

int main(void)
{
    int arr[] = {10, 20, 5, 40, 30};
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

/*
===========================================================
Q2. REMOVE DUPLICATE ELEMENTS FROM ARRAY
===========================================================
*/

/*
#include <stdio.h>

int main(void)
{
    int arr[] = {1, 2, 2, 3, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        int duplicate = 0;

        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                duplicate = 1;
                break;
            }
        }

        if (!duplicate)
            printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
*/

/*
===========================================================
Q3. REVERSE STRING WITHOUT LIBRARY FUNCTION
===========================================================
*/

/*
#include <stdio.h>

int main(void)
{
    char str[] = "EMBEDDED";
    int len = 0;

    while (str[len] != '\0')
        len++;

    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }

    printf("%s\n", str);

    return 0;
}
*/

/*
===========================================================
Q4. COUNT VOWELS IN STRING
===========================================================
*/

/*
#include <stdio.h>

int main(void)
{
    char str[] = "Embedded C Interview";
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];

        if (ch == 'a' || ch == 'e' || ch == 'i' ||
            ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' ||
            ch == 'O' || ch == 'U')
        {
            count++;
        }
    }

    printf("Vowels = %d\n", count);

    return 0;
}
*/

/*
===========================================================
Q5. FIND MISSING NUMBER FROM 1 TO N
===========================================================
*/

/*
#include <stdio.h>

int main(void)
{
    int arr[] = {1, 2, 4, 5, 6};
    int n = 6;

    int expected = n * (n + 1) / 2;
    int actual = 0;

    for (int i = 0; i < n - 1; i++)
        actual += arr[i];

    printf("Missing number = %d\n", expected - actual);

    return 0;
}
*/

/*
===========================================================
Q6. CHECK WHETHER NUMBER IS POWER OF 2
===========================================================
*/

/*
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint32_t num = 16;

    if (num != 0 && (num & (num - 1)) == 0)
        printf("Power of 2\n");
    else
        printf("Not Power of 2\n");

    return 0;
}
*/

/*
===========================================================
Q7. SWAP TWO NUMBERS WITHOUT TEMPORARY VARIABLE
===========================================================
*/

/*
#include <stdio.h>

int main(void)
{
    int a = 10;
    int b = 20;

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    printf("a = %d, b = %d\n", a, b);

    return 0;
}
*/

/*
===========================================================
Q8. REVERSE BITS OF 8-BIT NUMBER
===========================================================
*/

/*
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t num = 0x96;
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
===========================================================
Q9. STRUCTURE FOR SENSOR DATA
===========================================================
*/

/*
#include <stdio.h>

typedef struct
{
    float temperature;
    float humidity;
    int sensor_id;
} Sensor;

int main(void)
{
    Sensor s1 = {25.5f, 60.0f, 101};

    printf("Sensor ID = %d\n", s1.sensor_id);
    printf("Temperature = %.1f\n", s1.temperature);
    printf("Humidity = %.1f\n", s1.humidity);

    return 0;
}
*/

/*
===========================================================
Q10. SIMULATE LED USING FSM
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

    for (int i = 0; i < 5; i++)
    {
        if (state == LED_OFF)
        {
            printf("LED OFF\n");
            state = LED_ON;
        }
        else
        {
            printf("LED ON\n");
            state = LED_OFF;
        }
    }

    return 0;
}
*/
