Double random encryption program based on Blowfish (symmetric key block cipher), Spritz, VMPC(Variably Modified Permutation Composition), RC4+ and RC4A. The program randomly chooses a twofold combination between the encryption algorithms listed above. 
A salt function (adding a random extra bit at the end of the clear message) and a random_shuffle function (shuffling randomly the letters of the salt message) are also integrated within the program; in order to change drastically the nature of the clear message and thus, reducing the risk of collision. Intermediate stages are not outputted. Only the final result is outputted.

![Output](https://github.com/AndryRafam/Program-Output/blob/master/epsilonTTY.gif)

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

# WARRANTY
THE SOFTWARE IS UNDER GPL 3.0 LICENSE AND IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND.
