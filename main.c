#include "S5p4418_GPIO.h"
//LED1 @PB12
//LED2 @PB11
#define uint  unsigned int
void LED_Gpio_init(void)
{
    GPIOB_ALTFN0 = (uint)(0);
		//select function 2 PB11 PB12
		GPIOB_ALTFN0 |= (uint)(2 << 24);
		GPIOB_ALTFN0 |= (uint)(2 << 22);
    //set PB12 PB11 outputenable
		GPIOB_OUTENB |= (uint)(1 << 12);
    GPIOB_OUTENB |= (uint)(1 << 11);
		//set PB11 PB12 output High
    GPIOB_OUT |= (uint)(1 << 12);
		GPIOB_OUT |= (uint)(1 << 11);
}

void Led_Status_one(void)
{
    GPIOB_OUT &= (uint)(0 << 12);
		GPIOB_OUT |= (uint)(1 << 11);
}

void Led_Status_two(void)
{
		GPIOB_OUT &= (uint)(0 << 11);
    GPIOB_OUT |= (uint)(1 << 12);
}

void delay(unsigned int t)
{
    while(t--);
}

int main(void)
{
		uint freq=20000;
		LED_Gpio_init();
    while(1)
		{
        Led_Status_one();
        delay( freq );
        Led_Status_two();
        delay( freq );
				freq = freq<<1;
				if(freq >= 20000000)
				{
					freq = 20000;
				}
    }
    return 0;
}


