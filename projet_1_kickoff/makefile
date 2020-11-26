projetc++ : main.o
		g++ -c -Wall projetc++ main.o distance_map.o image2d.o
		
main.o : distance_map.hh image2d.hh distance_map.cc image2d.cc main.cc
		g++ -c -Wall main.cc

distance_map.o : box2d_iterator.hh box2d_iterator.cc image2d.hh image2d.cc neighb2d_iterator.hh neighb2d_iterator.cc
		g++ -c -Wall 
