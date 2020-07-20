#include <iostream>
#include <new>
#include <cstring>
#include "../Header/Spritz.h"
#include "../Header/Blowfish.h"
#include "../Header/print.h"


void print4 (uchar *input)
{
	Blowfish *B = new(std::nothrow)Blowfish;
	Spritz *S = new(std::nothrow)Spritz;

	uint32_t L, R;

	uchar *cipher = new(std::nothrow)uint8_t[strlen((const char*)input)];
	int len_Spritz_key = strlen((const char*)S->Spritz_key());
	char *key_temp_Spritz = new(std::nothrow)char[len_Spritz_key];
	memcpy (key_temp_Spritz, S->Spritz_key(), len_Spritz_key);

	/* Performing Spritz */

	S->Encrypt ((uchar*)input, key_temp_Spritz, cipher);

	int len_Blowfish_key = strlen((const char*)B->Blowfish_key());
	uchar *key_temp_Blowfish = new(std::nothrow)uchar[len_Blowfish_key];
	memcpy (key_temp_Blowfish, B->Blowfish_key(), len_Blowfish_key);

	B->crack_text (cipher, &L, &R, strlen((const char*)cipher));
	B->Blowfish_Encipher (&L, &R);
	fprintf(stdout,"%08X ", R); // Print the right part first, then the left part of the encrypted message
	fprintf(stdout,"%08X\n\n\n", L);

	delete [ ] key_temp_Spritz;
	delete [ ] key_temp_Blowfish;
	delete [ ] cipher;
	delete S;
	delete B;
}
