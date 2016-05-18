#include <stdio.h>
#include <iostream>

using namespace std;

const int Nmax = 1000;
int rang[Nmax] = { 0 };
int countnum[Nmax] = { 0 };

int main(void)
{
	freopen("graph2.txt", "r", stdin);
	int n, m;

	scanf("%d%d", &n, &m);

	while (m--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		rang[x]++;
		rang[y]++;
	}

	for (int i = 1; i <= n; i++)
		countnum[rang[i]]++;

	for (int i = Nmax - 2; i >= 0; i--)
		countnum[i] += countnum[i + 1];


	if (countnum[2] > 5 || countnum[3] > 4) printf("Nonplanar graph");
	else printf("Planar graph");
}
