SRC:= $(wildcard Cipher/* .cpp) \
	 $(wildcard Print/* .cpp) \
	 $(wildcard Main/* .cpp)
      
 
OBJECTS:= $(SRC:.cpp=.o) 

exe: $(OBJECTS)
	 $(CXX) -o $@ $^

clean:
	rm -f $(OBJ) exe

