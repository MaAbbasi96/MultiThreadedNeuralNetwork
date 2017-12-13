#include "utils.h"

using namespace std;

void utils::get_input(vector<vector<long double> >& input, string fileName){
    ifstream file;
    long double x;
    file.open(fileName.c_str());
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

vector<long double> utils::f1(const vector<long double>& input){
    return input;
}

vector<long double> utils::f3(const vector<long double>& input){
    vector<long double> res;
    long double sum = 0;
    for(int i = 0; i < input.size(); i++)
        sum += input[i];
    res.push_back(sum);
    return res;
}

vector<long double> utils::f2(const vector<long double>& input){
    vector<long double> res;
    long double sum = 0;
    for(int i = 0; i < input.size(); i++)
        sum += input[i];
    res.push_back(tanh(sum));
    return res;
}

void utils::print_vector(const vector<long double>& vec){
    cout << setprecision(20) << fixed;
    for(int i = 0; i < vec.size(); i++){
        if(vec[i] > 0)
            cout << "+";
        cout << vec[i] << endl;
    }
}

long double utils::function(const vector<long double>& input){
    return (-input[1] + sqrt(fabs(input[1]*input[1] - 4*input[0]*input[2]))/ (2*input[0]+sin(input[0]*M_PI)));
}

vector<long double> utils::get_real_answer(const vector<vector<long double> >& input){
    vector<long double> res;
    for(int i = 0; i < input.size(); i++)
        res.push_back(function(input[i]));
    return res;
}

long double utils::get_fault(const vector<long double>& in1, const vector<long double>& in2){
    int size = in1.size();
    long double fault = 0;
    for(int i = 0; i < size; i++)
        fault += (in1[i] - in2[i]) * (in1[i] - in2[i]);
    return sqrt(fault/(double)size);
}
