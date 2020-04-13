#ifndef EXTREMAL_HH
#define EXTREMAL_HH

#include <string>
#include <cmath>
#include <iostream>
#include <vector>

class ExtremalPoints
{
public:
    struct Point
    {
        double p;
        std::string p_Type;
        Point()
        {
            p = 0;
            p_Type = "";
        }
    };
    static std::vector<Point> findMinimum(const std::vector<double> &source);
};

#endif // EXTREMAL_HH