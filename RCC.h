#ifndef RCC_H
#define RCC_H

//#include "stm32f429xx.h"
#define RCC_BASE 0x40023800
#define _memWord(offset) *(volatile long *)(RCC_BASE + offset)

#define RCC_AHB1ENR  _memWord(0x30)
#define RCC_CR _memWord(0x00)
#define RCC_PLLCFGR _memWord(0x04)
#define RCC_CFGR _memWord(0x08)
#define RCC_CIR _memWord(0x0C)


typedef enum 
{
    MRCC_GPIOA,
    MRCC_GPIOB,
    MRCC_GPIOC,
    MRCC_GPIOD,
    MRCC_GPIOE,
    MRCC_GPIOF,
    MRCC_GPIOG,
    MRCC_GPIOH,
    MRCC_GPIOI,
    MRCC_GPIOJ,
    MRCC_GPIOK


}MRCC_GPIO_PORTS_t;


typedef enum 
{
    MRCC_OK,
    MRCC_NOK,
    MRCC_DEFAULT_ERROR
}MRCC_GPIO_Error_t;

class MRCC
{
    public:
    MRCC_GPIO_Error_t rccError;
    MRCC();
    static MRCC_GPIO_Error_t MRCC_GPIO_EnableClock(MRCC_GPIO_PORTS_t gpioPort);
    ~MRCC();

    private:

};

#endif