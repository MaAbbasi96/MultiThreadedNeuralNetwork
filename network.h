#ifndef NETWORK_H
#define NETWORK_H
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include "layer.h"
#include "neuron.h"

class Network{
    public:
        Network(int h);
        double calculate(double x, double y, double z);
    private:
        void get_info();
        std::vector<double> biases, outputWeights;
        std::vector<Arguments> hiddenLayerWeights;
        int hiddenLayerSize;
        double outputBias;
        Layer* hiddenLayer;
        Neuron* output;
        Neuron* input;
};

#endif