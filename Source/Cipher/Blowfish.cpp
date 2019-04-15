#include <iostream>
#include <new>
#include <cstring>
#include "Blowfish.h"
#include "ORIG_S_P.h"

#define N 16
#define MaxBytes 56

using namespace std;

uint32_t P[N+2];
uint32_t S[4][256];

Core::Core(void){ } // Constructor - Builds everything

uint32_t Blowfish::F (uint32_t x)
{
	ushort a, b, c, d;
	uint32_t y;

	d = x & 0X00FF;
	x >>= 8;
	c = x & 0X00FF;
	x >>= 8;
	b = x & 0X00FF;
	x >>= 8;
	a = x & 0X00FF;

	y = ((S[0][a] + S[1][b])^S[2][c]) + S[3][d];
	return y;
}

void Blowfish::Blowfish_Encipher (uint32_t *L, uint32_t *R)
{
	uint32_t Xl, Xr;

	Xl = *L;
	Xr = *R;

	for (int i = 0; i < N; ++i)
	{
		Xl = Xl^P[i];
		Xr = F(Xl)^Xr;
		swap (Xl, Xr);
	}

	swap (Xl, Xr);
	Xr = Xr^P[N];
	Xl = Xl^P[N+1];
	*L = Xl;
	*R = Xr;

	return;
}

void Blowfish::Blowfish_Init (uchar *key, int keybytes)
{
	uint32_t data, dataL, dataR;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 256; j++)
			S[i][j] = ORIG_S[i][j];
	}

	int j = 0;
	for (int i = 0; i < N+2; ++i)
	{
		data = 0X00000000;
		for (int k = 0; k < 4; ++k)
		{
			data = (data << 8) | key[j];
			j = j+1;
			if (j >= keybytes)
				j = 0;
		}
		P[i] = ORIG_P[i]^data;
	}

	dataL = 0X00000000;
	dataR = 0X00000000;

	for (int i = 0; i < N; i += 2)
	{
		Blowfish_Encipher (&dataL, &dataR);
		P[i] = dataL;
		P[i+1] = dataR;
	}

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 256; j += 2)
		{
			Blowfish_Encipher (&dataL, &dataR);
			S[i][j] = dataL;
			S[i][j+1] = dataR;
		}
	}
	return;
}

uchar *Blowfish::Blowfish_key()
{
	srand(time(NULL));
	int key_random = rand() % MaxBytes + 4;
	uchar *key = new(nothrow)uchar[key_random];
	int count, key1, key2;

	for (int i = 0; i < key_random; i++)
	{
		count = rand() % 2;
		key1 = rand() % 26;
		key2 = rand() % 26;

		if (count == 0)
			key[i] = char((key1 - 65) % 26 + 65);
		else
			key[i] = char((key2 - 97) % 26 + 97);
	}
	return key;
}

void *Blowfish::crack_text (uchar *text, uint32_t *Left, uint32_t *Right, int len_text)
{
	int block_len;
	while (len_text)
	{
		Left = Right = 0UL;

		for (block_len = 0; block_len < 4; block_len++)
		{
			if (len_text)
			{
				Left += *text++;
				len_text--;
			}
			else Left += 0;
		}
		for (block_len = 0; block_len < 4; block_len++)
		{
			if (len_text)
			{
				Right += *text++;
				len_text--;
			}
			else Right += 0;
		}
	}
}


