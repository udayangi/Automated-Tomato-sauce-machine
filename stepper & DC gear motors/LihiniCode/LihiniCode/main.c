#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
int flag = 0;
int main(void)
{
    DDRB |= (1<<PB6);
	DDRD |= 0xFF;					/* Make PORTD lower pins as output */
	
	int period;
	period = 100;
	
	while(1){
		if(flag == 0){
			PORTB |= (1<<PB6);
			_delay_ms(7000);
			PORTB &= ~(1<<PB6);
			flag = 1;	
		}
		if (flag==1) 
		{
				//stepper motor clockwise half step sequence
			PORTD = 0x90;
			_delay_ms(period); 
			PORTD = 0x80;
			_delay_ms(period);
			PORTD = 0xC0;
			_delay_ms(period);
			PORTD = 0x40;
			_delay_ms(period);
			PORTD = 0x60;
			_delay_ms(period);
			PORTD = 0x20;
			_delay_ms(period);
			PORTD = 0x30;
			_delay_ms(period);
			PORTD = 0x10;
			_delay_ms(period);
			
			
			PORTD = 0x90;
			_delay_ms(period);
			_delay_ms(1000);
			
			
			//stepper motor anti clockwise full step sequence
			PORTD = 0x90;
			_delay_ms(period);
			PORTD = 0x30;
			_delay_ms(period);
			PORTD = 0x60;
			_delay_ms(period);
			PORTD = 0xC0;
			_delay_ms(period);
			
			PORTD = 0x90;
			_delay_ms(period);
			_delay_ms(1000);
			flag=2;
			
		}
			
	}  
}

