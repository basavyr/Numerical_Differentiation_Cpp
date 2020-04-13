#include "../include/functions.h"

double Functions::Trigonometric(double x)
{

    auto result = sin(x);
    return static_cast<double>(result);
}

double Functions::Exponential(double x)
{
    auto result = exp(x);
    return static_cast<double>(result);
}

double Functions::Polynomial(double x)
{
    auto result = pow(x, 2) + x;
    return static_cast<double>(result);
}
