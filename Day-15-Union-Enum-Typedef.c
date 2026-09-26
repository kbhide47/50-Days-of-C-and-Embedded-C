/* =========================================================
   Q1: q01_basic_union.c
   Basic union
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

    printf("Integer = %d\n", data.integer);

    data.decimal = 25.5f;

    printf("Decimal = %.2f\n", data.decimal);

    data.character = 'A';

    printf("Character = %c\n", data.character);

    return 0;
}


/* =========================================================
   Q2: q02_union_memory.c
   Understand shared memory
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

    printf("Size of union = %zu bytes\n", sizeof(data));
    printf("Size of int = %zu bytes\n", sizeof(data.integer));
    printf("Size of float = %zu bytes\n", sizeof(data.decimal));
    printf("Size of char = %zu bytes\n", sizeof(data.character));

    return 0;
}


/* =========================================================
   Q3: q03_union_update.c
   Modify union members
   ========================================================= */

#include <stdio.h>

union Value
{
    int number;
    float voltage;
};

int main(void)
{
    union Value value;

    value.number = 50;
    printf("Number = %d\n", value.number);

    value.voltage = 3.3f;
    printf("Voltage = %.2f V\n", value.voltage);

    return 0;
}


/* =========================================================
   Q4: q04_union_vs_structure.c
   Structure vs union memory
   ========================================================= */

#include <stdio.h>

struct StructureData
{
    int a;
    float b;
    char c;
};

union UnionData
{
    int a;
    float b;
    char c;
};

int main(void)
{
    struct StructureData s;
    union UnionData u;

    printf("Structure size = %zu bytes\n", sizeof(s));
    printf("Union size     = %zu bytes\n", sizeof(u));

    return 0;
}


/* =========================================================
   Q5: q05_basic_enum.c
   Basic enum
   ========================================================= */

#include <stdio.h>

enum Day
{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY
};

int main(void)
{
    enum Day today = WEDNESDAY;

    printf("Day value = %d\n", today);

    return 0;
}


/* =========================================================
   Q6: q06_enum_status.c
   Device status using enum
   ========================================================= */

#include <stdio.h>

enum DeviceStatus
{
    DEVICE_OFF,
    DEVICE_ON,
    DEVICE_ERROR
};

int main(void)
{
    enum DeviceStatus status = DEVICE_ON;

    if (status == DEVICE_ON)
        printf("Device is ON\n");
    else if (status == DEVICE_OFF)
        printf("Device is OFF\n");
    else
        printf("Device ERROR\n");

    return 0;
}


/* =========================================================
   Q7: q07_enum_switch.c
   Enum with switch
   ========================================================= */

#include <stdio.h>

enum SystemState
{
    INIT,
    RUNNING,
    STOPPED,
    ERROR_STATE
};

int main(void)
{
    enum SystemState state = RUNNING;

    switch (state)
    {
        case INIT:
            printf("System initializing\n");
            break;

        case RUNNING:
            printf("System running\n");
            break;

        case STOPPED:
            printf("System stopped\n");
            break;

        case ERROR_STATE:
            printf("System error\n");
            break;

        default:
            printf("Unknown state\n");
    }

    return 0;
}


/* =========================================================
   Q8: q08_basic_typedef.c
   Basic typedef
   ========================================================= */

#include <stdio.h>

typedef unsigned int uint;

int main(void)
{
    uint number = 100;

    printf("Number = %u\n", number);

    return 0;
}


/* =========================================================
   Q9: q09_typedef_structure.c
   typedef with structure
   ========================================================= */

#include <stdio.h>

typedef struct
{
    int id;
    float temperature;
} Sensor;

int main(void)
{
    Sensor sensor;

    sensor.id = 101;
    sensor.temperature = 28.5f;

    printf("Sensor ID = %d\n", sensor.id);
    printf("Temperature = %.2f C\n", sensor.temperature);

    return 0;
}


/* =========================================================
   Q10: q10_embedded_device_config.c
   Embedded-style union + enum + typedef
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

typedef enum
{
    MODE_IDLE,
    MODE_RUN,
    MODE_ERROR
} DeviceMode;

typedef union
{
    uint32_t raw_value;
    float voltage;
} SensorValue;

typedef struct
{
    DeviceMode mode;
    SensorValue value;
} Device;

int main(void)
{
    Device device;

    device.mode = MODE_RUN;
    device.value.voltage = 3.3f;

    printf("Device mode = %d\n", device.mode);
    printf("Sensor voltage = %.2f V\n",
           device.value.voltage);

    return 0;
}
