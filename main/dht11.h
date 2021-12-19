#include <stdbool.h>
#include <stdint.h>

#include "sdkconfig.h"

#define DHT11_PIN CONFIG_DHT11_GPIO //可通过宏定义，修改引脚

typedef struct {
    uint8_t temperature; // 温度
    uint8_t humidity;    // 湿度
} dht11_data_t;

// 初始化DHT11引脚
void dht11_init();

// 读取DHT11温湿度数据，成功返回true，失败返回false
bool dht11_read(dht11_data_t *dht11_data);
