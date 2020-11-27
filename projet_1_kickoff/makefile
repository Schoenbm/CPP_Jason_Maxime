CXX = g++
CXXFLAGS = -Wall -pedantic -Wextra -Werror -ansi -std=c++2a # -ggdb
LDFLAGS =
INCLUDES =
EXEC_NAME = projetc++
SRC = $(wildcard *.cc)
OBJ = $(SRC:.cc=.o)

<<<<<<< Updated upstream
CC = g++ 
CCFLAGS = -std=c++14 -Wextra -pedantic -g -DLINUX -Wall
=======
all : $(EXEC_NAME)
>>>>>>> Stashed changes

$(EXEC_NAME) : $(OBJ)
	$(CXX) -o $(EXEC_NAME) $^ $(LDFLAGS)

%.o : %.cc
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ -c $<


.PHONY : clean

clean :
	rm -f $(EXEC_NAME) *.o

<<<<<<< Updated upstream
projetc++ : main.o distance_map.o box2d.o box2d_iterator.o neighb2d_iterator.o point2d.o image2d.o
	    $(CC) $(CCFLAGS) main.o distance_map.o image2d.o box2d.o box2d_iterator.o neighb2d_iterator.o point2d.o -o projetc++
		
main.o : distance_map.hh image2d.hh distance_map.cc image2d.cc main.cc
		$(CC) $(CCFLAGS) -c -lm main.cc

distance_map.o : box2d_iterator.hh box2d_iterator.cc image2d.hh image2d.cc neighb2d_iterator.hh neighb2d_iterator.cc
		$(CC) $(CCFLAGS) -c -lm distance_map.cc
		
box2d.o : point2d.hh point2d.cc neighb2d_iterator.hh neighb2d_iterator.cc box2d_iterator.hh box2d_iterator.cc
		$(CC) $(CCFLAGS) -c -lm box2d.cc
		
box2d_iterator.o : point2d.hh point2d.cc box2d.hh box2d.cc
		$(CC) $(CCFLAGS) -c -lm box2d_iterator.cc
		
image2d.o : box2d.hh box2d.cc utils.hh
		$(CC) $(CCFLAGS) -c -lm image2d.cc
		
neighb2d_iterator.o : point2d.hh point2d.cc box2d.hh box2d.cc box2d_iterator.hh box2d_iterator.cc
		$(CC) $(CCFLAGS) -c -lm neighb2d_iterator.cc

point2d.o : point2d.hh
		$(CC) $(CCFLAGS) -c -lm point2d.cc
=======
run : $(EXEC_NAME)
	./$(EXEC_NAME)
>>>>>>> Stashed changes
