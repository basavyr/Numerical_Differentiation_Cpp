#include "../include/extremal.h"

std::vector<ExtremalPoints::Point> ExtremalPoints::findMinimum(const std::vector<double> &source)
{
    std::vector<Point> extremals;

    auto product = [](auto x, auto y) { return x * y; };
    auto smaller = [](auto x) { return x < 0 ? 1 : 0; };

    int pos = 0;
    for (auto id = 0; id < source.size() - 1; ++id)
    {
        auto fx0 = source.at(id);
        auto fx1 = source.at(id + 1);

        if (product(fx0, fx1) < 0)
        {
            extremals.emplace_back(Point());
            extremals.at(pos).p = id;
            if (smaller(fx0))
            {
                extremals.at(pos).p_Type = "minimum";
            }
            else
            {
                extremals.at(pos).p_Type = "minimum";
            }
            pos++;
        }
    }
    return extremals;
}