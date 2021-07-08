### Password Based Security Door Lock: 
based on 2 ATmeaga16 microcontrollers that communicates using UART protocol, first MCU for human interface machine connected to LCD and Keypad, second MCU for control that handles all the system logic and decision making connected to DC motor “act as door”, External EEPROM “to store password”, and buzzer “to keep privacy in case of theft”
All drivers are implemented using the configurations technique, different design methods used like interrupts, call backs, tight and periodic polling, and software layers for portability and maintainability purpose with high quality and readable code with good comments. 
Drivers designed for the project: Timer, UART, I2C, External EEPROM, LCD, Keypad, DC motor, and buzzer.

![Capture](https://user-images.githubusercontent.com/75904835/124969665-46bbef00-e027-11eb-9ae1-44ece7590c46.PNG)

Sequence of the Application as follow:

- **Step (1)**:
At first time to run the program:
human intrface LCD will ask the user to enter the required password to be saved 2 times using the Keypad
by entering 5 digits of any required character then enter "=" to complete entering password and
never complete it until he enters "="
if the two entered passwords don't match each other it will ask him to repeat the same step 
and enter the password 2 times again, he will never leave this step until he entered matched two passwords.
if the two entered passwords match each other, it will be saved successfully in the external EEPROM 
this step will never be repeated at any time of running the program unless the EEPROM forced to be removed.

- **Step(2)**: 
give the user chance to select his required option from :
1. change password
2. open the door 

- if option 1 is selected:
User will be asked to enter his password,
if the entered paswword matches the original password, it will allow him to enter the new password 
for 2 times and store it in the EEPROM same as Step(1).
- if the entered password doesn't match the original password
it will tell him that is invalid password and ask him to enter it again.
and give him the chance to enter it for certain times, if the entered password was wrong along this attempts
The system will be hold and the buzzer will be opened for some time whie the LCD tell that there is a theif.
after this time the system will restart automatically to return to the main program to select the required option. 

- if option 2 is selected:
User will be asked to enter his password 
if the entered paswword matches the original password, the motor will move on clock wise direction for sometime
to act as the door is opening while the LCD is presenting "Door is opening" , then motor will stop for some time to act 
as the door is open while the LCD is presenting "Door is open now", then the motor will move anti-clock wise for sometime
to act as the door is closed while LCD is presenting "Door is closing", then the motor will stop and LCD will present "Door is closed now"
and the system is being hold during this operation of openning the door.

- if the entered password doesn't match the original password
it will tell him that is invalid password and ask him to enter it again.
and give him the chance to enter it for certain times, if the entered password was wrong along this attempts
The system will be hold and the buzzer will be opened for some time whie the LCD tell that there is a theif.
after this time the system will restart automatically to return to the main program to select the required option. 


