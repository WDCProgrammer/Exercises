CXX=				g++
CXXFLAGS=			-std=c++2a

OBJ=				main.o StopWatch.o
TARGET=				app


$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o:	main.cpp StopWatch.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

StopWatch.o: StopWatch.cpp StopWatch.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
clean:
	del *.exe *.o

