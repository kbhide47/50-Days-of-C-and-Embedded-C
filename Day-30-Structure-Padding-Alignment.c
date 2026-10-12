/* =========================================================
   Q1: Structure Size
   File: q01_structure_size.c
   ========================================================= */

#include <stdio.h>

struct Example
{
    char a;
    int b;
    char c;
};

int main(void)
{
    printf("Size of char = %zu\n", sizeof(char));
    printf("Size of int = %zu\n", sizeof(int));
    printf("Size of structure = %zu\n", sizeof(struct Example));

    return 0;
}


/* =========================================================
   Q2: Structure Padding
   File: q02_structure_padding.c
   ========================================================= */

#include <stdio.h>

struct Data
{
    char a;
    int b;
};

int main(void)
{
    struct Data d;

    printf("Size of char = %zu bytes\n", sizeof(d.a));
    printf("Size of int = %zu bytes\n", sizeof(d.b));
    printf("Size of structure = %zu bytes\n", sizeof(d));

    return 0;
}


/* =========================================================
   Q3: Structure Member Order
   File: q03_structure_member_order.c
   ========================================================= */

#include <stdio.h>

struct First
{
    char a;
    int b;
    char c;
};

struct Second
{
    int b;
    char a;
    char c;
};

int main(void)
{
    printf("First structure = %zu bytes\n", sizeof(struct First));
    printf("Second structure = %zu bytes\n", sizeof(struct Second));

    return 0;
}


/* =========================================================
   Q4: Structure Member Alignment
   File: q04_structure_alignment.c
   ========================================================= */

#include <stdio.h>
#include <stddef.h>

struct Sample
{
    char a;
    int b;
    char c;
};

int main(void)
{
    printf("Offset of a = %zu\n",
           offsetof(struct Sample, a));

    printf("Offset of b = %zu\n",
           offsetof(struct Sample, b));

    printf("Offset of c = %zu\n",
           offsetof(struct Sample, c));

    printf("Total size = %zu\n", sizeof(struct Sample));

    return 0;
}


/* =========================================================
   Q5: Nested Structure Size
   File: q05_nested_structure_size.c
   ========================================================= */

#include <stdio.h>

struct Address
{
    int pin;
    char building;
};

struct Student
{
    int roll;
    struct Address address;
};

int main(void)
{
    printf("Address size = %zu\n", sizeof(struct Address));
    printf("Student size = %zu\n", sizeof(struct Student));

    return 0;
}


/* =========================================================
   Q6: Array of Structures
   File: q06_array_of_structures.c
   ========================================================= */

#include <stdio.h>

struct Sensor
{
    char id;
    int reading;
};

int main(void)
{
    struct Sensor sensors[3] = {
        {'A', 100},
        {'B', 200},
        {'C', 300}
    };

    printf("One sensor size = %zu bytes\n",
           sizeof(sensors[0]));

    printf("All sensors size = %zu bytes\n",
           sizeof(sensors));

    for (int i = 0; i < 3; i++)
    {
        printf("%c: %d\n",
               sensors[i].id,
               sensors[i].reading);
    }

    return 0;
}


/* =========================================================
   Q7: Union vs Structure
   File: q07_union_vs_structure.c
   ========================================================= */

#include <stdio.h>

struct MyStruct
{
    char a;
    int b;
};

union MyUnion
{
    char a;
    int b;
};

int main(void)
{
    printf("Structure size = %zu\n", sizeof(struct MyStruct));
    printf("Union size = %zu\n", sizeof(union MyUnion));

    return 0;
}


/* =========================================================
   Q8: Inspect Structure Object Representation
   File: q08_structure_padding_bytes.c
   ========================================================= */

#include <stdio.h>

struct Data
{
    char a;
    int b;
};

int main(void)
{
    struct Data d = {1, 100};

    const unsigned char *bytes =
        (const unsigned char *)&d;

    printf("Structure size = %zu bytes\n", sizeof(d));

    for (size_t i = 0; i < sizeof(d); i++)
    {
        printf("Byte %zu = %u\n",
               i, (unsigned int)bytes[i]);
    }

    return 0;
}


/* =========================================================
   Q9: Packed Structure
   File: q09_packed_structure.c
   ========================================================= */

#include <stdio.h>

/* GCC/Clang-specific attribute; not standard C. */
struct __attribute__((packed)) PackedData
{
    char a;
    int b;
};

int main(void)
{
    struct PackedData d = {1, 100};

    printf("Packed structure size = %zu bytes\n",
           sizeof(d));

    printf("a = %d, b = %d\n", d.a, d.b);

    return 0;
}


/* =========================================================
   Q10: Embedded Packet Layout
   File: q10_embedded_packet_layout.c
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

struct SensorPacket
{
    uint8_t sensor_id;
    uint16_t reading;
    uint32_t timestamp;
};

int main(void)
{
    struct SensorPacket packet = {
        1U,
        2500U,
        100000U
    };

    printf("Sensor ID = %u\n",
           (unsigned int)packet.sensor_id);

    printf("Reading = %u\n",
           (unsigned int)packet.reading);

    printf("Timestamp = %lu\n",
           (unsigned long)packet.timestamp);

    printf("Structure size = %zu bytes\n",
           sizeof(packet));

    return 0;
}
