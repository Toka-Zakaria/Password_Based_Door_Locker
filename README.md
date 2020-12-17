# Password_Based_Door_Locker
Password Based Security Door Lock based on 2 ATmega16 microcontrollers,
one for human interfacing connected to LCD to display messages and Keypad to enter password and select options,
The other one connected DC motor act as a door, 
external EEPROM to store password in it and buzzer to use it if the entered password was wrong for several times.

Sequence of the Application as follow:

Step (1)
At first time to run the program:
human intrface LCD will ask the user to enter the required password to be saved 2 times using the Keypad
by entering 5 digits of any required character then enter "=" to complete entering password and
never complete it until he enters "="
if the two entered passwords don't match each other it will ask him to repeat the same step 
and enter the password 2 times again, he will never leave this step until he entered matched two passwords.
if the two entered passwords match each other, it will be saved successfully in the external EEPROM 
this step will never be repeated at any time of running the program unless the EEPROM forced to be removed.

Step(2) 
give the user chance to select his required option from :
1- change password
2- open the door 

if option 1 is selected:
User will be asked to enter his password,
if the entered paswword matches the original password, it will allow him to enter the new password 
for 2 times and store it in the EEPROM same as Step(1).
if the entered password doesn't match the original password
it will tell him that is invalid password and ask him to enter it again.
and give him the chance to enter it for certain times, if the entered password was wrong along this attempts
The system will be hold and the buzzer will be opened for some time whie the LCD tell that there is a theif.
after this time the system will restart automatically to return to the main program to select the required option. 


if option 2 is selected:
User will be asked to enter his password 
if the entered paswword matches the original password, the motor will move on clock wise direction for sometime
to act as the door is opening while the LCD is presenting "Door is opening" , then motor will stop for some time to act 
as the door is open while the LCD is presenting "Door is open now", then the motor will move anti-clock wise for sometime
to act as the door is closed while LCD is presenting "Door is closing", then the motor will stop and LCD will present "Door is closed now"
and the system is being hold during this operation of openning the door.

if the entered password doesn't match the original password
it will tell him that is invalid password and ask him to enter it again.
and give him the chance to enter it for certain times, if the entered password was wrong along this attempts
The system will be hold and the buzzer will be opened for some time whie the LCD tell that there is a theif.
after this time the system will restart automatically to return to the main program to select the required option. 


