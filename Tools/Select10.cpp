#include <iostream>
#include <new>
#include <cstring>
#include <ctime>
#include "../Header/RC4plus.h"
#include "../Header/VMPC.h"
#include "../Header/print.h"

void print10(uchar *input){
  RC4plus *Rplus = new(std::nothrow)RC4plus;
  VMPC *V = new(std::nothrow)VMPC;

  uchar *Rplus_cipher = new(std::nothrow)uchar[strlen((const char*)input)];
  int len_RC4plus_key = strlen((const char*)Rplus->RC4plus_key());
  char *key_temp_RC4plus = new(std::nothrow)char[len_RC4plus_key];
  memcpy(key_temp_RC4plus, Rplus->RC4plus_key(), len_RC4plus_key);

  uchar *VMPC_cipher = new(std::nothrow)uchar[strlen((const char*)input)];
  int len_VMPC_key = strlen((const char*)V->VMPC_key());
  char *key_temp_VMPC = new(std::nothrow)char[len_VMPC_key];
  memcpy(key_temp_VMPC, V->VMPC_key(), len_VMPC_key);

  srand(time(NULL));
  int random = rand()%2;

  switch (random) {
    case 0:
      Rplus->Encrypt((uchar*)input, key_temp_RC4plus, Rplus_cipher);
      V->Encrypt((uchar*)Rplus_cipher, key_temp_VMPC, VMPC_cipher);
      fprintf(stdout, "\n\n\t\t");
      for (auto x = 0; x < strlen((const char*)VMPC_cipher); x++)
        fprintf(stdout, "%02X", *(VMPC_cipher +x));
      std::cout << "\n\n";
      exit(0);

    case 1:
      V->Encrypt((uchar*)input, key_temp_VMPC, VMPC_cipher);
      Rplus->Encrypt((uchar*)VMPC_cipher, key_temp_RC4plus, Rplus_cipher);
      fprintf(stdout, "\n\n\t\t");
      for (auto x = 0; x < strlen((const char*)Rplus_cipher); x++)
        fprintf(stdout, "%02X", *(Rplus_cipher + x));
      std::cout << std::endl << std::endl;
      exit(0);
  }
}
