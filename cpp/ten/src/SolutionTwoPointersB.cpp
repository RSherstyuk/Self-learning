#include "SolutionTwoPointersB.h"

#include <algorithm>

std::vector<std::vector<int>>
SolutionTwoPointersB::threeSum(std::vector<int> &nums) {

  std::sort(nums.begin(), nums.end());
  std::vector<std::vector<int>> result;

  int n = nums.size();

  for (int i = 0; i < n - 1; ++i) {

    if (i > 0 && nums[i] == nums[i - 1]) {
      continue;
    }

    int target = -nums[i];
    int left = i + 1;
    int right = n - 1;

    while (left < right) {
      int sum = nums[left] + nums[right];
      if (sum == target) {
        result.push_back({nums[i], nums[left], nums[right]});

        int current_left = nums[left];
        int current_right = nums[right];

        while (left < right && nums[left] == current_left) {
          left++;
        }

        while (left < right && nums[right] == current_right) {
          right--;
        }

      } else if (sum > target) {
        right--;
      } else {
        left++;
      }
    }
  }

  return result;
}
