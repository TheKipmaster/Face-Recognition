CXX 	 = g++
STD		 = -std=c++11
OBJS   = Usuario.o LINF.o
OPENCV = `pkg-config opencv --libs`
LFLAGS = -Wall $(STD)
CFLAGS = $(LFLAGS) -c

all: LINF.o Usuario.o a.out teste.out

a.out: main.cpp Usuario.o LINF.o
	$(CXX) main.cpp $(OBJS) $(LFLAGS)

Usuario.o: Usuario.hpp Usuario.cpp
	$(CXX) Usuario.cpp $(CFLAGS)

LINF.o: LINF.hpp LINF.cpp Usuario.hpp
	$(CXX) LINF.cpp $(CFLAGS)

objectDetection.out: objectDetection.cpp
	$(CXX) objectDetection.cpp $(LFLAGS) $(OPENCV) -o objectDetection.out

test.out: test.cpp
	$(CXX) test.cpp $(LFLAGS) $(OPENCV) -o test.out

clean:
	rm *.o*
