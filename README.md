![Text](https://github.com/AndryRafam/Program-Output/blob/master/CastleBravo.gif)

Double random multiple choice encryption program. The program choose randomly a twin combination between the following encryption algorithm: Blowfish, RC4A, RC4+, Spritz, VMPC. Only the final result is outputted.

THE PROGRAM IS UNDER GPL 3.0 LICENSE.

# What are the intermediate stages ?
- 1) Shuffle randomly the clear message
- 2) Apply OTP (One Time Pad) to the shuffled clear message
- 3) Salt the OTP message
- 4) Shuffle randomly the salt message

# How to run it on Linux (Debian / Ubuntu)
- 1) Download the program
- 2) In command line, go to the folder containing the downloaded program
- 3) Type make and press enter to compile
- 4) Type ./exe and press enter to run
