#ifndef NETWORK_H
#define NETWORK_H
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <pthread.h>
#include <semaphore.h>
#include "neuron.h"

class Network{
    public:
        Network(int h, const std::vector<activationFunc>& _actFunc);
        std::vector<long double> calculate(const std::vector<std::vector<long double> >& input);
        std::vector<long double> calculate_serial(const std::vector<std::vector<long double> >& input);
    private:
        void get_info();
        void make_layers();
        static void* input_layer_calc(void* arg);
        static void* hidden_layer_calc(void* arg);
        static void* output_layer_calc(void* arg);
        std::vector<long double> bias;
        std::vector<std::vector<long double> > weights;
        int hiddenLayerSize;
        std::vector<Neuron*> hiddenNeuron;
        Neuron* outputNeuron;
        Neuron* inputNeuron;
        std::vector<activationFunc> actFunc; 
};

#endif