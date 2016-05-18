#include <iostream>
#include <fstream>
#define inf 100000
using namespace std;
struct Edges{
int u, v, w;
};
const int Vmax=1000;
const int Emax=Vmax*(Vmax-1)/2;
int i, j, n,m, e, start;
Edges edge[Emax];
int d[Vmax];
char y;
int route[100],route_num,stak[100];
//алгоритм Беллмана-Форда
void bellman_ford(int n, int s)
{
    int i, j;

    bool x=true;
for (i=0; i<n; i++)
{
if (i!=n-1)
for (j=0; j<e; j++)
if (d[edge[j].v]+edge[j].w<d[edge[j].u]){
d[edge[j].u]=d[edge[j].v]+edge[j].w;
route[edge[j].u+1]=edge[j].v+1;
}
if (i==n-1)
for (j=0; j<e; j++)
if (d[edge[j].v]+edge[j].w<d[edge[j].u]) x=false;
}
if (!x) cout<<endl<<"Граф содержит отриц. циклы"<<endl;




for (i=0; i<n; i++) d[i]=inf;
d[s]=0;

for (i=0; i<n-1; i++)
for (j=0; j<e; j++)
if (d[edge[j].v]+edge[j].w<d[edge[j].u]){
d[edge[j].u]=d[edge[j].v]+edge[j].w;
route[edge[j].u+1]=edge[j].v+1;
}
if (x){
for (i=0; i<n; i++) if (d[i]==inf)
cout<<endl<<start<<"->"<<i+1<<"="<<"Not";
else cout<<endl<<start<<"->"<<i+1<<"="<<d[i];
}
}

void readfile(){

int l=0;


fstream Ffile;
    Ffile.open("graf.txt", ios::in);
    Ffile >> n;
    Ffile >> m;
/*e=0;

        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++){
                edge[e].w=inf;
                e++;
            }*/
e=0;
        while(!Ffile.eof()){
            Ffile >> edge[e].v;
            edge[e].v--;
            Ffile >> edge[e].u;
            edge[e].u--;
            Ffile >> edge[e].w;
            e++;

        }
        e--;
    Ffile.close();

}
//главная функция
int main()
{
setlocale(LC_ALL, "Rus");
/*int w;
cout<<"Количество вершин > "; cin>>n;
e=0;
for (i=0; i<n; i++)
for (j=0; j<n; j++)
{
cout<<"Вес "<<i+1<<"->"<<j+1<<" > "; cin>>w;
if (w!=0)
{
edge[e].v=i;
edge[e].u=j;
edge[e].w=w;
e++;
}
}*/
readfile();

cout<<"Стартовая вершина > "; cin>>start;
cout<<"Список кратчайших путей:";
bellman_ford(n, start-1);

cout<<endl<<"find the route?[y/n]"<<endl;
cin>>y;
if (y=='y'){
cin>>route_num;

if (route[route_num]!=0){

            stak[0]=route_num;
            int fixed=route_num,i=1;
        do {
            stak[i]=route[fixed];
            fixed=route[fixed];
            i++;
        } while (route[fixed]!=start);
        stak[i]=start;
        cout<<"route to vertex "<<route_num<<" : ";
         for (int j=i;j>=0;j--){
        cout<<stak[j];
    }
}
      else {

        cout<<"vertex "<<route_num<<" is unreachble"<<endl;
      }
}
return 0;
}
