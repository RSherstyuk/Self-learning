#include "../include/SolutionTwoPointers.h"

#include <algorithm>

void SolutionTwoPointers::customSwap(char &a, char &b) {
  char temp = a;
  a = b;
  b = temp;
}

void SolutionTwoPointers::reverseString(std::string &s) {
  int left = 0;
  int right = s.size() - 1;
  while (left < right) {
    customSwap(s[left], s[right]);
    left++;
    right--;
  }
}

bool SolutionTwoPointers::isPalindrome(std::string s) {
  std::string original_s = s;
  reverseString(s);
  return (s == original_s);
}

std::vector<int> SolutionTwoPointers::twoSum(std::vector<int> &arr, int n) {
  std::sort(arr.begin(), arr.end());

  int l = 0;
  int r = arr.size() - 1;

  while (l < r) {
    int sum = arr[l] + arr[r];
    if (sum < n) {
      l++;
    } else if (sum > n) {
      r--;
    } else {
      return {arr[l], arr[r]};
    }
  }

  return {-1, -1};
}

std::vector<std::vector<int>>
SolutionTwoPointers::threeSum(std::vector<int> &nums) {
  sort(nums.begin(), nums.end());

  std::vector<std::vector<int>> result;
  int n = nums.size();

  for (int i = 0; i < n; i++) {

    if (i > 0 && nums[i] == nums[i - 1])
      continue;

    int target = -nums[i];
    int left = i + 1;
    int right = n - 1;

    while (left < right) {
      int current_sum = nums[left] + nums[right];

      if (current_sum == target) {
        result.push_back({nums[i], nums[left], nums[right]});

        // Пропуск дубликатов
        while (left < right && nums[left] == nums[left + 1])
          left++;
        while (left < right && nums[right] == nums[right - 1])
          right--;

        left++;
        right--;
      }

      else if (current_sum > target) {

        right--;
      } else {
        left++;
      }
    }
  }
  return result;
}

std::vector<int> SolutionTwoPointers::sortedSquares(std::vector<int> nums) {
  int n = nums.size();
  std::vector<int> result(n);
  int left = 0, right = n - 1;
  int pos = n - 1;
  while (left <= right) {
    int leftSquare = nums[left] * nums[left];
    int rightSquare = nums[right] * nums[right];

    if (leftSquare > rightSquare) {
      result[pos] = leftSquare;
      left++;
    } else {

      result[pos] = rightSquare;
      right--;
    }
    pos--;
  }

  return result;
}
