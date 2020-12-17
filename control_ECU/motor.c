/**********************************************************************************
 * [FILE NAME]: motor.c
 *
 * [AUTHOR]: Toka Zakaria Mohamed Ramadan
 *
 * [DATE CREATED]: Nov 5, 2020
 *
 * [Description]: Functions will be used to work with DC motor.
 *
 ***********************************************************************************/

#include"motor.h"


/***************************************************************************************************
 * [Function Name]: motor_on_ClockWise
 *
 * [Description]:  Function to make the motor move on clockwise direction
 *
 * [Args]:         NONE
 *
 * [In]            NONE
 *
 * [Out]           NONE
 *
 * [Returns]:      NONE
 ***************************************************************************************************/

void motor_on_ClockWise(void)
{
	MOTOR_DATA_PORT = CLEAR_BIT(MOTOR_DATA_PORT , MOTOR_PIN_IN1);
	MOTOR_DATA_PORT = SET_BIT(MOTOR_DATA_PORT , MOTOR_PIN_IN2);

}/*End of motor_onClockWise*/

/***************************************************************************************************
 * [Function Name]: motor_on_AntiClockWise
 *
 * [Description]:  Function to make the motor move on  Anti clockwise direction
 *
 * [Args]:         NONE
 *
 * [In]            NONE
 *
 * [Out]           NONE
 *
 * [Returns]:      NONE
 ***************************************************************************************************/

void motor_onAnti_ClockWise(void)
{
	MOTOR_DATA_PORT = CLEAR_BIT( MOTOR_DATA_PORT, MOTOR_PIN_IN2);
	MOTOR_DATA_PORT = SET_BIT (MOTOR_DATA_PORT, MOTOR_PIN_IN1);

}/*End of motor_onClockWise*/

/***************************************************************************************************
 * [Function Name]: motor_on_ClockWise
 *
 * [Description]:  Function to make the motor stop moving.
 *
 * [Args]:         NONE
 *
 * [In]            NONE
 *
 * [Out]           NONE
 *
 * [Returns]:      NONE
 ***************************************************************************************************/
void motor_on_Stop(void)
{
	MOTOR_DATA_PORT = CLEAR_BIT(MOTOR_DATA_PORT , MOTOR_PIN_IN2);
	MOTOR_DATA_PORT = CLEAR_BIT( MOTOR_DATA_PORT, MOTOR_PIN_IN1);

}/*End of motor_onClockWise*/
/**************************************************************************************************/
