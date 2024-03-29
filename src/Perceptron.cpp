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
            float error = 0;
            for (auto data : trainingData) {
                float target = data[4];

                float input_sum = 0;
                for (int j=0; j < weights.size(); j++) {
                    input_sum += data[j] * weights[j];
                }

                if (input_sum != target) {
                    error += pow(target - input_sum, 2);
                    for (int j=0; j < weights.size(); j++) {
                        weights[j] += learningRate * (target - input_sum) * data[j];
                    }
                }
            }

            error *= 0.5F;

            if (error < 0.001F) {
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
        std::cout << "Weight Sum (not rounded): " << input_sum << std::endl;
        return  input_sum;
    }
};
