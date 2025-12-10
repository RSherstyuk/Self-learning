#include "Backpropagation.h"
#include <iostream>

Backpropagation::Backpropagation(double lr, int epochs)
    : learning_rate(lr), max_epochs(epochs) {}

void Backpropagation::train(Perceptron &model,
                       const std::vector<TrainingData> &data) {
  std::cout << "--- start Backpropagation Trainer ---\n";

  for (int epoch = 0; epoch < max_epochs; ++epoch) {
    int total_error = 0;

    for (const auto &sample : data) {
      int prediction = model.predict(sample.inputs);

      int error = sample.target - prediction;
      total_error += std::abs(error);

      if (error != 0) {
        for (size_t i = 0; i < model.get_inputsize(); ++i) {
          // Delta = LR * Error * Input
          double delta = learning_rate * error * sample.inputs[i];
          model.update_weights(i, delta);
        }

        model.update_bias(learning_rate * error);
      }
    }

    std::cout << "Epoch " << epoch + 1 << ": Err = " << total_error << " ";
    model.print_weights();
    std::cout << "\n";

    if (total_error == 0) {
      std::cout << "-> Convergence stop!\n";
      break;
    }
  }
  std::cout << "--- stop train ---\n\n";
}
