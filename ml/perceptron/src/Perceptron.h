#pragma once

#include <vector>

class Perceptron {
private:
  std::vector<int> weights;
  double bias;

  int activate_func(double net_input) const { return (net_input >= 0.0) ? 1 : 0; }

public:
  Perceptron(int inputs);

  int predict(const std::vector<double> num_input) const;

  void update_weights(size_t index, double delta);

  void update_bias(int delta);

  void print_weights() const;

  size_t get_inputsize() const;

};
