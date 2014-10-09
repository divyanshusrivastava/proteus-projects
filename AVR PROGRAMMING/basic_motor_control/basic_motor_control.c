#include<avr/io.h>
#include<util/delay.h>

void main ()
{
	DDRC= 0x03;

	while(1)
	{
		PORTC = 0x01;
		_delay_ms(5000);

		PORTC = 0x00;
		_delay_ms(5000);

		PORTC= 0x02;
		_delay_ms(5000);

		PORTC= 0x00;
		_delay_ms(5000);

	}
}
