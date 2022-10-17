CXX=				g++
CXXFLAGS=			-std=c++2a

OBJ=				main.o
TARGET=				app


$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o:	main.cpp KeyValuePair.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del *.exe *.o

