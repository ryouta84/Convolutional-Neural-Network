OBJS	= main.o CNN.o ConvLayer.o PoolingLayer.o Perceptron.o
PROGRAM = main

all:			$(PROGRAM)

$(PROGRAM):		$(OBJS)
				g++  $(OBJS) -o $(PROGRAM)

main.o:			main.cpp
				g++ -std=c++14 -c main.cpp

CNN.o:			CNN.cpp
				g++ -std=c++14 -c CNN.cpp

ConvLayer.o:	ConvLayer.cpp
				g++ -std=c++14 -c ConvLayer.cpp

PoolingLayer.o: PoolingLayer.cpp
				g++ -std=c++14 -c PoolingLayer.cpp

Perceptron.o: 	Perceptron.cpp
				g++ -std=c++14 -c Perceptron.cpp
