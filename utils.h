#ifndef UTILS_H
#define UTILS_H

#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>
#include <time.h>

namespace utils{
    void get_input(std::vector<std::vector<long double> >& input);
    std::vector<long double> f1(const std::vector<long double>& input);
    std::vector<long double> f3(const std::vector<long double>& input);
    std::vector<long double> f2(const std::vector<long double>& input);
    void print_vector(const std::vector<long double>& vec);
    long double function(const std::vector<long double>& input);
    std::vector<long double> get_real_answer(const std::vector<std::vector<long double> >& input);
    long double get_fault(const std::vector<long double>& in1, const std::vector<long double>& in2);
};

#endif