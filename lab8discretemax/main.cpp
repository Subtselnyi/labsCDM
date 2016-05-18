#include <iostream>
#include <fstream>
#include <iostream>
#include <deque>
#include <vector>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

struct edge
{
	int from;
	int to;
	int weight;
};

vector <edge> graph;
vector <int> dist; // DISTANCE
vector <int> path;

void input(int&n)
{
	int m;
	edge temp;
	FILE* file = fopen("graf.txt", "rt"); // REDING FROM FILE

	fscanf(file, "%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		fscanf(file, "%d%d%d", &temp.from, &temp.to, &temp.weight);
		graph.push_back(temp);
	}

	fclose(file);
}

int ford_belman(int& n, int start)
{
	bool isNegativeCircul = false;
	dist.assign(n+1, INF); // ~ int dist[n];
	dist[start] = 0;
	path.assign(n+1, -1);

	for (int i = 0; i <= n; i++)
		for (int j = 0; j < graph.size(); j++)
		{
			int from = graph[j].from;
			int to = graph[j].to;
			int weight = graph[j].weight;

			if (dist[to] > dist[from] + weight)
			{
				dist[to] = dist[from] + weight;
				path[to] = from;
				if (i == n) isNegativeCircul = true;
			}
		}

	if (isNegativeCircul)
	{
		printf("Vid cycle\n");//Error. Negative circul in graph!
		return 0;
		//exit(-1);
	}
}

int output(int& n)
{
	int start;
	int end;
	int choise;

	//printf("Viberit:\n");//Make choice
	printf("1. route and distance ;\n2. distance .\n");//Out path and distance from point <start> to <end> Out distance from point <start> to other points
	scanf("%d", &choise);

	if (choise == 1)
	{
		printf("first vertex = ");
		scanf("%d", &start);
		printf("end vertex = ");
		scanf("%d", &end);

		ford_belman(n, start);

		printf("Distance: %d", dist[end]);

		vector <int> way;
		while (end != -1)
		{
			way.push_back(end);
			end = path[end];
		}

		printf("\nroute:\n");//Path
		for (int i = way.size() - 1; i >= 0; i--) printf("%d ", way[i]);
	}
	else if (choise == 2)
	{
		printf("first vertex= ");
		scanf("%d", &start);

		ford_belman(n, start);

		cout<<"Distance from "<<start<<" to:\n";
		for (int i = 1; i <= n; i++) printf("%d - %d\n", i, dist[i]);
	}
	else
	{
		printf("Input error!\n");
		//system("pause");
		return 0;
		//exit(-1);
	}

//	system("pause");
return 0;
}

int main(void)
{
	int n;
	input(n);
	output(n);
}
