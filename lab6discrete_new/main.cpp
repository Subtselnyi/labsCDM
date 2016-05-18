#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int a[100][100],b[100][100],n,m,s;
int data[100][100];
int color[100];
int c = 0, p = 0, p2 = 0;
int listing[100],component[100];
bool used[100];


void dfs(int v) {
used[v] = true;
	for (int i=1;i<=n;i++) if ((a[v][i] == 1) && (!used[i])) dfs(i);

p++;
listing[p] = v;
}


void dfs2(int v) {
used[v] = true;
p2++;
component[p2] = v;

	for (int i=1;i<=n;i++) if ((b[v][i] == 1) && (!used[i])) dfs2(i);

}

int main() {
int i=0,v;

  fstream Ffile;
    Ffile.open("graf.txt", ios::in);
    Ffile >> n;
    Ffile >> m;

        while(!Ffile.eof()){
            Ffile >> data[i][0];
            Ffile >> data[i][1];
           a[data[i][0]][data[i][1]]=1;
           b[data[i][1]][data[i][0]]=1;
             i++;
             used[i] = false;
        }
    Ffile.close();

/*cin>>n>>m;
cout<<endl;

for (i=1;i<=m;i++)
{		used[i] = false;
		cin>>v>>u;
		a[v][u]=1;
		b[u][v]=1;
}*/

for (i=1;i<=n;i++)
	if (!used[i]) dfs(i);
/*
cout<<"Список вершин в порядке уменьшения времени выхода: ";
for (i=1;i<=n;i++) cout<<listing[i]<<" ";
cout<<endl;
*/

for (i=1;i<=n;i++) used[i] = false;

for (i=1;i<=n;i++) {
v = listing[n-i+1];
	if (!used[v]) {
	p2 = 0;
	dfs2(v);
	c++;
	sort(component+1,component+p2+1);
	cout<<"Компонента сильной связности #"<<c<<": ";
	for (int j=1;j<=p2;j++) cout<<component[j]<<" ";
	cout<<endl;
	}

}

cout<<endl;

}
