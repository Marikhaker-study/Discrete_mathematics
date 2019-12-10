// Laba 6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;

unsigned long long factorial(unsigned long long n)
{
	return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

unsigned long long coef(int n, int k)
{
	return factorial(n) / (factorial(k)*factorial(n - k));
}

void newton()
{
	cout << "Newton's binominal expansion" << endl;
	cout << "==================\n";
	int n;
	cout << "Equation: (a-b)^n" << endl; // My power == 10
	cout << "Enter n" << endl;
	cin >> n;

	if (n == 0)
	{
		cout << "Binomial expansion: " << endl;
		cout << 1 << endl;
		return;
	}

	for (int k = 0; k <= n; k++)
	{
		unsigned long long result;
		if ((n - k) % 2 == 1)
		{
			if (coef(n, k) == (-1))
			{
				cout << "-" << "a^" << k << "b^" << n - k;
			}	
			else cout << "-" << coef(n, k) << "a^" << k << "b^" << n - k;
			
		}
		else
		{
			if (coef(n, k) == (1))
			{
				cout << "+" << "a^" << k << "b^" << n - k;
			}
			else cout << "+" << coef(n, k) << "a^" << k << "b^" << n - k;
			
		}
	}
	_getch();
	cout << endl;
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}


// Reverse by swapping elements from both edges of array
void reverse(int *array, int i, int j) 
{
	int temp = 0;
	while (i < j) {
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		i++;
		j--;
	}
}

bool next_permutation(int array[], int length) {

	if (length == 0)
		return false;

	int i = length - 1; // Index of target element

	while (i > 0 && array[i - 1] >= array[i]) // Going through mas from end to first decreasing element
		i--;								  

	if (i == 0) return false; // This is final permutation if target is first element

	// Looking for element just bigger than target from end
	int j = length - 1;
	while (array[j] <= array[i - 1])
		j--;

	// Swapping 
	swap(array[i - 1], array[j]);

	// Reverse elements after target
	j = length - 1;

	reverse(array, i, j); // Reverse by swapping elements from both edges of array

	return true; // There are more permutations

}

void permutation()
{
	cout << "Permutations: " << endl;
	cout << "==================\n";
	int n = 0;
	cout << "Enter amount of numbers" << endl;
	cin >> n;

	int *a = new int[n];

	cout << "\nPermutations of sequence: " << endl;
	for (int i = 0; i < n; i++)
	{
		a[i] = i + 1;
		cout << a[i] << " ";
	}
	cout << endl;

	while (true)
	{
		if (!next_permutation(a, n)) break;
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
	}
	delete[] a;
	_getch();
	cout << endl;
}

int main()
{
	permutation();

	newton();

	_getch();
	return 0;
}

