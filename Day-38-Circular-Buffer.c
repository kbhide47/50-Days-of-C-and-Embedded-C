/* =========================================================
   01_basic_circular_buffer.c
   Basic circular buffer
   ========================================================= */

#include <stdio.h>

#define SIZE 5

int main(void)
{
    int buffer[SIZE];

    int write_index = 0;

    for (int i = 0; i < 8; i++)
    {
        buffer[write_index] = i * 10;

        printf("Writing %d at index %d\n",
               buffer[write_index],
               write_index);

        write_index = (write_index + 1) % SIZE;
    }

    return 0;
}


/* =========================================================
   02_enqueue_dequeue.c
   Insert and remove data
   ========================================================= */

#include <stdio.h>

#define SIZE 5

int main(void)
{
    int buffer[SIZE];

    int head = 0;
    int tail = 0;
    int count = 0;

    /* Enqueue */
    buffer[head] = 10;
    head = (head + 1) % SIZE;
    count++;

    buffer[head] = 20;
    head = (head + 1) % SIZE;
    count++;

    printf("Elements = %d\n", count);

    /* Dequeue */
    printf("Removed = %d\n", buffer[tail]);

    tail = (tail + 1) % SIZE;
    count--;

    printf("Elements after dequeue = %d\n", count);

    return 0;
}


/* =========================================================
   03_buffer_full.c
   Detect full buffer
   ========================================================= */

#include <stdio.h>

#define SIZE 4

int main(void)
{
    int buffer[SIZE];

    int head = 0;
    int tail = 0;
    int count = 0;

    for (int i = 1; i <= SIZE; i++)
    {
        if (count == SIZE)
        {
            printf("Buffer FULL\n");
            break;
        }

        buffer[head] = i * 10;

        head = (head + 1) % SIZE;
        count++;

        printf("Inserted %d\n", i * 10);
    }

    if (count == SIZE)
    {
        printf("Buffer is FULL\n");
    }

    return 0;
}


/* =========================================================
   04_buffer_empty.c
   Detect empty buffer
   ========================================================= */

#include <stdio.h>

#define SIZE 5

int main(void)
{
    int buffer[SIZE];

    int head = 0;
    int tail = 0;
    int count = 0;

    (void)buffer;
    (void)head;
    (void)tail;

    if (count == 0)
    {
        printf("Buffer is EMPTY\n");
    }

    return 0;
}


/* =========================================================
   05_wrap_around.c
   Circular wrap-around
   ========================================================= */

#include <stdio.h>

#define SIZE 5

int main(void)
{
    int index = 0;

    for (int i = 0; i < 12; i++)
    {
        printf("Index = %d\n", index);

        index = (index + 1) % SIZE;
    }

    return 0;
}


/* =========================================================
   06_circular_buffer_string.c
   Circular character buffer
   ========================================================= */

#include <stdio.h>

#define SIZE 8

int main(void)
{
    char buffer[SIZE];

    int head = 0;
    int tail = 0;
    int count = 0;

    char data[] = "HELLO";

    for (int i = 0; data[i] != '\0'; i++)
    {
        if (count == SIZE)
        {
            printf("Buffer full\n");
            break;
        }

        buffer[head] = data[i];

        head = (head + 1) % SIZE;
        count++;
    }

    printf("Buffer data: ");

    while (count > 0)
    {
        printf("%c", buffer[tail]);

        tail = (tail + 1) % SIZE;
        count--;
    }

    printf("\n");

    return 0;
}


/* =========================================================
   07_uart_ring_buffer.c
   UART-style circular buffer
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

#define UART_BUFFER_SIZE 8

typedef struct
{
    uint8_t buffer[UART_BUFFER_SIZE];

    uint8_t head;
    uint8_t tail;
    uint8_t count;

} RingBuffer;

void init_buffer(RingBuffer *rb)
{
    rb->head = 0;
    rb->tail = 0;
    rb->count = 0;
}

int enqueue(RingBuffer *rb, uint8_t data)
{
    if (rb->count == UART_BUFFER_SIZE)
    {
        return 0;
    }

    rb->buffer[rb->head] = data;

    rb->head = (rb->head + 1) % UART_BUFFER_SIZE;

    rb->count++;

    return 1;
}

int dequeue(RingBuffer *rb, uint8_t *data)
{
    if (rb->count == 0)
    {
        return 0;
    }

    *data = rb->buffer[rb->tail];

    rb->tail = (rb->tail + 1) % UART_BUFFER_SIZE;

    rb->count--;

    return 1;
}

int main(void)
{
    RingBuffer uart;

    uint8_t data;

    init_buffer(&uart);

    enqueue(&uart, 'A');
    enqueue(&uart, 'B');
    enqueue(&uart, 'C');

    while (dequeue(&uart, &data))
    {
        printf("Received: %c\n", data);
    }

    return 0;
}


/* =========================================================
   08_buffer_count.c
   Track number of elements
   ========================================================= */

#include <stdio.h>

#define SIZE 5

int main(void)
{
    int buffer[SIZE];

    int head = 0;
    int tail = 0;
    int count = 0;

    /* Add three elements */
    for (int i = 1; i <= 3; i++)
    {
        buffer[head] = i * 100;

        head = (head + 1) % SIZE;
        count++;
    }

    printf("Number of elements = %d\n", count);

    /* Remove one */
    printf("Removed = %d\n", buffer[tail]);

    tail = (tail + 1) % SIZE;
    count--;

    printf("Number of elements = %d\n", count);

    return 0;
}


/* =========================================================
   09_buffer_overwrite.c
   Overwrite oldest data when full
   ========================================================= */

#include <stdio.h>

#define SIZE 4

int main(void)
{
    int buffer[SIZE];

    int head = 0;
    int tail = 0;
    int count = 0;

    for (int i = 1; i <= 6; i++)
    {
        buffer[head] = i * 10;

        head = (head + 1) % SIZE;

        if (count < SIZE)
        {
            count++;
        }
        else
        {
            /* Oldest data is overwritten */
            tail = (tail + 1) % SIZE;
        }
    }

    printf("Remaining data:\n");

    while (count > 0)
    {
        printf("%d ", buffer[tail]);

        tail = (tail + 1) % SIZE;
        count--;
    }

    printf("\n");

    return 0;
}


/* =========================================================
   10_embedded_ring_buffer.c
   Complete embedded-style ring buffer
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

#define BUFFER_SIZE 8

typedef struct
{
    uint8_t data[BUFFER_SIZE];

    uint8_t head;
    uint8_t tail;
    uint8_t count;

} RingBuffer;

void RingBuffer_Init(RingBuffer *rb)
{
    rb->head = 0;
    rb->tail = 0;
    rb->count = 0;
}

int RingBuffer_IsEmpty(const RingBuffer *rb)
{
    return rb->count == 0;
}

int RingBuffer_IsFull(const RingBuffer *rb)
{
    return rb->count == BUFFER_SIZE;
}

int RingBuffer_Put(RingBuffer *rb, uint8_t data)
{
    if (RingBuffer_IsFull(rb))
    {
        return 0;
    }

    rb->data[rb->head] = data;

    rb->head = (rb->head + 1) % BUFFER_SIZE;

    rb->count++;

    return 1;
}

int RingBuffer_Get(RingBuffer *rb, uint8_t *data)
{
    if (RingBuffer_IsEmpty(rb))
    {
        return 0;
    }

    *data = rb->data[rb->tail];

    rb->tail = (rb->tail + 1) % BUFFER_SIZE;

    rb->count--;

    return 1;
}

int main(void)
{
    RingBuffer rb;

    uint8_t value;

    RingBuffer_Init(&rb);

    RingBuffer_Put(&rb, 10);
    RingBuffer_Put(&rb, 20);
    RingBuffer_Put(&rb, 30);
    RingBuffer_Put(&rb, 40);

    printf("Reading buffer:\n");

    while (RingBuffer_Get(&rb, &value))
    {
        printf("%u\n", value);
    }

    return 0;
}
