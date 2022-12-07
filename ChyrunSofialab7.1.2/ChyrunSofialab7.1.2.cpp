// ChyrunSofialab7.1.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Lab_07_1.cpp
// < Чирун Софія >
// Лабораторна робота № 7.1.2
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці рекурсивним способом
// Варіант 18

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
void Sort(int** a, const int rowCount, const int colCount, int& i0, int& i1);
void Change(int** a, const int row1, const int row2, const int colCount, int& l);
int Calc(int** a, const int rowCount, const int colCount, int& k, int i, int j);

int main()
{
	srand((unsigned)time(NULL));
	int Low = -12;
	int High = 23;
	int rowCount = 7;
	int colCount = 6;
	int i0 = 0, i1 = 0;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Create(a, rowCount, colCount, Low, High, 0, 0);
	Print(a, rowCount, colCount, 0, 0);
	Sort(a, rowCount, colCount, i0, i1);
	Print(a, rowCount, colCount, 0, 0);
	int S = 0;
	int k = 0;
	S = Calc(a, rowCount, colCount, k, 0, 0);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	Print(a, rowCount, colCount, 0, 0);
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	    delete[] a;
	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);
	if (j < colCount - 1)
	   Create(a, rowCount, colCount, Low, High, i, j + 1);
	else
		if (i < rowCount - 1)
		   Create(a, rowCount, colCount, Low, High, i + 1, 0);
}

void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < colCount - 1)
	   Print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
		   cout << endl;
		   Print(a, rowCount, colCount, i + 1, 0);
		}
		else
		   cout << endl << endl;
}

void Sort(int** a, const int rowCount, const int colCount, int& i0, int& i1)
{
	int l = 0;
	if (i1 < rowCount - i0 - 1)
	{
		if ((a[i1][0] > a[i1 + 1][0])
			||
			(a[i1][0] == a[i1 + 1][0] &&
				a[i1][1] > a[i1 + 1][1])
			||
			(a[i1][0] == a[i1 + 1][0] &&
				a[i1][1] == a[i1 + 1][1] &&
				a[i1][3] < a[i1 + 1][3]))
		{
			l = 0;
            Change(a, i1, i1 + 1, colCount, l);
		}
		i1++;
		Sort(a, rowCount, colCount, i0, i1);
	}
	else
		if (i0 < rowCount - 1)
		{
		   i1 = 0;
           i0++;
           Sort(a, rowCount, colCount, i0, i1);
		}
}

void Change(int** a, const int row1, const int row2, const int colCount, int& l)
{
	int tmp;
	if (l < colCount)
	{
	   tmp = a[row1][l];
	   a[row1][l] = a[row2][l];
	   a[row2][l] = tmp;
	   l++;
	   Change(a, row1, row2, colCount, l);
	}
}

int Calc(int** a, const int rowCount, const int colCount, int& k, int i, int j)
{
	int b;
	if (j < colCount - 1)
	{
		if (a[i][j] % 2 != 0 && (a[i][j] > 0))
		{
		   k++;
		   b = a[i][j];
		   a[i][j] = 0;
		   return b + Calc(a, rowCount, colCount, k, i, j + 1);
		}
		else return Calc(a, rowCount, colCount, k, i, j + 1);
	}
	else
		if (i < rowCount - 1)
		{
			if (a[i][j] % 2 != 0 && (a[i][j] > 0))
			{
			   k++;
			   b = a[i][j];
			   a[i][j] = 0;
			   return b + Calc(a, rowCount, colCount, k, i + 1, 0);
			}
			else return Calc(a, rowCount, colCount, k, i + 1, 0);
		}
		else
		return a[i][j];
}


