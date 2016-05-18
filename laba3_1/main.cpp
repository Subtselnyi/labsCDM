#include <iostream>
using namespace std;


int q[100],a[100][100],b[100][100],c[100][100];
int n;
int cycle[100];
bool haveCycle = false;
int f=0;
int comp = 0;

bool sm = false;
int type = 1;
//1 - не связный
//2 - односторонне-связный
//3 - сильно-связный

void dfs (int v) {
		f++;
		cycle[f]=v;
		q[v] = 1;
		for (int i=1;i<=n;i++)
				if (c[v][i] > 0 && q[i]==1)
				{
						haveCycle = true;
						cout<<"найден цикл:"<<endl;
						for (int j=i;j<=f;j++)
								cout<<cycle[j]<<" ";
						cout<<endl;
						if (f==n) sm = true;

				}

				else if (c[v][i] > 0)
						dfs(i);
			q[v] = 2;
}




int min2 (int a, int b)
{
		if (a < b) return a; else return b;
}

int main() {

int un,in[100],out[100],m,i,j,v,u;
bool uniform = true;
int min=999,max=0;
int task[100],visited[100],v2[100];
int total = 0;


cin>>n>>m;


	for (i=1;i<=n;i++)
	for (j=1;j<=n;j++)
	{	a[i][j]=999;
		b[i][j]=0;
		c[i][j]=0;
		q[i] = 0;
	}

for (i=1;i<=m;i++)
{
		cin>>v>>u;
		a[v][u]=1;
		b[v][u]=1;
		c[v][u]=1;
}


for (int k=1;k<=n;k++)
for (i=1;i<=n;i++)
for (j=1;j<=n;j++)
{
a[i][j] = min2(a[i][j], a[i][k] + a[k][j]);
b[i][j] = b[i][j] || (b[i][k] && b[k][j]);
}

cout<<endl<<"Матриця видстаней графа:"<<endl;

	for (i=1;i<=n;i++) {
	for (j=1;j<=n;j++)
	{if (a[i][j]==999) a[i][j]=0;
			cout<<a[i][j]<<" ";
	}
		cout<<endl;
	}

cout<<endl<<"Матрица досяжнносты графа:"<<endl;

	for (i=1;i<=n;i++) {
	for (j=1;j<=n;j++)
		cout<<b[i][j]<<" ";
		cout<<endl;
	}

for (i=1;i<=n;i++)
	if (q[i]==0) {f=0; dfs(i); comp++; }

cout<<"кылькысть компонент звязносты: "<<comp<<endl;

if (sm && comp==1) type=3;
if (!sm && comp==1) type=2;

switch(type) {
		case 1: cout<<"Граф незвязний"<<endl; break;
		case 2: cout<<"Граф односторонньо-звязный"<<endl; break;
		case 3: cout<<"Граф сильно-звязный"<<endl; break;
		default: cout<<"not defined"<<endl;

}



}
