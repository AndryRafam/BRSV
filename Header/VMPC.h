#ifndef _VMPC_h
#define _VMPC_h

#include "Core.h"

class VMPC: virtual public Core // Declares Core class as virtual base class in order to avoid Diamond Problem
{
	public:
		void Encrypt (uchar *plaintext, char *key, uchar *ciphertext);
		char *VMPC_key();
	
	protected:
		void KSA (char *key, uchar S[256]);
		void PRGA (uchar S[256], uchar *plaintext, uchar *ciphertext);
};

#endif
