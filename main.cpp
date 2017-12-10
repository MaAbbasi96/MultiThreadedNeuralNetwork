#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include "network.h"
#include <math.h>

using namespace std;

void get_input(vector<vector<double> >& input){
    ifstream file;
    double x;
    file.open("InputFile.txt");
    while(!file.eof()){
        vector<double> temp;
        for(int i = 0; i < 3; i++){
            file >> x;
            temp.push_back(x);
        }
        input.push_back(temp);
    }
    file.close();
}

double f1(double input){
    return input;
}

double f2(double input){
    return tanh(input);
}

int main(){
    int n;
    double out;
    vector<vector<double> > input;
    vector<activationFunc> actFunc;
    actFunc.push_back(f1);
    actFunc.push_back(f2);
    actFunc.push_back(f1);
    cout << "Enter number of neurons in hidden layer: ";
    cin >> n;
    get_input(input);
    Network* net = new Network(n, actFunc); 
    // net->calculate("InputFile.txt");   
}