#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include "network.h"

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

int main(){
    int n;
    double out;
    vector<vector<double> > input;
    cout << "Enter number of neurons in hidden layer: ";
    cin >> n;
    get_input(input);
    Network* net = new Network(n); 
    // net->calculate("InputFile.txt");   
}