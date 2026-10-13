/* =========================================================
   Q1: Endianness Basics
   File: q01_endianness_basic.c
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint32_t value = 0x12345678U;

    printf("Value = 0x%08X\n", (unsigned int)value);
    printf("Little-endian stores the least significant byte first.\n");
    printf("Big-endian stores the most significant byte first.\n");

    return 0;
}


/* =========================================================
   Q2: Detect Endianness
   File: q02_detect_endianness.c
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint32_t value = 1U;
    const unsigned char *ptr =
        (const unsigned char *)&value;

    if (ptr[0] == 1U)
        printf("Little-endian\n");
    else
        printf("Big-endian\n");

    return 0;
}


/* =========================================================
   Q3: Print Bytes of an Integer
   File: q03_print_bytes.c
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint32_t value = 0x12345678U;
    const unsigned char *ptr =
        (const unsigned char *)&value;

    printf("Memory bytes in address order:\n");

    for (size_t i = 0; i < sizeof(value); i++)
        printf("%02X ", (unsigned int)ptr[i]);

    printf("\n");

    return 0;
}


/* =========================================================
   Q4: Extract Bytes
   File: q04_extract_bytes.c
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint32_t value = 0x12345678U;

    uint8_t byte0 = (uint8_t)(value & 0xFFU);
    uint8_t byte1 = (uint8_t)((value >> 8) & 0xFFU);
    uint8_t byte2 = (uint8_t)((value >> 16) & 0xFFU);
    uint8_t byte3 = (uint8_t)((value >> 24) & 0xFFU);

    printf("Byte 0 = 0x%02X\n", (unsigned int)byte0);
    printf("Byte 1 = 0x%02X\n", (unsigned int)byte1);
    printf("Byte 2 = 0x%02X\n", (unsigned int)byte2);
    printf("Byte 3 = 0x%02X\n", (unsigned int)byte3);

    return 0;
}


/* =========================================================
   Q5: Combine Bytes into a 16-bit Value
   File: q05_combine_bytes.c
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t high = 0x12U;
    uint8_t low = 0x34U;

    uint16_t value =
        (uint16_t)(((uint16_t)high << 8) | low);

    printf("Combined value = 0x%04X\n",
           (unsigned int)value);

    return 0;
}


/* =========================================================
   Q6: Swap Bytes
   File: q06_swap_bytes.c
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint16_t value = 0x1234U;

    uint16_t swapped =
        (uint16_t)((value << 8) | (value >> 8));

    printf("Original = 0x%04X\n", (unsigned int)value);
    printf("Swapped  = 0x%04X\n", (unsigned int)swapped);

    return 0;
}


/* =========================================================
   Q7: Big-endian / Network Byte Order
   File: q07_network_byte_order.c
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint32_t value = 0x12345678U;

    uint8_t bytes[4];

    bytes[0] = (uint8_t)(value >> 24);
    bytes[1] = (uint8_t)(value >> 16);
    bytes[2] = (uint8_t)(value >> 8);
    bytes[3] = (uint8_t)value;

    printf("Big-endian byte sequence:\n");

    for (int i = 0; i < 4; i++)
        printf("%02X ", (unsigned int)bytes[i]);

    printf("\n");

    return 0;
}


/* =========================================================
   Q8: Float Memory Representation
   File: q08_float_memory.c
   ========================================================= */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(void)
{
    float value = 1.0f;
    unsigned char bytes[sizeof(value)];

    memcpy(bytes, &value, sizeof(value));

    printf("Float size = %zu bytes\n", sizeof(value));
    printf("Object representation:\n");

    for (size_t i = 0; i < sizeof(value); i++)
        printf("%02X ", (unsigned int)bytes[i]);

    printf("\n");

    return 0;
}


/* =========================================================
   Q9: Union and Endianness
   File: q09_union_endianness.c
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

union Data
{
    uint32_t value;
    uint8_t bytes[4];
};

int main(void)
{
    union Data data = {0};

    data.value = 0x12345678U;

    printf("Value = 0x%08X\n",
           (unsigned int)data.value);

    printf("Bytes in address order:\n");

    for (int i = 0; i < 4; i++)
        printf("%02X ", (unsigned int)data.bytes[i]);

    printf("\n");

    return 0;
}


/* =========================================================
   Q10: Embedded Packet Serialization
   File: q10_embedded_packet.c
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t sensor_id = 0x01U;
    uint16_t reading = 0x1234U;
    uint32_t timestamp = 0x01020304U;

    uint8_t packet[7];

    /* Serialize into big-endian byte order. */
    packet[0] = sensor_id;
    packet[1] = (uint8_t)(reading >> 8);
    packet[2] = (uint8_t)reading;
    packet[3] = (uint8_t)(timestamp >> 24);
    packet[4] = (uint8_t)(timestamp >> 16);
    packet[5] = (uint8_t)(timestamp >> 8);
    packet[6] = (uint8_t)timestamp;

    printf("Transmitted packet:\n");

    for (int i = 0; i < 7; i++)
        printf("%02X ", (unsigned int)packet[i]);

    printf("\n");

    /* Deserialize the reading field. */
    uint16_t received_reading =
        (uint16_t)(((uint16_t)packet[1] << 8) |
                   (uint16_t)packet[2]);

    printf("Received reading = 0x%04X\n",
           (unsigned int)received_reading);

    return 0;
}
