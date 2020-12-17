/**********************************************************************************
 * [FILE NAME]: buzzer.h
 *
 * [AUTHOR]: Toka Zakaria Mohamed Ramadan
 *
 * [DATE CREATED]: Nov 5, 2020
 *
 * [Description]:File of All types Declaration and Functions prototypes of buzzer.
 ***********************************************************************************/
#ifndef BUZZER_H_
#define BUZZER_H_


#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

#define BUZZER_DIRECTION_PORT                 DDRA
#define BUZZER_PIN                             PA0
#define BUZZER_DATA_PORT                     PORTA

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

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

void Buzzer_On(void);

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
void Buzzer_Off(void);




#endif /* BUZZER_H_ */
