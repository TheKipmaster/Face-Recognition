CXX 	 = g++
STD		 = -std=c++11
OPENCV = `pkg-config opencv --libs`
LFLAGS = -Wall $(STD) $(OPENCV)

all: a.out

a.out: objectDetection.cpp
	$(CXX) objectDetection.cpp $(LFLAGS)

clean:
	rm *.o*
