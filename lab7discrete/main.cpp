#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int data[100][3],table[100][100],dist[100],n,m,num,num_help,minimal,route[100],route_num,stak[100],k=0;;
bool colour[100];
char agree;
void readfile(){

int i=0;

fstream Ffile;
    Ffile.open("graf2.txt", ios::in);
    Ffile >> n;
    Ffile >> m;

        while(!Ffile.eof()){
            Ffile >> data[i][0];
            Ffile >> data[i][1];
            Ffile >> data[i][2];
           table[data[i][0]-1][data[i][1]-1]=data[i][2];
           i++;
        }
    Ffile.close();

}

int main()
{
    readfile();

    for  (int i=0; i<m; i++){
        if (data[i][2]<0) {cout<<"Graf has negative edge";
        return 0 ;
        }
    }

    for (int i=0;i<n;i++){
        colour[i]=true;
    }

    cout<<"Enter vertex"<<endl;
    cin>>num_help;
    cout<<endl;
    cout<<"do you want to find the route[y/n]"<<endl;
    cin>>agree;
    cout<<endl;
    if (agree=='y') {
        cout<<"enter the vertix"<<endl;
        cin>>route_num;
    }

    for (int i=0; i<n; i++){
        dist[i]=1000;
    }
    dist[num_help-1]=0;
    num=num_help-1;
    route[num]=num_help;
    minimal=dist[num];
    for (int h=0;h<n;h++){
    for (int i=0;i<n;i++){
    if ((dist[i]<minimal)&&colour[i]) {
        num=i;
        minimal=dist[num];

    }
    }
    for (int j=0;j<n;j++){
         if (colour[num]&&(dist[j]>(table[num][j]+dist[num]))&&table[num][j]!=0){
                dist[j]=table[num][j]+dist[num];
                route[j+1]=num+1;
    }

    }
    colour[num]=false;
    minimal=1001;

    }

  /*  for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){

            if ((dist[j]>(table[num-1][j]+dist[num-1]))&&table[num-1][j]!=0){
                dist[j]=table[num-1][j]+dist[num-1];
                stak[k++]=j
            }

            }
            num++;
            if (num==n+1){
            num=1;
            }



    }*/




    for (int i=0;i<n;i++){
            if (dist[i]==1000){
                cout<<"vertex "<<i+1<<" is unreachble from vertex "<<num_help<<endl;

                continue;
            }
        cout<<"to vertex "<<i+1<<" distance is "<<dist[i]<<endl;
    }



      if (agree=='y'){
            if(dist[route_num-1]!=1000){
            stak[0]=route_num;
            int fixed=route_num,i=1;
        do {
            stak[i]=route[fixed];
            fixed=route[fixed];
            i++;
        } while (route[fixed]!=num_help);
        stak[i]=num_help;
        cout<<"route to vertex "<<route_num<<" : ";
         for (int j=i;j>=0;j--){
        cout<<stak[j];
    }
      }
      else {
        cout<<"vertex "<<route_num<<" is unreachble"<<endl;
      }
    }

/*
for (int i=1;i<=n;i++){
    cout<<route[i];
}
*/

    return 0;
}
