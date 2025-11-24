#include "SlidingWindow.h"

double SlidingWindow::findMaxAverage(std::vector<int> nums, int k) {
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
