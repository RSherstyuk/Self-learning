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
  std::vector<int> v{2, 3, 1, 2, 4, 3};
  int target = 7;

  double result = sol.minSubArrayLen(target, v);
  double expected = 2;

  ASSERT_EQ(result, expected);
}

TEST(MinSubArrayLenTwo, minLenSubArray) {
  SlidingWindow sol;
  std::vector<int> v{1, 1, 1, 1, 1, 1, 1, 1};
  int target = 11;

  double result = sol.minSubArrayLen(target, v);
  double expected = 0;

  ASSERT_EQ(result, expected);
}

TEST(TestLongesOnes, longestOnes) {

  SlidingWindow sol;

  std::vector<int> v{1,1,1,0,0,0,1,1,1,1,0};
  int k = 2;

  double result = sol.longestOnes(v, k);
  double expected = 6;

  ASSERT_EQ(result, expected);
}
