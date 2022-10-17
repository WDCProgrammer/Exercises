CXX=				g++
CXXFLAGS=			-std=c++2a

OBJ=				main.o DbConnection.o SqlConnection.o OracleConnection.o DbCommand.o DbConnection.o PlayerPoolCommand.o
TARGET=				app


$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o:	main.cpp SqlConnection.h DbConnection.h	OracleConnection.h DbCommand.h PlayerPoolCommand.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

DbConnection.o: DbConnection.cpp DbConnection.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

SqlConnection.o: SqlConnection.cpp SqlConnection.h DbConnection.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

OracleConnection.o: OracleConnection.cpp OracleConnection.h DbConnection.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

DbCommand.o: DbCommand.cpp DbCommand.h DbConnection.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

PlayerPoolCommand.o: PlayerPoolCommand.cpp PlayerPoolCommand.h DbCommand.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del *.exe *.o

