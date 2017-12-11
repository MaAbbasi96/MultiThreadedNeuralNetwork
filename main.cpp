#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include "network.h"
#include <math.h>
#include <time.h>

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
    cout << setprecision(20) << fixed;
    for(int i = 0; i < vec.size(); i++){
        if(vec[i] > 0)
            cout << "+";
        cout << vec[i] << endl;
    }
}

long double function(const vector<long double>& input){
    return (-input[1] + sqrt(fabs(input[1]*input[1] - 4*input[0]*input[2]))/ (2*input[0]+sin(input[0]*M_PI)));
}

vector<long double> get_real_answer(const vector<vector<long double> >& input){
    vector<long double> res;
    for(int i = 0; i < input.size(); i++)
        res.push_back(function(input[i]));
    return res;
}

long double get_fault(const vector<long double>& in1, const vector<long double>& in2){
    int size = in1.size();
    long double fault = 0;
    for(int i = 0; i < size; i++)
        fault += (in1[i] - in2[i]) * (in1[i] - in2[i]);
    return sqrt(fault/(double)size);
}

int main(){
    int n;
    clock_t startTime, midTime, endTime;
    vector<vector<long double> > input;
    vector<activationFunc> actFunc;
    actFunc.push_back(f1);
    actFunc.push_back(f2);
    actFunc.push_back(f3);
    cout << "Enter number of neurons in hidden layer: ";
    cin >> n;
    get_input(input);
    Network* net = new Network(n, actFunc);
    startTime = clock();
    vector<long double> out1 = net->calculate(input);
    midTime = clock();
    vector<long double> out2 = net->calculate_serial(input);
    endTime = clock();
    vector<long double> ans = get_real_answer(input);
    cout << "Thread outputs are:\n";
    print_vector(out1);
    cout << "Serial outputs are:\n";
    print_vector(out2);
    cout << "Fault is: " << get_fault(out1, ans) << endl;
    cout << "Speedup is: " << ((float)(endTime - midTime) / CLOCKS_PER_SEC) / ((float)(midTime - startTime) / CLOCKS_PER_SEC) << endl;
}