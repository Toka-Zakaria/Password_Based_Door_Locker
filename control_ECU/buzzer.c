/**********************************************************************************
 * [FILE NAME]: buzzer.c
 *
 * [AUTHOR]: Toka Zakaria Mohamed Ramadan
 *
 * [DATE CREATED]: Nov 5, 2020
 *
 * [Description]: Functions will be used to work with buzzer.
 *
 ***********************************************************************************/
#include"buzzer.h"

/********************************************************************************
 * [Function Name]: Buzzer_On
 *
 * [Description]:  Function to turn on the buzzer
 *
 * [Args]:         NONE
 *
 * [In]            NONE
 *
 * [Out]           NONE
 *
 * [Returns]:      NONE
 *******************************************************************************/
void Buzzer_On(void)
{
	/*
	 * put 1 on the bit of buzzer_port
	 */
	SET_BIT(BUZZER_DATA_PORT , BUZZER_PIN );

}/*end of function buzzer_on*/


/********************************************************************************
 * [Function Name]: Buzzer_Off
 *
 * [Description]:  Function to turn off the buzzer
 *
 * [Args]:         NONE
 *
 * [In]            NONE
 *
 * [Out]           NONE
 *
 * [Returns]:      NONE
 *******************************************************************************/
void Buzzer_Off(void)
{
	/*
	 * put 0 on the bit of buzzer_port
	 */
	CLEAR_BIT(BUZZER_DATA_PORT , BUZZER_PIN);

}/*end of function buzzer_off*/
