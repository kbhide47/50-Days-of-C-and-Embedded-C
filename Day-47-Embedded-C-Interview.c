Q1
#include <stdio.h>

volatile int flag = 0;

int main(void)
{
    flag = 1;

    printf("Flag = %d\n", flag);

    return 0;
}

Q2 
#include <stdio.h>

const volatile int status_register = 5;

int main(void)
{
    printf("Status = %d\n", status_register);

    return 0;
}
Q3
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint32_t simulated_register = 0x12345678;

    printf("Register = 0x%08X\n",
           (unsigned int)simulated_register);

    return 0;
}

Q4
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint32_t reg = 0x00;
    uint32_t bit = 3;

    reg |= (1U << bit);

    printf("Register = 0x%X\n",
           (unsigned int)reg);

    return 0;
}
Q5
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint32_t reg = 0xFF;
    uint32_t bit = 3;

    reg &= ~(1U << bit);

    printf("Register = 0x%X\n",
           (unsigned int)reg);

    return 0;
}
Q6
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint32_t reg = 0x08;
    uint32_t bit = 3;

    reg ^= (1U << bit);

    printf("Register = 0x%X\n",
           (unsigned int)reg);

    return 0;
}
Q7
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint32_t reg = 0x08;
    uint32_t bit = 3;

    if (reg & (1U << bit))
    {
        printf("Bit is SET\n");
    }
    else
    {
        printf("Bit is CLEAR\n");
    }

    return 0;
}

Q8
#include <stdio.h>

volatile int interrupt_flag = 0;

/* Simulated Interrupt Service Routine (ISR) */
void timer_ISR(void)
{
    interrupt_flag = 1;
}

int main(void)
{
    timer_ISR();

    if (interrupt_flag == 1)
    {
        printf("Timer interrupt occurred\n");
        interrupt_flag = 0;
    }

    return 0;
}
Q9
#include <stdio.h>

typedef enum
{
    IDLE,
    RUNNING,
    STOPPED
} State;

int main(void)
{
    State current_state = IDLE;

    switch (current_state)
    {
        case IDLE:
            printf("System is IDLE\n");
            current_state = RUNNING;
            break;

        case RUNNING:
            printf("System is RUNNING\n");
            break;

        case STOPPED:
            printf("System is STOPPED\n");
            break;
    }

    printf("Next state = %d\n", current_state);

    return 0;
}
Q10
#include <stdio.h>

int shared_counter = 0;

int main(void)
{
    /* Simulated critical section */
    shared_counter++;

    printf("Counter = %d\n", shared_counter);

    return 0;
}
