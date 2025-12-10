#include "Perceptron.h"

#include <iostream>

Perceptron::Perceptron(int inputs) : weights(inputs, 0), bias(0.0) {}

int Perceptron::predict(const std::vector<double> num_input) const {
  int predicted = bias;

  for (size_t i = 0; i < num_input.size(); ++i) {
    predicted += weights[i] * num_input[i];
  }

  return activate_func(predicted);
}

void Perceptron::update_weights(size_t index, double delta) {
  if (index < weights.size()) {
    weights[index] += delta;
  }
}

void Perceptron::update_bias(int delta) { bias += delta; }

void Perceptron::print_weights() const {
  std::cout << "(weights: ";
  for (auto w : weights)
    std::cout << w << " ";
  std::cout << "| bias: " << bias << ")";
}

size_t Perceptron::get_inputsize() const { return weights.size(); }
