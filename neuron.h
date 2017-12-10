#ifndef NEURON_H
#define NEURON_H

#include <vector>

typedef long double (*activationFunc)(long double input);

class Neuron{
    public:
        Neuron(long double b, std::vector<long double>& w, activationFunc af);
    private:
        std::vector<long double> weight;
        long double bias;
        activationFunc actFunc;
};

#endif