#include "GPIO.h"


MGPIO_PinConfig::MGPIO_PinConfig()
{
}

MGPIO_ErrorType_t MGPIO_PinConfig::MGPIO_CfgIsOk()
{
    MGPIO_ErrorType_t MGPIO_retError = MGPIO_NOK;   
    if(MGPIO_portName > MGPIO_GPIOK || MGPIO_portName <  MGPIO_GPIOA)
    {
        MGPIO_retError  = MGPIO_NOK; 
    }
    else
    {
        if(MGPIO_pinNumber > MGPIO_PIN_15 || MGPIO_pinNumber < MGPIO_PIN_0)
        {
            MGPIO_retError  = MGPIO_NOK; 
        }
        else
        {
            MGPIO_retError  = MGPIO_OK;
        }

    }
    return MGPIO_retError;
}



MGPIO::MGPIO()
{

}

MGPIO_ErrorType_t MGPIO::MGPIO_InitPin(MGPIO_PinConfig *userCfg)
{

    MGPIO_ErrorType_t Error = MGPIO_DEFAULT_ERROR;
    if(MRCC::MRCC_GPIO_EnableClock((MRCC_GPIO_PORTS_t)userCfg->MGPIO_portName) == MRCC_OK)
    {
        MGPIO_InitPinError = MGPIO_OK;
    }
    else
    {
        MGPIO_InitPinError = MGPIO_NOK;
    }
    
    
    if(userCfg == NULL)
    {
        Error = MGPIO_NOK;
        userCfg->MGPIO_cfg_Error = MGPIO_NOK;
    }
    else
    {
        if( userCfg->MGPIO_CfgIsOk() == MGPIO_OK &&  MGPIO_InitPinError == MGPIO_OK)
        {
           if(userCfg ->MGPIO_pinMode == MGPIO_MODE_OUTPUT)
           {
                MODER(userCfg->MGPIO_portName) |= (1UL<<((userCfg->MGPIO_pinNumber)*2));
                MODER(userCfg->MGPIO_portName) &= ~(1UL<<(((userCfg->MGPIO_pinNumber)*2)+1));

                if(userCfg->MGPIO_outType == MGPIO_OUT_TYPE_PUSH_PULL)
                {
                    OTYPER(userCfg->MGPIO_portName) &= ~(1<< ((userCfg->MGPIO_pinNumber)));
                    userCfg->MGPIO_cfg_Error = MGPIO_OK;
                }
                else if(userCfg->MGPIO_outType == MGPIO_OUT_TYPE_OPEN_DRAIN)
                {
                    OTYPER(userCfg->MGPIO_portName) |= (1UL<< ((userCfg->MGPIO_pinNumber)));
                    userCfg->MGPIO_cfg_Error = MGPIO_OK;
                }
                else
                {

                }
                if(userCfg->MGPIO_outSpeed == MGPIO_OUT_SPEED_LOW)
                {
                    OSPEEDR(userCfg->MGPIO_portName) &=  ~(1UL<<((userCfg->MGPIO_pinNumber)*2));
                    OSPEEDR(userCfg->MGPIO_portName) &=  ~(1UL<<(((userCfg->MGPIO_pinNumber)*2)+1));
                    userCfg->MGPIO_cfg_Error = MGPIO_OK;
                }
                else if(userCfg->MGPIO_outSpeed == MGPIO_OUT_SPEED_MEDIUM)
                {
                    OSPEEDR(userCfg->MGPIO_portName) |= (1UL<<((userCfg->MGPIO_pinNumber)*2));
                    OSPEEDR(userCfg->MGPIO_portName) &= ~(1UL<<(((userCfg->MGPIO_pinNumber)*2)+1));
                    userCfg->MGPIO_cfg_Error = MGPIO_OK;
                }
                else if(userCfg->MGPIO_outSpeed == MGPIO_OUT_SPEED_HIGH)
                {
                    OSPEEDR(userCfg->MGPIO_portName) &= ~(1UL<<((userCfg->MGPIO_pinNumber)*2));
                    OSPEEDR(userCfg->MGPIO_portName) |= (1UL<<(((userCfg->MGPIO_pinNumber)*2)+1));
                    userCfg->MGPIO_cfg_Error = MGPIO_OK;
                }
                else if(userCfg->MGPIO_outSpeed == MGPIO_OUT_SPEED_FAST)
                {
                    OSPEEDR(userCfg->MGPIO_portName) |= (1UL<<((userCfg->MGPIO_pinNumber)*2));
                    OSPEEDR(userCfg->MGPIO_portName) |= (1UL<<(((userCfg->MGPIO_pinNumber)*2)+1));
                    userCfg->MGPIO_cfg_Error = MGPIO_OK;
                }
                else
                {

                }
                if(userCfg->MGPIO_pullUpDown == MGPIO_NO_PULL)
                {
                    PUPDR(userCfg->MGPIO_portName) &=  ~(1UL<<((userCfg->MGPIO_pinNumber)*2));
                    PUPDR(userCfg->MGPIO_portName) &=  ~(1UL<<(((userCfg->MGPIO_pinNumber)*2)+1));
                    userCfg->MGPIO_cfg_Error = MGPIO_OK;
                }
                else if(userCfg->MGPIO_pullUpDown == MGPIO_PULL_UP)
                {
                    PUPDR(userCfg->MGPIO_portName) |= (1UL<<((userCfg->MGPIO_pinNumber)*2));
                    PUPDR(userCfg->MGPIO_portName) &= ~(1UL<<(((userCfg->MGPIO_pinNumber)*2)+1));
                    userCfg->MGPIO_cfg_Error = MGPIO_OK;
                }
                else if(userCfg->MGPIO_pullUpDown == MGPIO_PULL_DOWN)
                {
                    PUPDR(userCfg->MGPIO_portName) &= ~(1UL<<((userCfg->MGPIO_pinNumber)*2));
                    PUPDR(userCfg->MGPIO_portName) |= (1UL<<(((userCfg->MGPIO_pinNumber)*2)+1));
                    userCfg->MGPIO_cfg_Error = MGPIO_OK;
                }
                else
                {

                }
           }
           else if (userCfg ->MGPIO_pinMode == MGPIO_MODE_INPUT)
           {
                MODER(userCfg->MGPIO_portName) &= ~(1UL<<((userCfg->MGPIO_pinNumber)*2));
                MODER(userCfg->MGPIO_portName) &= ~(1UL<<(((userCfg->MGPIO_pinNumber)*2)+1));

                if(userCfg->MGPIO_outType == MGPIO_OUT_TYPE_PUSH_PULL)
                {
                    OTYPER(userCfg->MGPIO_portName) &= ~(1<< ((userCfg->MGPIO_pinNumber)));
                    userCfg->MGPIO_cfg_Error = MGPIO_OK;
                }
                else if(userCfg->MGPIO_outType == MGPIO_OUT_TYPE_OPEN_DRAIN)
                {
                    OTYPER(userCfg->MGPIO_portName) |= (1UL<< ((userCfg->MGPIO_pinNumber)));
                    userCfg->MGPIO_cfg_Error = MGPIO_OK;
                }
                else
                {

                }   

             if(userCfg->MGPIO_outSpeed == MGPIO_OUT_SPEED_LOW)
                {
                    OSPEEDR(userCfg->MGPIO_portName) &=  ~(1UL<<((userCfg->MGPIO_pinNumber)*2));
                    OSPEEDR(userCfg->MGPIO_portName) &=  ~(1UL<<(((userCfg->MGPIO_pinNumber)*2)+1));
                    userCfg->MGPIO_cfg_Error = MGPIO_OK;
                }
                else if(userCfg->MGPIO_outSpeed == MGPIO_OUT_SPEED_MEDIUM)
                {
                    OSPEEDR(userCfg->MGPIO_portName) |= (1UL<<((userCfg->MGPIO_pinNumber)*2));
                    OSPEEDR(userCfg->MGPIO_portName) &= ~(1UL<<(((userCfg->MGPIO_pinNumber)*2)+1));
                    userCfg->MGPIO_cfg_Error = MGPIO_OK;
                }
                else if(userCfg->MGPIO_outSpeed == MGPIO_OUT_SPEED_HIGH)
                {
                    OSPEEDR(userCfg->MGPIO_portName) &= ~(1UL<<((userCfg->MGPIO_pinNumber)*2));
                    OSPEEDR(userCfg->MGPIO_portName) |= (1UL<<(((userCfg->MGPIO_pinNumber)*2)+1));
                    userCfg->MGPIO_cfg_Error = MGPIO_OK;
                }
                else if(userCfg->MGPIO_outSpeed == MGPIO_OUT_SPEED_FAST)
                {
                    OSPEEDR(userCfg->MGPIO_portName) |= (1UL<<((userCfg->MGPIO_pinNumber)*2));
                    OSPEEDR(userCfg->MGPIO_portName) |= (1UL<<(((userCfg->MGPIO_pinNumber)*2)+1));
                    userCfg->MGPIO_cfg_Error = MGPIO_OK;
                }
                else
                {

                }

                if(userCfg->MGPIO_pullUpDown == MGPIO_NO_PULL)
                {
                    PUPDR(userCfg->MGPIO_portName) &=  ~(1UL<<((userCfg->MGPIO_pinNumber)*2));
                    PUPDR(userCfg->MGPIO_portName) &=  ~(1UL<<(((userCfg->MGPIO_pinNumber)*2)+1));
                    userCfg->MGPIO_cfg_Error = MGPIO_OK;
                }
                else if(userCfg->MGPIO_pullUpDown == MGPIO_PULL_UP)
                {
                    PUPDR(userCfg->MGPIO_portName) |= (1UL<<((userCfg->MGPIO_pinNumber)*2));
                    PUPDR(userCfg->MGPIO_portName) &= ~(1UL<<(((userCfg->MGPIO_pinNumber)*2)+1));
                    userCfg->MGPIO_cfg_Error = MGPIO_OK;
                }
                else if(userCfg->MGPIO_pullUpDown == MGPIO_PULL_DOWN)
                {
                    PUPDR(userCfg->MGPIO_portName) &= ~(1UL<<((userCfg->MGPIO_pinNumber)*2));
                    PUPDR(userCfg->MGPIO_portName) |= (1UL<<(((userCfg->MGPIO_pinNumber)*2)+1));
                    userCfg->MGPIO_cfg_Error = MGPIO_OK;
                }
                else
                {

                }
           }    
           else
           {
                userCfg->MGPIO_cfg_Error = MGPIO_NOK;
                Error = MGPIO_NOK;
           }
        }
        else
        {     
            userCfg->MGPIO_cfg_Error = MGPIO_NOK;
            Error = MGPIO_NOK;
        }
    }

    return Error;
}

MGPIO_ErrorType_t MGPIO::MGPIO_SetPin(MGPIO_PinConfig * userCfg , MGPIO_PIN_STATE_t PinState)
{
    MGPIO_ErrorType_t Error = MGPIO_DEFAULT_ERROR;

    if(userCfg == NULL)
    {
        Error = MGPIO_NOK;
        userCfg->MGPIO_cfg_Error = MGPIO_NOK;
    }else
    {
        if(userCfg->MGPIO_cfg_Error == MGPIO_OK)
        {
            if(PinState == MGPIO_PIN_STATE_LOW)
            {
                ODR(userCfg->MGPIO_portName) &= ~(1U<<userCfg->MGPIO_pinNumber);
            }
            else if(PinState == MGPIO_PIN_STATE_HIGH)
            {
                ODR(userCfg->MGPIO_portName) |= (1U<<userCfg->MGPIO_pinNumber);
            }
            else
            {
                Error = MGPIO_NOK;
            }
                
        }
        else
        {
            Error = MGPIO_NOK;
        }
    }
    return Error;
    
}

MGPIO_PIN_STATE_t MGPIO::MGPIO_GetPin(MGPIO_PinConfig * userCfg)
{
    MGPIO_PIN_STATE_t state;

    if(!(IDR(userCfg->MGPIO_portName) & (1U<<userCfg->MGPIO_pinNumber)))
    {
        state = MGPIO_PIN_STATE_HIGH;
    }
    else
    {
        state = MGPIO_PIN_STATE_LOW;
    }
    return state;
}


MGPIO_ErrorType_t MGPIO::MGPIO_TogglePin(MGPIO_PinConfig * userCfg)
{
    MGPIO_ErrorType_t Error = MGPIO_DEFAULT_ERROR;

    if(userCfg == NULL)
    {
        Error = MGPIO_NOK;
        userCfg->MGPIO_cfg_Error = MGPIO_NOK;
    }else
    {
        if(userCfg->MGPIO_cfg_Error == MGPIO_OK)
        {
            ODR(userCfg->MGPIO_portName) ^= (1U<<userCfg->MGPIO_pinNumber);
            Error = MGPIO_OK;
        }
        else
        {
            Error = MGPIO_NOK;
        }
    }
    return Error;
}