#include <iostream>
#include <new>
#include <cstring>
#include "Spritz.h"
#include "Blowfish.h"
#include "print.h"

using namespace std;

void print4 (uchar *input)
{
	Blowfish *B = new(nothrow)Blowfish;
	Spritz *S = new(nothrow)Spritz;

	uint32_t L, R;
	uint64_t C;
	int block_len;

	uchar *cipher = new(nothrow)uint8_t[strlen((const char*)input)];
	int len_Spritz_key = strlen((const char*)S->Spritz_key());
	char *key_temp_Spritz = new(nothrow)char[len_Spritz_key];
	memcpy (key_temp_Spritz, S->Spritz_key(), len_Spritz_key);

	/* Performing Spritz */

	S->Encrypt ((uchar*)input, key_temp_Spritz, cipher);
	
	int len_Blowfish_key = strlen((const char*)B->Blowfish_key());
	uchar *key_temp_Blowfish = new(nothrow)uchar[len_Blowfish_key];
	memcpy (key_temp_Blowfish, B->Blowfish_key(), len_Blowfish_key);

	B->crack_text (cipher, &L, &R, strlen((const char*)cipher));
	B->Blowfish_Encipher (&L, &R);
	fprintf(stdout, "%08X %08X\n\n\n", R, L); // Print the right part first, then the left part of the encrypted message

	delete [ ] key_temp_Spritz;
	delete [ ] key_temp_Blowfish;
	delete [ ] cipher;
	delete S;
	delete B;
}
