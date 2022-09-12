CXX=					g++
CXXFLAGS=				-std=c++2a


OBJ=					main.o StockList.o StockType.o



app: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp StockList.h SmartPointer.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

StockType.o: StockType.cpp StockType.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

StockList.o: StockList.cpp StockList.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del *.o *.exe