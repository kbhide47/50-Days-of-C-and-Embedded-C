/* =========================================================
   01_basic_interrupt_concept.c
   Simulating an interrupt event
   ========================================================= */

#include <stdio.h>

void ISR_ButtonPressed(void)
{
    printf("Button interrupt occurred!\n");
}

int main(void)
{
    printf("Main program running\n");

    /* Simulate an interrupt */
    ISR_ButtonPressed();

    printf("Main program continues\n");

    return 0;
}


/* =========================================================
   02_polling_vs_interrupt.c
   Compare polling with event-driven handling
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int button_pressed = 1;

    /* Polling: repeatedly check a condition */
    if (button_pressed)
    {
        printf("Polling detected button press\n");
    }

    /* Simulation of interrupt-driven notification */
    int interrupt_flag = 1;

    if (interrupt_flag)
    {
        printf("Interrupt event handled\n");
        interrupt_flag = 0;
    }

    return 0;
}


/* =========================================================
   03_interrupt_flag.c
   Simulate setting and clearing an event flag
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int event_flag = 0;

    /* Simulate ISR setting a flag */
    event_flag = 1;

    /* Main loop handles the event */
    if (event_flag)
    {
        printf("Event processed\n");
        event_flag = 0;
    }

    printf("Flag = %d\n", event_flag);

    return 0;
}


/* =========================================================
   04_isr_counter.c
   Simulate counting interrupt events
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

static uint32_t event_count = 0U;

static void Simulated_ISR(void)
{
    event_count++;
}

int main(void)
{
    for (int i = 0; i < 5; i++)
    {
        Simulated_ISR();
    }

    printf("Interrupt events = %u\n",
           (unsigned)event_count);

    return 0;
}


/* =========================================================
   05_button_interrupt.c
   Simulate a button interrupt
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

static volatile uint8_t button_event = 0U;

/* In real firmware, the MCU invokes this ISR */
static void Button_ISR(void)
{
    button_event = 1U;
}

int main(void)
{
    /* Simulate hardware interrupt */
    Button_ISR();

    /* Main loop handles the event */
    if (button_event != 0U)
    {
        printf("Toggle LED\n");
        button_event = 0U;
    }

    return 0;
}


/* =========================================================
   06_timer_interrupt.c
   Simulate timer interrupt ticks
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

static volatile uint32_t system_ticks = 0U;

/* Simulated timer ISR */
static void Timer_ISR(void)
{
    system_ticks++;
}

int main(void)
{
    /* Simulate 10 timer interrupts */
    for (int i = 0; i < 10; i++)
    {
        Timer_ISR();
    }

    printf("Timer ticks = %u\n",
           (unsigned)system_ticks);

    return 0;
}


/* =========================================================
   07_uart_interrupt.c
   Simulate UART receive interrupt
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

static volatile uint8_t received_byte = 0U;
static volatile uint8_t data_ready = 0U;

/* Simulates a UART ISR receiving one byte */
static void UART_RX_ISR(uint8_t byte)
{
    received_byte = byte;
    data_ready = 1U;
}

int main(void)
{
    /* Simulate receiving 'A' */
    UART_RX_ISR((uint8_t)'A');

    if (data_ready != 0U)
    {
        printf("Received byte: %c\n", received_byte);
        data_ready = 0U;
    }

    return 0;
}


/* =========================================================
   08_isr_ring_buffer.c
   Simulate ISR-to-main ring buffer communication
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

#define SIZE 8U

static uint8_t buffer[SIZE];
static uint8_t head = 0U;
static uint8_t tail = 0U;

/*
   Single-producer/single-consumer demonstration.
   Assumes suitable atomic index accesses and target-specific
   synchronization. Not a universal ISR-safe implementation.
*/

static uint8_t Buffer_Push_From_ISR(uint8_t data)
{
    uint8_t next = (uint8_t)((head + 1U) % SIZE);

    if (next == tail)
    {
        return 0U; /* Full */
    }

    buffer[head] = data;
    head = next;

    return 1U;
}

static uint8_t Buffer_Pop(uint8_t *data)
{
    if (tail == head)
    {
        return 0U; /* Empty */
    }

    *data = buffer[tail];
    tail = (uint8_t)((tail + 1U) % SIZE);

    return 1U;
}

int main(void)
{
    uint8_t data;

    /* Simulate ISR receiving bytes */
    Buffer_Push_From_ISR((uint8_t)'H');
    Buffer_Push_From_ISR((uint8_t)'i');

    printf("Main loop received: ");

    while (Buffer_Pop(&data))
    {
        printf("%c", data);
    }

    printf("\n");

    return 0;
}


/* =========================================================
   09_interrupt_enable_disable.c
   Demonstrate a critical-section concept
   ========================================================= */

#include <stdio.h>

static int shared_data = 0;

static void Update_Shared_Data(void)
{
    /*
       On a real MCU, protect shared data using the
       platform's interrupt/critical-section API when needed.
       This function is only a desktop simulation.
    */

    shared_data++;
}

int main(void)
{
    Update_Shared_Data();

    printf("Shared data = %d\n", shared_data);

    return 0;
}


/* =========================================================
   10_embedded_interrupt_handler.c
   Event flag + main-loop processing
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

static volatile uint8_t sensor_event = 0U;
static uint32_t processed_events = 0U;

/* Hardware would invoke this ISR */
static void Sensor_ISR(void)
{
    sensor_event = 1U;
}

static void Process_Sensor_Event(void)
{
    processed_events++;
    printf("Processing sensor event %u\n",
           (unsigned)processed_events);
}

int main(void)
{
    /* Simulate a sensor interrupt */
    Sensor_ISR();

    /* Main-loop event handling */
    if (sensor_event != 0U)
    {
        sensor_event = 0U;
        Process_Sensor_Event();
    }

    return 0;
}
