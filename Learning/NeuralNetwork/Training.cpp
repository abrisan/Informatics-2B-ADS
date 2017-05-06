//
// Created by Alexandru Brisan on 5/5/17.
//
#include "NeuralNetwork.h"
#include "Training.h"

#include <vector>

namespace MachineLearning{

    using namespace std;

    void gradient_descent_training(SLFFNeuralNetwork *network, double learn_rate, pair<vector<double>,vector<double>> *training_data,
                                   int max_step_size, int training_data_size) {

        vector<double> *init_weights = new vector<double>;




        for(int i = 0 ; i < max_step_size ; ++i){

        }

        delete init_weights;

    }
}