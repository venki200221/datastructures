#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

#define Max 1000000000



int V;


int main(){



cout<<"enter the number of vertices:"<<endl;
cin>>V;
int G[V][V];
 for(int i=0;i<V;i++){
    cout<<"Enter the"<<i<<"th row:"<<endl;
    for(int j=0;j<V;j++){
    cin>>G[i][j];
    }
}
    int no_edge;
    int selected[V];
    memset(selected,false,sizeof(selected));
     vector <int> v;
    no_edge=0;

    selected[0]=true;

    int m,n;

    cout<<"Edge:Weight"<<endl;
    while(no_edge<V-1){
        int min=Max;
        m=0;n=0;
        for(int i=0;i<V;i++){
             if(selected[i]){
                for(int j=0;j<V;j++){
                    if(!selected[j] && G[i][j]){
                        if(min>G[i][j]){
                            min=G[i][j];
                            m=i;
                            n=j;
                           
                        }
                    }
                }
             }
        }
     cout << m << " - " << n << " :  " << G[m][n];
    cout << endl;
    selected[n] = true;
     v.push_back(min);
    no_edge++;
    }
    int final_cost=0;
    for(int i=0;i<v.size();i++){
        final_cost=final_cost+v[i];
    }
    cout<<final_cost<<endl;
}