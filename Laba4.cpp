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

	graph()
	{
	}

	graph(int a, int b, int w) : a{ a }, b{ b }, w{ w }
	{
	}
};

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

int min(graph *g, int size )
{
	int min_m = g[0].w;
	int min_index = 0;
	for (int i = 1; i < size; i++)
	{
		if (g[i].w < min_m)
		{
			min_m = g[i].w;
			min_index = i;
		}
	}
	//cout << "Min size is: " << min_m << endl;
	return min_index;
}

void MOD(graph *g, int nodes, int sides) // Відштовхуємось від неноданих нод
{
	bool *ck_sd = new bool[sides]; // ДОПИСАТИ шоб записувало в масив пройдені іі якшо пройдена - пропускало!!!!
	bool *ck_node = new bool[nodes];


	int i = 0;
	
	//int **adjacent = new int*[nodes - 1]; // масив для суміжних
	while (i<sides)
	{
		int active = 0;
		int adj_num = 0;
		//int active_i = 0;
		active = g[i].a;
	//	active_i = i;
		for (int i = 0; i < sides; i++) // рахуємо кількість суміжних вершин
		{
			if (g[i].a == active || g[i].b == active) 
			{
				adj_num++;
			}
		}
		graph *adj = new graph[adj_num];
		int k = 0;
		for (int i = 0; i < sides; i++) // рахуємо кількість суміжних вершин
		{
			if (g[i].a == active || g[i].b == active)
			{
				adj[k] = g[i];
				k++;
			}
		}
		int min_side = min(adj, adj_num);
		for (int i = 0; i < sides; i++) // перевірка на належність
		{
			if (g[i].a == active || g[i].b == active)
			{
				adj[k] = g[i];
				k++;
			}
		}
		cout << "Min side is: " <<  endl;
		cout << adj[min_side].a << "\t" << adj[min_side].b << "\t" << adj[min_side].w << "\t" << endl;

		delete[] adj;
		i++;
	}



	delete[] ck_node;
	delete[] ck_sd;
}

int main()
{
	int nodes = 11;
	int sides = 18;
	graph *g = new graph[sides];

	initgraph(g, nodes, sides);
	MOD(g, nodes, sides);

	delete[] g;
	_getch();
    return 0;
}

