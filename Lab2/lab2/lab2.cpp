#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "Combi.h"
#include "salesman.h"

using namespace std;
//4
#define N (sizeof(AD)/2)
#define M 3
//комм
#define L 10	//кол-во городов

double dget(double rmin, double rmax) // получить случайное число
{
	return ((double)rand() / (double)RAND_MAX) * (rmax - rmin) + rmin;
};

int iget(int rmin, int rmax)        // получить случайное число
{
	return (int)dget((double)rmin, (double)rmax);
};

int main()
{
	char  AA[][2] = { "A", "B", "C", "D" };
	cout << "Primary array: ";
	cout << "{ ";
	for (int i = 0; i < sizeof(AA) / 2; i++)
		cout << AA[i] << ((i < sizeof(AA) / 2 - 1) ? ", " : " ");

	cout << "}" << endl;
	cout << endl << "Generation of all subsets: ";

	combi::subset s1(sizeof(AA) / 2);         // создание генератора  
	int  n = s1.getfirst();                // первое (пустое) подмн-во    

	while (n >= 0)                          // пока есть подмн-ва 
	{
		cout << endl << "{ ";
		for (int i = 0; i < n; i++)
			cout << AA[s1.ntx(i)] << ((i < n - 1) ? ", " : " ");
		cout << "}";
		n = s1.getnext();                  // cледующее подмн-во 
	};
	cout << endl << "Vsego: " << s1.count() << endl;
	/////////////////////////////////////////////////////
	char  AB[][2] = { "A", "B", "C", "D", "E" };

	cout << "****** Generator of combinations *******";
	cout << endl << "Primary array: ";
	cout << "{ ";

	for (int i = 0; i < sizeof(AB) / 2; i++)

		cout << AB[i] << ((i < sizeof(AB) / 2 - 1) ? ", " : " ");
	cout << "}" << endl;
	cout << endl << "Generation of combinations ";

	combi::xcombination xc(sizeof(AB) / 2, 3);
	cout << "iz " << xc.n << " po " << xc.m << ":";

	int  n2 = xc.getfirst();

	while (n2 >= 0)
	{
		cout << endl << xc.nc << ": { ";

		for (int i = 0; i < n2; i++)
			cout << AB[xc.ntx(i)] << ((i < n2 - 1) ? ", " : " ");
		cout << "}";
		n2 = xc.getnext();
	};

	cout << endl << "Vsego: " << xc.count() << endl;
	////////////////////////////////////////
	char  AC[][2] = { "A", "B", "C", "D" };

	cout << "***** Generator of transpositions *****" << endl;
	cout << endl << "Primary array: ";
	cout << "{ ";

	for (int i = 0; i < sizeof(AC) / 2; i++)

		cout << AC[i] << ((i < sizeof(AC) / 2 - 1) ? ", " : " ");
	cout << "}" << endl;
	cout << endl << "Generation of transpositions: ";

	combi::permutation p(sizeof(AC) / 2);
	__int64  n3 = p.getfirst();

	while (n3 >= 0)
	{
		cout << endl << setw(4) << p.np << ": { ";

		for (int i = 0; i < p.n; i++)

			cout << AC[p.ntx(i)] << ((i < p.n - 1) ? ", " : " ");
		cout << "}";

		n3 = p.getnext();
	};

	cout << endl << "Vsego: " << p.count() << endl;
	//////////////////////////////////////
	char  AD[][2] = { "A", "B", "C", "D" };

	cout << "****** Generator of placement *******" << endl;
	cout << endl << "Primary array: ";
	cout << "{ ";

	for (int i = 0; i < N; i++)

		cout << AD[i] << ((i < N - 1) ? ", " : " ");
	cout << "}" << endl;
	cout << endl << "Generation of placements iz  " << N << " po " << M << ":";

	combi::accomodation s(N, M);

	int  n4 = s.getfirst();

	while (n4 >= 0)
	{
		cout << endl << setw(2) << s.na << ": { ";

		for (int i = 0; i < 3; i++)

			cout << AD[s.ntx(i)] << ((i < n4 - 1) ? ", " : " ");
		cout << "}";

		n4 = s.getnext();
	};

	cout << endl << "Vsego: " << s.count() << endl;
	////////////////////////////////////////////
	int d[L][L];
	clock_t  t1, t2;

	t1 = clock();
	srand((unsigned)time(NULL));

	for (int i = 0; i < L; i++)
		for (int k = 0; k < L; k++) {
			d[i][k] = iget(10, 300);
			if (i == k) d[i][k] = 0;
		}

	for (int i = 0; i < 3; i++)
		d[iget(0, L)][iget(0, L)] = INF;


	int r[L];       // результат
	int l = salesman(
		L,          // [in]  количество городов 
		(int*)d,    // [in]  массив [n*n] расстояний 
		r           // [out] массив [n] маршрут 0 x x x x  

	);
	cout << "-- Kommivoyazher -- ";
	cout << "\n-- City amount: " << L;
	cout << "\n-- Distance matrix : \n\n";

	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++)

			if (d[i][j] != INF)
				cout << setw(3) << d[i][j] << " ";
			else
				cout << setw(3) << "INF" << " ";
		cout << "\n";
	}

	cout << "\n-- Optimal route: ";
	for (int i = 0; i < L; i++)
		cout << r[i] << "-->";
	cout << 0;

	cout << "\n-- Route distance : " << l << "\n";
	t2 = clock();


	cout << "\ntime (sec):   " << (t2 - t1) << "\n";

	system("pause");
	return 0;
}
