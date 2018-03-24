#include<stdlib.h>
#include<iostream>
#include<string>
#include<sstream>
#include<ctype.h>

/*Check if there is numerical number in the string*/
bool isThereNum(std::string str);

/*Check if there is special character in the string*/
bool isThereSpecial(std::string str);

/*Check if there is alphebet letter in the string*/
bool isThereAlpha(std::string str);

/*Loop until user inputs a valid integer(Only allow empty space after the integer)*/
int Integer_validation1();

/*Same as above but don't allow empty space after*/
int Integer_validation2();

/*Calculate number of digits a numerical number had*/
int Calc_numDigits(unsigned long long int number);

/*Loop until user inputs a valid phone number(Do allow space after)*/
unsigned long long int phone_num_validation(int numDigits);

/*Same as above, but no space allowed after it*/
unsigned long long int phone_num_validation2(int numDigits);

/*-No space and backslash are allowed.
-Username:length <=16,must begin with an aphabet letter
-Password:length between 8 to 16 characters,must begin with a capital letter and
must contain at least one lower case letter,one numeric number, and one special character.*/
std::string username_validation();
std::string password_validation();