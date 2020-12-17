/**********************************************************************************
 * [FILE NAME]: application_functions.c
 *
 * [AUTHOR]: Toka Zakaria Mohamed Ramadan
 *
 * [DATE CREATED]: Nov 5, 2020
 *
 * [Description]: Functions will be used in the Applications in control ECU.
 *
 ***********************************************************************************/

#include"application_functions.h"



/************************************************************************************************
 *                                    Application_Functions
 ************************************************************************************************/

/***************************************************************************************************
 * [Function Name]: password_checkMismatch
 *
 * [Description]:  Function to check if the two passwords equal
 *                 or not.
 *
 * [Args]:         pass1, pass2
 *
 * [In]            pass1: Pointer to character
 *                 pass2: Pointer to character
 *
 * [Out]           unsigned char
 *
 * [Returns]:     the result of the comparing the two passwords
 ***************************************************************************************************/
uint8 password_checkMismatch(uint8* pass1, uint8* pass2)
{
	/*
	 * local variable to use it as a counter for the loop
	 */
	uint8 count;
	/*
	 * local variable to use it to check the mismatch
	 * between the two entered password
	 * give it initial value assuming no mismatch happen at first
	 */
	uint8 mismatch=0;

	/*
	 * for loop to check the matching or not
	 * to pass on the two passwords entered digit by digit
	 * to find the mismatch in any digit
	 */

	for(count=INITIAL_VALUE; count<PASSWORD_WIDTH; count++)
	{
		if( pass1[count] != pass2[count] )
		{
			/*
			 * change the value of the mismatch if any two digits
			 * are not equal
			 */
			mismatch = MISMATCH_OCCUR;

			/*
			 * change the value of the counter to another value
			 * value larger than the no of iteration to exit from the loop
			 * there is no need to complete the loop after finding difference in one digit
			 */
			count= PASSWORD_WIDTH;

		}/*End of compare passwords*/

	}/*End of for loop of mismatching*/

	/*
	 * return the final value of the mismatch variable to the original application
	 */
	return mismatch;

}/*End of check_Mismatch function*/
/*************************************************************************************************/


/************************************************************************************************
 *                                    TimerCallBack_Functions
 ************************************************************************************************/


/***************************************************************************************************
 * [Function Name]: timerMoving_Anti_Clockwise
 *
 * [Description]:  Function to increment the a counter for certain number of seconds
 *                 to keep the motor moving on Anti-ClockWise direction until these
 *                 seconds finish. it act as the door of the system is closing for
 *                 some time.after it has finished, it would return the counter and timer
 *                 to initial value, call function to force the motor to stop and
 *                 resumes the system again to allow it to restart after holding this time.
 *
 *
 * [Args]:         NONE
 *
 * [In]            NONE
 *
 * [Out]           NONE
 *
 * [Returns]:      NONE
 ***************************************************************************************************/
void timerMoving_Anti_Clockwise(void)
{
	/*
	 * increment the value of the global variable
	 * every increase of it means that an interrupt of the occurs
	 * every increase of it mans 1 second has passed
	 */
	g_tickFlag++;

	/*
	 * As long as g_tickFlag smaller than the value of maximum seconds
	 * the MOTOR is remaining to moving in the same direction
	 */
	if( g_tickFlag < MAXIMUM_SECONDS_ANTI_CLOCKWISE)
	{
		/*
		 * call the function of motor_onAnti_ClockWise
		 * to make the motor move in Anti clock wise direction
		 */
		motor_onAnti_ClockWise();
	}/*End of if condition*/

	/*
	 * As long as g_tickFlag reaches the maximum value of seconds
	 * so the MOTOR will stop moving
	 */
	else if(g_tickFlag == MAXIMUM_SECONDS_ANTI_CLOCKWISE)
	{
		/*
		 *DE-initialization of all the register of the timer
		 *to be ready for another interrupts occur
		 */
		Timer_DeInit(Timer1);

		/*
		 * call the function of motor_on_Stop
		 * to force the motor to return on its initial value
		 * in stopping state
		 */
		motor_on_Stop();
		/*
		 * return the initial value of the global flag
		 * to be ready for another interrupt occur
		 */
		g_tickFlag= 0;
		/*
		 * change the value of g_holdSystem variable to
		 * log out from the polling on the time interrupt
		 * and return to the remain parts of the application
		 */
		g_holdSystem = RESUME_SYSTEM;

	}/*End of else if condition*/

}/*end of timerMoving_Anti_Clockwise function*/
/**************************************************************************************************/

/***************************************************************************************************
 * [Function Name]: timerStopping
 *
 * [Description]:  Function to hold the motor stopped for some time, indicate to the door
 *                 is open, after time has finished, it would call another function to force it
 *                 to move in Anti-ClockWise direction and return the counter to initial value
 *
 * [Args]:         NONE
 *
 * [In]            NONE
 *
 * [Out]           NONE
 *
 * [Returns]:      NONE
 ***************************************************************************************************/
void timerStopping(void)
{
	/*
	 * increment the value of the global variable
	 * every increase of it means that an interrupt of the occurs
	 * every increase of it mans 1 second has passed
	 */
	g_tickFlag++;

	/*
	 * As long as g_tickFlag smaller than the value of maximum seconds
	 * the MOTOR is remaining to be in stop case
	 */
	if( g_tickFlag < MAXIMUM_SECONDS_STOPPING)
	{
		/*
		 * call the function of motor_on_Stop
		 * to force the motor to stop
		 */
		motor_on_Stop();
	}/*End of if condition*/

	/*
	 * As long as g_tickFlag reaches the maximum value of seconds
	 * so the LCD will stop displaying the message
	 */
	else if(g_tickFlag == MAXIMUM_SECONDS_STOPPING)
	{

		/*
		 * return the initial value of the global flag
		 * to be ready for another interrupt occur
		 */
		g_tickFlag=0;

		/*
		 * change the address of the function that the timer's ISR
		 * will call after every interrupt to be the address of
		 * the timerMoving_Anti_Clockwise function to make the
		 * door moving on anti clock wise direction after stopping
		 */
		Timer_setCallBack(timerMoving_Anti_Clockwise, Timer1);
	}/*End of else if condition*/

}/*End of timerStopping function*/
/***************************************************************************************************/


/***************************************************************************************************
 * [Function Name]: timerMoving_Clockwise
 *
 * [Description]:  Function to increment the a counter for certain number of seconds
 *                 to keep the motor moving on ClockWise direction until these
 *                 seconds finish. it act as the door of the system is opening for
 *                 some time.
 *
 * [Args]:         NONE
 *
 * [In]            NONE
 *
 * [Out]           NONE
 *
 * [Returns]:      NONE
 ***************************************************************************************************/
void timerMoving_Clockwise(void)
{
	/*
	 * to keep the system into polling to prevent it from doing
	 *  any thing until the operation of open door ends
	 */
	g_tickFlag++;
	/*
	 * As long as g_tickFlag smaller than the value of maximum seconds
	 * the MOTOR is remaining to moving in the same direction
	 */
	if( g_tickFlag < MAXIMUM_SECONDS_CLOCKWISE)
	{
		/*
		 * call the function of motor_on_CLOCKWISE to
		 * force the motor to move in clock wise direction
		 */
		motor_on_ClockWise();
	}/*end of if condition*/
	/*
	 * As long as g_tickFlag reaches the maximum value of seconds
	 * so the LCD will stop displaying the message
	 */
	else if(g_tickFlag == MAXIMUM_SECONDS_CLOCKWISE)
	{
		/*
		 * return the initial value of the global flag
		 * to be ready for another interrupt occur
		 */
		g_tickFlag=0;

		/*
		 * change the address of the function that the timer's ISR
		 * will call after every interrupt to be the address of
		 * the timerMoving_Anti_Clockwise function to make the
		 * door moving on anti clock wise direction after stopping
		 */
		Timer_setCallBack(timerStopping, Timer1);

	}/*End of else if condition*/

}/*end of timerMoving_Clockwise function*/
/*********************************************************************************************************/

/*********************************************************************************************************
 * [Function Name]: timerDanger
 *
 * [Description]:  Function to increment the counter to keep the Buzzer working
 *                 for some time and , after the time passed it stopped the buzzer,return counter
 *                 to initial value to be ready for any buzzer state occur and
 *                 resumes the system again to allow it to restart after holding this time,
 *                 and return the timer to default again.
 *
 *
 * [Args]:         NONE
 *
 * [In]            NONE
 *
 * [Out]           NONE
 *
 * [Returns]:      NONE
 *****************************************************************************************************/
void timerDanger(void)
{
	/*
	 * to keep the system into polling to prevent it from doing
	 *  any thing until the operation of open door ends
	 */
	g_tickFlag++;

	/*
	 * As long as g_tickFlag smaller than the value of maximum seconds
	 * the BUZZER is remaining to give sound
	 */
	if( g_tickFlag < MAXIMUM_SECONDS_BUZZER)
	{
		/*
		 * turn on the buzzer
		 */
		Buzzer_On();


	}/*End of if condition*/

	/*
	 * As long as g_tickFlag reaches the maximum value of seconds
	 * so the BUZZER will stop giving sound
	 */
	else if(g_tickFlag == MAXIMUM_SECONDS_BUZZER )
	{
		/*
		 * turn off the buzzer
		 */

		Buzzer_Off();
		/*
		 * change the mode of the timer to return to the
		 * initial state for all registers
		 */
		Timer_DeInit(Timer1);
		/*
		 * return the initial value of the global flag
		 * to be ready for another interrupt occur
		 */
		g_tickFlag=0;

		/*
		 * change the value of g_holdSystem variable to
		 * log out from the polling on the time interrupt
		 * and return to the remain parts of the application
		 */
		g_holdSystem= RESUME_SYSTEM;

	}/*end of else if condition*/

}/*End of timeDanger Function*/

/****************************************************************************************************/
