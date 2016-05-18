#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <math.h>
#include <algorithm>
#define INF 100000
#define inMST 13243546

using namespace std;


struct vertex
{
	int x;
	int y;

};
const int VMax=100;
vector <vertex> graph;
vector< pair<int,int> > MST ;
int n;

int input(){

    vertex temp;

    fstream Ffile;
    Ffile.open("graph.txt", ios::in);
    Ffile >> n;

    while(!Ffile.eof()){
            Ffile >> temp.x;
            Ffile >> temp.y;

            graph.push_back(temp);
            }

    Ffile.close();
}

void KOMIVOJAZHIER(){



    vector<bool> used (n,false);
    double table[VMax][VMax];

        for (int i=0;i<n;i++){
                for (int j=0;j<n;j++){
                    table[i][j]=pow((pow((graph[i].x-graph[j].x),2)+pow((graph[i].y-graph[j].y),2)),1.0/2);
                }
        }

        for (int i=0;i<n;i++)
                table[i][i]=INF;

        for (int i=0;i<n;i++){
                for (int j=0;j<n;j++){
                        if(table[i][j]==INF){
                            printf("    INF");
                        } else
                       printf("  %5.1f",table[i][j]);
                }
                cout<<endl;
        }

            int i=0;
            used[i]=true;
        for (int l=0;l<n-1;l++){
                double minimum=INF;
                int to;
            for (int j=0;j<n;j++){
                if ((table[i][j]<minimum)&&(!used[j])){
                    minimum=table[i][j];
                    to=j;

                }

            }
             MST.push_back (make_pair (i+1, to+1));
                used[i]=true;
                i=to;
        }
        MST.push_back (make_pair (i+1, 1));

    cout<<setw(15)<<"Гамильтонов цикл"<<endl;
    for (int i=0; i<n; i++){
        cout<<MST[i].first<<" ";
        cout<<MST[i].second<<endl;
    }
}


int main()
{
    input();
    KOMIVOJAZHIER();

    return 0;
}
