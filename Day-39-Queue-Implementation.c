/* =========================================================
   01_basic_queue.c
   Basic FIFO Queue
   ========================================================= */

#include <stdio.h>

#define SIZE 5

int main(void)
{
    int queue[SIZE] = {10, 20, 30};
    int front = 0;
    int rear = 2;

    printf("Queue: ");

    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    printf("\n");

    return 0;
}


/* =========================================================
   02_enqueue.c
   Adding an element to Queue
   ========================================================= */

#include <stdio.h>

#define SIZE 5

int main(void)
{
    int queue[SIZE];
    int front = 0;
    int rear = -1;
    int data = 10;

    if (rear == SIZE - 1)
    {
        printf("Queue Full\n");
    }
    else
    {
        rear++;
        queue[rear] = data;

        printf("Inserted: %d\n", queue[rear]);
    }

    return 0;
}


/* =========================================================
   03_dequeue.c
   Removing an element from Queue
   ========================================================= */

#include <stdio.h>

#define SIZE 5

int main(void)
{
    int queue[SIZE] = {10, 20, 30};
    int front = 0;
    int rear = 2;

    if (front > rear)
    {
        printf("Queue Empty\n");
    }
    else
    {
        printf("Removed: %d\n", queue[front]);
        front++;
    }

    return 0;
}


/* =========================================================
   04_queue_full.c
   Checking Queue Full condition
   ========================================================= */

#include <stdio.h>

#define SIZE 5

int main(void)
{
    int queue[SIZE];
    int front = 0;
    int rear = SIZE - 1;

    if (rear == SIZE - 1)
    {
        printf("Queue is FULL\n");
    }
    else
    {
        printf("Space available\n");
    }

    return 0;
}


/* =========================================================
   05_queue_empty.c
   Checking Queue Empty condition
   ========================================================= */

#include <stdio.h>

#define SIZE 5

int main(void)
{
    int queue[SIZE];
    int front = 0;
    int rear = -1;

    (void)queue;

    if (front > rear)
    {
        printf("Queue is EMPTY\n");
    }
    else
    {
        printf("Queue contains data\n");
    }

    return 0;
}


/* =========================================================
   06_queue_peek.c
   Peek = read front element without removing it
   ========================================================= */

#include <stdio.h>

#define SIZE 5

int main(void)
{
    int queue[SIZE] = {100, 200, 300};
    int front = 0;
    int rear = 2;

    if (front > rear)
    {
        printf("Queue Empty\n");
    }
    else
    {
        printf("Front element: %d\n", queue[front]);
    }

    return 0;
}


/* =========================================================
   07_queue_display.c
   Display all Queue elements
   ========================================================= */

#include <stdio.h>

#define SIZE 5

int main(void)
{
    int queue[SIZE] = {10, 20, 30, 40};
    int front = 0;
    int rear = 3;

    if (front > rear)
    {
        printf("Queue Empty\n");
    }
    else
    {
        printf("Queue: ");

        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }

        printf("\n");
    }

    return 0;
}


/* =========================================================
   08_circular_queue.c
   Circular Queue
   ========================================================= */

#include <stdio.h>

#define SIZE 5

int main(void)
{
    int queue[SIZE];
    int front = 0;
    int rear = 0;
    int count = 0;

    /* Enqueue */
    queue[rear] = 10;
    rear = (rear + 1) % SIZE;
    count++;

    queue[rear] = 20;
    rear = (rear + 1) % SIZE;
    count++;

    queue[rear] = 30;
    rear = (rear + 1) % SIZE;
    count++;

    printf("Queue: ");

    for (int i = 0; i < count; i++)
    {
        int index = (front + i) % SIZE;
        printf("%d ", queue[index]);
    }

    printf("\n");

    /* Dequeue */
    printf("Removed: %d\n", queue[front]);

    front = (front + 1) % SIZE;
    count--;

    printf("After Dequeue: ");

    for (int i = 0; i < count; i++)
    {
        int index = (front + i) % SIZE;
        printf("%d ", queue[index]);
    }

    printf("\n");

    return 0;
}


/* =========================================================
   09_uart_queue.c
   UART-style receive queue
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

#define SIZE 8

typedef struct
{
    uint8_t buffer[SIZE];
    uint8_t front;
    uint8_t rear;
    uint8_t count;
} Queue;

void Queue_Init(Queue *q)
{
    q->front = 0;
    q->rear = 0;
    q->count = 0;
}

int Queue_Enqueue(Queue *q, uint8_t data)
{
    if (q->count == SIZE)
    {
        return 0;
    }

    q->buffer[q->rear] = data;
    q->rear = (q->rear + 1U) % SIZE;
    q->count++;

    return 1;
}

int Queue_Dequeue(Queue *q, uint8_t *data)
{
    if (q->count == 0)
    {
        return 0;
    }

    *data = q->buffer[q->front];
    q->front = (q->front + 1U) % SIZE;
    q->count--;

    return 1;
}

int main(void)
{
    Queue rxQueue;
    uint8_t data;

    Queue_Init(&rxQueue);

    /* Simulating UART received bytes */
    Queue_Enqueue(&rxQueue, 'H');
    Queue_Enqueue(&rxQueue, 'i');
    Queue_Enqueue(&rxQueue, '!');

    printf("Received: ");

    while (Queue_Dequeue(&rxQueue, &data))
    {
        printf("%c", data);
    }

    printf("\n");

    return 0;
}


/* =========================================================
   10_embedded_queue_driver.c
   Complete Embedded C style Queue Driver
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

#define QUEUE_SIZE 10U

typedef struct
{
    uint8_t data[QUEUE_SIZE];
    uint8_t head;
    uint8_t tail;
    uint8_t count;
} Queue;

static Queue rx_queue;

void Queue_Init(void)
{
    rx_queue.head = 0U;
    rx_queue.tail = 0U;
    rx_queue.count = 0U;
}

uint8_t Queue_IsEmpty(void)
{
    return (rx_queue.count == 0U);
}

uint8_t Queue_IsFull(void)
{
    return (rx_queue.count == QUEUE_SIZE);
}

uint8_t Queue_Push(uint8_t data)
{
    if (Queue_IsFull())
    {
        return 0U;
    }

    rx_queue.data[rx_queue.head] = data;
    rx_queue.head = (rx_queue.head + 1U) % QUEUE_SIZE;
    rx_queue.count++;

    return 1U;
}

uint8_t Queue_Pop(uint8_t *data)
{
    if (Queue_IsEmpty())
    {
        return 0U;
    }

    *data = rx_queue.data[rx_queue.tail];
    rx_queue.tail = (rx_queue.tail + 1U) % QUEUE_SIZE;
    rx_queue.count--;

    return 1U;
}

int main(void)
{
    uint8_t data;

    Queue_Init();

    Queue_Push(10U);
    Queue_Push(20U);
    Queue_Push(30U);

    printf("Queue data:\n");

    while (Queue_Pop(&data))
    {
        printf("%u\n", (unsigned)data);
    }

    return 0;
}
