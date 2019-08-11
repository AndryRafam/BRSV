#include <iostream>
#include <new>
#include <cstring>
#include "../../Header/Otp.h"

uchar *OTP (uchar *text) {
	uchar *otp_cipher = new(std::nothrow)uchar[strlen((const char*)text)];
	srand(time(0));
	int *key_gen = new(std::nothrow)int[strlen((const char*)text)];
	
	for (int i = 0; *(text + i); i++) {
		key_gen[i] = rand() % 25 + 1;
		if (isupper(text[i]))
			otp_cipher[i] = char((int(text[i]^key_gen[i])-65)%26+65);
		else if (islower(text[i]))
			otp_cipher[i] = char((int(text[i]^key_gen[i])-97)%26+97);
		else
			otp_cipher[i] = text[i];
	}
	return otp_cipher;
} 
