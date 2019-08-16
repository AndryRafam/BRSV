#include <iostream>
#include <new>
#include <cstring>
#include <ctime>
#include "../Header/RC4A.h"
#include "../Header/VMPC.h"
#include "../Header/print.h"

void print7(uchar *input){
  RC4A *RA = new(std::nothrow)RC4A;
  VMPC *V = new(std::nothrow)VMPC;

  uchar *RC4A_cipher = new(std::nothrow)uchar[strlen((const char*)input)];
  int len_RC4A_key = strlen((const char*)RA->RC4A_key());
  char *key_temp_RC4A = new(std::nothrow)char[len_RC4A_key];
  memcpy(key_temp_RC4A, RA->RC4A_key(), len_RC4A_key);

  uchar *VMPC_cipher = new(std::nothrow)uchar[strlen((const char*)input)];
  int len_VMPC_key = strlen((const char*)V->VMPC_key());
  char *key_temp_VMPC = new(std::nothrow)char[len_VMPC_key];
  memcpy(key_temp_VMPC, V->VMPC_key(), len_VMPC_key);

  srand(time(NULL));
  int random = rand()%2;

  switch (random) {
    case 0:
      RA->Encrypt((uchar*)input, key_temp_RC4A, RC4A_cipher);
      V->Encrypt((uchar*)RC4A_cipher, key_temp_VMPC, VMPC_cipher);
      fprintf(stdout, "\n\n\t\t");
      for (auto x = 0; x < strlen((const char*)VMPC_cipher); x++)
        fprintf(stdout, "%02X", *(VMPC_cipher +x));
      std::cout << "\n\n";
      exit(0);

    case 1:
      V->Encrypt((uchar*)input, key_temp_VMPC, VMPC_cipher);
      RA->Encrypt((uchar*)VMPC_cipher, key_temp_RC4A, RC4A_cipher);
      fprintf(stdout, "\n\n\t\t");
      for (auto x = 0; x < strlen((const char*)RC4A_cipher); x++)
        fprintf(stdout, "%02X", *(RC4A_cipher + x));
      std::cout << std::endl << std::endl;
      exit(0);
  }
}
