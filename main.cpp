
#include "LED.h"


int main()
{


	led led_obj;
	//led_obj.LED_set_Led_State(ON,MGPIO_PIN_13);


	while(1)
	{
		led_obj.LED_ToggleLed(MGPIO_PIN_13);

		for(int i=0 ;i <1000000 ; i++)
		{
			
		}

	}
    return 0;
}
