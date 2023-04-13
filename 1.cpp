#include <math.h>
#include <iostream>

double a = 4;
double h = 1;

#define f underInegralFunction

double underInegralFunction(double x)
{
    return exp( -1/2 * h * h * (1 + x * x)) / (1 + x * x);
}


int main()
{
    int amount = 100; // на столько кусочков разобьем промежуток [0;a]
    double sum = 0;
    for(int i = 0; i < amount; ++i)
    {
        double x_curr = a / static_cast<double>(amount) * static_cast<double>(i);
        double x_next = a / static_cast<double>(amount) * static_cast<double>(i + 1);
        double ddx = a / static_cast<double>(amount) / 3.0;
        sum += 3.0 / 8.0 * ddx * (f(x_curr) + 3 * f(x_curr + ddx) + 3 * f(x_curr + 2 * ddx) + f(x_next));
    }
    std::cout << sum / 2 / M_PI << std::endl;
    return 0;
}