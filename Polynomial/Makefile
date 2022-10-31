CXX=				g++
CXXFLAGS=			-std=c++2a

OBJ=				main.o Polynomial.o
TARGET=				app


$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o:	main.cpp Polynomial.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

Polynomial.o: Polynomial.cpp Polynomial.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del *.exe *.o

