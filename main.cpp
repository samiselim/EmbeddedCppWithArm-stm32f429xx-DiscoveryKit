
#include "GPIO.h"

int main()
{
	MGPIO_PinConfig gpio_cfg;

	gpio_cfg.MGPIO_pinNumber = MGPIO_PIN_13;
	gpio_cfg.MGPIO_portName = MGPIO_GPIOG;
	
	gpio_cfg.MGPIO_pinMode = MGPIO_MODE_OUTPUT;
	gpio_cfg.MGPIO_outType = MGPIO_OUT_TYPE_PUSH_PULL;
	gpio_cfg.MGPIO_outSpeed = MGPIO_OUT_SPEED_MEDIUM;
	gpio_cfg.MGPIO_pullUpDown = MGPIO_PULL_DOWN;
	

	MGPIO gpio_obj(MGPIO_GPIOG);
	gpio_obj.MGPIO_InitPin(&gpio_cfg);
	gpio_obj.MGPIO_SetPin(&gpio_cfg , MGPIO_PIN_STATE_HIGH);

	while(1)
	{
	
	}
    return 0;
}
