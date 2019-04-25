#ifndef _Spritz_h
#define _Spritz_h

#include "Core.h"

class Spritz: virtual public Core // Declares Core class as virtual base class in order to avoid Diamond Problem
{
	public:
		void Encrypt (uchar *plaintext, char *Spritz_key, uchar *ciphertext);
		char *Spritz_key();

	protected:
		void KSA (char *key, uchar S[256]);
		void PRGA (uchar S[256], uchar *plaintext, uchar *ciphertext);
};

#endif
