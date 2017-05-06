//
// Created by Alexandru Brisan on 5/5/17.
//

#ifndef INF2B_NEURALNETWORK_H
#define INF2B_NEURALNETWORK_H

#include <vector>

namespace MachineLearning{

    using namespace std;

    enum Activation {STEP, SIGMOIDAL};

    class Neuron{
        double *weights;
        unsigned long size;
        Activation func;
    public:
        Neuron(vector<double> *weights, Activation ac);
        Neuron(unsigned long size, Activation ac);
        ~Neuron();
        void set_weights(vector<double> *weights);
        double compute_output_for_input(vector<double> *input);
        unsigned long get_size();
    };

    class SLFFNeuralNetwork{ // single layer feed forward neural network
        Neuron *n;
    public:
        SLFFNeuralNetwork(vector<double> *weights, Activation ac);
        SLFFNeuralNetwork(unsigned long n, Activation ac);
        ~SLFFNeuralNetwork();
        double compute_output_for_input(vector<double> *input);
        void update_weights(vector<double> *input);
        unsigned long input_size();
    };
}

#endif //INF2B_NEURALNETWORK_H
