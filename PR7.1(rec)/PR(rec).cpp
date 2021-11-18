#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int k, const int n,
	const int Low, const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);
	if (j < n - 1)
		Create(a, k, n, Low, High, i, j + 1);
	else
		if (i < k - 1)
			Create(a, k, n, Low, High, i + 1, 0);
}

void Print(int** a, const int k, const int n, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < n - 1)
		Print(a, k, n, i, j + 1);
	else
		if (i < k - 1)
		{
			cout << endl;
			Print(a, k, n, i + 1, 0);
		}
		else
			cout << endl << endl;
}
void Change(int** r, const int col1, const int col2, const int rowCount, int i)
{
	int tmp = r[i][col1];
	r[i][col1] = r[i][col2];
	r[i][col2] = tmp;

	if (i < rowCount - 1)
		Change(r, col1, col2, rowCount, i + 1);
}
void Sort(int** r, const int rowCount, const int colCount, int i0, int i1)
{
	if ((r[0][i1] > r[0][i1 + 1])
		|| (r[0][i1] == r[0][i1 + 1] && r[1][i1] > r[1][i1 + 1])
		|| (r[0][i1] == r[0][i1 + 1] && r[1][i1] == r[1][i1 + 1]
			&& r[2][i1] > r[2][i1 + 1]))
		Change(r, i1, i1 + 1, rowCount, 0);
	if (i1 < colCount - i0 - 2)
		Sort(r, rowCount, colCount, i0, i1 + 1);
	else
	if (i0 < colCount - 2)
		Sort(r, rowCount, colCount, i0 + 1, 0);

}

void Calc(int** r, const int rowCount, const int colCount, int& S, int& k, int i, int j)
{
	if (r[i][j] > 0 || r[i][j] % 3 != 0)
	{
		S += r[i][j];
		k++;
		r[i][j] = 0;
	}
	if (j < colCount - 1)
		Calc(r, rowCount, colCount, S, k, i, j + 1);
	else
		if (i < rowCount - 1)
			Calc(r, rowCount, colCount, S, k, i + 1, 0);
}
int main()
{
	srand((unsigned)time(NULL));

	int Low = -12;
	int High = 37;

	int rowCount = 7;
	int colCount = 9;

	int** r = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		r[i] = new int[colCount];
	Create(r, rowCount, colCount, Low, High, 0, 0);
	Print(r, rowCount, colCount, 0, 0);
	Sort(r, rowCount, colCount, 0, 0);
	Print(r, rowCount, colCount, 0, 0);

	int S = 0;
	int k = 0;
	Calc(r, rowCount, colCount, S, k, 0, 0);

	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	Print(r, rowCount, colCount, 0, 0);

	for (int i = 0; i < rowCount; i++)
		delete[] r[i];
	delete[] r;

	return 0;
}

