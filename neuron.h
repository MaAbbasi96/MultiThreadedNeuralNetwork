#ifndef NEURON_H
#define NEURON_H

struct Arguments{
    double x, y, z;
    Arguments(double _x, double _y, double _z){
        x = _x;
        y = _y;
        z = _z;
    }
};

class Neuron{
    public:
        Neuron(double w, double b);
    private:
        double weight, bias;
};

#endif