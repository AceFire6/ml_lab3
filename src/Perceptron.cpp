#include <iostream>
#include <cmath>
#include "Perceptron.h"

namespace MLLJET001 {
    /**
     * Using the training data the perceptron was initialized with
     * it trains it. It does iterations passes over the training data.
     */
    void Perceptron::trainPerceptron(int iterations, float learningRate) {
        bool broke = false;
        for (int i = 0; i < iterations; ++i) {
            int errors = 0;
            for (auto data : trainingData) {
                float target = data[4];

                float input_sum = 0;
                for (int j=0; j < weights.size(); j++) {
                    input_sum += data[j] * weights[j];
                }

                input_sum =  (float)ceil(input_sum*1000)/1000;

                if (input_sum != target) {
                    errors += 1;
                    for (int j=0; j < weights.size(); j++) {
                        weights[j] += learningRate * (target - input_sum) * data[j];
                    }
                }
            }

            if (errors == 0) {
                std::cout << "Iterations: " << i+1 << std::endl;
                broke = true;
                break;
            }
        }
        if (!broke) {
            std::cout << "Iterations: " << iterations << std::endl;
        }
    }

    /**
     * Computes the output of the perceptron with the
     * given inputs.
     */
    float Perceptron::compute(float in1, float in2, float in3, float in4) {
        float input_sum = (in1 * weights[0]) + (in2 * weights[1]) + (in3 * weights[2])
                          + (in4 * weights[3]) + weights[4];
        std::cout << "Weight Sum: " << input_sum << std::endl;
        return  (float) ceil(input_sum * 1000) / 1000;
    }
};
