#include <iostream>
#include "Perceptron.h"

namespace MLLJET001 {
    /**
     * Using the training data the perceptron was initialized with
     * it trains it. It does iterations passes over the training data.
     */
    void Perceptron::trainPerceptron(int iterations, float learningRate) {
        for (int i = 0; i < iterations; ++i) {
            int errors = 0;
            for (auto data : trainingData) {
                int target = (int)data[4];
                // only affects the temp data variable
                // Makes code less messy and accounts for the bias term.
                data[4] = 1;
                int output = -1;


                float input_sum = 0;
                for (int j=0; j < weights.size(); j++) {
                    input_sum += data[j] * weights[j];
                }

                if (input_sum > 0) {
                    output = 1;
                }

                if (output != target) {
                    errors += 1;
                    for (int j=0; j < weights.size(); j++) {
                        weights[j] += learningRate * (target - output) * data[j];
                    }
                }
            }

            if (errors == 0) {
                std::cout << "Iterations: " << i+1 << std::endl;
                break;
            }
        }
    }

    /**
     * Computes the output of the perceptron with the
     * given inputs.
     */
    int Perceptron::compute(float in1, float in2, float in3, float in4) {
        float input_sum = (in1 * weights[0]) + (in2 * weights[1]) + (in3 * weights[2])
                          + (in4 * weights[3]) + weights[4];
        std::cout << input_sum << std::endl;
        return ((input_sum > 0) ? 1 : -1);
    }
};
