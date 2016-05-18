#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void output(int);
void topological_sort();
void dfs(int);
void research(int);

    int data[100][2];
    int m,n,v=0,sort_i=0;;
    int link[100][100];
    int color_dfs[100];
    int pointer=0;
    int color[100];
    int stack_graf[100];
    int sort_graf[100];
    int counter=1;
int main()
{


    fstream Ffile;
    char x;
    int count_v = 0;
    int i = 0;
    int size_d = 0;

    n = 0;
    m = 0;

    Ffile.open("graf.txt", ios::in);

    Ffile >> n;
    Ffile >> m;

        while(!Ffile.eof()){
            Ffile >> data[i][0];
            Ffile >> data[i][1];
            i++;size_d++;
        }
    Ffile.close();


output(m);

/*for (int i=0;i<n;i++)
    link[data[i][0]][data[i][1]]=1;

cout<<endl<<"Поиск в глубину:"<<endl<<endl;
for (i=1;i<=n;i++)
	if (color[i] == 0) dfs(i);*/

topological_sort();

    return 0;
}

void output(int m){
for (int i=0;i<m;i++){
    for (int j=0;j<2;j++)
    cout<<data[i][j]<<" ";
    cout<<endl;
}

}

void topological_sort(){

stack_graf[0]=data[0][0];
counter=1;
while (counter>=1){
    v=stack_graf[counter-1];
    research(v);
}

for (int i=sort_i-1;i>=0;i--)
    cout<<"->"<<sort_graf[i];

}

void research(int v){
bool found=false;
for(int i = 0; i < m; i++){
if((data[i][0] == v) && (color[data[i][1]]!=2)){
found = true;
stack_graf[counter] =data[i][1];
counter++;
break;
}
}
if(found == false){
color[v] = 2;
sort_graf[sort_i] = v;
sort_i++;
int l=0;
while (stack_graf[l]!=0){
   l++;
}
stack_graf[l]=0;
counter--;
}

}

void dfs(int v) {
int i;
pointer++;

if (color_dfs[v] == 2) {return;} else {
	color_dfs[v] = 1;

	//Выводим содержимое стека:
	cout<<"Вершина: "<<v<<", DFS номер: "<<pointer<<", Содержимое стека:  ";
	for (i=1;i<=n;i++)
			if (color_dfs[i] == 1)
					cout<<i<<" ";
	cout<<""<<endl;

	for (i=1;i<=n;i++) if((link[v][i]==1)&&(color_dfs[i]==0)) dfs(i);

color_dfs[v] = 2;

	}
}
