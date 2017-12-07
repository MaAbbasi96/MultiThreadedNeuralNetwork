all: main

main: main.o network.o layer.o neuron.o
	g++ main.o network.o layer.o neuron.o -o program

network.o: network.h layer.h network.cpp
	g++ -c network.cpp

main.o: network.h main.cpp
	g++ -c main.cpp

layer.o: layer.h neuron.h layer.cpp
	g++ -c layer.cpp

neuron.o: neuron.h neuron.cpp
	g++ -c neuron.cpp

clean:
	rm *.o program