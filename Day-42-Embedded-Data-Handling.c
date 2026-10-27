/* =========================================================
   01_byte_split.c
   Split a 16-bit value into two bytes
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint16_t value = 0x1234;

    uint8_t high = (uint8_t)(value >> 8);
    uint8_t low = (uint8_t)(value & 0xFFU);

    printf("Value = 0x%04X\n", value);
    printf("High byte = 0x%02X\n", high);
    printf("Low byte  = 0x%02X\n", low);

    return 0;
}


/* =========================================================
   02_byte_combine.c
   Combine two bytes into a 16-bit value
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t high = 0x12;
    uint8_t low = 0x34;

    uint16_t value = ((uint16_t)high << 8) | low;

    printf("Combined value = 0x%04X\n", value);

    return 0;
}


/* =========================================================
   03_bit_packing.c
   Pack multiple small fields into one byte
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t mode = 3U;      /* 2 bits  */
    uint8_t enabled = 1U;   /* 1 bit   */
    uint8_t speed = 5U;     /* 3 bits  */

    /*
       Bit layout:
       [speed:3][enabled:1][mode:2]
    */

    uint8_t packet = 0U;

    packet |= (uint8_t)(mode & 0x03U);
    packet |= (uint8_t)((enabled & 0x01U) << 2);
    packet |= (uint8_t)((speed & 0x07U) << 3);

    printf("Packed byte = 0x%02X\n", packet);

    return 0;
}


/* =========================================================
   04_bit_unpacking.c
   Extract fields from packed byte
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t packet = 0x2FU;

    uint8_t mode = packet & 0x03U;
    uint8_t enabled = (packet >> 2) & 0x01U;
    uint8_t speed = (packet >> 3) & 0x07U;

    printf("Packet = 0x%02X\n", packet);
    printf("Mode = %u\n", mode);
    printf("Enabled = %u\n", enabled);
    printf("Speed = %u\n", speed);

    return 0;
}


/* =========================================================
   05_checksum.c
   Simple 8-bit additive checksum
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

uint8_t Calculate_Checksum(const uint8_t data[], uint8_t length)
{
    uint16_t sum = 0U;

    for (uint8_t i = 0U; i < length; i++)
    {
        sum += data[i];
    }

    return (uint8_t)sum;
}

int main(void)
{
    uint8_t data[] = {10U, 20U, 30U, 40U};
    uint8_t length = 4U;

    uint8_t checksum = Calculate_Checksum(data, length);

    printf("Checksum = 0x%02X\n", checksum);

    return 0;
}


/* =========================================================
   06_checksum_verify.c
   Calculate and verify checksum
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

uint8_t Calculate_Checksum(const uint8_t data[], uint8_t length)
{
    uint16_t sum = 0U;

    for (uint8_t i = 0U; i < length; i++)
    {
        sum += data[i];
    }

    return (uint8_t)sum;
}

int main(void)
{
    uint8_t data[] = {10U, 20U, 30U};
    uint8_t received_checksum = 60U;

    uint8_t calculated_checksum =
        Calculate_Checksum(data, 3U);

    if (calculated_checksum == received_checksum)
    {
        printf("Packet VALID\n");
    }
    else
    {
        printf("Packet INVALID\n");
    }

    return 0;
}


/* =========================================================
   07_xor_checksum.c
   XOR checksum
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

uint8_t XOR_Checksum(const uint8_t data[], uint8_t length)
{
    uint8_t result = 0U;

    for (uint8_t i = 0U; i < length; i++)
    {
        result ^= data[i];
    }

    return result;
}

int main(void)
{
    uint8_t data[] = {0x10U, 0x20U, 0x30U, 0x40U};

    uint8_t checksum = XOR_Checksum(data, 4U);

    printf("XOR Checksum = 0x%02X\n", checksum);

    return 0;
}


/* =========================================================
   08_crc8.c
   CRC-8 calculation
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

uint8_t CRC8(const uint8_t data[], uint8_t length)
{
    uint8_t crc = 0U;

    for (uint8_t i = 0U; i < length; i++)
    {
        crc ^= data[i];

        for (uint8_t bit = 0U; bit < 8U; bit++)
        {
            if (crc & 0x80U)
            {
                crc = (uint8_t)((crc << 1) ^ 0x07U);
            }
            else
            {
                crc <<= 1;
            }
        }
    }

    return crc;
}

int main(void)
{
    uint8_t data[] = {0x10U, 0x20U, 0x30U};

    uint8_t crc = CRC8(data, 3U);

    printf("CRC-8 = 0x%02X\n", crc);

    return 0;
}


/* =========================================================
   09_sensor_packet.c
   Create a simple sensor communication packet
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

uint8_t Calculate_Checksum(const uint8_t data[], uint8_t length)
{
    uint16_t sum = 0U;

    for (uint8_t i = 0U; i < length; i++)
    {
        sum += data[i];
    }

    return (uint8_t)sum;
}

int main(void)
{
    /*
       Packet format:

       Byte 0 = Start byte
       Byte 1 = Sensor ID
       Byte 2 = Temperature
       Byte 3 = Status
       Byte 4 = Checksum
    */

    uint8_t packet[5];

    packet[0] = 0xAAU;
    packet[1] = 0x01U;
    packet[2] = 25U;
    packet[3] = 0x01U;

    packet[4] = Calculate_Checksum(packet, 4U);

    printf("Sensor Packet:\n");

    for (uint8_t i = 0U; i < 5U; i++)
    {
        printf("0x%02X ", packet[i]);
    }

    printf("\n");

    return 0;
}


/* =========================================================
   10_embedded_packet_handler.c
   Complete embedded-style packet handling
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

#define PACKET_SIZE 5U
#define START_BYTE  0xAAU

typedef struct
{
    uint8_t sensor_id;
    uint8_t temperature;
    uint8_t status;
} SensorData;


static uint8_t Calculate_Checksum(
    const uint8_t data[],
    uint8_t length)
{
    uint16_t sum = 0U;

    for (uint8_t i = 0U; i < length; i++)
    {
        sum += data[i];
    }

    return (uint8_t)sum;
}


static uint8_t Validate_Packet(
    const uint8_t packet[],
    uint8_t length)
{
    if (length != PACKET_SIZE)
    {
        return 0U;
    }

    if (packet[0] != START_BYTE)
    {
        return 0U;
    }

    uint8_t calculated =
        Calculate_Checksum(packet, PACKET_SIZE - 1U);

    if (calculated != packet[PACKET_SIZE - 1U])
    {
        return 0U;
    }

    return 1U;
}


static void Process_Packet(const uint8_t packet[])
{
    SensorData sensor;

    sensor.sensor_id = packet[1];
    sensor.temperature = packet[2];
    sensor.status = packet[3];

    printf("Sensor ID    : %u\n", sensor.sensor_id);
    printf("Temperature  : %u C\n", sensor.temperature);
    printf("Status       : %u\n", sensor.status);
}


int main(void)
{
    uint8_t packet[PACKET_SIZE];

    packet[0] = 0xAAU;
    packet[1] = 1U;
    packet[2] = 25U;
    packet[3] = 1U;

    packet[4] =
        Calculate_Checksum(packet, PACKET_SIZE - 1U);

    if (Validate_Packet(packet, PACKET_SIZE))
    {
        printf("Packet valid\n");
        Process_Packet(packet);
    }
    else
    {
        printf("Packet invalid\n");
    }

    return 0;
}
