#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include "Perceptron.h"

using namespace std;

/**
 * Read in training data from file and return a vector of float
 * vectors.
 */
std::vector<std::vector<float>> getTrainingData(string fileName) {
    std::ifstream infile(fileName);
    std::vector<std::vector<float>> trainingData;
    if (infile.is_open()) {
        string line;
        while (getline(infile, line)) {
            stringstream inputLine(line);
            std::vector<float> data;
            for (int i = 0; i < 5; ++i) {
                float input;
                inputLine >> input;
                data.push_back(input);
            }
            trainingData.push_back(data);
        }
    } else {
        std::cout << "Couldn't open file: " << fileName << std::endl;
    }
    infile.close();

    return trainingData;
}

/**
 * Create the perceptron and read in its training data then train it.
 */
MLLJET001::Perceptron doTraining(int iterations, float learningRate) {
    MLLJET001::Perceptron perceptron(getTrainingData("training_data.txt"));

    perceptron.trainPerceptron(iterations, learningRate);

    cout << "W1: " << perceptron.weights[0] << endl;
    cout << "W2: " << perceptron.weights[1] << endl;
    cout << "W3: " << perceptron.weights[2] << endl;
    cout << "W4: " << perceptron.weights[3] << endl;

    return perceptron;
}

int main() {
    MLLJET001::Perceptron linear_perceptron = doTraining(1000000, 0.1);

    cout << "Perceptron trained!" << endl << endl;

    float x0, x1, x2, x3;

    while (true) {
        cout << "Enter test data" << endl;
        cout << "Enter x0: ";
        cin >> x0;
        cout << "Enter x1: ";
        cin >> x1;
        cout << "Enter x2: ";
        cin >> x2;
        cout << "Enter x3: ";
        cin >> x3;

        cout << "Perceptron Output: " << roundf(linear_perceptron.compute(x0, x1, x2, x3)) << endl;
        char answer;
        cout << "Test again?(y/n) ";
        cin >> answer;
        if (answer == 'n' || answer == 'N') {
            break;
        }
    }

    return 0;
}

