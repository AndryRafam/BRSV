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

#define MAX 2048

int main (void) {
	system("clear");
	srand(time(0));
	uchar *clear_message = new(std::nothrow)uchar[MAX];
	uchar *salt_message = new(std::nothrow)uchar[6+MAX];

	std::cout << Cyan << "\n\t*******************************************************************" << std::endl;
	std::cout << Red << "\n\t\t\t[ SR-71 (Andry Rafam Andrianjafy) ]" << std::endl;
	std::cout << Cyan << "\n\t*******************************************************************" << std::endl;
	std::cout << Reset;

	std::cout << Yellow << "\n\n\t\t [ Input a clear message ] → "; std::cout << Reset;
	std::cin.get((char*)clear_message,MAX);
	std::random_shuffle(clear_message,clear_message+strlen((const char*)clear_message)); // Shuffle the clear message
	std::cout << Yellow << "\n\n\t\t [ Shuffled clear message ] → " << Reset << clear_message << std::endl;
	OTP (clear_message);
	std::cout << "\n\n\t\t << APPLYING OTP ... DONE >> " << std:: endl;
	strcpy((char*)salt_message,(char*)OTP(clear_message));
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
	delete [] clear_message;
	delete [] salt_message;
}
