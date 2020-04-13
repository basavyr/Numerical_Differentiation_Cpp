#include <iostream>
#include <vector>
#include <fstream>

#include "../include/functions.h"
#include "../include/diff.h"
#include "../include/extremal.h"

void newline()
{
    std::cout << "\n";
}

void done()
{
    std::cout << "Program finished!...";
    std::cout << " ✅  🔥  💪  💻 ";
    newline();
}

template <typename T>
void generateArray(std::vector<T> &v, T (*func)(T))
{
    //interval for function evaluation
    const double xLeft = -5.0;
    const double xRight = 5.0;

    double h = 0.01;

    for (double i = xLeft; i <= xRight; i += h)
    {
        auto value = static_cast<T>(func(i));
        v.emplace_back(value);
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

template <typename T>
void mathPrintToFile(std::ofstream &out, const std::vector<T> &v, const std::string &plotName)
{
    std::string plotname;
    plotname.append(plotName);
    plotname.append("={ ");
    out << plotname;
    if (!v.size())
    {
        plotname.append("0 };");
    }
    else
    {
        for (int id = 0; id < v.size(); ++id)
        {
            if (id == v.size() - 1)
            {
                out << v.at(id) << " };";
                out << "\n";
                // out << "Listplot[" << plotName << ", Joined->True]";
            }
            else
            {
                out << v.at(id) << " , ";
            }
        }
    }
}

template <typename T>
std::vector<T> evaluateDerivative(T (*function)(T))
{
    //array to store the derivatives (will be returned as result)
    std::vector<T> deriv;

    //interval for function evaluation
    const double xLeft = -5.0;
    const double xRight = 5.0;

    double h = 0.01;

    for (auto x0 = xLeft; x0 <= xRight; x0 += h)
    {
        auto fx = static_cast<T>(function(x0));

        //choose method of differentiation from Diff class
        auto dfdx = Differentiation::OnePoint_CD<double (*)(double), double>(function, x0, h);
        deriv.emplace_back(dfdx);
    }
    return deriv;
}

int main()
{
    //store the exponential values
    std::vector<double> fxTable;

    //function to be differentiated (chosen from Function class)
    auto poly = Functions::Polynomial;

    //generate an array with the values of the function
    generateArray<double>(fxTable, poly);

    auto dfxdxTable = evaluateDerivative<double>(poly);

    std::ofstream gout;
    gout.open("../resources/mathPlots.dat", std::ios::trunc);

    const std::string fxPlot = "fx";
    std::string dfxPlot = "dfx";

    mathPrintToFile<double>(gout, fxTable, fxPlot);
    mathPrintToFile<double>(gout, dfxdxTable, dfxPlot);

    gout << "ListPlot[{" << fxPlot << "," << dfxPlot << "}, Joined->True]";

    auto w = ExtremalPoints::findMinimum(dfxdxTable);
    for (auto &&n : w)
    {
        std::cout << "The point x_m= " << (-5.0 + n.p * 0.01) << " is a extremal point: " << n.p_Type << "\n";
    }
    done();
}