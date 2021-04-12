#include <iostream>
#include <time.h>
#include <algorithm> 
using namespace std;
const int MAX_SIZE = 1000;
const int MAX_VALUE = 10; // A must contain only numbers in interval [0 ..MAX_VALUE)

// Array.hpp
class Array
{
	int* A;
	int N;
public:

	Array(int n)
	{
		// выделение памяти
		A = new int[MAX_SIZE];
		N = n;
	}
	void gen();
	void print();
	void sort();
	int different();
	int find(int value);
	void append(int value);
	void remove(int index);
	void remove_by_value(int value);
	~Array()
	{
		delete[] A;
	}
};

// Array.cpp
void Array::gen()
{
	for (int i = 0; i < N; i++)
	{
		A[i] = rand() % MAX_VALUE;
	}
}
void Array::print()
{
	for (int i = 0; i < N; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}
void Array::sort()
{
	int B[MAX_VALUE];
	for (int i = 0; i < MAX_VALUE; i++)
		B[i] = 0;
	for (int i = 0; i < N; i++)
	{
		B[A[i]]++;
	}
	int j = 0;
	for (int i = 0; i < MAX_VALUE; i++)
	{
		for (int k = 0; k < B[i]; k++)
		{
			A[j++] = i;
		}
	}
}
int Array::different()
{
	// Suppose A is sorted in increase order
	int count = 1;
	for (int i = 0; i < N - 1; i++)
	{
		if (A[i] != A[i + 1])
			++count;
	}
	return count;
}
// return index of element=value if found,
// -1 if not found
int Array::find(int value)
{
	for (int i = 0; i < N; i++)
		if (A[i] == value)
			return i;
	return -1;
}
void Array::append(int value)
{
	A[N] = value; // N=6 [0 1 2 3 4 5] value=6, N = 7
	++N;
	sort();
}
// remove element by index
void Array::remove(int index)
{
	if (index < 0 || index >= N)
	{
		cout << "Incorrect index" << endl;
		return;
	}

	for (int i = index; i < N; i++)

	{

		A[i] = A[i + 1];

	}

	--N;

}

// remove by value all elements 

void Array::remove_by_value(int value)

{

	while (1)

	{

		int index = find(value);

		if (index == -1) return;

		remove(index);

	}

}

void menu()

{

	cout << "1.Генерация массива." << endl;

	cout << "2.Печать массива " << endl;

	cout << "3.Сортировка массива подсчётом " << endl;

	cout << "4.Поиск количества различных чисел среди элементов массива " <<
		endl;

	cout << "5.Поиск индекса искомого значения в массиве " << endl;

	cout << "6.Добавление элемента в массив " << endl;

	cout << "7.Удаление элемента по индексу " << endl;

	cout << "8.Удаление элемента по значению " << endl;

	cout << "9.Выход из программы " << endl;

}

int main()

{

	setlocale(LC_ALL, "Russian");

	srand(time(NULL));

	int choose = 0;

	int N, Value, Index;

	cout << "Input array size: " << endl;

	cin >> N;

	if (N > MAX_SIZE)

	{

		cout << "N is too big!";

		exit(1);

	}

	Array A(N);

	do
	{
		cout << "Выберите пункт меню: " << endl;
		menu();
		cin >> choose;

		switch (choose)
		{
		case 1:
		{
			A.gen();
			break;
		}
		case 2:
		{
			A.print();
			break;
		}
		case 3:
		{
			A.sort();
			break;
		}
		case 4:
		{
			int c = A.different();
			cout << "Уникальных элементов в массиве: " << c << endl;
			break;
		}
		case 5:
		{
			cout << "Insert find value: ";
			cin >> Value;
			int c = A.find(Value);
			cout << "Индекс искомого элемента равен: " << c << endl;
			break;
		}
		case 6:
		{
			cout << "Insert add value: ";
			cin >> Value;
			A.append(Value);
			break;
		}
		case 7:
		{
			cout << "Insert index remove value: ";
			cin >> Index;
			A.remove(Index);
			break;
		}
		case 8:
		{
			cout << "Insert find value: ";
			cin >> Value;
			A.remove_by_value(Value);
			break;
		}
		}
	} while (choose != 9);
	system("pause");
	return 0;
}