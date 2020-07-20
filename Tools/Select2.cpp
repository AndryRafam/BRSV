#include <iostream>
#include <new>
#include <cstring>
#include "../Header/RC4plus.h"
#include "../Header/Blowfish.h"
#include "../Header/print.h"


void print2 (uchar *input)
{
	Blowfish *B = new(std::nothrow)Blowfish;
	RC4plus *Rplus = new(std::nothrow)RC4plus;

	uint32_t L, R;

	uchar *cipher = new(std::nothrow)uint8_t[strlen((const char*)input)];
	int len_RC4plus_key = strlen((const char*)Rplus->RC4plus_key());
	char *key_temp_RC4plus = new(std::nothrow)char[len_RC4plus_key];
	memcpy (key_temp_RC4plus, Rplus->RC4plus_key(), len_RC4plus_key);

	/* Performing RC4plus */

	Rplus->Encrypt ((uchar*)input, key_temp_RC4plus, cipher);

	int len_Blowfish_key = strlen((const char*)B->Blowfish_key());
	uchar *key_temp_Blowfish = new(std::nothrow)uchar[len_Blowfish_key];
	memcpy (key_temp_Blowfish, B->Blowfish_key(), len_Blowfish_key);

	/* Performing Blowfish */
	B->Blowfish_Init (key_temp_Blowfish, len_Blowfish_key);
	B->crack_text (cipher, &L, &R, strlen((const char*)cipher));
	B->Blowfish_Encipher (&L, &R);
	fprintf(stdout,"%08X ", R); // Print the right part first, then the left part of the encrypted message
	fprintf(stdout,"%08X\n\n\n ", L);

	delete [ ] key_temp_RC4plus;
	delete [ ] key_temp_Blowfish;
	delete [ ] cipher;
	delete Rplus;
	delete B;

}
