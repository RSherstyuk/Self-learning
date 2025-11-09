#include <vector>

class MatrixTestHelper;

template <typename T> class Matrix {
private:
  std::vector<std::vector<T>> data;

  void MakeRec() {
    size_t maxSize = 0;

    for (const auto &row : data) {
      if (row.size() > maxSize) {
        maxSize = row.size();
      }
    }

    for (auto &row : data) {
      row.resize(maxSize);
    }
  }

public:
  Matrix(const std::vector<std::vector<T>> &d) : data(d) { MakeRec(); }

  friend class MatrixTestHelper;
};

class MatrixTestHelper {
public:
  template <typename T>
  static const std::vector<std::vector<T>> &getData(const Matrix<T> &m) {
    return m.data;
  }
};
