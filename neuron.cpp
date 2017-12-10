#include "neuron.h"
#include <iostream> // remove it

using namespace std;

Neuron::Neuron(long double b, std::vector<long double>& w, activationFunc af){
    bias = b;
    actFunc = af;
    for(int i = 0; i < w.size(); i++)
        weight.push_back(w[i]);
}
