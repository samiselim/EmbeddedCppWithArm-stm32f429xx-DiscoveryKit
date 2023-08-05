#ifndef RCC_H
#define RCC_H

//#include "stm32f429xx.h"

#define AHB1ENR  *(volatile long *)(0x40023800 + 0x30)

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
    MRCC_NOK
}MRCC_GPIO_Error_t;

class MRCC
{
    public:
    MRCC_GPIO_Error_t rccError;
    MRCC();
    MRCC_GPIO_Error_t MRCC_GPIO_Port_Init(MRCC_GPIO_PORTS_t gpioPort);
    ~MRCC();
    private:



};

#endif