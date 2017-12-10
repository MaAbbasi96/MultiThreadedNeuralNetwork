#ifndef NETWORK_H
#define NETWORK_H
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <pthread.h>
#include <semaphore.h>
#include "neuron.h"

class Network{
    public:
        Network(int h, const std::vector<activationFunc>& _actFunc);
        void calculate(const std::vector<std::vector<long double> >& input);
    private:
        void get_info();
        void make_layers();
        std::vector<long double> bias;
        std::vector<std::vector<long double> > weights;
        int hiddenLayerSize;
        std::vector<Neuron*> hiddenNeuron;
        Neuron* outputNeuron;
        Neuron* inputNeuron;
        std::vector<activationFunc> actFunc; 
};

#endif