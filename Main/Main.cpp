/* Andry RAFAM ANDRIANJAFY - Eagle April 2019 (Updated May 2019)

OS : Ubuntu 16.04 LTS

GCC : Version 6.5.0

GDB : Version 8.2 */

#include <iostream>
#include <ctime>
#include <cstring>
#include <algorithm>
#include "../Header/print.h"
#include "../Header/Otp.h"

#define MAX 2048

int main (void) {
	system("clear");
	srand(time(0));
	uchar *clear_message = new(std::nothrow)uchar[MAX];
	uchar *salt_message = new(std::nothrow)uchar[6+MAX];
	
	std::cout << "\n\t*******************************************************************" << std::endl;
	std::cout << "\n\t\t[ Tomahawk (Andry Rafam Andrianjafy ]" << std::endl;	
	std::cout << "\n\t*******************************************************************" << std::endl;
	
	std::cout << "\n\n\t [ Input a clear message ] → ";
	std::cin.get((char*)clear_message,MAX);
	std::random_shuffle(clear_message,clear_message+strlen((const char*)clear_message)); // Shuffle the clear message
	std::cout << "\n\n\t [ Shuffled clear message ] → " << clear_message << std::endl;
	OTP (clear_message);
	std::cout << "\n\n\t << APPLYING OTP ... DONE >> " << std:: endl;
	strcpy((char*)salt_message,(char*)OTP(clear_message));
	strcat((char*)salt_message,(char*)Salt());
	std::random_shuffle(salt_message,salt_message+strlen((const char*)salt_message)); // Shuffle the salt message
	std::cout << "\n\n\t << SALTING MESSAGE ... DONE >> " << std::endl;

	srand(time(NULL));
	int random = rand() % 4;

	if (random == 0) {
		fprintf(stdout,"\n\n\t [ ENCRYPTED MESSAGE (Blowfish_RC4A) ] → ");
		print1 (salt_message);
	}
	else if (random == 1) {
		fprintf(stdout,"\n\n\t [ ENCRYPTED MESSAGE (Blowfish_RC4plus) ] → ");
		print2 (salt_message);
	}
	else if (random == 2) {
		fprintf(stdout,"\n\n\t [ ENCRYPTED MESSAGE (Blowfish_VMPC) ] → ");
		print3 (salt_message);
	}
	else if (random == 3) {
		fprintf(stdout, "\n\n\t [ ENCRYPTED MESSAGE (Blowfish_Spritz) ] → ");
		print4 (salt_message);
	}
	delete [] clear_message;
	delete [] salt_message;
}

