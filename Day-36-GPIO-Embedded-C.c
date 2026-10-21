/* =========================================================
   01_gpio_output.c
   GPIO output logic
   ========================================================= */

#include <stdio.h>

#define GPIO_LOW  0
#define GPIO_HIGH 1

int main(void)
{
    int gpio_pin = GPIO_LOW;

    printf("Initial GPIO = %d\n", gpio_pin);

    gpio_pin = GPIO_HIGH;

    printf("GPIO after setting HIGH = %d\n", gpio_pin);

    return 0;
}


/* =========================================================
   02_gpio_input.c
   GPIO input logic
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int button_state;

    printf("Enter button state (0 = released, 1 = pressed): ");
    scanf("%d", &button_state);

    if (button_state == 1)
    {
        printf("Button is PRESSED\n");
    }
    else
    {
        printf("Button is RELEASED\n");
    }

    return 0;
}


/* =========================================================
   03_led_control.c
   LED ON/OFF control
   ========================================================= */

#include <stdio.h>

#define LED_OFF 0
#define LED_ON  1

int main(void)
{
    int led = LED_OFF;

    printf("LED = OFF\n");

    led = LED_ON;

    if (led == LED_ON)
    {
        printf("LED = ON\n");
    }

    led = LED_OFF;

    if (led == LED_OFF)
    {
        printf("LED = OFF\n");
    }

    return 0;
}


/* =========================================================
   04_button_led.c
   Button controls LED
   ========================================================= */

#include <stdio.h>

#define PRESSED  1
#define RELEASED 0

int main(void)
{
    int button;
    int led;

    printf("Enter button state (1 = pressed, 0 = released): ");
    scanf("%d", &button);

    if (button == PRESSED)
    {
        led = 1;
    }
    else
    {
        led = 0;
    }

    printf("LED = %s\n", led ? "ON" : "OFF");

    return 0;
}


/* =========================================================
   05_toggle_led.c
   Toggle GPIO output
   ========================================================= */

#include <stdio.h>

void toggle(int *gpio)
{
    *gpio ^= 1;
}

int main(void)
{
    int led = 0;

    printf("Initial LED = %d\n", led);

    toggle(&led);
    printf("After toggle = %d\n", led);

    toggle(&led);
    printf("After toggle = %d\n", led);

    toggle(&led);
    printf("After toggle = %d\n", led);

    return 0;
}


/* =========================================================
   06_register_bit_control.c
   GPIO register bit manipulation
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

#define GPIO_PIN 3

int main(void)
{
    uint8_t gpio_register = 0x00;

    /* Set pin */
    gpio_register |= (1U << GPIO_PIN);

    printf("After SET    : 0x%02X\n", gpio_register);

    /* Clear pin */
    gpio_register &= ~(1U << GPIO_PIN);

    printf("After CLEAR  : 0x%02X\n", gpio_register);

    /* Toggle pin */
    gpio_register ^= (1U << GPIO_PIN);

    printf("After TOGGLE : 0x%02X\n", gpio_register);

    /* Read pin */
    if (gpio_register & (1U << GPIO_PIN))
    {
        printf("Pin is HIGH\n");
    }
    else
    {
        printf("Pin is LOW\n");
    }

    return 0;
}


/* =========================================================
   07_gpio_active_low.c
   Active-low GPIO
   ========================================================= */

#include <stdio.h>

#define GPIO_LOW  0
#define GPIO_HIGH 1

int main(void)
{
    int gpio;

    /*
       Active-low device:
       LOW  -> device ON
       HIGH -> device OFF
    */

    gpio = GPIO_LOW;

    if (gpio == GPIO_LOW)
    {
        printf("Device ON\n");
    }

    gpio = GPIO_HIGH;

    if (gpio == GPIO_HIGH)
    {
        printf("Device OFF\n");
    }

    return 0;
}


/* =========================================================
   08_gpio_multiple_pins.c
   Multiple GPIO pins
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

#define LED1_PIN 0
#define LED2_PIN 1
#define LED3_PIN 2

int main(void)
{
    uint8_t gpio = 0;

    /* Turn ON LED1 and LED3 */
    gpio |= (1U << LED1_PIN);
    gpio |= (1U << LED3_PIN);

    printf("GPIO register = 0x%02X\n", gpio);

    /* Turn OFF LED1 */
    gpio &= ~(1U << LED1_PIN);

    printf("After LED1 OFF = 0x%02X\n", gpio);

    /* Toggle LED2 */
    gpio ^= (1U << LED2_PIN);

    printf("After LED2 toggle = 0x%02X\n", gpio);

    return 0;
}


/* =========================================================
   09_gpio_debounce_logic.c
   Simple button debounce concept
   ========================================================= */

#include <stdio.h>

int main(void)
{
    int previous_state = 0;
    int current_state;
    int stable_count = 0;

    int samples[] = {0, 1, 1, 1, 1};
    int size = sizeof(samples) / sizeof(samples[0]);

    for (int i = 0; i < size; i++)
    {
        current_state = samples[i];

        if (current_state == previous_state)
        {
            stable_count++;
        }
        else
        {
            stable_count = 0;
        }

        if (stable_count >= 2)
        {
            printf("Stable button state = %d\n", current_state);
        }

        previous_state = current_state;
    }

    return 0;
}


/* =========================================================
   10_embedded_gpio_driver.c
   Simple GPIO driver
   ========================================================= */

#include <stdio.h>
#include <stdint.h>

#define GPIO_OUTPUT 1
#define GPIO_INPUT  0

static uint8_t gpio_direction = 0;
static uint8_t gpio_data = 0;

void GPIO_Init(uint8_t pin, uint8_t direction)
{
    if (direction == GPIO_OUTPUT)
    {
        gpio_direction |= (1U << pin);
    }
    else
    {
        gpio_direction &= ~(1U << pin);
    }
}

void GPIO_Write(uint8_t pin, uint8_t value)
{
    if (gpio_direction & (1U << pin))
    {
        if (value)
        {
            gpio_data |= (1U << pin);
        }
        else
        {
            gpio_data &= ~(1U << pin);
        }
    }
}

uint8_t GPIO_Read(uint8_t pin)
{
    return (gpio_data >> pin) & 1U;
}

int main(void)
{
    GPIO_Init(2, GPIO_OUTPUT);

    GPIO_Write(2, 1);

    printf("GPIO pin 2 = %u\n", GPIO_Read(2));

    GPIO_Write(2, 0);

    printf("GPIO pin 2 = %u\n", GPIO_Read(2));

    return 0;
}
