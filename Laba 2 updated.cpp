// Laba2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "conio.h"
#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

const int n = 5;
const long double hu = trunc(0.1 * 10) / 10;

struct set {

	void inp_set(double *a) //////////
	{
		char ck[5];
		cout << "Enter set a with different values" << endl;
		for (int i = 0; i < n; i++)
		{
		p1:
			cin >> ck;
			if (atof(ck) || ck[0] == '0') a[i] = atof(ck);
			else
			{
				cout << "Enter again" << endl;
				goto p1;
			}
			a[i] = trunc(a[i] * 10) / 10;
		}

	}

	void out_set(double *a, int n)  //////////
	{
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << "\t";
		}
		cout << endl;
	}

	void out_set(bool *a, int n)  //////////
	{
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << "\t";
		}
		cout << endl;
	}

	void sort_set(double m[n])  //////////
	{
		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < n - 1; i++)
			{
				double temp = m[i];
				if (m[i + 1] < m[i])
				{
					m[i] = m[i + 1];
					m[i + 1] = temp;
				}
			}
		}
	}

	int u_range(double *a)
	{
		int r = 0;
		double x = a[0];
		while (x <= a[n - 1] + hu / 2)
		{
			x += hu;
			r++;
		}
		return r;
	}

	void universe(double *a, double *u, int u_r)
	{
		double k = a[0];
		for (int i = 0; i < u_r; i++, k += hu)
		{
			u[i] = k;
			u[i] = round(u[i] * 10) / 10;
			if (u[i] == -0) u[i] = 0;
		}
	}

	void mask(double *a, double *u, bool *a_mask, bool *u_mask, int u_r)
	{
		int k = 0;
		for (int i = 0; i < u_r; i++)
		{
			u_mask[i] = 1;
			if (a[k] == u[i])
			{
				a_mask[i] = 1;
				k++;
			}
			else a_mask[i] = 0;
		}
	}

	void complement(bool *a_mask, bool *u_mask, bool *a_mask_comp, int u_r)
	{
		for (int i = 0; i < u_r; i++)
		{
			a_mask_comp[i] = u_mask[i] - a_mask[i];
		}
	}

	void boolean(double *a, int n) // Принцип: будується ніби табл істиності для всіх варіацій значень
								   // тоді ми робимо проходи по табличці і якшо є 1 то виводимо ці значення якшо 0 то ніякі не виводимо
								   // & - побітове порівнння а не порівняння значень напри 3(11) & 1(01) = true
								   // f - побітове представлення індексів
								   // i - це бітова маска кожного рядка в таблиці істиності яка і є булеаном 
	{
		int nos = 1 << n; // Кількість підмножин
		int f = 0;
		for (int i = 0; i < nos; i++) //Перебір бітових масок(значення числа по таблиці істиності)
		{
			cout << ("{ ");
			for (int j = 0; j < n; j++) // Перебір бітів(значення в таблиці істиності)
			{
				f = 1 << j; // Бітова маска(побітове представлення) індексів, а індекси в свою чергу представляють елементи масиву
				if (i & f) // Якщо в значення і (по таблиці істиності) є таке двійкове f що вони мають спільні елементи(якщо двійкове f входить до i)( то виводимо ті спільні елементи)
					cout << a[j] << "  "; // То виводимо jй елемент множини
			}
			cout << "}\n";
		}
	}
};


int main()
{
	set s;

	double a[n] = { 0 };

	s.inp_set(a);
	cout << endl;
	cout << "Set a:" << endl;
	s.out_set(a, n);
	cout << endl;
	cout << "Set a sorted:" << endl;
	s.sort_set(a);
	s.out_set(a, n);
	cout << endl;

	int u_r = s.u_range(a);
	double *u = new double[u_r];
	bool *a_mask = new bool[u_r];
	bool *u_mask = new bool[u_r];
	bool *a_mask_compl = new bool[u_r];
	cout << "Set universe:" << endl; // Від найменшого а до найбільшого а - межі універсуму
	s.universe(a, u, u_r);
	s.out_set(u, u_r);
	cout << endl;

	cout << "Power of universe is: " << u_r << endl;
	cout << endl;

	cout << "Mask a:" << endl;
	s.mask(a, u, a_mask, u_mask, u_r);
	s.out_set(a_mask, u_r);
	cout << endl;

	cout << "Mask a complemention:" << endl;
	s.complement(a_mask, u_mask, a_mask_compl, u_r);
	s.out_set(a_mask_compl, u_r);
	cout << endl;

	int pa = 0;
	int pac = 0;
	for (int i = 0; i < u_r; i++)
	{
		if (a_mask[i] == 1) pa++;
		if (a_mask_compl[i] == 1) pac++;
	}
	cout << "Power of a = " << pa << "  Power of a complemented = " << pac << endl;
	cout << endl;

	cout << "A complemention:" << endl;
	for (int i = 0; i < u_r; i++)
	{
		if (a_mask_compl[i] == 1) cout << u[i] << "\t";
	}
	cout << endl;
	cout << endl;
	///////////////////////
	cout << "Boolean of a:" << endl;
	s.boolean(a, n);
	cout << endl;

	delete[] a_mask_compl;
	delete[] a_mask;
	delete[] u_mask;
	delete[] u;

	_getch();
	return 0;
}

