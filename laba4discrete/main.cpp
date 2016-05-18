#include <iostream>

using namespace std;

int a[100][100],n,m,s;
int color[100];
int pointer = 0;
int q[100];
int last=2,first=1;
bool used[100];


void dfs(int v) {
int i;
pointer++;

if (color[v] == 2) {return;} else {
	color[v] = 1;

	//Выводим содержимое стека:
	cout<<"Вершина: "<<v<<", DFS номер: "<<pointer<<", Содержимое стека:  ";
	for (i=1;i<=n;i++)
			if (color[i] == 1)
					cout<<i<<" ";
	cout<<""<<endl;

	for (i=1;i<=n;i++) if ((a[v][i] == 1) && (color[i]==0)) dfs(i);

color[v] = 2;
cout<<"Вершина: "<<"-"<<", DFS номер: "<<"-"<<", Содержимое стека:  ";
  	for (i=1;i<n;i++)
			if (color[i] == 1)
					cout<<i<<" ";
	cout<<""<<endl;
	}
}

int main() {
int k,i,j,v,u;

cin>>n>>m>>s;


for (i=1;i<=m;i++)
{
		cin>>v>>u;
		a[v][u]=1;
}
cout<<endl<<"Поиск в глубину:"<<endl<<endl;
for (i=s;i<=n;i++)
	if (color[i] == 0) dfs(i);

cout<<endl;

used[s] = true;
q[1]=s;
pointer = 1;
cout<<"Поиск в ширину:"<<endl<<endl;

while (last!=first)  {
	k = q[first];
	cout<<"Вершина: "<<k<<", BFS номер: "<<pointer<<", Содержимое очереди:  ";
	for (i=first;i<last;i++) cout<<q[i]<<" ";
	cout<<""<<endl;
	pointer++;

	for (i=1;i<=n;i++)  {
		if ((a[k][i]==1) && (!used[i])) {used[i] = true; q[last]=i; last++;}
}

first++;
/*cout<<"Вершина: "<<"-"<<", BFS номер: "<<"-"<<", Содержимое очереди:  ";
	for (i=first;i<last;i++) cout<<q[i]<<" ";
	cout<<""<<endl;*/
}



}
