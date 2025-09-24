#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

struct Solution {
    void sort(std::vector<int>& arr)
    {
        int n = arr.size();
        bool swapped;
        for (int i = 0; i < n - 1; ++i) {
            swapped = false;
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
        }
    }
};

int main()
{
    Solution sol;
    std::vector<int> arr(10);

    int original_size
        = arr.size();
    for (int i = 0; i < original_size - 1; i++) {
        arr.push_back(std::rand());
    }

    sol.sort(arr);
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
