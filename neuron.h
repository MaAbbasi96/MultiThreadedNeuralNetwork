#ifndef NEURON_H
#define NEURON_H

#include <vector>

typedef double (*activationFunc)(double input);

class Neuron{
    public:
        
    private:
        std::vector<double> weight;
        double bias;
};

#endif