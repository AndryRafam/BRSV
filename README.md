# Eagle
Lightweight random multiple choice encryption program based on Blowfish, RC4A, RC4plus, Spritz and VMPC. The program choose randomly between the following combination:
  - Blowfish_RC4A
  - Blowfish_RC4plus
  - Blowfish_VMPC
  - Blowfish_Spritz

THE PROGRAM IS UNDER GPL 3.0 LICENSE.

# Files included
- Source folder:
  - Blowfish.h
  - Core.h (Mother class)
  - ORIG_S_P (Original Sbox / Pbox)
  - RC4A.h (Child class)
  - RC4plus.h (Child class)
  - Spritz.h (Child class)
  - VMPC.h (Child class)
  - Blowfish.cpp
  - Select1.cpp
  - Select2.cpp
  - Select3.cpp
  - RC4A.cpp
  - RC4plus.cpp
  - Spritz.cpp
  - VMPC.cpp
  
- Main folder
  - Main.cpp
  - print.h

- Makefile

# How to run it on Linux (Debian / Ubuntu)
- 1) Download the program
- 2) In command line, go to the folder containing the downloaded program
- 3) Type make and press enter
