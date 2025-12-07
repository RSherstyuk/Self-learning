#include <gtest/gtest.h>
#include <matr.h>
#include <vector>

using namespace std;

TEST(TestFindUniqEl, testUniq) {

  vector<vector<double>> matrix = {{2, -1, 0}, {-1, 2, -1}, {0, -1, 2}};

  double result = calculateDeterminant(matrix);

  ASSERT_EQ(result, 4);
}
