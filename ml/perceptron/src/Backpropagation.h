#pragma once

#include "Perceptron.h"
#include "TrainingData.h"

class Backpropagation {
private:
  double learning_rate;
  int max_epochs;

public:
  Backpropagation(double lr, int epochs);

  void train(Perceptron &model, const std::vector<TrainingData> &data);
};
