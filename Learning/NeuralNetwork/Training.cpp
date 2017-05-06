//
// Created by Alexandru Brisan on 5/5/17.
//
#include "NeuralNetwork.h"
#include "Training.h"

#include <vector>

namespace MachineLearning{

    using namespace std;

    double get_delta(SLFFNeuralNetwork *network, pair<vector<double>,double> *training_data, int td_size){
        
    }

    void gradient_descent_training(SLFFNeuralNetwork *network, double learn_rate, const pair<vector<double>,double> *training_data,
                                   int max_step_size, int training_data_size) {

        vector<double> *init_weights = new vector<double>;

        int input_size = network->input_size();

        for(int i = 0 ; i < input_size; ++i){
            init_weights->push_back((double) rand()/RAND_MAX);
        }

        network->update_weights(init_weights);

        for(int i = 0 ; i < max_step_size ; ++i){
            double delta = get_delta(network, training_data, training_data_size);
        }

        delete init_weights;

    }
}