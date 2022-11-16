// lab_7.1_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** , const int rowCount, const int colCount, const int Low, const int High);
void Print(int** b, const int rowCount, const int colCount);
void Sort(int** b, const int rowCount, const int colCount);
void Change(int** b, const int row1, const int row2, const int colCount);
void Calc(int** b, const int rowCount, const int colCount, int& S, int& k);
int main()
{
	srand((unsigned)time(NULL));
	int Low = 8;
	int High = 73;
	int rowCount = 7;
	int colCount = 6;
	int** b = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		b[i] = new int[colCount];
	Create(b, rowCount, colCount, Low, High);
	Print(b, rowCount, colCount);
	Sort(b, rowCount, colCount);
	Print(b, rowCount, colCount);
	int S = 0;
	int k = 0;
	Calc(b, rowCount, colCount, S, k);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	Print(b, rowCount, colCount);
	for (int i = 0; i < rowCount; i++)
		delete[] b[i];
	delete[] b;
	return 0;
}
void Create(int** b, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			b[i][j] = High + rand() % (Low - High + 1);
}
void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
void Sort(int** b, const int rowCount, const int colCount)
{
	for (int i0 = 0; i0 < rowCount - 1; i0++)
		for (int i1 = 0; i1 < rowCount - i0 - 1; i1++)
			if ((b[i1][0] < b[i1 + 1][0])
				||
				(b[i1][0] == b[i1 + 1][0] &&
					b[i1][1] < b[i1 + 1][1])
				||
				(b[i1][0] == b[i1 + 1][0] &&
					b[i1][1] == b[i1 + 1][1] &&
					b[i1][3] > b[i1 + 1][3]))
				Change(b, i1, i1 + 1, colCount);
}
void Change(int** b, const int row1, const int row2, const int colCount)
{
	int tmp;
	for (int j = 0; j < colCount; j++)
	{
		tmp = b[row1][j];
		b[row1][j] = b[row2][j];
		b[row2][j] = tmp;
	}
}
void Calc(int** b, const int rowCount, const int colCount, int& S, int& k)
{
	S = 0;
	k = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (b[i][j] % 2 == 0 && !(b[i][j] % 8 == 0))
			{
				S += b[i][j];
				k++;
				b[i][j] = 0;
			}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
