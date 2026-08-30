
#include <stdio.h>                    
#include<driver/gpio.h>           
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>
#define PIN_LED GPIO_NUM_2

extern "C" void app_main(void)
{
    
    gpio_config_t Smallconf = {}; 
    Smallconf.pin_bit_mask = (1ULL<<PIN_LED); 
    Smallconf.mode = (GPIO_MODE_OUTPUT); 
    Smallconf.pull_down_en = GPIO_PULLDOWN_DISABLE; 
    Smallconf.pull_up_en = GPIO_PULLUP_DISABLE; 
    gpio_config(&Smallconf); // нельзя забывать принимать настройки 
    
    int count = 5;
    for (int i = 0; i < count; i++)
    {
        vTaskDelay(pdMS_TO_TICKS(200));
        gpio_set_level(PIN_LED,1 );
        printf("Светодиод загорелся\n");
        vTaskDelay(pdMS_TO_TICKS(200));
        gpio_set_level(PIN_LED,0 );
        printf("Светодиод выключен\n");
    }
    // int count1 = 0;
    // while (true)
    // {
    //     vTaskDelay(pdMS_TO_TICKS(200));
    //     gpio_set_level(PIN_LED,1 );
    //     // printf("Светодиод загорелся\n");
    //     vTaskDelay(pdMS_TO_TICKS(200));
    //     gpio_set_level(PIN_LED,0 );
    //     count1++;
    //     // printf("Светодиод выключен\n");
    //     if(count1%5 == 0)
    //     {
    //         printf("Прошло 5 миганий\n");
    //     }
    // }
    
}