CXX 	 = g++
STD		 = -std=c++11
OBJS   = Usuario.o Reserva.o LINF.o
OPENCV = `pkg-config opencv --libs`
LFLAGS = -Wall $(STD)
CFLAGS = $(LFLAGS) -c

all: Reserva.o LINF.o Usuario.o a.out teste.out

a.out: main.cpp Usuario.o LINF.o Reserva.o
	$(CXX) main.cpp $(OBJS) $(LFLAGS)

Usuario.o: Usuario.hpp Usuario.cpp Reserva.hpp
	$(CXX) Usuario.cpp $(CFLAGS)

LINF.o: LINF.hpp LINF.cpp Usuario.hpp Reserva.hpp
	$(CXX) LINF.cpp $(CFLAGS)

Reserva.o: Reserva.hpp Reserva.cpp Usuario.hpp
	$(CXX) Reserva.cpp $(CFLAGS)

teste.out: objectDetection.cpp
	$(CXX) objectDetection.cpp $(LFLAGS) $(OPENCV) -o teste.out


clean:
	rm *.o*
