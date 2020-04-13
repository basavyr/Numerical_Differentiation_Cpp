#include <iostream>
#include <vector>

#include "../include/functions.h"
#include "../include/diff.h"

void newline()
{
    std::cout << "\n";
}

void done()
{
    std::cout << " Program finished: ";
    std::cout << "  ✅  🔥  💪  💻  ";
    newline();
}

template <typename T>
void generateArray(std::vector<T> &v, T (*func)(T))
{
    for (double i = 0.0; i <= 1.0; i += 0.1)
    {
        auto value = Functions::Polynomial(i);
        v.emplace_back(static_cast<T>(func(value)));
    }
}

template <typename T>
void printArray(const std::vector<T> &v)
{
    for (auto &&n : v)
    {
        std::cout << n << " , ";
    }
    newline();
}

// template <typename T>
// void mathPrintToFile(std::ofstream &gout, const std::string &v, const std::string &plotName)
// {
//     std::string;
// }

int main()
{
    //store the exponential values
    std::vector<double> v;

    // generateArray<double>(v, Functions::Polynomial);
    // printArray<double>(v);
    const double x0 = 1.0;
    std::cout << Functions::Polynomial(x0);
    newline();

    auto dx = Differentiation::OnePoint_CD<double (*)(double), double>(Functions::Polynomial, x0, 0.1);
    std::cout << dx;
    newline();

    done();
}