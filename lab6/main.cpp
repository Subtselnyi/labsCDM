#include <iostream>
#include <fstream>

using namespace std;

int a[100][100],n,m,s,timing;
int tout[100];
int data[100][100];
int color[100];
int pointer = 0;
int q[100];
int last=2,first=1;
bool used[100];

void dfs(int v) {
int i;
pointer++;
timing++;

if (color[v] == 2) {return;} else {
	color[v] = 1;

	//Выводим содержимое стека:
	cout<<"Вершина: "<<v<<", DFS номер: "<<pointer<<", Содержимое стека:  ";
	for (i=1;i<=n;i++)
			if (color[i] == 1)
					cout<<i<<" ";
	cout<<""<<endl;

	for (i=1;i<=n;i++) if ((a[v][i] == 1) && (color[i]==0)) dfs(i);
    tout[v]=timing;
    color[v] = 2;
/*cout<<"Вершина: "<<"-"<<", DFS номер: "<<"-"<<", Содержимое стека:  ";
  	for (i=1;i<n;i++)
			if (color[i] == 1)
					cout<<i<<" ";
	cout<<""<<endl;*/
	}
}



int main()
{
     fstream Ffile;
    Ffile.open("graf.txt", ios::in);
     int i=0;
    Ffile >> n;
    Ffile >> m;

        while(!Ffile.eof()){
            Ffile >> data[i][0];
            Ffile >> data[i][1];
           a[data[i][0]][data[i][1]]=1;
             i++;
        }
    Ffile.close();
    for (i=s;i<=n;i++)
	if (color[i] == 0) {timing=1; dfs(i); }
	for (i=1; i<=n;i++)
        cout<<"   time "<<i<<" = " <<tout[i];
    return 0;
}
