#include <iostream>
#include <new>
#include <cstring>
#include <ctime>
#include "../Header/RC4A.h"
#include "../Header/RC4plus.h"
#include "../Header/print.h"

void print5(uchar *input){
  RC4plus *Rplus = new(std::nothrow)RC4plus;
  RC4A *RA = new(std::nothrow)RC4A;

  uchar *Rplus_cipher = new(std::nothrow)uchar[strlen((const char*)input)];
  int len_RC4plus_key = strlen((const char*)Rplus->RC4plus_key());
  char *key_temp_RC4plus = new(std::nothrow)char[len_RC4plus_key];
  memcpy(key_temp_RC4plus, Rplus->RC4plus_key(), len_RC4plus_key);

  uchar *RC4A_cipher = new(std::nothrow)uchar[strlen((const char*)input)];
  int len_RC4A_key = strlen((const char*)RA->RC4A_key());
  char *key_temp_RC4A = new(std::nothrow)char[len_RC4A_key];
  memcpy(key_temp_RC4A, RA->RC4A_key(), len_RC4A_key);

  srand(time(NULL));
  int random = rand()%2;

  switch (random) {
    case 0:
      RA->Encrypt((uchar*)input, key_temp_RC4A, RC4A_cipher);
      Rplus->Encrypt((uchar*)RC4A_cipher, key_temp_RC4plus, Rplus_cipher);
      fprintf(stdout, "\n\n\t\t");
      for (auto x = 0; x < strlen((const char*)Rplus_cipher); x++)
        fprintf(stdout, "%02X", *(Rplus_cipher + x));
      std::cout << "\n\n";
      exit(0);

    case 1:
      Rplus->Encrypt((uchar*)input, key_temp_RC4plus, Rplus_cipher);
      RA->Encrypt((uchar*)Rplus_cipher, key_temp_RC4A, RC4A_cipher);
      fprintf(stdout, "\n\n\t\t");
      for (auto x = 0; x < strlen((const char*)RC4A_cipher); x++)
        fprintf(stdout, "%02X", *(RC4A_cipher + x));
      std::cout << std::endl << std::endl;
      exit(0);
  }
}
