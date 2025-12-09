#include "SolutionTwoPointers.h"
#include "SolutionTwoPointersB.h"
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

TEST(ThreeSumTestB, HandlesSpecificCase) {
  SolutionTwoPointersB sol_B;
  std::vector<int> v{-1, 0, 1, 2, -1, 4};

  std::vector<std::vector<int>> result = sol_B.threeSum(v);
  std::vector<std::vector<int>> nums = {{-1, -1, 2}, {-1, 0, 1}};

  EXPECT_EQ(result, nums);
}

TEST(SquareTwoPointers, sortTrue) {
  SolutionTwoPointers sol;
  std::vector<int> v{-4, -1, 0, 3, 10};

  std::vector<int> res = sol.sortedSquares(v);
  std::vector<int> true_res{0, 1, 9, 16, 100};

  EXPECT_EQ(res, true_res);
}

TEST(SquareTwoPointers, fSum) {
  SolutionTwoPointers sol;
  std::vector<int> v = {-1, 0, -1, 0, -2, 2};

  std::vector<std::vector<int>> result = sol.fSum(v, 0);
  std::vector<std::vector<int>> true_res{{-2, 0, 0, 2}, {-1, -1, 0, 2}};

  EXPECT_EQ(result, true_res);
}

TEST(maxAreaPointers, maxArea) {
  SolutionTwoPointers sol;
  std::vector<int> v = {1, 8, 6, 2, 5, 4, 8, 3, 7};

  int result = sol.maxArea(v);
  int true_res = 49;

  EXPECT_EQ(result, true_res);
}

TEST(removeDupicatesFormSortedArray, removeDuplicates) {
  SolutionTwoPointers sol;
  std::vector<int> v = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

  int result = sol.removeDuplicates(v);
  int true_res = 5;

  EXPECT_EQ(result, true_res);
}

TEST(moveAllZeroes, moveZeroes) {

  SolutionTwoPointers sol;

  std::vector<int> v = {0, 1, 0, 3, 12};

  sol.moveZeroes(v);
  std::vector<int> true_res = {1, 3, 12, 0, 0};

  EXPECT_EQ(v, true_res);
}

TEST(isSubseq, isSubSeq) {

  SolutionTwoPointers sol;

  std::string s = "abc";
  std::string t = "ahbgdc";

  bool res = sol.isSubseq(s, t);

  EXPECT_EQ(res, true);
}

TEST(backSpace, compareBackspace) {

  SolutionTwoPointers sol;

  std::string s = "ab#c";
  std::string t = "ad#c";

  bool res = sol.backspaceCompare(s, t);

  EXPECT_EQ(res, true);
}

TEST(MergeTest, BasicMergeCase) {
  std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  int m = 3;
  std::vector<int> nums2 = {2, 5, 6};
  int n = 3;

  std::vector<int> expected = {1, 2, 2, 3, 5, 6};

  SolutionTwoPointers sol;

  sol.merge(nums1, m, nums2, n);
  ASSERT_EQ(nums1, expected) << "Слияние не дало ожидаемого результата. nums1 "
                                "должно быть: [1, 2, 2, 3, 5, 6]";
}

TEST(MergeTestWith, BasicMergeCase) {
  std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};

  int m = 3;
  std::vector<int> nums2 = {2, 5, 6};
  int n = 3;

  std::vector<int> expected = {1, 2, 2, 3, 5, 6};

  SolutionTwoPointers sol;

  sol.mergeWith(nums1, m, nums2, n);
  ASSERT_EQ(nums1, expected) << "Слияние не дало ожидаемого результата. nums1 "
                                "должно быть: [1, 2, 2, 3, 5, 6]";
}

