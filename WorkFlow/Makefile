CXX=				g++
CXXFLAGS=			-std=c++2a

OBJ=				main.o WorkFlow.o WorkFlowEngine.o UploadVideoActivity.o VideoProcessedActivity.o WebServiceActivity.o EmailActivity.o
TARGET=				app


$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o:	main.cpp WebServiceActivity.h UploadVideoActivity.h Activity.h EmailActivity.h WorkFlow.h WorkFlowEngine.h VideoProcessedActivity.h
	$(CXX) $(CXXFLAGS) -c $< -o $@


UploadVideoActivity.o: UploadVideoActivity.cpp UploadVideoActivity.h Activity.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

VideoProcessedActivity.o: VideoProcessedActivity.cpp VideoProcessedActivity.h Activity.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

WebServiceActivity.o: WebServiceActivity.cpp WebServiceActivity.h Activity.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

WorkFlow.o: WorkFlow.cpp WorkFlow.h Activity.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

WorkFlowEngine.o: WorkFlowEngine.cpp WorkFlowEngine.h WorkFlow.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del *.exe *.o

