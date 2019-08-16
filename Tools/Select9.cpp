#include <iostream>
#include <new>
#include <cstring>
#include <ctime>
#include "../Header/RC4plus.h"
#include "../Header/Spritz.h"
#include "../Header/print.h"

void print9(uchar *input){
  RC4plus *Rplus = new(std::nothrow)RC4plus;
  Spritz *S = new(std::nothrow)Spritz;

  uchar *Rplus_cipher = new(std::nothrow)uchar[strlen((const char*)input)];
  int len_RC4plus_key = strlen((const char*)Rplus->RC4plus_key());
  char *key_temp_RC4plus = new(std::nothrow)char[len_RC4plus_key];
  memcpy(key_temp_RC4plus, Rplus->RC4plus_key(), len_RC4plus_key);

  uchar *Spritz_cipher = new(std::nothrow)uchar[strlen((const char*)input)];
  int len_Spritz_key = strlen((const char*)S->Spritz_key());
  char *key_temp_Spritz = new(std::nothrow)char[len_Spritz_key];
  memcpy(key_temp_Spritz, S->Spritz_key(), len_Spritz_key);

  srand(time(NULL));
  int random = rand()%2;

  switch (random) {
    case 0:
      S->Encrypt((uchar*)input, key_temp_Spritz, Spritz_cipher);
      Rplus->Encrypt((uchar*)Spritz_cipher, key_temp_RC4plus, Rplus_cipher);
      fprintf(stdout, "\n\n\t\t");
      for (auto x = 0; x < strlen((const char*)Rplus_cipher); x++)
        fprintf(stdout, "%02X", *(Rplus_cipher + x));
      std::cout << std::endl << std::endl;
      exit(0);

    case 1:
      Rplus->Encrypt((uchar*)input, key_temp_RC4plus, Rplus_cipher);
      S->Encrypt((uchar*)Rplus_cipher, key_temp_Spritz, Spritz_cipher);
      fprintf(stdout, "\n\n\t\t");
      for (auto x = 0; x < strlen((const char*)Spritz_cipher); x++)
        fprintf(stdout, "%02X", *(Spritz_cipher + x));
      std::cout << std::endl << std::endl;
      exit(0);
  }
}
