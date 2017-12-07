#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include "network.h"

using namespace std;

void get_input(vector<Arguments>& input){
    ifstream file;
    double x, y, z;
    file.open("InputFile.txt");
    while(!file.eof()){
        file >> x >> y >> z;
        input.push_back(Arguments(x, y, z)); 
    }
    file.close();
}

int main(){
    int n;
    double out;
    vector<Arguments> input;
    cout << "Enter number of neurons in hidden layer: ";
    cin >> n;
    get_input(input);
    Network* net = new Network(n);    
}