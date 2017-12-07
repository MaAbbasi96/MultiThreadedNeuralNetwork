#ifndef NETWORK_H
#define NETWORK_H
#include <vector>
#include "layer.h"
#include "neuron.h"

class Network{
    public:
        Network(int h) {hiddenLayerSize = h;}
        double calculate(double x, double y, double z);
    private:
        int hiddenLayerSize;
        Layer* hiddenLayer;
        // Neuron* input, output;
};

#endif