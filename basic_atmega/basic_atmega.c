#include<avr/io.h>
#include<util/delay.h>

void main() {
	DDRA = 0x01;

	while (1) {
		PORTA = 0x01;
		_delay_ms(5000);

		PORTA = 0x00;
		_delay_ms(5000);
	}
}
