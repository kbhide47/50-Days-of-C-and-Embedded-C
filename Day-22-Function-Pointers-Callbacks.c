/* =========================================================
   DAY 22 — FUNCTION POINTERS & CALLBACKS
   ========================================================= */


/* =========================================================
   Q1. Basic function pointer
   File: q01_basic_function_pointer.c
   ========================================================= */

#include <stdio.h>

void display(void)
{
    printf("Hello from function\n");
}

int main(void)
{
    void (*ptr)(void);

    ptr = display;

    ptr();

    return 0;
}


/* =========================================================
   Q2. Function pointer with arguments
   File: q02_function_pointer_arguments.c
   ========================================================= */

#include <stdio.h>

void add(int a, int b)
{
    printf("Sum = %d\n", a + b);
}

int main(void)
{
    void (*operation)(int, int);

    operation = add;

    operation(10, 20);

    return 0;
}


/* =========================================================
   Q3. Function pointer returning a value
   File: q03_function_pointer_return.c
   ========================================================= */

#include <stdio.h>

int multiply(int a, int b)
{
    return a * b;
}

int main(void)
{
    int (*operation)(int, int);

    operation = multiply;

    int result = operation(5, 4);

    printf("Result = %d\n", result);

    return 0;
}


/* =========================================================
   Q4. Callback function
   File: q04_callback_function.c
   ========================================================= */

#include <stdio.h>

void task(void)
{
    printf("Task executed\n");
}

void execute_task(void (*callback)(void))
{
    printf("Calling callback...\n");

    callback();
}

int main(void)
{
    execute_task(task);

    return 0;
}


/* =========================================================
   Q5. Calculator using function pointer
   File: q05_calculator_using_function_pointer.c
   ========================================================= */

#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int main(void)
{
    int (*operation)(int, int);

    operation = add;
    printf("Addition = %d\n", operation(10, 5));

    operation = subtract;
    printf("Subtraction = %d\n", operation(10, 5));

    operation = multiply;
    printf("Multiplication = %d\n", operation(10, 5));

    return 0;
}


/* =========================================================
   Q6. Array of function pointers
   File: q06_array_of_function_pointers.c
   ========================================================= */

#include <stdio.h>

void task1(void)
{
    printf("Task 1 executed\n");
}

void task2(void)
{
    printf("Task 2 executed\n");
}

void task3(void)
{
    printf("Task 3 executed\n");
}

int main(void)
{
    void (*tasks[3])(void) =
    {
        task1,
        task2,
        task3
    };

    for (int i = 0; i < 3; i++)
    {
        tasks[i]();
    }

    return 0;
}


/* =========================================================
   Q7. Function pointer typedef
   File: q07_function_pointer_typedef.c
   ========================================================= */

#include <stdio.h>

typedef int (*Operation)(int, int);

int add(int a, int b)
{
    return a + b;
}

int main(void)
{
    Operation operation = add;

    printf("Result = %d\n",
           operation(20, 30));

    return 0;
}


/* =========================================================
   Q8. Callback with data
   File: q08_callback_with_data.c
   ========================================================= */

#include <stdio.h>

void process_sensor(int temperature)
{
    printf("Temperature = %d C\n",
           temperature);
}

void sensor_event(
    int value,
    void (*callback)(int))
{
    callback(value);
}

int main(void)
{
    sensor_event(30, process_sensor);

    return 0;
}


/* =========================================================
   Q9. Embedded event callback
   File: q09_embedded_event_callback.c
   ========================================================= */

#include <stdio.h>

typedef void (*EventCallback)(void);

void button_pressed(void)
{
    printf("Button pressed event handled\n");
}

void sensor_ready(void)
{
    printf("Sensor ready event handled\n");
}

void trigger_event(EventCallback callback)
{
    if (callback != NULL)
    {
        callback();
    }
}

int main(void)
{
    trigger_event(button_pressed);
    trigger_event(sensor_ready);

    return 0;
}


/* =========================================================
   Q10. Interrupt-style callback
   File: q10_interrupt_style_callback.c
   ========================================================= */

#include <stdio.h>

typedef void (*ISRCallback)(void);

ISRCallback interrupt_handler = NULL;

void uart_receive_handler(void)
{
    printf("UART data received\n");
}

void register_interrupt_handler(ISRCallback handler)
{
    interrupt_handler = handler;
}

void simulate_interrupt(void)
{
    if (interrupt_handler != NULL)
    {
        interrupt_handler();
    }
}

int main(void)
{
    register_interrupt_handler(uart_receive_handler);

    simulate_interrupt();

    return 0;
}
