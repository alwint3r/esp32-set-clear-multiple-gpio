#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

void app_main()
{
    /**
     * Setting IO15 and IO16 as output with no interrupt enabled
     */
    gpio_config_t io_config = {
        .mode = GPIO_MODE_OUTPUT,
        .intr_type = GPIO_INTR_DISABLE,
        .pin_bit_mask = GPIO_SEL_15 | GPIO_SEL_16,
    };

    ESP_ERROR_CHECK(gpio_config(&io_config));

    while (true)
    {
        // set IO15 and IO16
        REG_WRITE(GPIO_OUT_W1TS_REG, GPIO_SEL_15 | GPIO_SEL_16);
        vTaskDelay(pdMS_TO_TICKS(1000));

        // unset IO16 and IO16
        REG_WRITE(GPIO_OUT_W1TC_REG, GPIO_SEL_15 | GPIO_SEL_16);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}