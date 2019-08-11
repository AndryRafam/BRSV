SRC:= $(wildcard Cipher/Blowfish/* .cpp) \
	 $(wildcard Cipher/OTP/* .cpp) \
	 $(wildcard Cipher/RC4A/* .cpp) \
	 $(wildcard Cipher/RC4plus/* .cpp) \
	 $(wildcard Cipher/Spritz/* .cpp) \
	 $(wildcard Cipher/VMPC/* .cpp) \
	 $(wildcard Print/* .cpp) \
	 $(wildcard OTP/* .cpp) \
	 $(wildcard Main/* .cpp)
      
 
OBJECTS:= $(SRC:.cpp=.o) 

exe: $(OBJECTS)
	 $(CXX) -g -o $@ $^

clean:
	rm -f $(OBJECTS) exe

