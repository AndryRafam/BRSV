#include <iostream>
#include <new>
#include <cstring>
#include "../Header/VMPC.h"
#include "../Header/Blowfish.h"
#include "../Header/print.h"


void print3 (uchar *input)
{

	Blowfish *B = new(std::nothrow)Blowfish;
	VMPC *V = new(std::nothrow)VMPC;
		
	uint32_t L, R;
	
	uchar *cipher = new(std::nothrow)uint8_t[strlen((const char*)input)];
	int len_VMPC_key = strlen((const char*)V->VMPC_key());
	char *key_temp_VMPC = new(std::nothrow)char[len_VMPC_key];
	memcpy (key_temp_VMPC, V->VMPC_key(), len_VMPC_key);

	/* Performing VMPC */

	V->Encrypt ((uchar*)input, key_temp_VMPC, cipher);
	
	int len_Blowfish_key = strlen((const char*)B->Blowfish_key());
	uchar *key_temp_Blowfish = new(std::nothrow)uchar[len_Blowfish_key];
	memcpy (key_temp_Blowfish, B->Blowfish_key(), len_Blowfish_key);

	/* Performing Blowfish */
	B->Blowfish_Init (key_temp_Blowfish, len_Blowfish_key);
	B->crack_text (cipher, &L, &R, strlen((const char*)cipher));
	B->Blowfish_Encipher (&L, &R);
	fprintf(stdout,"%08x %08x\n\n\n", R, L); // Print the right part first, then the left part of the encrypted message

	delete [ ] key_temp_VMPC;
	delete [ ] key_temp_Blowfish;
	delete [ ] cipher;
	delete V;
	delete B;

}

