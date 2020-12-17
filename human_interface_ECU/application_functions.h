/**********************************************************************************
 * [FILE NAME]: application_functions.h
 *
 * [AUTHOR]: Toka Zakaria Mohamed Ramadan
 *
 * [DATE CREATED]: Nov 5, 2020
 *
 * [Description]:File of All types Declaration and Functions prototypes of HMI
 *                ECU configuration.
 *
 *
 ***********************************************************************************/
#ifndef APPLICATION_FUNCTIONS_H_
#define APPLICATION_FUNCTIONS_H_

#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"

#include"keyPad.h"
#include"lcd.h"
#include"uart.h"
#include"timer.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

#define ECU_READY                              0x10
#define FIRST_TIME_TO_LOG_IN                      1

#define ALLOWED_TRIES_TO_ENTER_PASSWORD           3

#define NO_DANGER                                 0

#define MISMATCH                                  1
#define MATCH                                     0

#define START_VALUE                               0
#define COMPARE_VALUE                          8000

#define CHOICE_1                                  1
#define CHOICE_2                                  2

#define INITIAL_VALUE                             0
#define PASSWORD_WIDTH                            5

#define MISMATCH_OCCUR                            1

#define MAXIMUM_SECONDS_ANTI_CLOCKWISE           15
#define MAXIMUM_SECONDS_STOPPING                  5
#define MAXIMUM_SECONDS_CLOCKWISE                15
#define MAXIMUM_SECONDS_BUZZER                   15


#define RESUME_SYSTEM                             0
#define HOLD_SYSTEM                               1


/*******************************************************************************
 *                        External variables                                   *
 *******************************************************************************/


/*
 *array to store the first password entered from the user
 *and to use it to check the matching between it and the
 *second time to enter the password
 */
extern uint8 g_password1[PASSWORD_WIDTH];
/*
 *array to store the second password entered from the user
 *and to use it to check the matching between it and the
 *first time to enter the password
 *use it to also to store the password at any tie in the program
 *use to check if it is the main ADMIN or not
 */
extern uint8 g_password2[PASSWORD_WIDTH];

/*
 * variable to use it in the functions call back in of the timer
 * use it as a counter for seconds
 */
extern uint8 g_tickFlag;

/*
 * variable to use it to hold the system with no work
 * while the door opening and closing
 */
extern uint8 g_holdSystem;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/***************************************************************************************************
 * [Function Name]: password_checkMismatch
 *
 * [Description]:  Function to choose an option from opening the door or changing the password
 *
 * [Args]:
 *
 * [In]            NONE
 *
 * [Out]           unsigned char
 *
 * [Returns]:     the result of the required choice
 ***************************************************************************************************/
uint8 select_Option (void);
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
uint8 password_checkMismatch(uint8* pass1, uint8* pass2);
/***************************************************************************************************
 * [Function Name]: store_Password
 *
 * [Description]:  Function to get the password from the user and store it in array
 *
 * [Args]:         pass
 *
 * [In]            pass: Pointer to character
 *
 * [Out]           NONE
 *
 * [Returns]:      NONE
 ***************************************************************************************************/
void store_Password(uint8 *pass);
/***************************************************************************************************
 * [Function Name]: start_System
 *
 * [Description]:  Function to start the system for the first time
 *                 -Display welcome message for user
 *                 -Ask him to enter the password 2 times
 *                 -store the two passwords in two separate arrays
 * [Args]:         NONE
 *
 * [In]            NONE
 *
 * [Out]           NONE
 *
 * [Returns]:      NONE
 ***************************************************************************************************/
void start_System(void);

/***************************************************************************************************
 * [Function Name]: timerMoving_Anti_Clockwise
 *
 * [Description]:  Function to make LCD tell the user that the door is closing.
 *
 * [Args]:         NONE
 *
 * [In]            NONE
 *
 * [Out]           NONE
 *
 * [Returns]:      NONE
 ***************************************************************************************************/
void timerMoving_Anti_Clockwise(void);
/***************************************************************************************************
 * [Function Name]: timerStopping
 *
 * [Description]:  Function to tell the user the door is opening for some time
 *
 * [Args]:         NONE
 *
 * [In]            NONE
 *
 * [Out]           NONE
 *
 * [Returns]:      NONE
 ***************************************************************************************************/
void timerStopping(void);
/***************************************************************************************************
 * [Function Name]: timerMoving_Anti_Clockwise
 *
 * [Description]:  Function to make LCD tell the user that the door is opening.
 *
 * [Args]:         NONE
 *
 * [In]            NONE
 *
 * [Out]           NONE
 *
 * [Returns]:      NONE
 ***************************************************************************************************/
void timerMoving_Clockwise(void);
/*********************************************************************************************************
 * [Function Name]: timerDanger
 *
 * [Description]:  Function to tell the hacking person he is thief
 *
 * [Args]:         NONE
 *
 * [In]            NONE
 *
 * [Out]           NONE
 *
 * [Returns]:      NONE
 *****************************************************************************************************/
void timerDanger(void);






#endif /* APPLICATION_FUNCTIONS_H_ */
