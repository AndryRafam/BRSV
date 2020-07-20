/* Andry RAFAM ANDRIANJAFY - Epsilon

OS : Xubuntu 20.04 LTS

Compiler : Version 9.3

GDB : Version 9.1 */

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
	
	// Fisher-Yates shuffle algorithm. Shuffle the clear message
	for(int i = strlen((const char*)args[1]-1); i > 0; i--){
		int j = rand()%(i+1);
		std::swap(args[1][i],args[1][j]);
	}
	
	OTP ((uchar*)args[1]);
	strcpy((char*)salt_message,(char*)OTP((uchar*)args[1]));
	strcat((char*)salt_message,(char*)Salt());
	
	// Fisher-Yates shuffle algorithm. Shuffle the salt message
	for(int i = strlen((const char*)salt_message)-1; i > 0; i--){
		int j = rand()%(i+1);
		std::swap(salt_message[i],salt_message[j]);
	}
	
	std::cout << "\n\n\t\t << INTERMEDIATE STAGE ... COMPLETED >> " << std::endl;
	
	srand(time(0));
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
