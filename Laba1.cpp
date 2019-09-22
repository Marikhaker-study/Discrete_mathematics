// Laba1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;

int input_var(int a, int code) // Метод для перевірки на коректність вхідних даних(
{
	int ck = 0; // змінна для перевірки

	while (ck != 2)
	{
		a = 0;
		cout << "Enter " << (char)code << endl; // Виведення назви змінної типу x, y, z через інкрементацію ascii коду в виклику функції
		cin >> a;
		if (a == 1 || a == 0)
		{
			ck = 2;

		}
		else
		{
			cout << endl;
			cout << "Again ";
		}
	}
	return a;
}

int and(int a, int b)
{
	if (a*b == 0) return 0;
	if (a*b == 1) return 1;
}

int or (int a, int b)
{
	if (a + b == 0) return 0;
	if (a + b>0) return 1;
}

int not(int a)
{
	if (a == 0) return 1;
	else if (a == 1) return 0;
}

int impl(int a, int b)
{
	if (b == 0) return 0;
	else return 1;
}


void auto_(int rez)  // Метод для виводу всієї таблиці істинності
{
	int x = 0; int y = 0; int z = 0;
	cout << "====================================TABLE=====================================" << endl;
	cout << "|   X   |   Y   |   Z   |(X or nY)|(Y and nZ)| (X or Y)|   2->3  | 1->[2->3] |" << endl;
	cout << "==============================================================================" << endl;
	x = 0;
	while (x < 2)
	{
		y = 0;
		while (y < 2)
		{
			z = 0;
			while (z < 2)
			{
				int hp = impl(and (y, not(z)), or (x, y));   // Побічна допоміжна змінна
				rez = impl(or (x, not(y)), hp);
				cout << "|   " << x << "   |   " << y << "   |   " << z << "   |    "<< or(x, not(y)) << "    |     " << and (y, not(z)) << "    |    "<<or(x, y) << "    |    " << hp << "    |     " << rez << "     |" << endl;
				z++;
			}
			y++;
		}
		x++;
	}
	cout << "==============================================================================" << endl;
}

void s_manual(int rez)  // Метод для виведення значень тыльки при ваших вхыдних даних
{
	int code = 88;
	int x = 0; int y = 0; int z = 0;
	x = input_var(x, code++);
	y = input_var(y, code++);
	z = input_var(z, code++);
	cout << "====================================TABLE=====================================" << endl;
	cout << "|   X   |   Y   |   Z   |(X or nY)|(Y and nZ)| (X or Y)|   2->3  | 1->[2->3] |" << endl;
	cout << "==============================================================================" << endl;
	int hp = impl(and (y, not(z)), or (x, y));   // Побічна допоміжна змінна
	rez = impl(or (x, not(y)), hp);
	cout << "|   " << x << "   |   " << y << "   |   " << z << "   |    "<< or(x, not(y)) << "    |     " << and (y, not(z)) << "    |    "<<or(x, y) << "    |    " << hp << "    |     " << rez << "     |" << endl;
	cout << "==============================================================================" << endl;
}

int main()
{
	system("MODE CON: COLS=100 LINES=30"); // Настройки консольки: довжина і висота
	int a[5]; // Array for input
	int n = 0;
	int rez = 0; // 

	int ck = 0; // Menu start

	while (ck != 3)
	{
		ck = 0;
		system("@cls||clear"); // Очистка екрану
		cout << "1 to auto, 2 to semi manual, 3 to exit" << endl;
		cin >> ck;
		if (ck == 1) auto_(rez); // Виклик авто - методу

		else if (ck == 2) s_manual(rez); // Виклик ручного методу
		getch();
	}

	_getch(); // Затримка екрану
	return 0;
}


