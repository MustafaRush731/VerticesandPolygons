proj6Base : proj6Base.o vertex.o vertexSet.o polygon.o
	g++ -o proj6Base proj6Base.o vertex.o vertexSet.o polygon.o

proj6Base.o : proj6Base.cpp vertex.h vertexSet.h polygon.h
	g++ -g -c proj6Base.cpp

vertex.o : vertex.cpp vertex.h
	g++ -g -c vertex.cpp

vertexSet.o : vertexSet.cpp vertexSet.h vertex.h
	g++ -g -c vertexSet.cpp

polygon.o : polygon.cpp vertexSet.h polygon.h vertex.h
	g++ -g -c polygon.cpp

.cpp.o :
	g++ -g -c $<

debug : proj6Base.cpp vertex.cpp vertexSet.cpp polygon.cpp
	g++ -o proj6BaseDebug -g -DDEBUG proj6Base.cpp vertex.cpp vertexSet.cpp polygon.cpp

clean :
	rm *.o core