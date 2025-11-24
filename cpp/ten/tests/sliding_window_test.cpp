#include "SlidingWindow.h"
#include <gtest/gtest.h>

TEST(MaxAverageSubArray, findMaxAverage) {
  SlidingWindow sol;
  std::vector<int> v{1,12,-5,-6,50,3};
  int k = 4;

  double result = sol.findMaxAverage(v, k);
  double expected = 12.75000;

  ASSERT_EQ(result, expected);
}
