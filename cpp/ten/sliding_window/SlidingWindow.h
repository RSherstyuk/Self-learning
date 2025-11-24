#pragma once

#include <vector>
#include <algorithm>

class SlidingWindow {
public:
  double findMaxAverage(std::vector<int> &nums, int k); //643

  double findMaxAverageTen(std::vector<int> &nums, int k); //643

  int minSubArrayLen(int target, std::vector<int> &nums);

};
