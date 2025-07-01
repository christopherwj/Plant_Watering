#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_system.h"
#include "esp_log.h"
#include "esp_mac.h"

#define BLINK_GPIO 2

void app_main() {
    // Print chip ID (MAC address)
    uint8_t mac[6];
    esp_read_mac(mac, ESP_MAC_WIFI_STA);
    printf("ESP32 Chip ID (MAC): %02X:%02X:%02X:%02X:%02X:%02X\n",
           mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);

    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
    while (1) {
        gpio_set_level(BLINK_GPIO, 1);
        vTaskDelay(500 / portTICK_PERIOD_MS);
        gpio_set_level(BLINK_GPIO, 0);
        vTaskDelay(500 / portTICK_PERIOD_MS);
        //printf("ESP32 Chip ID (MAC): %02X:%02X:%02X:%02X:%02X:%02X\n",
        //   mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
    }
    // to get the debug print output, use the command:
    //platformio device monitor -b 115200 
}