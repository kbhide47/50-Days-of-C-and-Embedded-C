/* =========================================================
   01_basic_fsm.c
   Basic Finite State Machine
   ========================================================= */

#include <stdio.h>

typedef enum
{
    STATE_OFF,
    STATE_ON
} State;

int main(void)
{
    State state = STATE_OFF;

    printf("Initial state: OFF\n");

    state = STATE_ON;

    if (state == STATE_ON)
    {
        printf("Current state: ON\n");
    }

    state = STATE_OFF;

    if (state == STATE_OFF)
    {
        printf("Current state: OFF\n");
    }

    return 0;
}


/* =========================================================
   02_traffic_light_fsm.c
   Traffic light FSM
   ========================================================= */

#include <stdio.h>

typedef enum
{
    RED,
    GREEN,
    YELLOW
} TrafficState;

int main(void)
{
    TrafficState state = RED;

    for (int i = 0; i < 6; i++)
    {
        switch (state)
        {
            case RED:
                printf("RED -> Stop\n");
                state = GREEN;
                break;

            case GREEN:
                printf("GREEN -> Go\n");
                state = YELLOW;
                break;

            case YELLOW:
                printf("YELLOW -> Wait\n");
                state = RED;
                break;
        }
    }

    return 0;
}


/* =========================================================
   03_button_fsm.c
   Button state machine
   ========================================================= */

#include <stdio.h>

typedef enum
{
    BUTTON_RELEASED,
    BUTTON_PRESSED
} ButtonState;

int main(void)
{
    ButtonState state = BUTTON_RELEASED;

    int button_input[] = {0, 0, 1, 1, 1, 0, 0};

    int size = sizeof(button_input) / sizeof(button_input[0]);

    for (int i = 0; i < size; i++)
    {
        if (button_input[i] == 1)
        {
            state = BUTTON_PRESSED;
        }
        else
        {
            state = BUTTON_RELEASED;
        }

        if (state == BUTTON_PRESSED)
        {
            printf("Button PRESSED\n");
        }
        else
        {
            printf("Button RELEASED\n");
        }
    }

    return 0;
}


/* =========================================================
   04_led_fsm.c
   LED state machine
   ========================================================= */

#include <stdio.h>

typedef enum
{
    LED_OFF,
    LED_ON
} LEDState;

void process_led(LEDState *state)
{
    if (*state == LED_OFF)
    {
        *state = LED_ON;
    }
    else
    {
        *state = LED_OFF;
    }
}

int main(void)
{
    LEDState led = LED_OFF;

    for (int i = 0; i < 5; i++)
    {
        process_led(&led);

        if (led == LED_ON)
        {
            printf("LED ON\n");
        }
        else
        {
            printf("LED OFF\n");
        }
    }

    return 0;
}


/* =========================================================
   05_state_transition.c
   State transition
   ========================================================= */

#include <stdio.h>

typedef enum
{
    IDLE,
    RUNNING,
    ERROR_STATE
} State;

int main(void)
{
    State state = IDLE;

    int start_command = 1;
    int error = 0;

    if (state == IDLE && start_command)
    {
        state = RUNNING;
    }

    if (state == RUNNING && error)
    {
        state = ERROR_STATE;
    }

    switch (state)
    {
        case IDLE:
            printf("State = IDLE\n");
            break;

        case RUNNING:
            printf("State = RUNNING\n");
            break;

        case ERROR_STATE:
            printf("State = ERROR\n");
            break;
    }

    return 0;
}


/* =========================================================
   06_fsm_switch_case.c
   FSM using switch-case
   ========================================================= */

#include <stdio.h>

typedef enum
{
    INIT,
    READY,
    ACTIVE,
    FAULT
} State;

int main(void)
{
    State state = INIT;

    for (int i = 0; i < 4; i++)
    {
        switch (state)
        {
            case INIT:
                printf("INIT\n");
                state = READY;
                break;

            case READY:
                printf("READY\n");
                state = ACTIVE;
                break;

            case ACTIVE:
                printf("ACTIVE\n");
                state = FAULT;
                break;

            case FAULT:
                printf("FAULT\n");
                break;
        }
    }

    return 0;
}


/* =========================================================
   07_fsm_event_based.c
   Event-driven FSM
   ========================================================= */

#include <stdio.h>

typedef enum
{
    IDLE,
    PROCESSING,
    COMPLETE
} State;

typedef enum
{
    EVENT_NONE,
    EVENT_START,
    EVENT_FINISH
} Event;

int main(void)
{
    State state = IDLE;

    Event events[] =
    {
        EVENT_START,
        EVENT_FINISH
    };

    int size = sizeof(events) / sizeof(events[0]);

    for (int i = 0; i < size; i++)
    {
        switch (state)
        {
            case IDLE:
                if (events[i] == EVENT_START)
                {
                    state = PROCESSING;
                    printf("IDLE -> PROCESSING\n");
                }
                break;

            case PROCESSING:
                if (events[i] == EVENT_FINISH)
                {
                    state = COMPLETE;
                    printf("PROCESSING -> COMPLETE\n");
                }
                break;

            case COMPLETE:
                printf("Operation completed\n");
                break;
        }
    }

    return 0;
}


/* =========================================================
   08_fsm_timeout.c
   FSM with timeout
   ========================================================= */

#include <stdio.h>

typedef enum
{
    WAITING,
    PROCESSING,
    TIMEOUT
} State;

int main(void)
{
    State state = WAITING;

    int elapsed_time = 0;
    int timeout_limit = 5;

    state = PROCESSING;

    while (state == PROCESSING)
    {
        elapsed_time++;

        printf("Processing... time = %d\n", elapsed_time);

        if (elapsed_time >= timeout_limit)
        {
            state = TIMEOUT;
        }
    }

    if (state == TIMEOUT)
    {
        printf("Operation timed out\n");
    }

    return 0;
}


/* =========================================================
   09_fsm_embedded_device.c
   Embedded device startup FSM
   ========================================================= */

#include <stdio.h>

typedef enum
{
    SYSTEM_INIT,
    SYSTEM_READY,
    SYSTEM_RUNNING,
    SYSTEM_ERROR
} SystemState;

int main(void)
{
    SystemState state = SYSTEM_INIT;

    int initialization_success = 1;
    int sensor_error = 0;

    switch (state)
    {
        case SYSTEM_INIT:

            printf("Initializing system...\n");

            if (initialization_success)
            {
                state = SYSTEM_READY;
            }
            else
            {
                state = SYSTEM_ERROR;
            }

            break;

        case SYSTEM_READY:
            break;

        case SYSTEM_RUNNING:
            break;

        case SYSTEM_ERROR:
            break;
    }

    if (state == SYSTEM_READY)
    {
        printf("System READY\n");

        if (!sensor_error)
        {
            state = SYSTEM_RUNNING;
        }
        else
        {
            state = SYSTEM_ERROR;
        }
    }

    if (state == SYSTEM_RUNNING)
    {
        printf("System RUNNING\n");
    }
    else if (state == SYSTEM_ERROR)
    {
        printf("System ERROR\n");
    }

    return 0;
}


/* =========================================================
   10_complete_fsm.c
   Complete embedded-style FSM
   ========================================================= */

#include <stdio.h>

typedef enum
{
    STATE_INIT,
    STATE_IDLE,
    STATE_RUNNING,
    STATE_ERROR
} State;

typedef enum
{
    EVENT_INIT_DONE,
    EVENT_START,
    EVENT_STOP,
    EVENT_ERROR
} Event;

void process_event(State *state, Event event)
{
    switch (*state)
    {
        case STATE_INIT:

            if (event == EVENT_INIT_DONE)
            {
                *state = STATE_IDLE;
            }

            break;

        case STATE_IDLE:

            if (event == EVENT_START)
            {
                *state = STATE_RUNNING;
            }

            break;

        case STATE_RUNNING:

            if (event == EVENT_STOP)
            {
                *state = STATE_IDLE;
            }
            else if (event == EVENT_ERROR)
            {
                *state = STATE_ERROR;
            }

            break;

        case STATE_ERROR:

            printf("System is in ERROR state\n");

            break;
    }
}

int main(void)
{
    State state = STATE_INIT;

    process_event(&state, EVENT_INIT_DONE);
    printf("State = IDLE\n");

    process_event(&state, EVENT_START);
    printf("State = RUNNING\n");

    process_event(&state, EVENT_ERROR);

    if (state == STATE_ERROR)
    {
        printf("State = ERROR\n");
    }

    return 0;
}
