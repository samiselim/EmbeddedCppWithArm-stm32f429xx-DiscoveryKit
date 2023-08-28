#include "LED.h"
#include "LED_Cfg.h"



extern MGPIO_PinConfig LED_Config[LED_NUMBER];
MGPIO gpio_object[LED_NUMBER];
led::led()
{
    for(int i=0 ; i<LED_NUMBER ; i++)
    {
        gpio_object[i].MGPIO_InitPin(&LED_Config[i]);
    }
}

void led::set_Led_State(Led_State_t _state , MGPIO_PIN_NUMBER_t Led_Num)
{   
    if(_state == ON)
    {
        for(int i=0 ; i<LED_NUMBER ; i++)
        {
            if(LED_Config[i].MGPIO_pinNumber == Led_Num)
            {
                gpio_object[i].MGPIO_SetPin(&(LED_Config[i]) , (MGPIO_PIN_STATE_t)ON);
            }
            else
            {
                // TODO
            }
        }
    }
    else if(_state == OFF)
    {
        for(int i=0 ; i<LED_NUMBER ; i++)
        {
            if(LED_Config[i].MGPIO_pinNumber == Led_Num)
            {
                gpio_object[i].MGPIO_SetPin(&(LED_Config[i]) , (MGPIO_PIN_STATE_t)OFF);
            }
            else
            {
                // TODO
            }
        }
    }
    else
    {

    }
}

Led_State_t led::get_Led_State( MGPIO_PIN_NUMBER_t Led_Num)
{
    Led_State_t led_state;

    for(int i=0 ; i<LED_NUMBER ; i++)
    {
        if(LED_Config[i].MGPIO_pinNumber == Led_Num)
        {
            led_state = (Led_State_t) gpio_object[i].MGPIO_GetPin(&LED_Config[i]);
        }
        else
        {
            // TODO
        }
    }
    return led_state;
}
