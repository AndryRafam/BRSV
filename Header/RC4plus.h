#ifndef _RC4plus_h
#define _RC4plus_h

#include "Core.h"

class RC4plus: virtual public Core // Declares Core class as virtual base class in order to avoid Diamond Problem
{
	public:
		void Encrypt (uchar *plaintext, char *RC4plus_key, uchar *ciphertext);
		char *RC4plus_key();
	
	protected:
		void KSA (char *key, uchar S[256]);
		void PRGA (uchar S[256], uchar *plaintext, uchar *ciphertext);
};

#endif
