#include "SolutionTwoPointers.h"
#include <gtest/gtest.h>

TEST(TwoSumTest, FindsPairThatSumsToTarget) {
  SolutionTwoPointers sol;
  std::vector<int> nums = {2, 7, 11, 15};
  int target = 9;

  std::vector<int> result = sol.twoSum(nums, target);
  std::sort(result.begin(), result.end());

  EXPECT_EQ(result, std::vector<int>({2, 7}));
}

TEST(isPolTest, find) {
  SolutionTwoPointers sol;
  std::string s = "aasaa";

  EXPECT_TRUE(sol.isPalindrome(s));
}

TEST(reverseStringTest, reverse) {
  SolutionTwoPointers sol;
  std::string s = "asdfe";

  sol.reverseString(s);

  EXPECT_EQ(s, "efdsa");
}

TEST(ThreeSumTest, find) {
  SolutionTwoPointers sol;
  std::vector<int> v{-1, 0, 1, 2, -1, 4};

  std::vector<std::vector<int>> result = sol.threeSum(v);
  std::vector<std::vector<int>> nums = {{-1, -1, 2}, {-1, 0, 1}};

  EXPECT_EQ(result, nums);
}
