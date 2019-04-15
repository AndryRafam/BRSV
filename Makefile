SRC:= $(wildcard Source/Cipher/* .cpp) \
	 $(wildcard Source/Print/* .cpp)
      
MAIN:= $(wildcard Main/* .cpp)
 
OBJECTS:= $(SRC:.cpp=.o) $(MAIN:.cpp=.o) 

PROG: $(OBJECTS)
	 $(CXX) -o $@ $^


