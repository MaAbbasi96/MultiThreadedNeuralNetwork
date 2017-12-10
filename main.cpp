#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include "network.h"
#include <math.h>

using namespace std;

void get_input(vector<vector<long double> >& input){
    ifstream file;
    long double x;
    file.open("InputFile.txt");
    while(!file.eof()){
        vector<long double> temp;
        for(int i = 0; i < 3; i++){
            file >> x;
            temp.push_back(x);
        }
        input.push_back(temp);
    }
    file.close();
}

long double f1(long double input){
    return input;
}

long double f2(long double input){
    return tanh(input);
}

int main(){
    int n;
    long double out;
    vector<vector<long double> > input;
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