#include <gtest/gtest.h>
#include <vector>
#include "Perceptron.h" // Подключаем ваш заголовочный файл с классами
#include "TrainingData.h"
#include "Backpropagation.h"

TEST(PerceptronTrainingTest, SolvesLogicalAND) {
    std::vector<TrainingData> dataset = {
        {{0, 0}, 0},
        {{0, 1}, 0},
        {{1, 0}, 0},
        {{1, 1}, 1}
    };

    Perceptron model(2);
    Backpropagation optimizer(0.1, 50); 

    optimizer.train(model, dataset);

    for (const auto& sample : dataset) {
        int prediction = model.predict(sample.inputs);
        
        SCOPED_TRACE("Input: " + std::to_string(sample.inputs[0]) + ", " + std::to_string(sample.inputs[1]));
        
        EXPECT_EQ(prediction, sample.target);
    }
}

TEST(PerceptronTrainingTest, SolvesLogicalOR) {
    std::vector<TrainingData> dataset = {
        {{0, 0}, 0},
        {{0, 1}, 1},
        {{1, 0}, 1},
        {{1, 1}, 1}
    };

    Perceptron model(2);
    Backpropagation optimizer(0.1, 50);

    optimizer.train(model, dataset);

    for (const auto& sample : dataset) {
        SCOPED_TRACE("Input OR test");
        EXPECT_EQ(model.predict(sample.inputs), sample.target);
    }
}
