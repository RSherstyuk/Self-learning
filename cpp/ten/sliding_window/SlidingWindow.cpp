#include "SlidingWindow.h"
#include <cmath>

double SlidingWindow::findMaxAverage(std::vector<int> &nums, int k) {
  int n = nums.size();
  if (nums.empty() || k <= 0 || k > nums.size())
    return 0;

  double current_sum = 0;
  for (int i = 0; i < k; ++i) {
    current_sum += nums[i];
  }

  double max_sum = current_sum;

  for (int i = k; i < n; ++i) {
    current_sum = (current_sum - nums[i - k] + nums[i]) / k;

    max_sum = std::max(max_sum, current_sum);
  }

  return max_sum;
}

double SlidingWindow::findMaxAverageTen(std::vector<int> &nums, int k) {
  int n = nums.size();
  int begin = 0;
  double window_state = 0;
  double result = -std::numeric_limits<double>::infinity();

  for (int end = 0; end < n; ++end) {
    window_state += nums[end];
    
    if (end - begin + 1 == k) {
      result = std::max(result, window_state);
      window_state -= nums[begin];
      begin += 1;
    }
  }

  return result / k;
}

int SlidingWindow::minSubArrayLen(int target, std::vector<int> &nums) {
}
