/* ============================================================
   DAY 6 — ARRAYS
   Save each question as a separate .c file
   ============================================================ */


/* ============================================================
   Q1. Read and print elements of an array
   File: q01_read_print_array.c
   ============================================================ */

#include <stdio.h>

int main()
{
    int arr[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Array: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}


/* ============================================================
   Q2. Find the sum of all array elements
   File: q02_sum_array.c
   ============================================================ */

#include <stdio.h>

int main()
{
    int arr[100], n, i, sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    printf("Sum = %d\n", sum);

    return 0;
}


/* ============================================================
   Q3. Find the maximum element in an array
   File: q03_max_element.c
   ============================================================ */

#include <stdio.h>

int main()
{
    int arr[100], n, i, max;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    max = arr[0];

    for(i = 1; i < n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }

    printf("Maximum = %d\n", max);

    return 0;
}


/* ============================================================
   Q4. Find the minimum element in an array
   File: q04_min_element.c
   ============================================================ */

#include <stdio.h>

int main()
{
    int arr[100], n, i, min;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    min = arr[0];

    for(i = 1; i < n; i++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
        }
    }

    printf("Minimum = %d\n", min);

    return 0;
}


/* ============================================================
   Q5. Reverse an array
   File: q05_reverse_array.c
   ============================================================ */

#include <stdio.h>

int main()
{
    int arr[100], n, i, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }

    printf("Reversed array: ");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}


/* ============================================================
   Q6. Find the second largest element
   File: q06_second_largest.c
   ============================================================ */

#include <stdio.h>
#include <limits.h>

int main()
{
    int arr[100], n, i;
    int largest = INT_MIN;
    int second = INT_MIN;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n; i++)
    {
        if(arr[i] > largest)
        {
            second = largest;
            largest = arr[i];
        }
        else if(arr[i] > second && arr[i] != largest)
        {
            second = arr[i];
        }
    }

    if(second == INT_MIN)
        printf("Second largest does not exist\n");
    else
        printf("Second largest = %d\n", second);

    return 0;
}


/* ============================================================
   Q7. Count even and odd elements
   File: q07_count_even_odd.c
   ============================================================ */

#include <stdio.h>

int main()
{
    int arr[100], n, i;
    int even = 0, odd = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);

        if(arr[i] % 2 == 0)
            even++;
        else
            odd++;
    }

    printf("Even elements = %d\n", even);
    printf("Odd elements = %d\n", odd);

    return 0;
}


/* ============================================================
   Q8. Search an element using Linear Search
   File: q08_linear_search.c
   ============================================================ */

#include <stdio.h>

int main()
{
    int arr[100], n, i, key;
    int found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            printf("Element found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if(!found)
    {
        printf("Element not found\n");
    }

    return 0;
}


/* ============================================================
   Q9. Sort an array in ascending order using Bubble Sort
   File: q09_bubble_sort.c
   ============================================================ */

#include <stdio.h>

int main()
{
    int arr[100], n, i, j, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - 1 - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Sorted array: ");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}


/* ============================================================
   Q10. Remove duplicate elements from an array
   File: q10_remove_duplicates.c
   ============================================================ */

#include <stdio.h>

int main()
{
    int arr[100], n, i, j, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                for(k = j; k < n - 1; k++)
                {
                    arr[k] = arr[k + 1];
                }

                n--;
                j--;
            }
        }
    }

    printf("Array after removing duplicates: ");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
