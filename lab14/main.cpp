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
	int from;
	int to;

};
const int VMax=100;
vector <vertex> graph;
int table[VMax][VMax];
int colour[VMax];
int n,m;

int input(){

    vertex temp;

    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            table[i][j]=0;
        }
    }

    fstream Ffile;
    Ffile.open("graph3.txt", ios::in);
    Ffile >> n >> m;

    while(!Ffile.eof()){
            Ffile >> temp.from;
            Ffile >> temp.to;
            table[temp.from-1][temp.to-1]=1;
            table[temp.to-1][temp.from-1]=1;
            graph.push_back(temp);
            }

    Ffile.close();
}

void paint(){
    int color=1;
    int colour[VMax];
    for (int i=0;i<n;i++){
        colour[i]=0;
    }
   colour[0]=color;

   int dop=1;
   int start=0;
   while (dop!=n){

    for (int j=0;j<n;j++){
        if ((colour[j]==0)&&(table[start][j]==0)&&(start!=j)){
           bool flag=true;
           for (int i=0;i<n;i++){
            if ((table[j][i]==1)&&(colour[i]==color)){
               flag=false;
            }
           }
           if (flag){
                dop++;
                colour[j]=color;
           }

        }
    }
     color++;
    for (int i=0;i<n;i++){

        if (colour[i]==0){
            start=i;
            colour[start]=color;
            dop++;
            break;
        }
    }

   }

   for (int i=0;i<n;i++){
        cout<<"colour "<<i+1<<" = "<<colour[i]<<endl;
   }

}


int main()
{
    input();
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    paint();

    return 0;
}
