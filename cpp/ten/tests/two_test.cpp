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
