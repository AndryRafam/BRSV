#include <iostream>
#include <new>
#include <cstring>
#include <ctime>
#include "../Header/VMPC.h"
#include "../Header/Spritz.h"
#include "../Header/print.h"

void print6(uchar *input){
  VMPC *V = new(std::nothrow)VMPC;
  Spritz *S = new(std::nothrow)Spritz;

  uchar *VMPC_cipher = new(std::nothrow)uchar[strlen((const char*)input)];
  int len_VMPC_key = strlen((const char*)V->VMPC_key());
  char *key_temp_VMPC = new(std::nothrow)char[len_VMPC_key];
  memcpy(key_temp_VMPC, V->VMPC_key(), len_VMPC_key);

  uchar *Spritz_cipher = new(std::nothrow)uchar[strlen((const char*)input)];
  int len_Spritz_key = strlen((const char*)S->Spritz_key());
  char *key_temp_Spritz = new(std::nothrow)char[len_Spritz_key];
  memcpy(key_temp_Spritz, S->Spritz_key(), len_Spritz_key);

  srand(time(NULL));
  int random = rand()%2;

  switch (random) {
    case 0:
      V->Encrypt((uchar*)input, key_temp_VMPC, VMPC_cipher);
      S->Encrypt((uchar*)VMPC_cipher, key_temp_Spritz, Spritz_cipher);
      fprintf(stdout, "\n\n\t\t");
      for (auto x = 0; x < strlen((const char*)Spritz_cipher); x++)
        fprintf(stdout, "%02X", *(Spritz_cipher +x));
      std::cout << "\n\n";
      exit(0);

    case 1:
      S->Encrypt((uchar*)input, key_temp_Spritz, Spritz_cipher);
      V->Encrypt((uchar*)Spritz_cipher, key_temp_VMPC, VMPC_cipher);
      fprintf(stdout, "\n\n\t\t");
      for (auto x = 0; x < strlen((const char*)VMPC_cipher); x++)
        fprintf(stdout, "%02X", *(VMPC_cipher +x));
      std::cout << "\n\n";
      exit(0);
  }
}
