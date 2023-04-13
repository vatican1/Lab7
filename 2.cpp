#include <math.h>
#include <iostream>
#include <vector>

double a = 4;
double h = 1;

#define f underInegralFunction

double underInegralFunction(double x)
{
    x = a * (x + 1) / 2;
    return exp( -1/2 * h * h * (1 + x * x)) / (1 + x * x);
}


int main()
{
    double sum = 0;
    std::vector<double> x = {-0.1488743389816312, 0.1488743389816312,-0.4333953941292472, 0.4333953941292472, -0.6794095682990244, 0.6794095682990244, -0.8650633666889845, 0.8650633666889845, -0.9739065285171717, 0.9739065285171717};
	std::vector<double> w = { 0.2955242247147529, 0.2955242247147529, 0.2692667193099963, 0.2692667193099963,  0.2190863625159820, 0.2190863625159820,  0.1494513491505806, 0.1494513491505806,  0.0666713443086881, 0.0666713443086881};
    for (int i = 0; i < 10; i++)
	{
        sum += w[i] * f(x[i]);
    }
    std::cout << a * sum / 4 / M_PI << std::endl;
    return 0;
}