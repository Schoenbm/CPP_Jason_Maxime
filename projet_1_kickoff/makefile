CXX = g++
CXXFLAGS = -Wall -pedantic -Wextra -Werror -ansi -std=c++2a # -ggdb
LDFLAGS =
INCLUDES =
EXEC_NAME = projetc++
SRC = $(wildcard *.cc)
OBJ = $(SRC:.cc=.o)

all : $(EXEC_NAME)

$(EXEC_NAME) : $(OBJ)
	$(CXX) -o $(EXEC_NAME) $^ $(LDFLAGS)

%.o : %.cc
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ -c $<


.PHONY : clean

clean :
	rm -f $(EXEC_NAME) *.o

run : $(EXEC_NAME)
	./$(EXEC_NAME)
