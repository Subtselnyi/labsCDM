#include <iostream>
#include <fstream>
#define INF 1000000

using namespace std;
const int VMax = 100;
int data[VMax][VMax];
int table[VMax][VMax];
int n,m;
int exit_v,enter_v;


void readfile(){

int l=0;
fstream Ffile;
    Ffile.open("graf1.txt", ios::in);
    Ffile >> n;
    Ffile >> m;


        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                table[i][j]=0;

        while(!Ffile.eof()){
            Ffile >> data[l][0];
            Ffile >> data[l][1];
           table[data[l][0]-1][data[l][1]-1]=1;
         //  table[data[l][1]-1][data[l][0]-1]=-1;
           l++;
        }
    Ffile.close();

}
int if_eiler_cycle(){

    for (int i =0; i<n;i++){
        int s=0;
        for (int j = 0; j<n; j++){
                s+=table[i][j]-table[j][i];
        }
        if (s!=0){ cout<<"NO cycle"<<endl;return 0;}
    }
    cout<<"cycle yes"<<endl;
    return 1;
}
int eiler_cycle(){
        int start = data[0][0]-1;
        cout<<start+1;
                for (int i=0;i<m;i++){
                        bool repeat=true;
                        bool repeat1=true;
                for (int j=0;j<n;j++){
                    if (table[start][j]==1){
                    if (repeat){
                        cout<<j+1;
                        table[start][j]=INF;
                        //table[j][start]=INF;
                        start=j;
                        break;
                    }
                    if (repeat1){
                        repeat =true;
                    }
                    }

                }
        }
}

int if_eiler_path(){
    bool enter=true;
    bool exit = true;

     for (int i =0; i<n;i++){
        int s=0;
        for (int j = 0; j<n; j++){
                s+=table[i][j]-table[j][i];
        }
        if (s!=0){
            if (s==-1){
                    if(!exit){cout<<"No path"<<endl; return 0;}
                exit=false;
                exit_v=i;
                    }
            if (s==1){
                    if (!enter) {return 0;}
                enter=false;
                enter_v=i;
            }
        }
    }
    if (!exit&&!enter) cout<<"path yes"<<endl;
    return 1;
}

int eiler_path(){
      cout<<enter_v+1;
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            if (table[enter_v][j]==1){
                        cout<<j+1;
                        table[enter_v][j]=INF;
                        //table[j][start]=INF;
                        enter_v=j;
                        break;
                    }
        }
    }
    return 0;
}

int main()
{
    readfile();
        if (if_eiler_cycle()) {
        eiler_cycle();
    } else if (if_eiler_path()){
        eiler_path();
    }
    else cout<<"NOT EILER";
    return 0;
}
