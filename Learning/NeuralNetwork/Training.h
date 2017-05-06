//
// Created by Alexandru Brisan on 5/5/17.
//

#ifndef INF2B_TRAINING_H
#define INF2B_TRAINING_H

#include "NeuralNetwork.h"

namespace MachineLearning{

    void gradient_descent_training(SLFFNeuralNetwork *network, double learn_rate, vector<double> *training_data, int max_step_size);


}

#endif //INF2B_TRAINING_H
