all: main

main: main.o network.o neuron.o
	g++ main.o network.o neuron.o -lpthread -o program

network.o: network.h neuron.h network.cpp
	g++ -c network.cpp

main.o: network.h main.cpp
	g++ -c main.cpp

neuron.o: neuron.h neuron.cpp
	g++ -c neuron.cpp

clean:
	rm *.o program