#include <iostream>
#include <new>
#include <cstring>
#include <ctime>
#include "../Header/RC4A.h"
#include "../Header/Spritz.h"
#include "../Header/print.h"

void print8(uchar *input){
  RC4A *RA = new(std::nothrow)RC4A;
  Spritz *S = new(std::nothrow)Spritz;

  uchar *RC4A_cipher = new(std::nothrow)uchar[strlen((const char*)input)];
  int len_RC4A_key = strlen((const char*)RA->RC4A_key());
  char *key_temp_RC4A = new(std::nothrow)char[len_RC4A_key];
  memcpy(key_temp_RC4A, RA->RC4A_key(), len_RC4A_key);

  uchar *Spritz_cipher = new(std::nothrow)uchar[strlen((const char*)input)];
  int len_Spritz_key = strlen((const char*)S->Spritz_key());
  char *key_temp_Spritz = new(std::nothrow)char[len_Spritz_key];
  memcpy(key_temp_Spritz, S->Spritz_key(), len_Spritz_key);

  srand(time(NULL));
  int random = rand()%2;

  switch (random){
    case 0:
      RA->Encrypt((uchar*)input, key_temp_RC4A, RC4A_cipher);
      S->Encrypt((uchar*)RC4A_cipher, key_temp_Spritz, Spritz_cipher);
      for (auto x = 0; x < strlen((const char*)Spritz_cipher); x++)
        fprintf(stdout, "%02X", *(Spritz_cipher + x));
      std::cout << std::endl << std::endl;
      exit(0);

    case 1:
      S->Encrypt((uchar*)input, key_temp_Spritz, Spritz_cipher);
      RA->Encrypt((uchar*)Spritz_cipher, key_temp_RC4A, RC4A_cipher);
      for (auto x = 0; x < strlen((const char*)RC4A_cipher); x++)
        fprintf(stdout, "%02X", *(RC4A_cipher + x));
      std::cout << std::endl << std::endl;
      exit(0);

  }
}
