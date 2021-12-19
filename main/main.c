#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"
#include "sdkconfig.h"

#include "dht11.h"

#define TAG __FILE__

void app_main(void) {
    ESP_LOGI(TAG, "CONFIG_DHT11_GPIO=%d", CONFIG_DHT11_GPIO);

    dht11_init();

    dht11_data_t dht11_data;
    while (true) {
        if (dht11_read(&dht11_data)) {
            ESP_LOGI(TAG, "temperature: %d humidity: %d", dht11_data.temperature, dht11_data.humidity);
        }

        // 间隔>2s
        vTaskDelay(3000 / portTICK_PERIOD_MS);
    }
}
