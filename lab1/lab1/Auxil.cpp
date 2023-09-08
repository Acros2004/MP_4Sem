#include "Auxil.h" 
#include "pch.h"
#include <ctime> 
namespace auxil
{
    void start()                          // старт  генератора сл. чисел
    {
        srand((unsigned)time(NULL));
    };
    double dget(double rmin, double rmax) // получить случайное число
    {
        return ((double)rand() / (double)RAND_MAX) * (rmax - rmin) + rmin;
    };

    int iget(int rmin, int rmax)         // получить случайное число
    {
        return (int)dget((double)rmin, (double)rmax);
    };
    int recursion_fibonachi(int number)
    {
        if (number == 1)
            return 0;
        if (number == 2 or number == 3)
            return 1;
        return recursion_fibonachi(number - 1) + recursion_fibonachi(number - 2);
    }
}