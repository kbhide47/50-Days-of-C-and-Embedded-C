/* =========================================================
   Q1: Size of Data Types
   File: q01_sizeof_data_types.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    printf("char        = %zu bytes\n", sizeof(char));
    printf("short       = %zu bytes\n", sizeof(short));
    printf("int         = %zu bytes\n", sizeof(int));
    printf("long        = %zu bytes\n", sizeof(long));
    printf("long long   = %zu bytes\n", sizeof(long long));
    printf("float       = %zu bytes\n", sizeof(float));
    printf("double      = %zu bytes\n", sizeof(double));

    return 0;
}


/* =========================================================
   Q2: Size of an Array
   File: q02_sizeof_array.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};

    size_t total_size = sizeof(arr);
    size_t element_size = sizeof(arr[0]);
    size_t count = total_size / element_size;

    printf("Array size = %zu bytes\n", total_size);
    printf("Element size = %zu bytes\n", element_size);
    printf("Number of elements = %zu\n", count);

    return 0;
}


/* =========================================================
   Q3: Size of a Pointer
   File: q03_sizeof_pointer.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int value = 100;
    int *ptr = &value;

    printf("Size of int = %zu bytes\n", sizeof(value));
    printf("Size of pointer = %zu bytes\n", sizeof(ptr));
    printf("Value = %d\n", *ptr);

    return 0;
}


/* =========================================================
   Q4: Signed vs Unsigned
   File: q04_signed_unsigned.c
   ========================================================= */

#include <stdio.h>
#include <limits.h>

int main(void)
{
    unsigned int u = 10U;
    int s = -10;

    printf("Signed value = %d\n", s);
    printf("Unsigned value = %u\n", u);
    printf("INT_MIN = %d\n", INT_MIN);
    printf("INT_MAX = %d\n", INT_MAX);
    printf("UINT_MAX = %u\n", UINT_MAX);

    return 0;
}


/* =========================================================
   Q5: Type Modifiers
   File: q05_type_modifiers.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    short int a = 100;
    unsigned int b = 500U;
    long int c = 100000L;
    long long int d = 9000000000LL;

    printf("short = %hd\n", a);
    printf("unsigned = %u\n", b);
    printf("long = %ld\n", c);
    printf("long long = %lld\n", d);

    return 0;
}


/* =========================================================
   Q6: Unsigned Integer Wraparound
   File: q06_integer_overflow.c
   ========================================================= */

#include <stdio.h>
#include <limits.h>

int main(void)
{
    unsigned char value = UCHAR_MAX;

    printf("Before increment = %u\n", (unsigned int)value);

    value++;

    printf("After increment = %u\n", (unsigned int)value);

    return 0;
}


/* =========================================================
   Q7: Type Conversion
   File: q07_type_conversion.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int a = 5;
    int b = 2;

    float implicit_conversion = a;
    float explicit_conversion = (float)a / b;

    printf("Implicit conversion = %.2f\n", implicit_conversion);
    printf("Explicit division = %.2f\n", explicit_conversion);

    return 0;
}


/* =========================================================
   Q8: Integer vs Floating-Point Division
   File: q08_integer_division.c
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int a = 7;
    int b = 2;

    printf("Integer division = %d\n", a / b);
    printf("Floating division = %.2f\n", (double)a / b);

    return 0;
}


/* =========================================================
   Q9: Fixed-Width Integer Types
   File: q09_fixed_width_types.c
   ========================================================= */

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    uint8_t sensor_status = 255U;
    uint16_t adc_value = 4095U;
    uint32_t timestamp = 100000U;

    printf("Status = %" PRIu8 "\n", sensor_status);
    printf("ADC = %" PRIu16 "\n", adc_value);
    printf("Timestamp = %" PRIu32 "\n", timestamp);

    printf("uint8_t size = %zu bytes\n", sizeof(sensor_status));
    printf("uint16_t size = %zu bytes\n", sizeof(adc_value));
    printf("uint32_t size = %zu bytes\n", sizeof(timestamp));

    return 0;
}


/* =========================================================
   Q10: Embedded Data Types
   File: q10_embedded_data_types.c
   ========================================================= */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int main(void)
{
    uint16_t adc_reading = 3000U;
    int16_t temperature = -10;
    uint32_t uptime_ms = 500000U;
    bool sensor_ready = true;

    printf("ADC Reading = %" PRIu16 "\n", adc_reading);
    printf("Temperature = %d\n", (int)temperature);
    printf("Uptime = %" PRIu32 " ms\n", uptime_ms);
    printf("Sensor Ready = %s\n",
           sensor_ready ? "Yes" : "No");

    return 0;
}
