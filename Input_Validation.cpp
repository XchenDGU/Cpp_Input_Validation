#include"Input_Validation.h"

bool isThereNum(std::string str) {
	for (int i = 1; i < (int)str.size(); i++) {
		if (isdigit(str[i]))
			return true;
	}
	return false;
}


bool isThereSpecial(std::string str) {
	for (int i = 1; i < (int)str.size(); i++) {
		if (ispunct(str[i]))
			return true;
	}
	return false;
}

bool isThereAlpha(std::string str) {
	for (int i = 1; i < (int)str.size(); i++) {
		if (isalpha(str[i]) && islower(str[i]))
			return true;
	}
	return false;
}

//**************************************************************
//***************Validating Integer Input******************
//**************************************************************
int Integer_validation1() {
	int number;
	bool invalidInput = true;
	while (invalidInput) {
		std::cout << "Enter the number: ";
		if (std::cin >> number){//Successfully read in an integer
			char c;
			invalidInput = false;
			//Check if there is anything left after reading the integer,only allow spaces
			while (std::cin.get(c) && c != '\n') { 
				if (!isspace(c)){
					std::cout << "ERROR unexpected character '" << c << "' found\n";
					invalidInput = true;
					break;
				}
			}
		}
		else  //Didn't read in a integer
			std::cout << "ERROR reading number\n";
		if (!invalidInput)
			break;
		
		//clear error flag and skips to the next newline
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return number;
}

int Integer_validation2() {
	int num;
	while (true) {
		std::cout << "Enter a number: ";
		char checkNext;
		if (std::cin >> num && (std::cin.get(checkNext) && checkNext == '\n'))
			break;
		else {
			std::cout << "Invalid input, please try again!" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	std::cout << "num = " << num << std::endl;
	return num;
}



//**************************************************************
//***************Validating phone number input******************
//**************************************************************

int Calc_numDigits(unsigned long long int number) {
	int digits = 0;
	while (number >= 1)
	{
		number /= 10;
		digits++;
	}
	return digits;
}


unsigned long long int phone_num_validation(int numDigits) {
	unsigned long long int phone_number;
	bool invalidInput = true;
	while (invalidInput)
	{
		std::cout << "Enter the phone number: ";
		if (std::cin >> phone_number)
		{
			char c;
			invalidInput = false;
			while (std::cin.get(c) && c != '\n') {
				if (!isspace(c))
				{
					std::cout << "ERROR unexpected character '" << c << "' found\n";
					invalidInput = true;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					break;
				}
			}
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "ERROR reading number\n";
			
		}
		
		if (!invalidInput) {
			int digits = Calc_numDigits(phone_number);
			if (digits != numDigits) {
				std::cout << "digits = " << digits;
				std::cout << " Please enter 10 digits of phone number\n";
				invalidInput = true;
			}
			else
				break;
		}
	}
		
	std::cout << "Phone Number : " << phone_number << std::endl;
	return phone_number;
}

unsigned long long int phone_num_validation2(int numDigits) {
	unsigned long long int phone_num;
	while (true) {
		char nextChar;
		std::cout << "Enter the phone number: ";
		if (std::cin >> phone_num && (std::cin.get(nextChar)) && (nextChar == '\n')) {
			if (Calc_numDigits(phone_num) == numDigits)
				break;
			else
				std::cout << "Phone number must be a " << numDigits << " digits number" << std::endl;
		}
		else {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input, please try again!" << std::endl;
		}
		
	}
	std::cout << "phone number = " << phone_num << std::endl;
	return phone_num;
}

//**************************************************************
//***************Validating username and password******************
//**************************************************************
std::string username_validation() {
	static int max_length = 16;
	static int min_length = 8;
	std::string username;
	while (true) {
		std::cout << "Enter the username: ";
		std::getline(std::cin, username);
		if (username.find(' ') != std::string::npos)
			std::cout << "Invalid username:can't contain space \n";
		else if (username.find('\\') != std::string::npos)
			std::cout << "Invalid username:can't have backslash '\\' \n";
		else if ((int)username.size() > max_length|| (int)username.size() < min_length)
			std::cout << "Invalid username:Too short or too long.\n";
		else if (!isalpha(username.front()))
			std::cout << "Invalid username: It must begin with an alphabet letter\n";
		else
			break;
	}
	std::cout << "Username : " << username << std::endl;
	return username;
}


std::string password_validation(){
	static int min_length = 8;
	static int max_length = 16;
	std::string password;
	while (true) {
		std::cout << "Enter the password: ";
		std::getline(std::cin, password);
		if (password.find(' ') != std::string::npos)
			std::cout << "Invalid password:can't have space \n";
		else if (password.find('\\') != std::string::npos)
			std::cout << "Invalid password:can't have backslash '\\' \n";
		else if (!isalpha(password.front()) || !isupper(password.front()))
			std::cout << "Invalid password: It must begin with an uppercase alphabet letter\n";
		else if (!isThereAlpha(password))
			std::cout << "Invalid password:It must has at least one lowercase letter\n";
		else if (!isThereNum(password))
			std::cout << "Invalid password: It must has at least one numerical number\n";
		else if (!isThereSpecial(password))
			std::cout << "Invalid password: It must has at least one special character\n";
		else if ((int)password.size() < 8)
			std::cout << "Invalid password: Too short\n";
		else if ((int)password.size() >= 16)
			std::cout << "Invalid password:Exceed the maximum length \n";
		else
			break;
	}

	std::cout << "password: " << password << std::endl;
	return password;
}
