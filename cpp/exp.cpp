#include "sys/resource.h"
#include "unistd.h"
#include <cmath>
#include <iomanip> // Добавляем для std::setprecision
#include <iostream>
#include <vector>

void printMemUse()
{
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    std::cout << "Mem use: " << usage.ru_maxrss << " KB" << std::endl;
}

long double fact(int x)
{
    if (x == 0) {
        return 1;
    }
    long double result = 1;
    for (int i = 1; i <= x; ++i) {
        result *= i;
    }
    return result;
}

long double exp(double x, int bound)
{
    long double rez = 0;
    for (int i = 0; i < bound; i++) {
        rez += std::pow(x, i) / fact(i);
    }
    return rez;
}

int vecSum(std::vector<double>& arr)
{
    for (int i = 0; i < arr.size() - 1; i++) {
        arr[i] = i * i * i;
    }

    return arr.size();
}

int main()
{
    std::vector<int> arr = { 1, 2, 3, 5 };
    for (int i : arr) {
        std::cout << i << " ";
    }
}
