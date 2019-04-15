#include <iostream>
#include <cstring>
#include <new>
#include "RC4A.h"

using namespace std;


void RC4A::KSA (char *key, uchar S[256])
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

void RC4A::PRGA_RC4A (uchar S1[256], uchar S2[256], uchar *plaintext, uchar *ciphertext)
{
	int i = 0;
	int j1 = 0, j2 = 0;

	for (int n = 0; n < strlen((const char*)plaintext); n++)
	{
		i = (i + 1) % 256;
		j1 = (j1 + S1[i]) % 256;
		swap(S1[i],S1[j1]);
		int K1 = S2[(S1[i] + S1[j1]) % 256];

		ciphertext[n] = K1^plaintext[n];
	}

	for (int k = 0; k < strlen((const char*)ciphertext); k++)
	{
		i = (i + 1) % 256;
		j2 = (j2 + S2[i]) % 256;
		swap(S2[i],S2[j2]);
		int K2 = S1[(S2[i] + S2[j2]) % 256];

		ciphertext[k] = K2^ciphertext[k];
	}
	return;
}

void RC4A::Encrypt (uchar *plaintext, char *RC4A_key, uchar *ciphertext)
{
	uchar S1[256];
	uchar S2[256];

	KSA (RC4A_key, S1);
	KSA (RC4A_key, S2);
	PRGA_RC4A (S1,S2,plaintext,ciphertext);
	
	return;
}

char *RC4A::RC4A_key()
{
	srand(time(NULL));
	int key, count;
	int len_key = rand() % 128 + 5;

	char *result = new(nothrow)char[len_key];

	for (int i = 0; i < len_key; i++)
	{
		count = rand() % 2;
		key = rand() % 26;
		if (count == 0)
			result[i] = char((key-65) % 26 + 65);
		else
			result[i] = char((key-97) % 26 + 97);
	}
	return result;
}

