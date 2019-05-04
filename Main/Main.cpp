/* Andry RAFAM ANDRIANJAFY - Eagle (April 2019)

OS : Ubuntu 16.04 LTS

GCC : Version 6.5.0

GDB : Version 8.2 */

#include <iostream>
#include <ctime>
#include "../Header/print.h"

#define MAX 2048

int main (void)
{
	system("clear");
	uchar *clear_message = new(std::nothrow)uchar[MAX];

	fprintf(stdout,"\n\t************************************");
	fprintf(stdout,"\n\t\t[ EAGLE ]");	
	fprintf(stdout,"\n\t************************************");
	fprintf(stdout,"\n\n\t [ Input a clear message ] >> ");
	std::cin.get((char*)clear_message,MAX);

	srand(time(NULL));
	int random = rand() % 4;

	if (random == 0)
	{
		fprintf(stdout,"\n\n\t [ ENCRYPTED MESSAGE (Blowfish_RC4A) ] >> ");
		print1 (clear_message);
	}
	else if (random == 1)
	{
		fprintf(stdout,"\n\n\t [ ENCRYPTED MESSAGE (Blowfish_RC4plus) ] >> ");
		print2 (clear_message);
	}
	else if (random == 2)
	{
		fprintf(stdout,"\n\n\t [ ENCRYPTED MESSAGE (Blowfish_VMPC) ] >> ");
		print3 (clear_message);
	}
	else if (random == 3)
	{
		fprintf(stdout, "\n\n\t [ ENCRYPTED MESSAGE (Blowfish_Spritz) ] >> ");
		print4 (clear_message);
	}
	delete [] clear_message;
}
