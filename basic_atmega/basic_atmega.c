#include<avr/io.h>
#include<util/delay.h>

void main() {
	DDRD = 0x03;

	while (1) {
		PORTD = 0x01;
		_delay_ms(1000);

		PORTD = 0x02;
		_delay_ms(1000);
	}
}
