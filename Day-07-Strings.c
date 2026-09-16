/* ============================================================
   DAY 7 — STRINGS
   Save each question as a separate .c file
   ============================================================ */


/* ============================================================
   Q1. Read and print a string
   File: q01_read_print_string.c
   ============================================================ */

#include <stdio.h>

int main()
{
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("String: %s", str);

    return 0;
}


/* ============================================================
   Q2. Find length of a string without strlen()
   File: q02_string_length.c
   ============================================================ */

#include <stdio.h>

int main()
{
    char str[100];
    int i = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    while(str[i] != '\0' && str[i] != '\n')
    {
        i++;
    }

    printf("Length = %d\n", i);

    return 0;
}


/* ============================================================
   Q3. Reverse a string without strrev()
   File: q03_reverse_string.c
   ============================================================ */

#include <stdio.h>

int main()
{
    char str[100], temp;
    int i, j, length = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    while(str[length] != '\0' && str[length] != '\n')
    {
        length++;
    }

    i = 0;
    j = length - 1;

    while(i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;

        i++;
        j--;
    }

    str[length] = '\0';

    printf("Reversed string: %s\n", str);

    return 0;
}


/* ============================================================
   Q4. Copy one string to another without strcpy()
   File: q04_copy_string.c
   ============================================================ */

#include <stdio.h>

int main()
{
    char source[100], destination[100];
    int i = 0;

    printf("Enter source string: ");
    fgets(source, sizeof(source), stdin);

    while(source[i] != '\0' && source[i] != '\n')
    {
        destination[i] = source[i];
        i++;
    }

    destination[i] = '\0';

    printf("Copied string: %s\n", destination);

    return 0;
}


/* ============================================================
   Q5. Compare two strings without strcmp()
   File: q05_compare_strings.c
   ============================================================ */

#include <stdio.h>

int main()
{
    char str1[100], str2[100];
    int i = 0, equal = 1;

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);

    while(str1[i] != '\0' && str1[i] != '\n' &&
          str2[i] != '\0' && str2[i] != '\n')
    {
        if(str1[i] != str2[i])
        {
            equal = 0;
            break;
        }

        i++;
    }

    if(equal &&
       (str1[i] == '\n' || str1[i] == '\0') &&
       (str2[i] == '\n' || str2[i] == '\0'))
    {
        printf("Strings are equal\n");
    }
    else
    {
        printf("Strings are not equal\n");
    }

    return 0;
}


/* ============================================================
   Q6. Count vowels and consonants
   File: q06_count_vowels_consonants.c
   ============================================================ */

#include <stdio.h>

int main()
{
    char str[100];
    int i, vowels = 0, consonants = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for(i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];

        if(ch >= 'A' && ch <= 'Z')
        {
            ch = ch + ('a' - 'A');
        }

        if(ch >= 'a' && ch <= 'z')
        {
            if(ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u')
            {
                vowels++;
            }
            else
            {
                consonants++;
            }
        }
    }

    printf("Vowels = %d\n", vowels);
    printf("Consonants = %d\n", consonants);

    return 0;
}


/* ============================================================
   Q7. Count number of words in a string
   File: q07_count_words.c
   ============================================================ */

#include <stdio.h>

int main()
{
    char str[200];
    int i, words = 0, in_word = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
        {
            if(in_word == 0)
            {
                words++;
                in_word = 1;
            }
        }
        else
        {
            in_word = 0;
        }
    }

    printf("Number of words = %d\n", words);

    return 0;
}


/* ============================================================
   Q8. Check whether a string is a palindrome
   File: q08_palindrome_string.c
   ============================================================ */

#include <stdio.h>

int main()
{
    char str[100];
    int i = 0, j, length = 0, palindrome = 1;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    while(str[length] != '\0' && str[length] != '\n')
    {
        length++;
    }

    j = length - 1;

    while(i < j)
    {
        if(str[i] != str[j])
        {
            palindrome = 0;
            break;
        }

        i++;
        j--;
    }

    if(palindrome)
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");

    return 0;
}


/* ============================================================
   Q9. Count occurrences of a character
   File: q09_count_character.c
   ============================================================ */

#include <stdio.h>

int main()
{
    char str[100], ch;
    int i, count = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter character to search: ");
    scanf(" %c", &ch);

    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == ch)
        {
            count++;
        }
    }

    printf("'%c' occurs %d times\n", ch, count);

    return 0;
}


/* ============================================================
   Q10. Remove spaces from a string
   File: q10_remove_spaces.c
   ============================================================ */

#include <stdio.h>

int main()
{
    char str[100];
    int i, j = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] != ' ')
        {
            str[j] = str[i];
            j++;
        }
    }

    str[j] = '\0';

    printf("String without spaces: %s", str);

    return 0;
}
