#include "RCC.h"

MRCC::MRCC()
{
    rccError = MRCC_NOK;
}
MRCC::~MRCC()
{
	rccError = MRCC_OK;
}

MRCC_GPIO_Error_t MRCC::MRCC_GPIO_EnableClock(MRCC_GPIO_PORTS_t gpioPort)
{
    MRCC_GPIO_Error_t Error;
    if(gpioPort < MRCC_GPIOA || gpioPort > MRCC_GPIOK)
    {
        Error = MRCC_NOK;
    }
    else
    {
        RCC_AHB1ENR |= (0x0001<<gpioPort);
        Error = MRCC_OK;    
    }

    return Error;
}

