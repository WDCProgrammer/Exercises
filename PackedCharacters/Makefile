CXX=							g++
CXXFLAGS=						-std=c++2a
OBJ=							main.o




app: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $<

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@