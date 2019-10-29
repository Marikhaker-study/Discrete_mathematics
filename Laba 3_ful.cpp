// Laba3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

//const int n = 5;

struct set
{
	void inp_set(int *a, int n) //////////
	{
		char ck[5];
		cout << "Enter set with different values" << endl;
		for (int i = 0; i < n; i++)
		{
		p1:
			cin >> ck;
			if (atoi(ck) || ck[0] == '0') a[i] = atoi(ck);
			else
			{
				cout << "Enter again" << endl;
				goto p1;
			}
		}
	}

	void out_set(int *a, int n)  //////////
	{
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << "\t";
		}
		cout << endl;
	}

	void bin_rel(int *a, int an, int *b, int bn, bool **b_r)
	{

		for (int i = 0; i < an; i++)
		{
			for (int j = 0; j < bn; j++)
			{
				if ((2 * a[i]) >(3 * b[j])) b_r[i][j] = 1;
				else b_r[i][j] = 0;
			}
		}

		//b_r[0][0] = 1; b_r[0][1] = 0; b_r[0][2] = 1; b_r[0][3] = 1;   //Preset 1
		//b_r[1][0] = 0; b_r[1][1] = 1; b_r[1][2] = 0; b_r[1][3] = 0;
		//b_r[2][0] = 0; b_r[2][1] = 0; b_r[2][2] = 1; b_r[2][3] = 0;
		//b_r[3][0] = 1; b_r[3][1] = 0; b_r[3][2] = 0; b_r[3][3] = 1;

		//b_r[0][0] = 1; b_r[0][1] = 0; b_r[0][2] = 1; b_r[0][3] = 0;	//Preset 2
		//b_r[1][0] = 0; b_r[1][1] = 1; b_r[1][2] = 0; b_r[1][3] = 1;
		//b_r[2][0] = 1; b_r[2][1] = 0; b_r[2][2] = 1; b_r[2][3] = 0;
		//b_r[3][0] = 0; b_r[3][1] = 1; b_r[3][2] = 0; b_r[3][3] = 1;

		cout << "AxB" << "\t";
		for (int j = 0; j < bn; j++)
		{
			cout << b[j] << "\t";
		}
		cout << endl;

		for (int i = 0; i < an; i++)
		{
			cout << a[i] << "\t";
			for (int j = 0; j < bn; j++)
			{
				cout << b_r[i][j] << "\t";
			}
			cout << endl;
		}
	}

	struct binary
	{
		int reflex(bool **b_r, int an, int bn, set s)
		{
			//bool flag = 1;
			int k = 0;
			for (int i = 0; i < an; i++)
			{
				if (b_r[i][i] == 1) k++;
			}
			cout << "Reflex: ";
			if (k == an)
			{
				cout << "True" << endl;
				return 1;
			}
			else
			{
				cout << "False" << endl;
				return 0;
			}
		}

		void anti_reflex(bool **b_r, int an, int bn, set s)
		{
			int k = 0;
			for (int i = 0; i < an; i++)
			{
				if (b_r[i][i] == 0) k++;
			}
			cout << "Anti reflex: ";
			if (k == an) cout << "True" << endl;
			else cout << "False" << endl;
		}

		int simetr(bool **b_r, int an, int bn, set s)
		{
			bool flag = 1;
			int cond = 0;
			for (int i = 0; i < an; i++)
			{
				for (int j = 0; j < an; j++)
				{
					if (b_r[i][j] == 0)cond++;
				}
			}
			if (cond == (an*an))
			{
				cout << "Simetr: ";
				cout << "False" << endl;
				return 0;
			}
			int i = 0;
			do {
				for (int j = 0; j < an; j++)
				{
					if (i != j)
					{
						if ((b_r[i][j] == 1 && b_r[j][i] == 0) || (b_r[i][j] == 0 && b_r[j][i] == 1)) flag = 0;

					}
				}
				i++;
			} while (i < an&&flag != 1);
			cout << "Simetr: ";
			if (flag)
			{
				cout << "True" << endl;
				return 1;
			}
			else
			{
				cout << "False" << endl;
				return 0;
			}
		}

		int a_simetr(bool **b_r, int an, int bn, set s, int sim)
		{
			if (sim == 1)
			{
				cout << "A_simetr: ";
				cout << "False" << endl;
				return 0;
			}
			bool flag = 1;
			int i = 0;
			int tf = 0;
			int ff = 0;
			do {
				for (int j = 0; j < bn; j++)
				{
					if (i != j)
					{
						if ((b_r[i][j] == 1 && b_r[j][i] == 0) || (b_r[i][j] == 0 && b_r[j][i] == 1))
						{
							flag = 0;
							ff++;
						}
						if (b_r[i][j] == b_r[j][i]) tf++;
					}
				}
				i++;
			} while (i < an&&flag != 1);
			cout << "A_simetr: ";
			if (!flag && ff != 0 && tf != 0) {
				cout << "True" << endl;
				return 1;
			}
			else
			{
				cout << "False" << endl;
				return 0;
			}
		}

		void anti_simetr(bool **b_r, int an, int bn, set s, int sim, int a_sim)
		{
			if (sim == 1 || a_sim == 1)
			{
				cout << "Anti_simetr: ";
				cout << "False" << endl;
				return;
			}



			bool flag = 1;

			int i = 0;
			do {
				for (int j = 0; j < an; j++)
				{
					if (i != j)
					{
						if (b_r[i][j] == 1 && b_r[j][i] == 1) flag = 0;
					}
				}
				i++;
			} while (i < an&&flag != 1);
			cout << "Anti_simetr: ";
			if (flag) cout << "True" << endl;
			else cout << "False" << endl;
		}

		int trans(bool **b_r, int an, int bn, set s)
		{
			bool flag = 1;

			int cond = 0;
			for (int i = 0; i < an; i++)
			{
				for (int j = 0; j < an; j++)
				{
					if (b_r[i][j] == 0)cond++;
				}
			}
			if (cond == (an*an))
			{
				cout << "Trans: ";
				cout << "False" << endl;
				return 0;
			}
			for (int i = 0; i < an; i++)
			{
				for (int j = 0; j < an; j++)
				{
					for (int k = 0; k < an; k++)
					{
						if (b_r[i][k] && b_r[k][j] && !b_r[i][j]) flag = 0;
					}
				}
			}
			cout << "Trans: ";
			if (flag)
			{
				cout << "True" << endl;
				return 1;
			}
			else
			{
				cout << "False" << endl;
				return 0;
			}
		}

		void anti_trans(bool **b_r, int an, int bn, set s, int trans)
		{
			if (trans == 1) return;
			bool flag = 1;

			for (int i = 0; i < an; i++)
			{
				for (int j = 0; j < an; j++)
				{
					for (int k = 0; k < an; k++)
					{
						if (b_r[i][k] && b_r[k][j] && b_r[i][j]) flag = 0;
					}
				}
			}
			cout << "Anti_trans: ";
			if (flag) cout << "True" << endl;
			else cout << "False" << endl;
		}

	}bin;

	void type_b_r(bool **b_r, int an, int bn, set s)
	{
		int refl = bin.reflex(b_r, an, bn, s);
		bin.anti_reflex(b_r, an, bn, s);
		int sim = bin.simetr(b_r, an, bn, s);
		int a_sim = bin.a_simetr(b_r, an, bn, s, sim);
		bin.anti_simetr(b_r, an, bn, s, sim, a_sim);
		int tran = bin.trans(b_r, an, bn, s);
		bin.anti_trans(b_r, an, bn, s, tran);

		cout << "Full: ";
		if (refl == 1 && sim == 1 && tran == 1)
		{
			cout << "True" << endl;
		}
		else cout << "False" << endl;
	}
};

int main()
{
	set s;

	int an, bn, b_rn;
	//cout << "Enter size of set a, b" << endl;
	//cin >> an >> bn;
	an = 4; bn = 4;
	int *a = new int[an];
	int *b = new int[bn];

	bool **b_r = new bool*[an];
	for (int i = 0; i < an; i++)
		b_r[i] = new bool[bn];

	s.inp_set(a, an);
	s.inp_set(b, bn);
	cout << endl;

	cout << "Set a:" << endl;
	s.out_set(a, an);
	cout << endl;
	cout << "Set b:" << endl;
	s.out_set(b, bn);
	cout << endl;

	s.bin_rel(a, an, b, bn, b_r);
	cout << endl;

	s.type_b_r(b_r, an, bn, s);

	for (int i = 0; i < an; i++)
		delete[] b_r[i];
	delete[] b_r;

	delete[] a;
	delete[] b;
	_getch();
	return 0;
}

