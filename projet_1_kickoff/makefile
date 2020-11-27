OBJ= point2d.o box2d.o neighb2d_iterator.o box2d_iterator.o image2d.o distance_map.o main.o projetc++

CC = g++ 
CCFLAGS = -std=c++14 -Wextra -pedantic -g -DLINUX -Wall

obj:	$(OBJ)


clean:
	rm -f $(OBJ); rm -f *.o

.SUFFIXES:	.exe

.c.exe:	
	$(CC) $(CCFLAGS) $< $(OBJ) -lm -o $@

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
