#include "neuron.h"

using namespace std;

Neuron::Neuron(long double b, const std::vector<long double>& w, activationFunc af){
    bias = b;
    actFunc = af;
    for(int i = 0; i < w.size(); i++)
        weight.push_back(w[i]);
}

vector<long double> Neuron::calculate(const std::vector<long double> input){
    vector<long double> res;
    for(int i = 0; i < input.size(); i++)
        res.push_back(weight[i]*input[i]);
    res.push_back(bias);
    return (*actFunc)(res);
}
