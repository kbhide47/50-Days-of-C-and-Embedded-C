/* ============================================================
   DAY 9 — POINTERS + ARRAYS
   Save each question as a separate .c file
   ============================================================ */


/* ============================================================
   Q1. Print array elements and their addresses
   File: q01_array_address.c
   ============================================================ */

#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int i;

    for(i = 0; i < 5; i++)
    {
        printf("arr[%d] = %d, Address = %p\n",
               i, arr[i], (void *)&arr[i]);
    }

    return 0;
}


/* ============================================================
   Q2. Traverse an array using a pointer
   File: q02_array_traversal_pointer.c
   ============================================================ */

#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr;
    int i;

    for(i = 0; i < 5; i++)
    {
        printf("%d ", *ptr);
        ptr++;
    }

    printf("\n");

    return 0;
}


/* ============================================================
   Q3. Find sum of array elements using a pointer
   File: q03_sum_array_pointer.c
   ============================================================ */

#include <stdio.h>

int main()
{
    int arr[100], n;
    int *ptr;
    int sum = 0;
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    ptr = arr;

    for(i = 0; i < n; i++)
    {
        sum += *ptr;
        ptr++;
    }

    printf("Sum = %d\n", sum);

    return 0;
}


/* ============================================================
   Q4. Find maximum element using a pointer
   File: q04_find_max_pointer.c
   ============================================================ */

#include <stdio.h>

int main()
{
    int arr[100], n;
    int *ptr;
    int max;
    int i;

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
        ptr++;

        if(*ptr > max)
        {
            max = *ptr;
        }
    }

    printf("Maximum = %d\n", max);

    return 0;
}


/* ============================================================
   Q5. Reverse an array using two pointers
   File: q05_reverse_array_pointer.c
   ============================================================ */

#include <stdio.h>

int main()
{
    int arr[100], n;
    int *start, *end;
    int temp;
    int i;

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
   Q6. Copy one array into another using pointers
   File: q06_copy_array_pointer.c
   ============================================================ */

#include <stdio.h>

int main()
{
    int source[100], destination[100];
    int n, i;
    int *src, *dest;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &source[i]);
    }

    src = source;
    dest = destination;

    for(i = 0; i < n; i++)
    {
        *dest = *src;

        src++;
        dest++;
    }

    printf("Copied array: ");

    for(i = 0; i < n; i++)
    {
        printf("%d ", destination[i]);
    }

    printf("\n");

    return 0;
}


/* ============================================================
   Q7. Compare two arrays using pointers
   File: q07_compare_arrays_pointer.c
   ============================================================ */

#include <stdio.h>

int main()
{
    int arr1[100], arr2[100];
    int n, i;
    int equal = 1;
    int *p1, *p2;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter first array:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter second array:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr2[i]);
    }

    p1 = arr1;
    p2 = arr2;

    for(i = 0; i < n; i++)
    {
        if(*p1 != *p2)
        {
            equal = 0;
            break;
        }

        p1++;
        p2++;
    }

    if(equal)
        printf("Arrays are equal\n");
    else
        printf("Arrays are not equal\n");

    return 0;
}


/* ============================================================
   Q8. Print a string using a character pointer
   File: q08_string_pointer.c
   ============================================================ */

#include <stdio.h>

int main()
{
    char str[100];
    char *ptr;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    ptr = str;

    printf("String: ");

    while(*ptr != '\0')
    {
        printf("%c", *ptr);
        ptr++;
    }

    return 0;
}


/* ============================================================
   Q9. Count vowels using a character pointer
   File: q09_count_vowels_pointer.c
   ============================================================ */

#include <stdio.h>

int main()
{
    char str[100];
    char *ptr;
    int vowels = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    ptr = str;

    while(*ptr != '\0')
    {
        char ch = *ptr;

        if(ch == 'a' || ch == 'e' || ch == 'i' ||
           ch == 'o' || ch == 'u' ||
           ch == 'A' || ch == 'E' || ch == 'I' ||
           ch == 'O' || ch == 'U')
        {
            vowels++;
        }

        ptr++;
    }

    printf("Vowels = %d\n", vowels);

    return 0;
}


/* ============================================================
   Q10. Access a 2D array using pointer notation
   File: q10_2d_array_pointer.c
   ============================================================ */

#include <stdio.h>

int main()
{
    int arr[2][3] = {
        {10, 20, 30},
        {40, 50, 60}
    };

    int i, j;

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("%d ", *(*(arr + i) + j));
        }

        printf("\n");
    }

    return 0;
}
