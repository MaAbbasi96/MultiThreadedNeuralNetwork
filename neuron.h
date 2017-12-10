#ifndef NEURON_H
#define NEURON_H

#include <vector>

typedef std::vector<long double> (*activationFunc)(const std::vector<long double>& input);

class Neuron{
    public:
        Neuron(long double b, const std::vector<long double>& w, activationFunc af);
        std::vector<long double> calculate(const std::vector<long double> input);
    private:
        std::vector<long double> weight;
        long double bias;
        activationFunc actFunc;
};

#endif