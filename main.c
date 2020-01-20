//enable clock access to the pin
//set pins mode(o/i)
//set output register
//RCGCGPIO

#include "TM4C123.h"                    // Device header

#define RED (1U<<29)
#define BLUE (1U<<30)
#define GREEN (1U<<31)

#define GPIOF_clock (1U<<5)
//gpio_dir direction register
#define GREEN_PIN (1U<<3)
#define RED_PIN (1U<<1)
#define BLUE_PIN (1U<<2)


int main() {
	
	SYSCTL->RCGC2 |= 0x20;
	
	GPIOF->DEN |= 0x0F;
	GPIOF->DIR |= 0x0F;
	while(1) {
		GPIOF->DATA |= GREEN_PIN | RED_PIN | BLUE_PIN;//2 red 4 blue 8 green
	}
}
