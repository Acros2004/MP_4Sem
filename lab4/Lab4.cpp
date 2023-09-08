#include "stdafx.h"
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <iomanip>
#include "Levinshtein.h"
#include "LCS.h"
#include <cstring>
#include "LCH.h"


#define N 6
#define _rand(min, max) ( rand() % ((max) - (min) + 1) + (min) )

void Task1_2() {
	srand(time(NULL));
	/*char abc[25];
	char s1[300], s2[250];

	for (int i = 97, n = 0; i <= 122; ++i, ++n)
	{
		abc[n] = (char)i;
	}
	std::cout << "S1 = ";
	for (int i = 0; i < 300; i++)
	{
		s1[i] = abc[_rand(0, 25)];
		if (i % 100 == 0)
			std::cout << std::endl;
		std::cout << s1[i];
	}
	std::cout << std::endl << std::endl << "S2 =";

	for (int i = 0; i < 250; i++)
	{
		s2[i] = abc[_rand(0, 25)];
		if (i % 100 == 0)
			std::cout << std::endl;
		std::cout << s2[i];
	}*/
	//exit(0);
	char s1[8] = "EDITING";
	char s2[9] = "DISTANCE";
	clock_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;
	int lx = sizeof(s1);
	int ly = sizeof(s2);
	/*int s1_size[]{ 12, 15, 20, 30, 60, 150, 300 };
	int s2_size[]{ 10, 13, 17, 25, 50, 125, 250 };*/
	int s1_size[]{  7};
	int s2_size[]{  8};

	std::cout << std::endl;
	std::cout << std::endl << "-- расстояние левенштейна -----";
	std::cout << std::endl << "--длина --- рекурсия -- дин.програм. --- результат" << std::endl;
	
	for (int i = 0; i < std::min(lx, ly); i++)
	{
		t1 = clock();
		int answer =  levenshtein_r(s1_size[i], s1, s2_size[i], s2);
		t2 = clock();
		t3 = clock();
		levenshtein(s1_size[i], s1, s2_size[i], s2);
		t4 = clock();
		std::cout << std::right << std::setw(2) << s1_size[i] << "/" << std::setw(2) << s2_size[i]
			<< "        " << std::left << std::setw(10) << (t2 - t1)
			<< "   " << std::setw(10) << (t4 - t3) << answer << std::endl;
		
	}
}
void Task5() {
	clock_t tt1 = 0, tt2 = 0, tt3 = 0, tt4 = 0;
	char X[] = "HRWCYUJ", Y[] = "FHEYVGF";
	std::cout << std::endl << "-- вычисление длины lcs для x и y(рекурсия)";
	std::cout << std::endl << "-- последовательность x: " << X;
	std::cout << std::endl << "-- последовательность y: " << Y;
	//tt1 = clock();
	//int s = lcs(
	//	sizeof(X) - 1,  // длина   последовательности  x   
	//	X,       // последовательность x
	//	sizeof(Y) - 1,  // длина   последовательности  y
	//	Y      // последовательность y
	//);
	//tt2 = clock();
	//std::cout << std::endl << "-- длина lcs: " << s << std::endl;
	//std::cout << std::endl << "-- затраченное время: " << (tt2 - tt1) << std::endl;
	/////////////////
	char z[100] = "";
	tt3 = clock();
	int l = lcsd(X, Y, z);
	tt4 = clock();
	std::cout << std::endl
		<< "-- наибольшая общая подпоследовательость - LCS(динамическое программирование)" << std::endl;
	std::cout << std::endl << "последовательость X: " << X;
	std::cout << std::endl << "последовательость Y: " << Y;
	std::cout << std::endl << "                LCH: " << z;
	std::cout << std::endl << "          длина LCH: " << l;
	std::cout << std::endl << "-- затраченное время: " << (tt4 - tt3) << std::endl;

}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	Task1_2();
	//Task5();
	system("pause");
	return 0;
}