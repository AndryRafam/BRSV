/* Andry RAFAM ANDRIANJAFY - SR-71

OS : Ubuntu 16.04 LTS

GCC : Version 6.5.0

GDB : Version 8.2 */

#include <iostream>
#include <ctime>
#include <cstring>
#include <algorithm>
#include "../Header/print.h"
#include "../Header/Otp.h"
#include "../Header/Colors.h"


int main (int argc, char **args) {
	if (argc != 2){
		std::cout << "\n";
		std::cout << "Usage : " << args[0] << Red << " < Clear message within coma > " << std::endl;
		std::cout << Reset;
		std::cout << "\n";
		exit(0);
	}
	system("clear");
	srand(time(0));
	uchar *salt_message = new(std::nothrow)uchar[6+strlen((const char*)args[1])];

	std::cout << Cyan << "\n\t*******************************************************************" << std::endl;
	std::cout << Red << "\n\t\t\t[ CastleBravo (Andry Rafam Andrianjafy) ]" << std::endl;
	std::cout << Cyan << "\n\t*******************************************************************" << std::endl;
	std::cout << Reset;

	std::cout << Yellow << "\n\n\t\t [ Clear message ] → " << Reset << args[1] << std::endl;
	std::random_shuffle(args[1],args[1]+strlen((const char*)args[1])); // Shuffle the clear message
	std::cout << Yellow << "\n\n\t\t [ Shuffled clear message ] → " << Reset << args[1] << std::endl;
	OTP ((uchar*)args[1]);
	std::cout << "\n\n\t\t << APPLYING OTP ... DONE >> " << std:: endl;
	strcpy((char*)salt_message,(char*)OTP((uchar*)args[1]));
	strcat((char*)salt_message,(char*)Salt()); // Shuffle the salt message
	std::random_shuffle(salt_message,salt_message+strlen((const char*)salt_message));
	std::cout << "\n\n\t\t << SALTING MESSAGE ... DONE >> " << std::endl;

	srand(time(NULL));
	int random = rand() % 4;

	if (random == 0) {
		std::cout << Green << "\n\n\t\t [ ENCRYPTED MESSAGE (Blowfish_RC4A) ]"; std::cout << Reset;
		print1 (salt_message); std::cout << Reset;
	}
	else if (random == 1) {
		std::cout << Green << "\n\n\t\t [ ENCRYPTED MESSAGE (Blowfish_RC4plus) ]"; std::cout << Reset;
		print2 (salt_message); std::cout << Reset;
	}
	else if (random == 2) {
		std::cout << Green << "\n\n\t\t [ ENCRYPTED MESSAGE (Blowfish_VMPC) ]"; std::cout << Reset;
		print3 (salt_message); std::cout << Reset;
	}
	else if (random == 3) {
		std::cout << Green << "\n\n\t\t [ ENCRYPTED MESSAGE (Blowfish_Spritz) ]"; std::cout << Reset;
		print4 (salt_message); std::cout << Reset;
	}
	delete [] salt_message;
}
