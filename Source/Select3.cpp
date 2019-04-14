#include <iostream>
#include <new>
#include <cstring>
#include "VMPC.h"
#include "Blowfish.h"
#include "print.h"

using namespace std;

void print3 (uchar *input)
{

	Blowfish *B = new(nothrow)Blowfish;
	VMPC *V = new(nothrow)VMPC;
		
	uint32_t L, R;
	uint64_t C;
	int block_len;
	
	uchar *cipher = new(nothrow)uint8_t[strlen((const char*)input)];
	int len_VMPC_key = strlen((const char*)V->VMPC_key());
	char *key_temp_VMPC = new(nothrow)char[len_VMPC_key];
	memcpy (key_temp_VMPC, V->VMPC_key(), len_VMPC_key);

	/* Performing VMPC */

	V->Encrypt ((uchar*)input, key_temp_VMPC, cipher);
	
	int len_Blowfish_key = strlen((const char*)B->Blowfish_key());
	uchar *key_temp_Blowfish = new(nothrow)uchar[len_Blowfish_key];
	memcpy (key_temp_Blowfish, B->Blowfish_key(), len_Blowfish_key);

	/* Performing Blowfish */
	B->Blowfish_Init (key_temp_Blowfish, len_Blowfish_key);
	B->crack_text (cipher, &L, &R, strlen((const char*)cipher));
	B->Blowfish_Encipher (&L, &R);
	fprintf(stdout,"%08X %08X\n\n\n", R, L); // Print the right part first, then the left part of the encrypted message

	delete [ ] key_temp_VMPC;
	delete [ ] key_temp_Blowfish;
	delete [ ] cipher;
	delete V;
	delete B;

}

