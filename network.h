#ifndef NETWORK_H
#define NETWORK_H
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include "neuron.h"

class Network{
    public:
        Network(int h, std::vector<activationFunc>& _actFunc);
        double calculate(std::string fileName);
    private:
        void get_info();
        void make_layers();
        std::vector<double> bias;
        std::vector<std::vector<double> > weight;
        int hiddenLayerSize;
        std::vector<Neuron*> hiddenNeuron;
        Neuron* output;
        Neuron* input;
        std::vector<activationFunc> actFunc; 
};

#endif