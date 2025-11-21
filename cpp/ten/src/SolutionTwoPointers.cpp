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

bool SolutionTwoPointers::isPalindrome(std::string &s) {
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

std::vector<int> SolutionTwoPointers::sortedSquares(std::vector<int> &nums) {
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

std::vector<std::vector<int>> SolutionTwoPointers::fSum(std::vector<int> &nums,
                                                        int target) {
  std::vector<std::vector<int>> result;
  int n = nums.size();

  if (n < 4)
    return result;

  sort(nums.begin(), nums.end());

  for (int i = 0; i < n - 3; ++i) {
    if (i > 0 && nums[i] == nums[i - 1])
      continue;

    for (int j = i + 1; j < n - 2; ++j) {
      if (j > i + 1 && nums[j] == nums[j - 1])
        continue;

      long long target_2 = (long long)target - nums[i] - nums[j];

      int l = j + 1;
      int r = n - 1;

      while (l < r) {
        long long cur_sum_2 = (long long)nums[l] + nums[r];

        if (cur_sum_2 == target_2) {
          result.push_back({nums[i], nums[j], nums[l], nums[r]});

          while (l < r && nums[l] == nums[l + 1])
            l++;
          while (l < r && nums[r] == nums[r - 1])
            r--;

          l++;
          r--;
        } else if (cur_sum_2 < target_2) {
          l++;
        } else {
          r--;
        }
      }
    }
  }

  return result;
}

int SolutionTwoPointers::maxArea(std::vector<int> &nums) {
  int n = nums.size();
  int l = 0;
  int r = n - 1;

  int result = 0;

  while (l <= r) {
    int width = r - l;

    result = std::max(result, width * std::min(nums[l], nums[r]));

    if (nums[l] < nums[r])
      l++;
    else
      r--;
  }

  return result;
}

int SolutionTwoPointers::removeDuplicates(std::vector<int> &nums) {
  int k = 0;

  for (int i = 0; i <= nums.size(); ++i) {

    if (nums[k] != nums[i]) {
      k++;
      nums[k] = nums[i];
    }
  }
  return k;
}

void SolutionTwoPointers::moveZeroes(std::vector<int> &nums) {
  int n = nums.size();

  int left = 0;
  for (int i = 0; i < n; i++) {
    if (nums[i] != 0) {
      std::swap(nums[left], nums[i]);
      left++;
    }
  }
}

bool SolutionTwoPointers::isSubseq(std::string &s, std::string &t) {
  int i = 0;
  int j = 0;
  int m = t.length();
  int n = s.length();

  while (i < n && j < m) {
    if (s[i] == t[j]) {
      i++;
    }
    j++;
  }

  return i == n;
}

bool SolutionTwoPointers::backspaceCompare(std::string &s, std::string &t) {
  int i = s.size() - 1;
  int j = t.size() - 1;
  int skipS = 0, skipT = 0;

  while (i >= 0 || j >= 0) {
    while (i >= 0) {
      if (s[i] == '#') {
        skipS++;
        i--;
      } else if (skipS > 0) {
        skipS--;
        i--;
      } else {
        break;
      }
    }

    while (j >= 0) {
      if (t[j] == '#') {
        skipT++;
        j--;
      } else if (skipT > 0) {
        skipT--;
        j--;
      } else {
        break;
      }
    }

    if (i >= 0 && j >= 0 && s[i] != t[j])
      return false;
    if ((i >= 0) != (j >= 0))
      return false;
    i--;
    j--;
  }
  return true;
}

void SolutionTwoPointers::merge(std::vector<int> nums1, int m,
                                std::vector<int> nums2, int n) {

  int p1 = m - 1;
  int p2 = n - 2;

  int result = m + n - 1;

  while (p1 >= 0 && p2 >= 0) {
    if (nums1[p1] > nums2[p2]) {
      nums1[result] = nums1[p1];
      p1--;
    } else {
      nums1[result] = nums2[p2];
      p2--;
    }
    result--;
  }

  while (p2 >= 0) {
    nums1[result] = nums2[p2];
    p2--;
    result--;
  }
}

void SolutionTwoPointers::mergeWith(std::vector<int> nums1, int m,
                                    std::vector<int> nums2, int n) {
  int p1 = 0;
  int p2 = 0;

  std::vector<int> res;

  while (p1 < m && p2 < n) {
    if (nums1[p1] < nums2[p2]) {

      res.push_back(nums1[p1]);
      p1++;
    } else {
      res.push_back(nums2[p2]);
      p2++;
    }
  }

  for (int k = p1; k < m; ++k) {
    res.push_back(nums1[k]);
  }

  for (int k = p2; k < n; ++k) {

    res.push_back(nums2[k]);
  }

  for (int i = 0; i < res.size(); ++i) {
    nums1[i] = res[i];
  }
}
