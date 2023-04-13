#include <iostream>
#include <cmath>

double a = 100;

double f(double x, double t, double g)
{
    return exp(-g * g) * exp(-( x - g) * (x - g) / (2 * a * t));
}

double integral(const double x, const double t, const double left, const double right)
{
    double sum = 0;
    double amount = 1000;
	for (int i = 0; i < amount - 1; ++i)
	{
        double x_curr = (i * left + (amount - i - 1) * right) / amount;
        double x_next = ( (i + 1) * left +  (amount - i - 2) * right) / amount;
		sum += (f(x, t, x_next) + f(x, t, x_curr)) / 2 * (x_next - x_curr);
	}
	return sum;
}

double T(double x, double t, double l, double r)
{
	return 1.0 / (2 * sqrt(M_PI * a * t)) * integral(x, t, l, r);
}


int main()
{
    double dt = 0.1;
    double TEps = 0.01;
    double left = -10;
    double right = 10;
    double T_min, T_max;
    double t = 0.1;
    int kernelLen = 100;
	do
	{
        double T_ = T((left + right) / 2, t, left, right);
		T_min = T_;
        T_max = T_;
		for (int i = 0; i < 100; ++i)
		{
			double x = ((kernelLen - i - 1) * left + i * right) / (kernelLen - 1);
			double T_now = T(x, t, left, right);
			T_min = std::min(T_min, T_now);
			T_max = std::max(T_max, T_now);
		}
		std::cout << "time: " << t << ", T min = " << T_min << ", T max = " << T_max << std::endl;
		t += dt;
	} while (std::abs(T_max - T_min) >= TEps);
	return 0;
}