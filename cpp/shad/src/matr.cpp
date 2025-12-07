#include "matr.h"
#include <algorithm>

double calculateDeterminant(std::vector<std::vector<double>> matrix) {
  int n = matrix.size();
  double det = 1.0;

  for (int i = 0; i < n; ++i) {
    int pivot = i;
    for (int j = i + 1; j < n; ++j) {
      if (std::abs(matrix[j][i]) > std::abs(matrix[pivot][i])) {
        pivot = j;
      }
    }

    if (std::abs(matrix[pivot][i]) < 1e-9) {
      return 0.0;
    }

    swap(matrix[i], matrix[pivot]);
    if (i != pivot) {
      det *= -1;
    }

    det *= matrix[i][i];

    for (int j = i + 1; j < n; ++j) {
      double factor = matrix[j][i] / matrix[i][i];
      for (int k = i + 1; k < n; ++k) {
        matrix[j][k] -= factor * matrix[i][k];
      }
    }
  }

  return det;
}
