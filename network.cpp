#include "network.h"

using namespace std;

void Network::get_info(){
    string gbg;
    double x, y, z;
    ifstream file;
    file.open("LayersInfo.txt");
    file >> gbg;
    for(int i = 0; i < hiddenLayerSize; i++){
        file >> x;
        biases.push_back(x);
    }
    file >> gbg;
    for(int i = 0; i < hiddenLayerSize; i++){
        file >> x >> y >> z;
        hiddenLayerWeights.push_back(Arguments(x, y, z));
    }
    file >> gbg;
    file >> outputBias;
    file >> gbg;
    for(int i = 0; i < hiddenLayerSize; i++){
        file >> x;
        outputWeights.push_back(x);
    }
    file.close();
}

Network::Network(int h){
    hiddenLayerSize = h;
    get_info();
}

double calculate(Arguments args){

}