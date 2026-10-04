/* =========================================================
   DAY 23 — ARRAYS, STRINGS & CHARACTER POINTERS
   ========================================================= */


/* =========================================================
   Q1. Find sum of array elements
   File: q01_array_sum.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    printf("Sum = %d\n", sum);

    return 0;
}


/* =========================================================
   Q2. Find maximum element in array
   File: q02_find_max_array.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int arr[] = {25, 10, 45, 30, 15};
    int size = sizeof(arr) / sizeof(arr[0]);

    int max = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    printf("Maximum = %d\n", max);

    return 0;
}


/* =========================================================
   Q3. Reverse an array
   File: q03_reverse_array.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    int start = 0;
    int end = size - 1;

    while (start < end)
    {
        int temp = arr[start];

        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }

    printf("Reversed array: ");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}


/* =========================================================
   Q4. Find string length without strlen()
   File: q04_string_length.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    char str[] = "Embedded";

    int length = 0;

    while (str[length] != '\0')
    {
        length++;
    }

    printf("Length = %d\n", length);

    return 0;
}


/* =========================================================
   Q5. Reverse a string
   File: q05_reverse_string.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    char str[] = "Embedded";

    int length = 0;

    while (str[length] != '\0')
    {
        length++;
    }

    for (int i = length - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }

    printf("\n");

    return 0;
}


/* =========================================================
   Q6. Count vowels in a string
   File: q06_count_vowels.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    char str[] = "Embedded C Programming";

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


/* =========================================================
   Q7. Compare two strings without strcmp()
   File: q07_compare_strings.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    char str1[] = "Embedded";
    char str2[] = "Embedded";

    int i = 0;
    int same = 1;

    while (str1[i] != '\0' || str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            same = 0;
            break;
        }

        i++;
    }

    if (same)
        printf("Strings are equal\n");
    else
        printf("Strings are different\n");

    return 0;
}


/* =========================================================
   Q8. Copy string without strcpy()
   File: q08_copy_string.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    char source[] = "Embedded C";
    char destination[50];

    int i = 0;

    while (source[i] != '\0')
    {
        destination[i] = source[i];
        i++;
    }

    destination[i] = '\0';

    printf("Copied string = %s\n",
           destination);

    return 0;
}


/* =========================================================
   Q9. Character pointer
   File: q09_character_pointer.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    char str[] = "UART";

    char *ptr = str;

    while (*ptr != '\0')
    {
        printf("%c ", *ptr);
        ptr++;
    }

    printf("\n");

    return 0;
}


/* =========================================================
   Q10. Embedded-style RX buffer
   File: q10_embedded_rx_buffer.c
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t rx_buffer[8] =
    {
        0xAA,
        0x10,
        0x25,
        0x30,
        0x55
    };

    uint8_t *ptr = rx_buffer;

    printf("Received bytes:\n");

    for (int i = 0; i < 5; i++)
    {
        printf("0x%02X ", *(ptr + i));
    }

    printf("\n");

    return 0;
}
