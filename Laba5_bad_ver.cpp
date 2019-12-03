
#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;

const int inf_max = 1000;

struct graph
{
	int a;
	int w;
	int b;
	bool ck_a;
	bool ck_b;
	int a_i, a_j, b_i, b_j;
	graph()
	{
	}

	graph(int a, int w, int b) : a{ a }, w{ w }, b{ b }
	{
		this->ck_a = 0;
		this->ck_b = 0;
		a_i = a / 10; a_j = a % 10;
		b_i = b / 10; b_j = b % 10;
	}
};

void initgraph(graph *g, int nodes, int sides)
{
	//Horisontal
	g[0] = { 0,6,1 };		g[1] = { 1,1,2 };		g[2] = { 2,1,3 };		g[3] = { 3,3,4 };		g[4] = { 4,3,5 };
	g[5] = { 10,2,11 };		g[6] = { 11,1,12 };		g[7] = { 12,4,13 };		g[8] = { 13,2,14 };		g[9] = { 14,4,15 };
	g[10] = { 20,7,21 };	g[11] = { 21,1,22 };	g[12] = { 22,2,23 };	g[13] = { 23,3,24 };	g[14] = { 24,7,25 };
	g[15] = { 30,7,31 };	g[16] = { 31,3,32 };	g[17] = { 32,1,33 };	g[18] = { 33,8,34 };	g[19] = { 34,5,35 };
	g[20] = { 40,4,41 };	g[21] = { 41,7,42 };	g[22] = { 42,3,43 };	g[23] = { 43,3,44 };	g[24] = { 44,6,45 };
	//Vertical
	g[25] = { 0,4,10 };		g[26] = { 1,8,11 };		g[27] = { 2,3,12 };		g[28] = { 3,1,13 };		g[29] = { 4,5,14 };		g[30] = { 5,7,15 };
	g[31] = { 10,5,20 };	g[32] = { 11,1,21 };	g[33] = { 12,3,22 };	g[34] = { 13,4,23 };	g[35] = { 14,1,24 };	g[36] = { 15,7,25 };
	g[37] = { 20,5,30 };	g[38] = { 21,7,31 };	g[39] = { 22,1,32 };	g[40] = { 23,4,33 };	g[41] = { 24,2,34 };	g[42] = { 25,8,35 };
	g[43] = { 30,8,40 };	g[44] = { 31,2,41 };	g[45] = { 32,1,42 };	g[46] = { 33,3,43 };	g[47] = { 34,3,44 };	g[48] = { 35,7,45 };

	/*{ {0, 6, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 6, 0, 0, 8, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 4, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 8, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 0, 0, 0, 1, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 3, 0, 0, 0, 5, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 1, 3, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 1, 0, 4, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 5, 0, 2, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 8, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 7, 0, 0, 0 },
	{ 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 1, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 3, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 7, 0, 0, 0, 2, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 2, 7, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 3, 0, 1, 0, 0, 1, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 1, 0, 8, 0, 0, 3, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 8, 0, 5, 0, 0, 3, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 5, 0, 0, 0, 0, 7 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 3, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 3, 0, 3, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 3, 0, 6 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 6, 0 }};*/
}

//Sorting incidence sides
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
		cout << g[i].a << "\t" << g[i].w << "\t" << g[i].b << "\t"<< endl;
	}
	cout << endl;
}

int min(graph *g, int size)
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

void dijkstra(graph *g, int nodes, int sides)
{

	//Massive of node weights
	int **node_w = new int*[5];
	for (int i = 0; i < 5; i++)
	{
		node_w[i] = new int[6];
	}
	//Initializing
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			node_w[i][j] = inf_max;
		}
	}
	node_w[0][0] = 0;// Start element = 0

	int *ck_node = new int [nodes]; // massive of checked
	int ck_size = 0;
	//Output
	cout << "Graph layout" << endl;
	cout << "Horisontal\n" << endl;
	for (int i = 0; i < sides; i++)
	{
		if (i == 25) cout << "\nVertical\n" << endl;
		cout << "S["<<i <<"]"<< "\t" << g[i].a << "\t" << g[i].b << "\t" << g[i].w << "\t" << endl;
	}
	cout << endl;
	//////////////////////////////////////////////////////////////////

	int active = g[0].a; // active node == #0
	int active_i = 0;
	int *adj_list = new int [nodes]; // massive to add incedence sides // 4 == max size of incidence
	int adj_count = 0;

	do
	{
		int adj_num = 0; // num of sumishni unchecked
		
		for (int i = 1; i < sides; i++) // Записуємо якшо наша вершина входить в провірені
		{
			for (int j = 0; j < ck_size; j++)
			{
				if (g[i].a == ck_node[j])
				{
					g[i].ck_a = 1;
					break;
				}
			}

			for (int j = 0; j < ck_size; j++)
			{
				if (g[i].b == ck_node[j])
				{
					g[i].ck_b = 1;
					break;
				}
			}
		}

		for (int i = 0; i < sides; i++) // Count num of sumish unchecked
		{
			if ((g[i].a == active || g[i].b == active))
			{
				adj_num++;
			}
		}

		//for (int i = 0; i < sides; i++) // Count num of sumish unchecked // Добавити перевірку на провірені
		//{
		//	if ((g[i].a == active || g[i].b == active))
		//	{
		//		if ((g[i].ck_a != 1 && g[i].ck_b != 1))
		//		{
		//			adj_num++;
		//		}
		//		
		//	}
		//}

		graph *adj = new graph[adj_num]; // Graph of incidence
		int k = 0;
		for (int i = 0; i < sides; i++) // adding incidence sides to the massive
		{
			if (g[i].a == active || g[i].b == active)
			{
				adj[k] = g[i];
				k++;
			}
		}

		sort(adj, adj_num);
		*adj_list = *adj;
		adj_count = 0;
		for (int i = 0; i < adj_num; i++) // Writing side_w to sumish
		{
			if (adj[i].a == active)
			{
				node_w[adj[i].b_i][adj[i].b_j] = node_w[adj[i].a_i][adj[i].a_j] + adj[i].w;
				cout << node_w[adj[i].b_i][adj[i].b_j] << endl;
			}
			else if (adj[i].b == active)
			{
				node_w[adj[i].a_i][adj[i].a_j] = node_w[adj[i].b_i][adj[i].b_j] + adj[i].w;
				cout << node_w[adj[i].a_i][adj[i].a_j] << endl;
			}
		}
		do {
			active = adj[adj_count].


		} while (adj_count < adj_num);


			delete[] adj;
	} while (ck_size < nodes);

	

	delete[] adj_list;



	//////////////////////////////////////////////////////////////////
		delete[] ck_node;
	for (int i = 0; i < 5; i++)
	{
		delete[] node_w[i];
	}
	delete[] node_w;

	
}


int main()
{
	int nodes = 6*5; // 30
	int sides = 5*5+4*6; // 49
	graph *g = new graph[sides];

	initgraph(g, nodes, sides);
	dijkstra(g, nodes, sides);
	delete[] g;
	_getch();
	return 0;
}
