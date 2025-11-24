#include "SlidingWindow.h"
#include <gtest/gtest.h>

TEST(MaxAverageSubArray, findMaxAverage) {
  SlidingWindow sol;
  std::vector<int> v{1, 12, -5, -6, 50, 3};
  int k = 4;

  double result = sol.findMaxAverage(v, k);
  double expected = 12.75000;

  ASSERT_EQ(result, expected);
}

TEST(MaxAverageSubArrayTen, findMaxAverageTen) {
  SlidingWindow sol;
  std::vector<int> v{1, 12, -5, -6, 50, 3};
  int k = 4;

  double result = sol.findMaxAverageTen(v, k);
  double expected = 12.75000;

  ASSERT_EQ(result, expected);
}

TEST(MinSubArrayLen, minLenSubArray) {
  SlidingWindow sol;
  std::vector<int> v{2,3,1,2,4,3};
  int target = 7;

  double result = sol.minSubArrayLen(target, v);
  double expected = 2;

  ASSERT_EQ(result, expected);
}
