#ifndef DIFF_HH
#define DIFF_HH

#include <cmath>
#include <vector>
#include <iostream>

#include "functions.h"

class Differentiation
{
    //general method for differentiation
public:
    template <typename Function, typename Diff_Method, typename T>
    static T NDSolve(Diff_Method method, Function func, T arg, T step)
    {
        auto x0 = arg;
        auto h = step;
        // the function pointer to the function for being evaluated
        auto result = method(func, x0, h);
        return static_cast<T>(result);
    }
    //methods for calculating derivative
public:
    template <typename Function, typename T>
    static T M1(Function func, T arg, T step)
    {
        auto x = arg;
        auto h = step;
        auto result = (func(x + step) - func(x - step)) / (2.0 * h);
        return static_cast<T>(result);
    }

    template <typename Function, typename T>
    static T M2(Function func, T arg, T step)
    {
        auto x = arg;
        auto h = step;
        auto result = (func(x + step) - func(x - step)) / (2.0 * h);
        return static_cast<T>(result);
    }

    template <typename Function, typename T>
    static T M3(Function func, T arg, T step)
    {
        auto x = arg;
        auto h = step;
        auto result = (func(x + step) - func(x - step)) / (2.0 * h);
        return static_cast<T>(result);
    }

    //methods using CENTRAL DIFFERENCE
    template <typename Function, typename T>
    static T OnePoint_CD(Function func, T arg, T step)
    {
        auto x = arg;
        auto h = step;
        auto result = M1<Function, T>(func, x, h);
        return static_cast<T>(result);
    }

    template <typename Function, typename T>
    static T TwoPoint_CD(Function func, T arg, T step)
    {
        auto x = arg;
        auto h = step;
        auto result = 4.0 / 3.0 * M1<Function, T>(func, x, h) - 1.0 / 3.0 * M2<Function, T>(func, x, h);
        return static_cast<T>(result);
    }

    template <typename Function, typename T>
    static T ThreePoint_CD(Function func, T arg, T step)
    {
        auto x = arg;
        auto h = step;
        auto result = 3.0 / 2.0 * M1<Function, T>(func, x, h) - 3.0 / 5.0 * M2<Function, T>(func, x, h) + 1.0 / 10.0 * M3<Function, T>(func, x, h);
        return static_cast<T>(result);
    }
};

#endif // DIFF_HH