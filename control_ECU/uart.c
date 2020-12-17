/*
 * uart.c
 *
 *  Created on: Oct 1, 2020
 *      Author: user
 */

#include "uart.h"


void UART_init(const UART_config * cofig_Ptr)
{

	UCSRB |= (1 << RXEN) | (1 << TXEN);
	UCSRC |= (1 << URSEL) ;

	/*double speed*/
	UCSRA = (UCSRA & 0xFD) | (double_speed << 1);

	UCSRC = (UCSRC & 0xF9) | ((cofig_Ptr->data_bits & 0x03)<<1);
	UCSRB = (UCSRB & 0xFB) | (cofig_Ptr->data_bits & 0x04);

	/*parity*/
	UCSRC = (UCSRC & 0xCF) | (cofig_Ptr->parity << 4);

	/* stop_bit*/
	UCSRC = (UCSRC & 0xF7) | (cofig_Ptr->stop_bit << 3);

	/*mode*/
	UCSRC = (UCSRC & 0xBF) | (mode_bit << 6);

	UBRRL = BAUD_PRESCALE;
	UBRRH = BAUD_PRESCALE >> 8;
}


void UART_sendByte(uint8 data)
{
	while (BIT_IS_CLEAR(UCSRA ,UDRE)){};
	UDR = data;
}

uint8 UART_recieveByte(void)
{
	while (BIT_IS_CLEAR(UCSRA ,RXC)){};
	return UDR;
}

void UART_sendString(const uint8 *str)
{
	uint8 i = 0;
	while (str[i] != '\0')
	{
		UART_sendByte(str[i]);
		i++;
	}
}

void UART_recieveString(uint8 *str)
{
	uint8 i = 0;
	str[i] = UART_recieveByte();
	while (str[i] != '#')
	{
		i++;
		str[i] = UART_recieveByte();
	}
	str[i] = '\0';
}
