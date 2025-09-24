#include <cmath>
#include <iostream>
#include <vector>

long long fact(int n)
{
    if (n == 1) {
        return 1;
    }

    return n * fact(n - 1);
}

class Ser {
public:
    long double sin(double x, int bound)
    {
        long double result = 0;
        int sign = 1;

        for (int i = 1; i < bound; i += 2) {
            result += sign * std::pow(x, i) / fact(i);
            sign *= -1;
        }

        return result;
    }

    long double cos(double x, int bound)
    {
        long double result = 1;
        double sign = -1;

        for (int i = 2; i <= bound; i += 2) {
            result += sign * std::pow(x, i) / fact(i);
            sign *= -1;
        }
        return result;
    }

    long double exp(double x, int bound)
    {
        long double result = 1;

        for (int i = 1; i <= bound; i++) {
            result += std::pow(x, i) / fact(i);
        }
        return result;
    }
};

int main()
{
    Ser s;
    s.sin(2, 12);

    std::sin(2);
}
