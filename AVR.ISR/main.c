/*
 * ISR_Project.c
 *
 * Created: 9/10/2023 7:28:51 AM
 * Author : Hussein Sabry
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


#define SET_BIT(ADDRESS,BIT) ADDRESS |= (1<<BIT)
#define RESET_BIT(ADDRESS,BIT) ADDRESS &= ~(1<<BIT)
#define TOGGLE_BIT(ADDRESS,BIT) ADDRESS ^= (1<<BIT)
#define READ_BIT(ADDRESS,BIT) ((ADDRESS & (1<<BIT))>>BIT)




int main(void)
{
	// SET ANY LOGICAL CHANGE 
	SET_BIT(MCUCR,0);
	RESET_BIT(MCUCR,1);
	
	//SET RAISING EDGE 
	SET_BIT(MCUCR,2);
	SET_BIT(MCUCR,3);
	
	//SET FALLING EDGE
	SET_BIT(MCUCR,6);
	
	
	// SET ALL GENERAL INTERRUPT CONTROL REGERTER 
	SET_BIT(GICR,5);
	SET_BIT(GICR,6);
	SET_BIT(GICR,7);
	
	//set bit as output bit 5,6,7
	
	SET_BIT(DDRD,5);
	SET_BIT(DDRD,6);
	SET_BIT(DDRD,7);

	
	//GLOBAL INTERRUPT ENABLE sei is a fuction in avr libr. to set GI reg. enebled	
	sei();
	
	
    /* Replace with your application code */
	//reat bit after interrupt.
    while (1) 
    {
		RESET_BIT(PORTD,5);
	    RESET_BIT(PORTD,6);
		RESET_BIT(PORTD,7);

    }
}

ISR(INT0_vect){
	
	SET_BIT(PORTD,5);
	_delay_ms(1000);
	
}
ISR(INT1_vect){
	
	SET_BIT(PORTD,6);
	_delay_ms(1000);
	
}
ISR(INT2_vect){
	
	SET_BIT(PORTD,7);
	_delay_ms(1000);	
}


