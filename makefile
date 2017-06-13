CXX 	 = g++
STD		 = -std=c++11
OPENCV = `pkg-config opencv --libs`
LFLAGS = -Wall $(STD) $(OPENCV)

all: a.out

teste: objectDetection.cpp
	$(CXX) objectDetection.cpp $(LFLAGS) -o teste

a.out: main.cpp
	$(CXX) main.cpp $(LFLAGS)

clean:
	rm *.o*
