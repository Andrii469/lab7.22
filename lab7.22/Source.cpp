#include <iostream>
#include <Windows.h>
#include <iomanip>

void matriz_create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j);
void matriz_print(int** a, const int  rowCount, const int colCount, int i, int j);
void matriz_print1(int* a, const int  rowCount, int i);
int MaxMinRows(int** a, int* min, const int  rowCount, int i, int max);

int main(void)
{
	srand((unsigned)time(NULL));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	using std::cout;
	using std::endl;
	using std::cin;

	int rowCount;
	int colCount;

	cout << "Задайте розмір матриці: " << endl;
	cout << endl;
	cout << "Кількість рядів: ";
	cin >> rowCount;
	cout << endl;
	cout << "Кількість стовпців: ";
	cin >> colCount;
	cout << endl;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	int High = 45;
	int Low = -35;
	cout << "РЕКУРСИВНИЙ СПОСІБ" << endl;
	matriz_create(a, rowCount, colCount, Low, High, 0, 0);
	cout << "Сформований масив: " << endl << endl;
	matriz_print(a, rowCount, colCount, 0, 0);
	cout << std::endl;

	int* min = new int[rowCount];
	for (int i = 0; i < rowCount; i++)
	{
		min[i] = a[i][0];
		for (int j = 1; j < colCount; j++)
			if (a[i][j] < min[i])
				min[i] = a[i][j];
	}
	cout << std::endl;
	cout << "Масив мінімальних елементів кожного рядка: " << endl;
	cout << std::endl;
	matriz_print1(min, rowCount, 0);

	cout << std::endl;
	int max = MaxMinRows(a, min, rowCount, 0, min[0]);
	cout << endl;
	cout << "Максимальний елемент серед мінімальних елементів кожного рядка: " << min << endl;

	delete[] min;
	delete[]a;

	return 0;
}

//РЕКУРСИВНИЙ СПОСІБ

void matriz_create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);
	if (j < colCount - 1)
		matriz_create(a, rowCount, colCount, Low, High, i, j + 1);
	else
		if (i < rowCount - 1)
			matriz_create(a, rowCount, colCount, Low, High, i + 1, 0);
}

void matriz_print(int** a, const int rowCount, const int colCount, int i, int j)
{
	using std::cout;
	using std::endl;
	cout << std::setw(4) << a[i][j];
	if (j < colCount - 1)
		matriz_print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			matriz_print(a, rowCount, colCount, i + 1, 0);
		}
}

void matriz_print1(int* a, const int rowCount, int index)
{
	using std::cout;
	using std::endl;
	std::cout << std::setw(5) << a[index];
	if (index < rowCount - 1)
		matriz_print1(a, rowCount, index + 1);
	else;
}


int MaxMinRows(int** a, int* min, const int rowCount, int index, int max)
{
	if (min[index] > max)
		max = min[index];
	if (index < rowCount - 1)
		MaxMinRows(a, min, rowCount, index + 1, max);
	else
		return max;
}