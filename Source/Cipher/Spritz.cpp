#include <iostream>
#include <new>
#include <cstring>
#include <algorithm>
#include "Spritz.h"

using namespace std;

void Spritz::KSA (char *key, uchar S[256])
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

void Spritz::PRGA (uchar S[256], uchar *plaintext, uchar *ciphertext)
{
	int i = 0, j = 0, k = 0, w = 0;
	srand(time(NULL));

	for (int n = 0; n < strlen((const char*)plaintext); n++)
	{
		do
		{
			w = rand() % 256 + 1; // w is relatively prime with S array size, which is 256
		} while (__gcd(w,256) != 1);
		
		i = (i + w) % 256;
		j = (k + S[j] + S[i]) % 256;
		k = (k + i + S[j]) % 256;

		swap (S[i],S[j]);

		int z = S[(j + S[i + S[z + k]]) % 256];

		ciphertext[n] = z^plaintext[n];
	}
	return;
}

void Spritz::Encrypt (uchar *plaintext, char *Spritz_key, uchar *ciphertext)
{
	uchar S[256];
	KSA(Spritz_key,S);
	PRGA (S,plaintext,ciphertext);

	return;
}

char *Spritz::Spritz_key()
{
	srand(time(NULL));
	int key, count;
	int len_key = rand() % 128 + 5;
	
	char *result = new(nothrow)char[len_key];

	for (int p = 0; p < len_key; p++)
	{
		count = rand() % 2;
		key = rand() % 26;
		if (count == 0)
			result[p] = char((key-65) % 26 + 65);
		else
			result[p] = char((key-97) % 26 + 97);
	}
	return result;
}
