#include <iostream>
#include "../Header/print.h"
#include "../Header/Colors.h"

void about(){
	std::cout << Cyan << "\n\t*******************************************************************" << std::endl;
	std::cout << Red << "\n\t\t\t[ Epsilon (Andry Rafam Andrianjafy) ]" << std::endl;
	std::cout << Reset;
	std::cout << "\n\n\t\t Double random encryption program. The program choose"  << std::endl;
	std::cout << "\t\t randomly a twin combination between the following" << std::endl; 
	std::cout << "\t\t encrytpion algorithm: Blowfish, RC4A, RC4plus, VMPC, Spritz." << std::endl;
	std::cout << "\t\t Only the final result is outputted. Intermediate stage are not outputted.";
	std::cout << Cyan << "\n\n\t*******************************************************************" << std::endl;
	std::cout << Reset;
}

