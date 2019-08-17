#include <iostream>
#include <new>
#include <cstring>
#include "../Header/RC4A.h"
#include "../Header/Blowfish.h"
#include "../Header/print.h"


void print1 (uchar *input)
{
	Blowfish *B = new(std::nothrow)Blowfish;
	RC4A *RA = new(std::nothrow)RC4A;

	uint32_t L, R;

	uchar *cipher = new(std::nothrow)uint8_t[strlen((const char*)input)];
	int len_RC4A_key = strlen((const char*)RA->RC4A_key());
	char *key_temp_RC4A = new(std::nothrow)char[len_RC4A_key];
	memcpy (key_temp_RC4A, RA->RC4A_key(), len_RC4A_key);

	/* Performing RC4A */

	RA->Encrypt ((uchar*)input, key_temp_RC4A, cipher);

	int len_Blowfish_key = strlen((const char*)B->Blowfish_key());
	uchar *key_temp_Blowfish = new(std::nothrow)uchar[len_Blowfish_key];
	memcpy (key_temp_Blowfish, B->Blowfish_key(), len_Blowfish_key);

	/* Performing Blowfish */
	B->Blowfish_Init (key_temp_Blowfish, len_Blowfish_key);
	B->crack_text (cipher, &L, &R, strlen((const char*)cipher));
	B->Blowfish_Encipher (&L, &R);
	fprintf(stdout,"%08X\n ", R); // Print the right part first, then the left part of the encrypted message
	fprintf(stdout,"\t\t\t\t\t %08X\n\n\n ", L);

	delete [ ] key_temp_RC4A;
	delete [ ] key_temp_Blowfish;
	delete [ ] cipher;
	delete RA;
	delete B;
}

