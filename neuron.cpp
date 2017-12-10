#include "neuron.h"

using namespace std;

Neuron::Neuron(long double b, const std::vector<long double>& w, activationFunc af){
    bias = b;
    actFunc = af;
    for(int i = 0; i < w.size(); i++)
        weight.push_back(w[i]);
}

long double Neuron::calculate(const std::vector<long double> input){
    long double sum = 0;
    if(input.size() != weight.size())
        return -1;
    for(int i = 0; i < weight.size(); i++)
        sum += input[i] * weight[i];
    sum += bias;
    return (*actFunc)(sum);
}
