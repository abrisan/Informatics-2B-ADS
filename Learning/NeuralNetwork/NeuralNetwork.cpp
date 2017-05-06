//
// Created by Alexandru Brisan on 5/5/17.
//
#include "NeuralNetwork.h"
#include <vector>
#include <cmath>

namespace MachineLearning{

    using namespace std;

    Neuron::Neuron(vector<double> *ws, Activation ac) {
        weights = new double[ws->size()];
        for(int i = 0 ; i <  ws->size(); ++i){
            weights[i] = (*ws)[i];
        }
        size = ws->size();
        func = ac;

    }

    Neuron::Neuron(unsigned long sz, Activation ac) {
        weights = new double[sz];
        size = sz;
        func = ac;
    }

    Neuron::~Neuron() {
        delete[] weights;
    }

    void Neuron::set_weights(vector<double> *ws) {
        if(ws->size() != size){
            throw "NEURON (SET_WEIGHTS) : INCOMPATIBLE SIZES";
        }
        for(unsigned long i = 0 ; i < size ; ++i){
            weights[i] = (*ws)[i];
        }
    }

    double Neuron::compute_output_for_input(vector<double> *input) {
        if(input->size() != size)
            throw "NEURON (OUTPUT) : INCOMPATIBLE SIZES";
        double result = 0;
        for(unsigned long i = 0 ; i < size ; ++i){
            result += weights[i] * (*input)[i];
        }
        if(func == SIGMOIDAL){
            return 1 / (1+exp(-1 * result));
        }else if(func == STEP){
            return result >= 0;
        }else{
            throw "NEURON (OUTPUT) : INVALID STATE";
        }
    }

    unsigned long Neuron::get_size() {
        return size;
    }


    SLFFNeuralNetwork::SLFFNeuralNetwork(vector<double> *weights, Activation ac) {
        n = new Neuron(weights, ac);
    }

    SLFFNeuralNetwork::SLFFNeuralNetwork(unsigned long m, Activation ac) {
        n = new Neuron(m, ac);
    }

    SLFFNeuralNetwork::~SLFFNeuralNetwork() {
        delete n;
    }

    double SLFFNeuralNetwork::compute_output_for_input(vector<double> *input) {
        return n->compute_output_for_input(input);
    }

    void SLFFNeuralNetwork::update_weights(vector<double> *input) {
        n->set_weights(input);
    }

    unsigned long SLFFNeuralNetwork::input_size() {
        return n->get_size();
    }
}
