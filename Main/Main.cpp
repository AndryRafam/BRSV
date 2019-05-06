/* Andry RAFAM ANDRIANJAFY - Eagle April 2019 (Updated May 2019)

OS : Ubuntu 16.04 LTS

GCC : Version 6.5.0

GDB : Version 8.2 */

#include <iostream>
#include <ctime>
#include <cstring>
#include "../Header/print.h"

#define MAX 2048

int main (void)
{
	system("clear");
	uchar *clear_message = new(std::nothrow)uchar[MAX];
	uchar *salt_message = new(std::nothrow)uchar[6+MAX];
	
	std::cout << "\n\t*******************************************************************" << std::endl;
	std::cout << "\n\t\t[ EAGLE Encryption Program (Andry Rafam Andrianjafy ]" << std::endl;	
	std::cout << "\n\t*******************************************************************" << std::endl;
	
	std::cout << "\n\n\t [ Input a clear message ] >> ";
	std::cin.get((char*)clear_message,MAX);
	strcpy((char*)salt_message,(char*)clear_message);
	strcat((char*)salt_message,(char*)Salt());
	std::cout << "\n\n\t [ Your salt message ] >> " << salt_message << std::endl;

	srand(time(NULL));
	int random = rand() % 4;

	if (random == 0)
	{
		fprintf(stdout,"\n\n\t [ ENCRYPTED MESSAGE (Blowfish_RC4A) ] >> ");
		print1 (salt_message);
	}
	else if (random == 1)
	{
		fprintf(stdout,"\n\n\t [ ENCRYPTED MESSAGE (Blowfish_RC4plus) ] >> ");
		print2 (salt_message);
	}
	else if (random == 2)
	{
		fprintf(stdout,"\n\n\t [ ENCRYPTED MESSAGE (Blowfish_VMPC) ] >> ");
		print3 (salt_message);
	}
	else if (random == 3)
	{
		fprintf(stdout, "\n\n\t [ ENCRYPTED MESSAGE (Blowfish_Spritz) ] >> ");
		print4 (salt_message);
	}
	delete [] clear_message;
	delete [] salt_message;
}

