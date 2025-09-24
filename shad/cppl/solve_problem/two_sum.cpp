#include <algorithm>
#include <iostream>
#include <utility> // для std::pair
#include <vector>

struct Solution {
    std::pair<int, int> two_sum(std::vector<int>& nums, int target)
    {
        std::vector<std::pair<int, int>> nums_with_index;
        for (int i = 0; i < nums.size(); i++) {
            nums_with_index.push_back({ nums[i], i });
        }

        std::sort(nums_with_index.begin(), nums_with_index.end(),
            [](const auto& a, const auto& b) {
                return a.first < b.first;
            });

        int left = 0;
        int right = nums_with_index.size() - 1;

        while (left < right) {
            int sum = nums_with_index[left].first + nums_with_index[right].first;

            if (sum == target) {
                return { nums_with_index[left].second, nums_with_index[right].second };
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return { -1, -1 };
    }
};

int main()
{
    Solution s;
    std::vector<int> arr = { 1, 2, 3, 5, 6, 8, 9, 10, 12, 14, 15, 234, 123123 };
    std::pair<int, int> rez = s.two_sum(arr, 12);

    std::cout << "Индексы: (" << rez.first << ", " << rez.second << ")\n";

    if (rez.first != -1) {
        std::cout << "Значения: " << arr[rez.first] << " + " << arr[rez.second]
                  << " = " << arr[rez.first] + arr[rez.second] << "\n";
    } else {
        std::cout << "Решение не найдено\n";
    }

    return 0;
}
