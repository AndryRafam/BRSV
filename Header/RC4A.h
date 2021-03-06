#ifndef _RC4A_h
#define _RC4A_h

#include "Core.h"

class RC4A: virtual public Core // Declares Core class as virtual base class in order to avoid Diamond Problem
{
	public:
		void Encrypt (uchar *plaintext, char *RC4A_key, uchar *ciphertext);
		char *RC4A_key();

	protected:
		void KSA (char *key, uchar S[256]);
		void PRGA (uchar S1[256], uchar S2[256], uchar *plaintext, uchar *ciphertext); // Function overloaded
};

#endif

