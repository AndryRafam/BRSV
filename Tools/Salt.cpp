#include <iostream>
#include <new>
#include <ctime>
#include "../Header/print.h"

typedef unsigned char uchar;

uchar *Salt() {
	
	uchar *string = new(std::nothrow)uchar[16];
	srand(time(0));
	int i = 0;

	while (i < 16) {
		int random = rand() % 2;
		int key = rand() % 26;

		if (random == 0)
			string[i] = (char)((key-65) % 26 + 65);
		else if (random == 1)
			string[i] = (char)((key-97) % 26 + 97);
		i += 1;
	}
	return string;
}
