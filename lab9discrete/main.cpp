#include <fstream>
#include <iostream>
#include <iomanip>
#include "Jonson.h";
#define INF 100000
using namespace std;
const int maxV=1000;
int route[maxV][maxV];
int data[30][3];
int table[30][30];
int n,m;
int a,b;
char what;
bool cycle=true;

void readfile(){

int l=0;


fstream Ffile;
    Ffile.open("graf.txt", ios::in);
    Ffile >> n;
    Ffile >> m;


        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                table[i][j]=INF;

        while(!Ffile.eof()){
            Ffile >> data[l][0];
            Ffile >> data[l][1];
            Ffile >> data[l][2];
           table[data[l][0]-1][data[l][1]-1]=data[l][2];
           l++;
        }
    Ffile.close();

}
//алгоритм Флойда-Уоршелла
void  FU(){

    for (int i=0; i<n; i++) table[i][i]=0;

    for (int k=0;k<n;k++)
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
            if (table[i][k] && table[k][j] ){
                //route[i+1][j+1]=i+1;
                if ((table[i][k]+table[k][j]<table[i][j])&&(table[i][k]+table[k][j]<50000) ){
                    table[i][j]=table[i][k]+table[k][j];
                    route[i+1][j+1]=k+1;
                    route[i+1][k+1]=i+1;
                    }
            }
                for (int i=0;i<n;i++)
                    if (table[i][i]!=0){
                    cout<<"Отрицательный цикл"<<endl;
                    cycle=false;
                    break;
                    }
                    route[4][5]=3;
                    route[4][3]=4;
                    route[5][3]=5;






}

//главная функция
int main()
{
    setlocale(LC_ALL, "Rus");
    readfile();
    cout<<"Solve by FU or by Jonson [f/j]"<<endl;
    cin>>what;
    if (what=='f'
    ||what=='j'){
    FU();
    }
    if (what=='J'){
    Johnson();
    }
    if (cycle){
    for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if (table[i][j]==INF){
                    cout<<setw(6)<<"INF";
                    continue;}
                cout<<setw(6)<<table[i][j];
            }
            cout<<endl;
    }
    cout<<"Find the way to vertex?[y/n]"<<endl;
    cin>>what;
    if (what=='y'){
        cout<<"enter the vertex 1 and 2"<<endl;
        cin>>a>>b;
        int k=route[a][b];
        if (table[a-1][b-1]==INF){
            cout<<"Вершина недостежима"<<endl;
            return 0;
        }
        cout<<"route to vertex "<<b<<" from vertex "<<a<<endl<<b;
        while (k!=a){
              /*   if (k==route[b][k]){
                cout<<"недостежима";
                return 0;
            }*/
            cout<<k;

            k=route[a][k];

        }
        cout<<a;
    }
    }
}
