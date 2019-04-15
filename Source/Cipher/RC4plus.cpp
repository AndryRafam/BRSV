#include <iostream>
#include <new>
#include <cstring>
#include "RC4plus.h"

using namespace std;

void RC4plus::KSA (char *key, uchar S[256])
{
	for (int i = 0; i < 256; i++)
		S[i] = i;
		
	int j = 0;
	for (int i = 0; i < 256; i++)
	{
		j = (j + S[i] + key[i % strlen((const char*)key)]) % 256;
		swap (S[i],S[j]);
	}
	return;
}

void RC4plus::PRGA (uchar S[256], uchar *plaintext, uchar *ciphertext)
{
	int i = 0;
	int j = 0;
	
	for (int n = 0; n < strlen((const char*)plaintext); n++)
	{
		i = (i+1) % 256;
		j = (j+S[i]) % 256;
		swap(S[i],S[j]);
		
		int c = (S[(i <<= 5)^(j >>= 3)] + S[(j <<= 5)^(i >>= 3)]) % 256;
		int K = ((S[(S[i]+S[j]) % 256] + S[c^0xAA]) % 256)^S[(j+S[j]) % 256];

		ciphertext[n] = K^plaintext[n];
	}
	return;
}

void RC4plus::Encrypt (uchar *plaintext, char *RC4plus_key, uchar *ciphertext)
{
	uchar S[256];
	KSA (RC4plus_key, S);
	PRGA (S,plaintext,ciphertext);

	return;
}

char *RC4plus::RC4plus_key()
{
	srand(time(NULL));
	int key1, key2, count;
	int len_key = rand() % 128 + 5;

	char *result = new(nothrow)char[len_key];

	for (int i = 0; i < len_key; i++)
	{
		count = rand() % 2;
		key1 = rand() % 26;
		key2 = rand() % 26;

		if (count == 0)
			result[i] = char((key1 - 65) % 26 + 65);
		else
			result[i] = char((key2 - 97) % 26 + 97);
	}
	return result;
}

