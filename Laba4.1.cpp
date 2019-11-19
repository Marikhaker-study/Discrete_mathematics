// Laba4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;

struct graph
{
	int a;
	int b;
	int w;
	bool ck_a;
	bool ck_b;

	graph()
	{
	}

	graph(int a, int b, int w) : a{ a }, b{ b }, w{ w }
	{
		this->ck_a = 0;
		this->ck_b = 0;
	}
};

//Initialisation of graph
void initgraph(graph *g, int nodes, int sides)
{
	g[0] = { 1,2,4 };
	g[1] = { 2,5,2 };
	g[2] = { 5,8,7 };
	g[3] = { 8,11,7 };
	g[4] = { 11,10,3 };
	g[5] = { 10,7,5 };
	g[6] = { 7,4,4 };
	g[7] = { 4,1,2 };
	g[8] = { 1,3,3 };
	g[9] = { 3,5,6 };
	g[10] = { 5,9,5 };
	g[11] = { 9,11,1 };
	g[12] = { 9,7,4 };
	g[13] = { 2,7,1 };
	g[14] = { 3,6,7 };
	g[15] = { 6,4,2 };
	g[16] = { 6,10,3 };
	g[17] = { 6,8,4 };
}

void sort(graph *g, int sides)
{
	graph t;
	for (int j = 0; j < sides - 1; j++)
	{
		for (int i = 0; i < sides - 1; i++)
		{
			if (g[i + 1].w < g[i].w)
			{
				t = g[i];
				g[i] = g[i + 1];
				g[i + 1] = t;
			}
		}
	}

	for (int i = 0; i < sides; i++)
	{
		cout << i<< "\t" << g[i].a << "\t" << g[i].b << "\t" << g[i].w << "\t" << endl;
	}
	cout << endl;
}


void MOD_P(graph *g, int nodes, int sides)
{
	sort(g, sides);

	int *ck_node = new int[nodes]; // Масив перевірки на приналежність
		
	int ck_i = 0; // Кількість записаних

	for (int i = 0; i < nodes; i++)
	{
		ck_node[i] = 0;
	}
	cout << "Min ost tree" << endl;
	cout << "A\t" << "B\t" << "Weight\t" << endl;
	cout << endl;
	cout << g[0].a << "\t" << g[0].b << "\t" << g[0].w << "\t" << endl;
	g[0].ck_a = 1; 	g[0].ck_b = 1;
	ck_node[ck_i] = g[0].a;
	ck_i++;
	ck_node[ck_i] = g[0].b;
	ck_i++;

	int active_i = 0; // Значення яке провіряється

	while (ck_i < nodes)
	{
		for (int i = 1; i < sides; i++) // Записуємо якшо наша вершина входить в провірені
		{
			for (int j = 0; j < ck_i; j++)
			{
				if (g[i].a == ck_node[j])
				{
					g[i].ck_a = 1;
					break;
				}
			}

			for (int j = 0; j < ck_i; j++)
			{
				if (g[i].b == ck_node[j])
				{
					g[i].ck_b = 1;
					break;
				}
			}
		}

		for (int i = 1; i < sides; i++) // рахуємо кількість суміжних вершин
		{
			if ( (g[i].ck_a == 1 && g[i].ck_b == 0) || (g[i].ck_a == 0 && g[i].ck_b == 1) )
			{
				if (g[i].ck_a == 1)
				{
					cout << g[i].a << "\t" << g[i].b << "\t" << g[i].w << "\t" << endl;
					g[i].ck_b = 1;
					ck_node[ck_i] = g[i].b;
					ck_i++;
					break;
				}

				if (g[i].ck_b == 1)
				{
					cout << g[i].a << "\t" << g[i].b << "\t" << g[i].w << "\t" << endl;
					g[i].ck_a = 1;
					ck_node[ck_i] = g[i].a;
					ck_i++;
					break;
				}				
			}
		}
	}

	delete[] ck_node;
}


int main()
{
	int nodes = 11;
	int sides = 18;
	graph *g = new graph[sides];
	cout << "Initialized graph" << endl;
	cout <<"Side\t" << "A\t" << "B\t" << "Weight\t" << endl;
	cout << endl;
	initgraph(g, nodes, sides); 
	
	MOD_P(g, nodes, sides);

	delete[] g;
	_getch();
	return 0;
}

