/* Andry RAFAM ANDRIANJAFY - Epsilon

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
	uchar *salt_message = new(std::nothrow)uchar[16+strlen((const char*)args[1])];
	about();
	std::cout << Yellow << "\n\n\t\t [ Clear message ] → " << Reset << args[1] << std::endl;

	/* Intermediate Stage */
	std::random_shuffle(args[1],args[1]+strlen((const char*)args[1])); // Shuffle the clear message
	OTP ((uchar*)args[1]);
	strcpy((char*)salt_message,(char*)OTP((uchar*)args[1]));
	strcat((char*)salt_message,(char*)Salt());
	std::random_shuffle(salt_message,salt_message+strlen((const char*)salt_message)); // Shuffle the salt message
	std::cout << "\n\n\t\t << INTERMEDIATE STAGE ... COMPLETED >> " << std::endl;

	srand(time(NULL));
	int random = rand() % 10+1;

	switch(random) {
		case 1:
			std::cout << Green << "\n\n\t\t [ ENCRYPTED MESSAGE ] → "; std::cout << Reset;
			print1 (salt_message); std::cout << Reset;
			break;

		case 2:
			std::cout << Green << "\n\n\t\t [ ENCRYPTED MESSAGE ] → "; std::cout << Reset;
			print2 (salt_message); std::cout << Reset;
			break;

		case 3:
			std::cout << Green << "\n\n\t\t [ ENCRYPTED MESSAGE ] → "; std::cout << Reset;
			print3 (salt_message); std::cout << Reset;
			break;

		case 4:
			std::cout << Green << "\n\n\t\t [ ENCRYPTED MESSAGE ] → "; std::cout << Reset;
			print4 (salt_message); std::cout << Reset;
			break;

		case 5:
			std::cout << Green << "\n\n\t\t [ ENCRYPTED MESSAGE ] → "; std::cout << Reset;
			print5 (salt_message); std::cout << Reset;
			break;

		case 6:
			std::cout << Green << "\n\n\t\t [ ENCRYPTED MESSAGE ] → "; std::cout << Reset;
			print6 (salt_message); std::cout << Reset;
			break;

		case 7:
			std::cout << Green << "\n\n\t\t [ ENCRYPTED MESSAGE ] → "; std::cout << Reset;
			print7 (salt_message); std::cout << Reset;
			break;

		case 8:
			std::cout << Green << "\n\n\t\t [ ENCRYPTED MESSAGE ] → "; std::cout << Reset;
			print8 (salt_message); std::cout << Reset;
			break;

		case 9:
			std::cout << Green << "\n\n\t\t [ ENCRYPTED MESSAGE ] → "; std::cout << Reset;
			print9 (salt_message); std::cout << Reset;
			break;

		case 10:
			std::cout << Green << "\n\n\t\t [ ENCRYPTED MESSAGE ] → "; std::cout << Reset;
			print10 (salt_message); std::cout << Reset;
			break;
	delete [] salt_message;
	}
	return 0;
}
