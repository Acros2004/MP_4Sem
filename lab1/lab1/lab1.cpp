#include "pch.h"
#include "Auxil.h"                            // вспомогательные функции 
#include <ctime>
#include <locale>
#define  CYCLE  100000                    // количество циклов  
#define  NUMBER 50
#include <iostream>

int main()
{
	setlocale(LC_ALL, "rus");
	double  av1 = 0, av2 = 0;
	clock_t  t1 = 0, t2 = 0,t3 = 0,t4 = 0;

	
	auxil::start();                          // старт генерации 
	t1 = clock();                            // фиксация времени 
	for (int i = 0; i < CYCLE; i++)
	{
		av1 += (double)auxil::iget(0, 100); // сумма случайных чисел 
		av2 += auxil::dget(-100, 100);         // сумма случайных чисел 
	}
	t2 = clock();                            // фиксация времени 
	std::cout << std::endl << "количество циклов:         " << CYCLE;
	std::cout << std::endl << "среднее значение (int):    " << av1 / CYCLE;
	std::cout << std::endl << "среднее значение (double): " << av2 / CYCLE;
	std::cout << std::endl << "продолжительность (у.е):   " << (t2 - t1);
	std::cout << std::endl << "                  (сек):   "
		<< ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
	std::cout << std::endl;

	t3 = clock();
	auxil::recursion_fibonachi(NUMBER);
	t4 = clock();
	std::cout << std::endl << "число:         " << NUMBER;
	std::cout << std::endl << "продолжительность (у.е):   " << (t4 - t3);
	std::cout << std::endl << "                  (сек):   "
		<< ((double)(t4 - t3)) / ((double)CLOCKS_PER_SEC) << std::endl;
	system("pause");
	return 0;
}

