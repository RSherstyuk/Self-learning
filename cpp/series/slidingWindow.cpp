#include <algorithm>
#include <iostream>
#include <vector>

int slide(const std::vector<int>& arr, int k)
{
    if (arr.size() < k)
        return -1;

    int sum = 0;

    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }

    int max_sum = sum;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i] - arr[i - k];
        max_sum = std::max(max_sum, sum);
    }

    return max_sum;
}

int main(int argc, char** argv)
{
    std::vector<int> v = { 1, 2, 3, 4 };

    for (int i = 0; i <= v.size(); i++) {
        std::cout << v[i] << " ";
    }

    std::cout << v[12] << std::endl;
}
