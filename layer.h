#ifndef LAYER_H
#define LAYER_H
#include <vector>
#include "neuron.h"

class Layer{
    public:
        Layer(int s, std::vector<double> w, std::vector<double> b);
    private:
        std::vector<Neuron*> neurons;
};

#endif