//#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <fstream>
using namespace std;
const int MAXN = 1000;
int ncycle = 0, color[20] = { 0 }, p[20] = { -1 }, cycle_st, cycle_end, n, m, i=0, j;
bool CycleFound;
vector<int> cycle[MAXN], temp[MAXN], g[MAXN];
int v[20], u[20];int aM[20][20];int a_dist[20][20];int a_aviab[20][20];

void readList(int *n, int *m, int *v, int *u) {

	/*cin >> *n >> *m;
	for (int i = 0; i < (*m); i++)
		cin >> *(v + i) >> *(u + i);*/

		fstream Ffile;
		Ffile.open("graf.txt", ios::in);

    Ffile >> n;
    Ffile >> m;

        while(!Ffile.eof()){
            Ffile >> v[i];
            Ffile >> u[i];
            i++;
        }
    Ffile.close();

}
void adjBuild(int n, int m, int *v, int *u) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			aM[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		aM[*(v + i) - 1][*(u + i) - 1] = 1;
		g[*(v + i) - 1].push_back(*(u + i) - 1);
	}
	cout << endl;
	cout << "  ";
	for (int i = 0; i < n; i++) {
		cout << " u" << i + 1;
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << "v" << i + 1;
		for (int j = 0; j < n; j++) {
			cout << "  " << aM[i][j];
		}
		cout << endl;
	}
}
void makeChoice() {
	adjBuild(n, m, v, u);
}
void floyd() {
	int i, j, k;
	for (i = 0; i<n; i++)
		for (j = 0; j<n; j++)
			a_dist[i][j] = aM[i][j];
	for (i = 0; i<n; i++)
		for (j = 0; j<n; j++)
			for (k = 0; k<n; k++)

				if (a_dist[i][k] != 0 && a_dist[k][j] != 0 && a_dist[i][j] != 0 && (a_dist[i][j]>a_dist[i][k] + a_dist[k][j]))
					a_dist[i][j] = a_dist[i][k] + a_dist[k][j];
				else
					if (a_dist[i][k] != 0 && a_dist[k][j] != 0 && a_dist[i][j] == 0 && i != j) a_dist[i][j] = a_dist[i][k] + a_dist[k][j];

	cout << endl;
	cout << "Distance matrix:\n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%2d", a_dist[i][j]);
		cout << endl;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			if (a_dist[i][j] != 0 || i == j)
				a_aviab[i][j] = 1;
	}
	cout << endl;
	cout << "Aviability matrix:\n";
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%2d", a_aviab[i][j]);
		cout << endl;
	}
}
int add_cycle(int cycle_end, int cycle_st)
{
	cycle[ncycle].clear();
	cycle[ncycle].push_back(cycle_st);
	for (int v = cycle_end; v != cycle_st; v = p[v])
		cycle[ncycle].push_back(v);
	reverse(cycle[ncycle].begin(), cycle[ncycle].end());
	sort(cycle[ncycle].begin(), cycle[ncycle].end());
	int i = 1;
	return cycle[ncycle].size();
}
void dfs(int v)
{
	color[v] = 1;
	for (int i = 0; i < g[v].size(); i++)

	{
		int to = g[v][i];
		if (color[to] == 0)
		{
			p[to] = v;
			dfs(to);
		}
		else if (color[to] == 1)
		{
			CycleFound = true;
			if (add_cycle(v, to) > 1)
				ncycle++;
		}
	}
	color[v] = 0;
}
void find_cycles()
{
	for (int i = 0; i < n; i++)
		p[i] = -1;
	cout << endl;
	for (int i = 0; i < n; i++)
		if (color[i] == 0)
			dfs(i);

	if (ncycle == 0) cout << "No cycles\n";
	else {
		cout << "Cycles:\n";
	}


	for (int i = 0; i < ncycle; i++)
		for (int j = i + 1; j < ncycle; j++)
			if (cycle[i] == cycle[j]) cycle[j][0] = -1;

	for (int i = 0; i < ncycle; i++)
	{
		if (cycle[i][0] != -1) {
			for (int j = 0; j < cycle[i].size(); j++)
				cout << cycle[i][j] + 1 << "  ";
			cout << endl;
		}
	}
	cout << endl;
}
bool connectivity1() {
	bool f1 = 1,f2=1;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			if (!a_aviab[i][j] || !a_aviab[j][i]) f1 = 0;
			if ((!a_aviab[i][j] && !a_aviab[j][i]) || (a_aviab[i][j] && a_aviab[j][i])) f2 = 0;
		}
	if (f1) cout << "Graf sylnozvyazniy\n";
	if (f2)	cout << "Graf odnobichno-zvyazniy\n";
		if (f1 || f2)
			return true;
		else
			return false;

}
void floyd2() {
	int i, j, k;
	for (i = 0; i<n; i++)
		for (j = 0; j<n; j++)
			if (aM[i][j] == 1 || aM[j][i] == 1) {
				a_dist[i][j] = 1;
				a_dist[j][i] = 1;
			}
			else
			{
				a_dist[i][j] = 0;
				a_dist[j][i] = 0;
			}
	for (i = 0; i<n; i++)
		for (j = 0; j<n; j++)
			for (k = 0; k<n; k++)

				if (a_dist[i][k] != 0 && a_dist[k][j] != 0 && a_dist[i][j] != 0 && (a_dist[i][j]>a_dist[i][k] + a_dist[k][j]))
					a_dist[i][j] = a_dist[i][k] + a_dist[k][j];
				else
					if (a_dist[i][k] != 0 && a_dist[k][j] != 0 && a_dist[i][j] == 0 && i != j) a_dist[i][j] = a_dist[i][k] + a_dist[k][j];

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			if (a_dist[i][j] != 0 || i == j)
				a_aviab[i][j] = 1;
	}
	bool f = 1;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (!a_aviab[i][j] || !a_aviab[j][i]) f = 0;
	if (f) cout << "Slabkozvyazniy\n";
	else
		cout << "Nezvyazniy\n";


}

int main()
{
	readList(&n, &m, v, u);
	makeChoice();
	floyd();
	find_cycles();
	if (!connectivity1())
		floyd2();
	system("pause");
}

