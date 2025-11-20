#include "Matrix.hpp"
#include "gtest/gtest.h"

template <typename T> class MatrixTest : public ::testing::Test {};

typedef ::testing::Types<int, double> MatrixTypes;
TYPED_TEST_SUITE(MatrixTest, MatrixTypes);

TYPED_TEST(MatrixTest, AlignmentAfterConstruction) {
  std::vector<std::vector<TypeParam>> initial_data = {
      {1, 2, 3}, {4, 5}, {6, 7, 8, 9}, {10}};

  Matrix<TypeParam> m(initial_data);

  const auto &result_data = MatrixTestHelper::getData(m);

  ASSERT_EQ(result_data.size(), 4)
      << "Количество строк должно соответствовать исходному.";

  size_t expected_size = 4;
  for (const auto &row : result_data) {
    EXPECT_EQ(row.size(), expected_size)
        << "Все строки должны быть выравнены до максимальной длины.";
  }

  EXPECT_EQ(result_data[0][0], (TypeParam)1);
  EXPECT_EQ(result_data[1][1], (TypeParam)5);
  EXPECT_EQ(result_data[2][3], (TypeParam)9);
}

TYPED_TEST(MatrixTest, AlreadyRectangular) {

  std::vector<std::vector<TypeParam>> initial_data = {{1, 2}, {3, 4}, {5, 6}};

  Matrix<TypeParam> m(initial_data);
  const auto &result_data = MatrixTestHelper::getData(m);

  ASSERT_EQ(result_data.size(), 3);
  for (const auto &row : result_data) {
    EXPECT_EQ(row.size(), 2)
        << "Размер должен остаться 2, так как выравнивание не требуется.";
  }

  EXPECT_EQ(result_data[2][1], (TypeParam)6);
}

TYPED_TEST(MatrixTest, WithEmptyRows) {
  std::vector<std::vector<TypeParam>> initial_data = {{}, {1, 2, 3}, {4}};

  Matrix<TypeParam> m(initial_data);
  const auto &result_data = MatrixTestHelper::getData(m);

  size_t expected_size = 3;
  ASSERT_EQ(result_data.size(), 3);
  for (const auto &row : result_data) {
    EXPECT_EQ(row.size(), expected_size)
        << "Все строки должны быть выравнены до 3.";
  }

  EXPECT_EQ(result_data[0][0], (TypeParam)0)
      << "Пустая строка должна заполниться значениями по умолчанию.";
  EXPECT_EQ(result_data[2][1], (TypeParam)0)
      << "Короткая строка должна заполниться значениями по умолчанию.";

  EXPECT_EQ(result_data[1][2], (TypeParam)3);
}

TEST(MatrixIntTest, EmptyMatrix) {
  std::vector<std::vector<int>> initial_data = {};

  Matrix<int> m(initial_data);
  const auto &result_data = MatrixTestHelper::getData(m);

  EXPECT_TRUE(result_data.empty())
      << "Конструктор пустой матрицы должен давать пустые данные.";
}

TEST(MatrixDoubleTest, AllEmptyRows) {
  std::vector<std::vector<double>> initial_data = {{}, {}, {}};

  Matrix<double> m(initial_data);
  const auto &result_data = MatrixTestHelper::getData(m);

  ASSERT_EQ(result_data.size(), 3);

  for (const auto &row : result_data) {
    EXPECT_EQ(row.size(), 0)
        << "Все строки должны остаться длиной 0, так как максимальная длина 0.";
  }
}
