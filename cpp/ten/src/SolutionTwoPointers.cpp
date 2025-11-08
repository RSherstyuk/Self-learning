#include "../include/SolutionTwoPointers.h"

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
  std::vector<std::vector<int>> result;
  int n = nums.size();

  std::sort(nums.begin(), nums.end());

  for (int i = 0; i < n - 2; ++i) {

    if (i > 0 && nums[i] == nums[i - 1]) {
      continue;
    }

    if (nums[i] > 0) {
      break;
    }

    int j = i + 1;
    int k = n - 1;
    int target = 0 - nums[i];

    while (j < k) {
      int current_sum = nums[j] + nums[k];

      if (current_sum == target) {
        result.push_back({nums[i], nums[j], nums[k]});

        while (j < k && nums[j] == nums[j + 1]) {
          j++;
        }
        while (j < k && nums[k] == nums[k - 1]) {
          k--;
        }

        j++;
        k--;
      } else if (current_sum < target) {
        j++;
      } else {
        k--;
      }
    }
  }

  return result;
}

