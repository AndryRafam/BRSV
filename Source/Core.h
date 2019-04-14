// Mother Class

#ifndef _Core_h
#define _Core_h

#include <cstdint>

typedef unsigned char uchar;
typedef unsigned short ushort;

class Core
{
	public:
		Core(void); // Constructor
		void Blowfish_Init (uchar *key, int keybytes);
		void Blowfish_Encipher (uint32_t  *L, uint32_t *R);
		void Encrypt (uchar *plaintext, char *key, uchar *ciphertext);
		void *crack_text (uchar *text, uint32_t *Left, uint32_t *Right, int text_len);
		uchar *Blowfish_key();
		char *RC4A_key();
		char *RC4plus_key();
		char *Spritz_key();
		char *VMPC_key();
		~Core(void); // Destructor

	protected:
		uint32_t F (uint32_t x);
		void KSA (char *key, uchar S[256]);
		void PRGA_RC4A (uchar S1[256], uchar S2[256], uchar *plaintext, uchar *ciphertext);
		void PRGA (uchar S[256], uchar *plaintext, uchar *ciphertext);

};

#endif
