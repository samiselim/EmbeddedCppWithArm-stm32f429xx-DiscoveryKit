#ifndef LED_H
#define LED_H
#include "GPIO.h"
#include "LED_Cfg.h"
#define LED_NUMBER 3

typedef enum 
{
    ON= 0,
    OFF

}Led_State_t;

/* LED Class which has all features and methods related to The Led */
class led
{
    private:
    public:
    led(); // Constructor to init Led State 
    void LED_set_Led_State(Led_State_t _state , MGPIO_PIN_NUMBER_t Led_Num);// Method to Set Led state ON or OFF
    Led_State_t LED_get_Led_State( MGPIO_PIN_NUMBER_t Led_Num); // Method To get Led State 
    void LED_ToggleLed(MGPIO_PIN_NUMBER_t Led_Num);
    
};




#endif //LED_H