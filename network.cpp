#include "network.h"
#include <iostream> //#TODO remove it :D
#include <stdio.h>
#include <unistd.h>

using namespace std;

struct Args{
    Neuron* neuron;
    int index;
};

sem_t semaphore[4];
vector<vector<long double> > inputData;
vector<long double> memory1;
vector<long double> memory2, memory3;
int hls;

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
    hls = h;
    for(int i = 0; i < h; i++)
        memory2.push_back(0);
    for(int i = 0; i < _actFunc.size(); i++)
        actFunc.push_back(_actFunc[i]);
    get_info();
    make_layers();
}

void* Network::input_layer_calc(void* arg){
    Neuron* neuron = (Neuron*) arg;
    for(int i = 0; i < inputData.size(); i++){
        memory1.clear();
        vector<long double> temp = neuron->calculate(inputData[i]);
        for(int j = 0; j < temp.size()-1; j++)
            memory1.push_back(temp[j]);
        for(int j = 0; j < hls; j++)
            sem_post(&semaphore[0]);
        for(int j = 0; j < hls; j++)
            sem_wait(&semaphore[1]);
    }
}

void* Network::hidden_layer_calc(void* arg){
    Args* args = (Args*) arg;
    long double temp;
    for(int i = 0; i < inputData.size(); i++){
        sem_wait(&semaphore[0]);
        temp = args->neuron->calculate(memory1)[0];
        memory2[args->index] = temp;
        sem_post(&semaphore[2]);
        sem_wait(&semaphore[3]);
        sem_post(&semaphore[1]);
    }
}

void* Network::output_layer_calc(void* arg){
    Neuron* neuron = (Neuron*) arg;
    for(int i = 0; i < inputData.size(); i++){
        for(int j = 0; j < hls; j++){
            sem_wait(&semaphore[2]);
        }
        memory3.push_back(neuron->calculate(memory2)[0]);
        printf("%Lf\n", memory3[memory3.size()-1]);
        for(int j = 0; j < hls; j++)
            sem_post(&semaphore[3]);
    }
}

void Network::calculate(const vector<vector<long double> >& input){
    int gbg;
    for(int i = 0; i < input.size(); i++)
        inputData.push_back(input[i]);
    pthread_t thread[hiddenLayerSize+2];
    gbg = pthread_create(&thread[0], NULL, input_layer_calc, inputNeuron);
    gbg = pthread_create(&thread[hiddenLayerSize+1], NULL, output_layer_calc, outputNeuron);
    for(int i = 0; i < hiddenLayerSize; i++){
        Args* t = new Args;
        t->index = i;
        t->neuron = hiddenNeuron[i];
        gbg = pthread_create(&thread[i+1], NULL, hidden_layer_calc, t);
    }
    for(int i = 0; i < hiddenLayerSize+2; i++)
        pthread_join(thread[i], NULL);
}