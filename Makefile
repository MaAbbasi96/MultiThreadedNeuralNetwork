all: main random

main: main.o network.o neuron.o utils.o
	g++ main.o network.o neuron.o utils.o -lpthread -o program

network.o: network.h neuron.h network.cpp
	g++ -c network.cpp

utils.o: utils.h utils.cpp
	g++ -c utils.cpp

main.o: network.h utils.h main.cpp
	g++ -c main.cpp

neuron.o: neuron.h neuron.cpp
	g++ -c neuron.cpp

random: randomgen.cpp
	g++ randomgen.cpp -o randomgen && ./randomgen

clean:
	rm *.o program randomgen