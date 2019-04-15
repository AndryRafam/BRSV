#include <iostream>
#include <cstring>
#include <new>
#include "VMPC.h"

using namespace std;


void VMPC::KSA (char *key, uchar S[256])
{
	int j = 0;

	for (int i = 0; i < 256; i++)
		S[i] = i;

	for (int i = 0; i < 256; i++)
	{
		j = ((j + S[i] + key[i % strlen((const char*)key)]) % 256);
		swap(S[i],S[j]);
	}
	return;
}

void VMPC::PRGA (uchar S[256], uchar *plaintext, uchar *ciphertext)
{
	int i = 0;
	int j, K;

	for (size_t n = 0, len = strlen((const char*)plaintext); n < len; n++)
	{
		j = S[(j + S[i]) % 256];
		K = S[S[(S[j] + 1) % 256]];
		ciphertext[n] = K^plaintext[n];
		swap(S[i],S[j]);
		i = (i+1) % 256;
	}
	return;
}

void VMPC::Encrypt (uchar *plaintext, char *key, uchar *ciphertext)
{
	uchar S[256];
	KSA (key,S);
	PRGA (S,plaintext,ciphertext);
	
	return;
}

char *VMPC::VMPC_key()
{
	srand(time(NULL));
	int count, key_gen;
	int len_key = rand() % 128 + 5;
	char *key = new(nothrow)char[len_key];

	for (int i = 0; i < len_key; i++)
	{
		count = rand() % 2;
		key_gen = rand() % 26;

		if (count == 0)
			key[i] = char((key_gen - 65) % 26 + 65);
		else
			key[i] = char((key_gen - 97) % 26 + 97);
	}
	return key;
}

Core::~Core(void){ } // Destructor - Destroy everything
