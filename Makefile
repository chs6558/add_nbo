add_nbo : add_nbo.o
	g++ -o add_nbo add_nbo.o
add_nbo.o : add_nbo.cpp
	g++ -c add_nbo.cpp
clean :
	rm add_nbo add_nbo.o
