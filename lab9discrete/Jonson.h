#include <iostream>
using namespace std;
const int siz = 20, inf = 1E9;
typedef int Matrix[siz][siz], Matrix1[2*siz][2*siz];
int  start, _end, h[siz+1],n1,m1;
//bool cycle=false;
Matrix G, W,D1,D,p;
Matrix1 G1, W1,A;
int BelmanFord(Matrix1 w, int st)
{
	for (int v = 0; v < n1+1; v++) A[0][v] = inf;
	A[0][st - 1] = 0;
	for (int i = 1; i < n1+1; i++)
	{
		for (int v = 0; v < n1+1; v++)
			A[i][v] = A[i - 1][v];
		for (int r = 0; r < m1+n1; r++)
			if (A[i][G1[r][1] - 1]>A[i - 1][G1[r][0] - 1] + w[G1[r][0] - 1][G1[r][1] - 1])
			{
				A[i][G1[r][1] - 1] = A[i - 1][G1[r][0] - 1] + w[G1[r][0] - 1][G1[r][1] - 1];
			}
	}
	for (int r = 0; r < m1+n1; r++)
		if (A[n1][G1[r][1] - 1]>A[n1][G1[r][0] - 1] + w[G1[r][0] - 1][G1[r][1] - 1])
		{

			cout << G1[r][0] << " " << G1[r][1] << endl;
			//cycle = true;
			break;
		}
}
void Dijkstra(Matrix GR, int st)
{
    int INT_MAX;
	int distance[siz], count, index, i, u, m = st + 1,way[siz];
	bool visited[siz];
	for (i = 0; i<n1; i++)
	{
		distance[i] = INT_MAX; visited[i] = false;
	}
	distance[st] = 0;
	for (count = 0; count<n1 - 1; count++)
	{
		int min = INT_MAX;
		for (i = 0; i<n1; i++)
			if (!visited[i] && distance[i] <= min)
			{
				min = distance[i]; index = i;
			}
		u = index;
		visited[u] = true;
		for (i = 0; i<n1; i++)
			if (!visited[i] && GR[u][i]>0 && distance[u] != INT_MAX &&
				distance[u] + GR[u][i] < distance[i])
			{
				distance[i] = distance[u] + GR[u][i];
				way[i] = u+1;
			}
	}
	for (int i = 0; i < n1; i++)
		D1[st][i] = distance[i];
}
void Johnson()
{
    Matrix w; int st; int nd;
	for (int i = 0; i < m1; i++)
	{
		G1[i][0] = G[i][0];
		G1[i][1] = G[i][1];
		G1[i][2] = G[i][2];
	}
	for (int i = 0; i < n1; i++)
	{
		G1[m1 + i][0] = n1+1;
		G1[m1 + i][1] = i+1;
		G1[m1 + i][2] = 0;
	}
    BelmanFord(W1, n1+1);
//	if (cycle) return;
	for (int v = 0; v < n1; v++)
		h[v] = A[n1][v];
	for (int i = 0; i < m1 + n1; i++)
		w[G1[i][0] - 1][G1[i][1] - 1]= w[G1[i][0] - 1][G1[i][1] - 1]+h[G1[i][0] - 1] -h[G1[i][1] - 1];
	for (int i = 0; i < n1; i++)
		Dijkstra(w, i);
	for (int i = 0; i < n1; i++)
		for (int j = 0; j < n1; j++)
			D[i][j] = D1[i][j] - h[i] + h[j];
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n1; j++)
			if (D[i][j]>10000 || D[i][j]<-10000) cout << setw(4) << "inf"; else
				cout << setw(4) << D[i][j];
		cout << endl;
	}
}

