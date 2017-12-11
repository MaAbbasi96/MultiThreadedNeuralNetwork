#include "network.h"
#include "utils.h"

using namespace std;

int main(){
    int n;
    clock_t startTime, midTime, endTime;
    vector<vector<long double> > input;
    vector<activationFunc> actFunc;
    actFunc.push_back(utils::f1);
    actFunc.push_back(utils::f2);
    actFunc.push_back(utils::f3);
    cout << "Enter number of neurons in hidden layer: ";
    cin >> n;
    utils::get_input(input);
    Network* net = new Network(n, actFunc);
    startTime = clock();
    vector<long double> out1 = net->calculate(input);
    midTime = clock();
    vector<long double> out2 = net->calculate_serial(input);
    endTime = clock();
    vector<long double> ans = utils::get_real_answer(input);
    cout << "Thread outputs are:\n";
    utils::print_vector(out1);
    cout << "Serial outputs are:\n";
    utils::print_vector(out2);
    cout << "Fault is: " << utils::get_fault(out1, ans) << endl;
    cout << "Speedup is: " << ((float)(endTime - midTime) / CLOCKS_PER_SEC) / ((float)(midTime - startTime) / CLOCKS_PER_SEC) << endl;
}