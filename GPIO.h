#ifndef GPIO_H
#define GPIO_H
#include "RCC.h"


#define NULL (void*)0
#define MGPIO_BASE 0x40020000

#define MODER(x)    (*(volatile long *) ((0x400 * x)+ (MGPIO_BASE) + (0x00)))
#define OTYPER(x)   (*(volatile long *) ((0x400 * x)+ (MGPIO_BASE) + (0x04)))
#define OSPEEDR(x)  (*(volatile long *) ((0x400 * x)+ (MGPIO_BASE) + (0x08)))
#define PUPDR(x)    (*(volatile long *) ((0x400 * x)+ (MGPIO_BASE) + (0x0C)))
#define IDR(x)      (*(volatile long *) ((0x400 * x)+ (MGPIO_BASE) + (0x10)))
#define ODR(x)      (*(volatile long *) ((0x400 * x)+ (MGPIO_BASE) + (0x14)))
#define BSRR(x)     (*(volatile long *) ((0x400 * x)+ (MGPIO_BASE) + (0x18)))
#define LCKR(x)     (*(volatile long *) ((0x400 * x)+ (MGPIO_BASE) + (0x1C)))
#define AFRL(x)     (*(volatile long *) ((0x400 * x)+ (MGPIO_BASE) + (0x20)))
#define AFRH(x)     (*(volatile long *) ((0x400 * x)+ (MGPIO_BASE) + (0x24)))

typedef enum 
{
    MGPIO_OK = 0,
    MGPIO_NOK,
    MGPIO_DEFAULT_ERROR
}MGPIO_ErrorType_t;

typedef enum 
{
    MGPIO_GPIOA = 0,
    MGPIO_GPIOB,
    MGPIO_GPIOC,
    MGPIO_GPIOD,
    MGPIO_GPIOE,
    MGPIO_GPIOF,
    MGPIO_GPIOG,
    MGPIO_GPIOH,
    MGPIO_GPIOI,
    MGPIO_GPIOJ,
    MGPIO_GPIOK

}MGPIO_PORTS_t;

typedef enum 
{
    MGPIO_PIN_STATE_HIGH = 0,
    MGPIO_PIN_STATE_LOW,
    MGPIO_PIN_STATE_FLOATING

}MGPIO_PIN_STATE_t;


typedef enum
{
    MGPIO_MODE_INPUT = 0,
    MGPIO_MODE_OUTPUT,
    MGPIO_MODE_ALTERNATE_FUNCTION,
    MGPIO_MODE_ANALOG
}MGPIO_PIN_MODE_t ;

typedef enum 
{
    MGPIO_PIN_0 = 0, MGPIO_PIN_1, MGPIO_PIN_2, MGPIO_PIN_3, MGPIO_PIN_4, MGPIO_PIN_5,
    MGPIO_PIN_6, MGPIO_PIN_7, MGPIO_PIN_8, MGPIO_PIN_9, MGPIO_PIN_10, MGPIO_PIN_11,     
    MGPIO_PIN_12, MGPIO_PIN_13, MGPIO_PIN_14, MGPIO_PIN_15

}MGPIO_PIN_NUMBER_t;

typedef enum 
{
    MGPIO_OUT_SPEED_LOW = 0,
    MGPIO_OUT_SPEED_MEDIUM,
    MGPIO_OUT_SPEED_FAST,
    MGPIO_OUT_SPEED_HIGH
}MGPIO_OUT_SPEED_t;


typedef enum
{
    MGPIO_OUT_TYPE_PUSH_PULL = 0,
    MGPIO_OUT_TYPE_OPEN_DRAIN
}MGPIO_OUT_TYPE_t;

typedef enum
{
    MGPIO_NO_PULL = 0,
    MGPIO_PULL_UP,
    MGPIO_PULL_DOWN
}MGPIO_PULL_UP_DOWN_t; 

typedef enum
{
    MGPIO_AF0 = 0,
    MGPIO_AF1,
    MGPIO_AF2,
    MGPIO_AF3,
    MGPIO_AF4,
    MGPIO_AF5,
    MGPIO_AF6,
    MGPIO_AF7,
    MGPIO_AF8,
    MGPIO_AF9,
    MGPIO_AF10,
    MGPIO_AF11,
    MGPIO_AF12,
    MGPIO_AF13,
    MGPIO_AF14,
    MGPIO_AF15

}MGPIO_AF_t;



class MGPIO_PinConfig
{
    public:
    MGPIO_PinConfig();
    MGPIO_ErrorType_t MGPIO_CfgIsOk();
    MGPIO_ErrorType_t MGPIO_cfg_Error;
    MGPIO_PORTS_t MGPIO_portName;
    MGPIO_PIN_NUMBER_t MGPIO_pinNumber;
    MGPIO_PIN_STATE_t MGPIO_pinState;    
    MGPIO_PIN_MODE_t MGPIO_pinMode;
    MGPIO_OUT_SPEED_t MGPIO_outSpeed;
    MGPIO_OUT_TYPE_t MGPIO_outType;
    MGPIO_PULL_UP_DOWN_t MGPIO_pullUpDown;
    MGPIO_AF_t MGPIO_AFtype;

    ~MGPIO_PinConfig();
    private:


};

class MGPIO
{
    public:
    MGPIO_ErrorType_t MGPIO_InitPinError;

    MGPIO();
    MGPIO_ErrorType_t MGPIO_InitPin(MGPIO_PinConfig * userCfg);
    MGPIO_PIN_STATE_t MGPIO_GetPin(MGPIO_PinConfig * userCfg);
    MGPIO_ErrorType_t MGPIO_SetPin(MGPIO_PinConfig * userCfg , MGPIO_PIN_STATE_t PinState);
    MGPIO_ErrorType_t MGPIO_TogglePin(MGPIO_PinConfig * userCfg);

    private:


};



#endif