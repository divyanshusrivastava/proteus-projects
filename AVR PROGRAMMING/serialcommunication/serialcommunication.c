#include<avr/io.h>
#include<util/delay.h>

void USARTInit () {


   //Set Baud rate

   UBRRL = 103;
   UBRRH = 0;

   /*Set Frame Format


   >> Asynchronous mode
   >> No Parity
   >> 1 StopBit

   >> char size 8

   */

   UCSRC=(1<<URSEL)|(3<<UCSZ0);


   //Enable The receiver and transmitter

   UCSRB=(1<<TXCIE)|(1<<TXEN)|(1<<RXEN)|(1<<RXCIE);


}

char USARTReadChar()
{
   //Wait untill a data is available

   while(!(UCSRA & (1<<RXC)))
   {
      //Do nothing
   }

   //Now USART has got data from host
   //and is available is buffer

   return UDR;
}

void main () {
	USARTInit();
	DDRA = 0x03;
	char data;
	
	while(1) {
		data = USARTReadChar();
		_delay_ms(500);

		if (data) {
			PORTA = 0x02;
			_delay_ms(500);
			PORTA = 0x00;
		}


		if (data == '1')	{
			PORTA = 0x01;
			_delay_ms(2000);
		}

		if (data == '2') {
			PORTA = 0x00;
			_delay_ms(2000);
		}
		
	}
}
