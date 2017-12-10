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

vector<long double> f1(const vector<long double>& input){
    return input;
}

vector<long double> f3(const vector<long double>& input){
    vector<long double> res;
    long double sum = 0;
    for(int i = 0; i < input.size(); i++)
        sum += input[i];
    res.push_back(sum);
    return res;
}

vector<long double> f2(const vector<long double>& input){
    vector<long double> res;
    long double sum = 0;
    for(int i = 0; i < input.size(); i++)
        sum += input[i];
    res.push_back(tanh(sum));
    return res;
}

void print_vector(const vector<long double>& vec){
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << endl;
}

int main(){
    int n;
    vector<vector<long double> > input;
    vector<activationFunc> actFunc;
    actFunc.push_back(f1);
    actFunc.push_back(f2);
    actFunc.push_back(f3);
    cout << "Enter number of neurons in hidden layer: ";
    cin >> n;
    get_input(input);
    Network* net = new Network(n, actFunc); 
    vector<long double> out = net->calculate(input);
    print_vector(out);
}