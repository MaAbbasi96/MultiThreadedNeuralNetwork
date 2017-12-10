#include "network.h"
#include <iostream> //#TODO remove it :D

using namespace std;

sem_t semaphore[4];
vector<vector<long double> > inputData;
long double memory1;
vector<long double> memory2;

void Network::get_info(){
    string gbg;
    long double x, y, z;
    vector<long double> temp;

    // input neuron initialize
    bias.push_back(0);
    for(int i = 0; i < 3; i++)
        temp.push_back(1);
    weights.push_back(temp);
    temp.clear();

    // hidden neurons initialize
    ifstream file;
    file.open("LayersInfo.txt");
    file >> gbg;
    for(int i = 0; i < hiddenLayerSize; i++){
        file >> x;
        bias.push_back(x);
    }
    file >> gbg;
    for(int i = 0; i < hiddenLayerSize; i++){
        file >> x >> y >> z;
        temp.push_back(x);
        temp.push_back(y);
        temp.push_back(z);
        weights.push_back(temp);
        temp.clear();
    }

    // output neuron initialize
    file >> gbg;
    file >> x;
    bias.push_back(x);
    file >> gbg;
    for(int i = 0; i < hiddenLayerSize; i++){
        file >> x;
        temp.push_back(x);
    }
    weights.push_back(temp);
    file.close();
}

void Network::make_layers(){
    inputNeuron = new Neuron(bias[0], weights[0], actFunc[0]);
    outputNeuron = new Neuron(bias[bias.size()-1], weights[weights.size()-1], actFunc[2]);
    for(int i = 1; i <= hiddenLayerSize; i++)
        hiddenNeuron.push_back(new Neuron(bias[i], weights[i], actFunc[1]));
}

Network::Network(int h, const vector<activationFunc>& _actFunc){
    hiddenLayerSize = h;
    for(int i = 0; i < h; i++)
        memory2.push_back(0);
    for(int i = 0; i < _actFunc.size(); i++)
        actFunc.push_back(_actFunc[i]);
    get_info();
    make_layers();
}

void* Network::input_layer_calc(void* arg){

}

void* Network::hidden_layer_calc(void* arg){
    
}

void* Network::output_layer_calc(void* arg){
    
}

void Network::calculate(const vector<vector<long double> >& input){
    int gbg;
    pthread_t thread[hiddenLayerSize+2];
    gbg = pthread_create(&thread[0], NULL, input_layer_calc, inputNeuron);
    gbg = pthread_create(&thread[hiddenLayerSize+1], NULL, output_layer_calc, outputNeuron);
    for(int i = 0; i < hiddenLayerSize; i++)
        gbg = pthread_create(&thread[i+1], NULL, hidden_layer_calc, hiddenNeuron[i]);
    
}