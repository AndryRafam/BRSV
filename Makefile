SRC = $(wildcard Source/* .cpp)
      
MAIN = $(wildcard Main/* .cpp)

OBJECTS = $(SRC:.cpp=.o) $(MAIN:.cpp=.o)

PROG: $(OBJECTS)
	 $(CXX) -o $@ $^

