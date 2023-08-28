

#include "LED.h"

int main()
{
	// MGPIO_PinConfig gpio_cfg[2];

	// gpio_cfg[0].MGPIO_pinNumber = MGPIO_PIN_13;
	// gpio_cfg[0].MGPIO_portName = MGPIO_GPIOG;
	
	// gpio_cfg[0].MGPIO_pinMode = MGPIO_MODE_OUTPUT;
	// gpio_cfg[0].MGPIO_outType = MGPIO_OUT_TYPE_PUSH_PULL;
	// gpio_cfg[0].MGPIO_outSpeed = MGPIO_OUT_SPEED_MEDIUM;
	// gpio_cfg[0].MGPIO_pullUpDown = MGPIO_NO_PULL;
	


	// gpio_cfg[1].MGPIO_pinNumber = MGPIO_PIN_14;
	// gpio_cfg[1].MGPIO_portName = MGPIO_GPIOD;
	
	// gpio_cfg[1].MGPIO_pinMode = MGPIO_MODE_INPUT;
	// gpio_cfg[1].MGPIO_outType = MGPIO_OUT_TYPE_PUSH_PULL;
	// gpio_cfg[1].MGPIO_outSpeed = MGPIO_OUT_SPEED_MEDIUM;
	// gpio_cfg[1].MGPIO_pullUpDown = MGPIO_PULL_UP;



	// MGPIO gpio_obj;
	// /**** Loop to init All pins ********/
	// for(int i=0 ; i< 2 ;i++)
	// {
	// 	gpio_obj.MGPIO_InitPin(&gpio_cfg[i]);
	// }
	// gpio_obj.MGPIO_SetPin(&gpio_cfg[0] , MGPIO_PIN_STATE_HIGH);



	led led_obj;
	led_obj.set_Led_State(ON,MGPIO_PIN_13);

	// while(1)
	// {
	// 	if(gpio_obj.MGPIO_GetPin(&gpio_cfg[1]) == 1)
	// 	{
	// 		gpio_obj.MGPIO_SetPin(&gpio_cfg[0] , MGPIO_PIN_STATE_HIGH);	
	// 	}
	// 	else
	// 	{
	// 		gpio_obj.MGPIO_SetPin(&gpio_cfg[0] , MGPIO_PIN_STATE_LOW);	

	// 	}
	// }
    return 0;
}
