#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> two_sum(std::vector<int> arr, int target)
{
    int l = 0;
    int r = arr.size() - 1;

    std::sort(arr.begin(), arr.end());

    while (l < r) {
        int cur_sum = arr[l] + arr[r];

        if (cur_sum == target) {
            return { l, r };
        }

        if (cur_sum > target) {
            r -= 1;
        } else {
            l += 1;
        }
    }

    return {};
}

int main()
{
    std::vector<int> arr = { 1, 2, 3, 5, 6, 7, 8, 9, 123, 123123, 1231, 123123 };
    std::vector<int> rez = two_sum(arr, 9);

    if (rez.size() == 2) {
        std::cout << rez[0] << rez[1] << std::endl;
        std::cout << arr[rez[0]] << " " << arr[rez[1]] << std::endl;
    } else {
        std::cout << "no solution" << std::endl;
    }

    return 0;
}
