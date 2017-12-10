#include "network.h"

using namespace std;

void Network::get_info(){
    string gbg;
    double x, y, z;
    vector<double> temp;

    // input neuron initialize
    bias.push_back(0);
    for(int i = 0; i < 3; i++)
        temp.push_back(1);
    weight.push_back(temp);
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
        weight.push_back(temp);
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
    weight.push_back(temp);
    file.close();
}

void Network::make_layers(){
    
}

Network::Network(int h){
    hiddenLayerSize = h;
    get_info();
    // make_layers();
}

double calculate(string fileName){
    
}