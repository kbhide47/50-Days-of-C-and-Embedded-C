/* =========================================================
   DAY 25 — STRUCTURES, UNIONS, TYPEDEF & BIT-FIELDS
   ========================================================= */


/* =========================================================
   Q1. Basic structure
   File: q01_basic_structure.c
   ========================================================= */

#include <stdio.h>

struct Student
{
    int roll_no;
    float marks;
    char grade;
};

int main(void)
{
    struct Student student;

    student.roll_no = 101;
    student.marks = 85.5f;
    student.grade = 'A';

    printf("Roll No = %d\n", student.roll_no);
    printf("Marks   = %.2f\n", student.marks);
    printf("Grade   = %c\n", student.grade);

    return 0;
}


/* =========================================================
   Q2. Array of structures
   File: q02_structure_array.c
   ========================================================= */

#include <stdio.h>

struct Sensor
{
    int id;
    float temperature;
};

int main(void)
{
    struct Sensor sensors[3] =
    {
        {1, 25.5f},
        {2, 28.2f},
        {3, 30.1f}
    };

    for (int i = 0; i < 3; i++)
    {
        printf("Sensor %d: %.2f C\n",
               sensors[i].id,
               sensors[i].temperature);
    }

    return 0;
}


/* =========================================================
   Q3. Pointer to structure
   File: q03_structure_pointer.c
   ========================================================= */

#include <stdio.h>

struct Device
{
    int id;
    int status;
};

int main(void)
{
    struct Device device = {10, 1};

    struct Device *ptr = &device;

    printf("ID = %d\n", ptr->id);
    printf("Status = %d\n", ptr->status);

    ptr->status = 0;

    printf("Updated Status = %d\n",
           ptr->status);

    return 0;
}


/* =========================================================
   Q4. Nested structure
   File: q04_nested_structure.c
   ========================================================= */

#include <stdio.h>

struct Location
{
    int x;
    int y;
};

struct Device
{
    int id;
    struct Location position;
};

int main(void)
{
    struct Device device =
    {
        101,
        {20, 30}
    };

    printf("Device ID = %d\n", device.id);
    printf("X = %d\n", device.position.x);
    printf("Y = %d\n", device.position.y);

    return 0;
}


/* =========================================================
   Q5. Pass structure to function
   File: q05_structure_function.c
   ========================================================= */

#include <stdio.h>

struct Sensor
{
    int id;
    float temperature;
};

void display_sensor(struct Sensor sensor)
{
    printf("ID = %d\n", sensor.id);
    printf("Temperature = %.2f\n",
           sensor.temperature);
}

int main(void)
{
    struct Sensor sensor = {101, 27.5f};

    display_sensor(sensor);

    return 0;
}


/* =========================================================
   Q6. typedef with structure
   File: q06_typedef_structure.c
   ========================================================= */

#include <stdio.h>

typedef struct
{
    int id;
    float voltage;
} Sensor;

int main(void)
{
    Sensor sensor;

    sensor.id = 10;
    sensor.voltage = 3.3f;

    printf("Sensor ID = %d\n", sensor.id);
    printf("Voltage = %.2f V\n",
           sensor.voltage);

    return 0;
}


/* =========================================================
   Q7. Basic union
   File: q07_basic_union.c
   ========================================================= */

#include <stdio.h>

union Data
{
    int integer;
    float decimal;
    char character;
};

int main(void)
{
    union Data data;

    data.integer = 100;

    printf("Integer = %d\n",
           data.integer);

    data.decimal = 25.5f;

    printf("Float = %.2f\n",
           data.decimal);

    return 0;
}


/* =========================================================
   Q8. Demonstrate shared union memory
   File: q08_union_memory.c
   ========================================================= */

#include <stdio.h>

union Data
{
    int integer;
    float decimal;
    char character;
};

int main(void)
{
    union Data data;

    printf("Size of union = %zu bytes\n",
           sizeof(data));

    printf("Address of integer   = %p\n",
           (void *)&data.integer);

    printf("Address of decimal   = %p\n",
           (void *)&data.decimal);

    printf("Address of character = %p\n",
           (void *)&data.character);

    return 0;
}


/* =========================================================
   Q9. Structure bit-fields
   File: q09_structure_bitfield.c
   ========================================================= */

#include <stdio.h>

struct Status
{
    unsigned int ready : 1;
    unsigned int error : 1;
    unsigned int enable : 1;
    unsigned int reserved : 5;
};

int main(void)
{
    struct Status status = {0};

    status.ready = 1;
    status.enable = 1;

    printf("Ready  = %u\n",
           status.ready);

    printf("Error  = %u\n",
           status.error);

    printf("Enable = %u\n",
           status.enable);

    return 0;
}


/* =========================================================
   Q10. Embedded-style register structure
   File: q10_embedded_register_structure.c
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

typedef struct
{
    uint8_t control;
    uint8_t status;
    uint16_t data;
} DeviceRegisters;

int main(void)
{
    DeviceRegisters device = {0};

    /* Set enable bit */
    device.control |= (1U << 0);

    /* Set ready bit */
    device.status |= (1U << 1);

    device.data = 0x1234;

    printf("CONTROL = 0x%02X\n",
           device.control);

    printf("STATUS  = 0x%02X\n",
           device.status);

    printf("DATA    = 0x%04X\n",
           device.data);

    return 0;
}
