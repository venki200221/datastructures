#include<iostream>

#define I 32767;

using namespace std;

int cost [8][8] {
            {32762, 32762,32762 , 32762, 32762,32762, 32762, 32762},
            {32762, 32762, 25, 32762, 32762, 32762, 5, 32762},
            {32762, 25, 32762, 12, 32762, 32762, 32762, 10},
            {32762, 32762, 12, 32762, 8, 32762, 32762, 32762},
            {32762, 32762, 32762, 8, 32762, 16, 32762, 14},
            {32762, 32762, 32762, 32762, 16, 32762, 20, 18},
            {32762, 5, 32762, 32762, 32762, 20, 32762, 32762},
            {32762, 32762, 10, 32762, 14, 18, 32762, 32762},
    };

int near[8];

int t[2][6];

int main(){
    int mini=I;
    int u,v,k;
    for(int i=1;i<8;i++){
        near[i]=32762;
        for(int j=i;j<8;j++){
           if(cost[i][j]<mini){
            mini=cost[i][j];
             u=i;
             v=j;
           }
        }
    }
    t[0][0]=u;
    t[1][0]=v;
    near[u]=0;
    near[v]=0;

    for(int i=1;i<8;i++){
        if(near[i]!=0){
            if(cost[i][u]<cost[i][v]){
                near[i]=u;
            }
            else{
                near[i]=v;
            }
        }
    }

    for(int i=1;i<7;i++){
        mini=32762;
        for(int j=1;j<8;j++){
            if(near[j]!=0 && cost[j][near[j]]<mini){
                     mini=cost[j][near[j]];
                     k=j;
            }

        }
    t[0][i]=k;
    t[1][i]=near[k];
    near[k]=0;


    for(int j=1;j<8;j++){
        if(near[j]!=0 && cost[j][k]<cost[j][near[j]]){
            near[j]=k;
        }
    }
    }

   int sum {0};
    for (int i {0}; i<8-2; i++){
        int c = cost[t[0][i]][t[1][i]];
        cout << "[" << t[0][i] << "]---[" << t[1][i] << "] cost: " << c << endl;
        sum += c;
    }
    cout << endl;
    cout << "Total cost of MST: " << sum << endl;
   

}
// #include <iostream>
// #define V 8
// #define I 32767

// using namespace std;
 
// void PrintMST(int T[][V-2], int G[V][V]){
//     cout << "\nMinimum Spanning Tree Edges (w/ cost)\n" << endl;
//     int sum {0};
//     for (int i {0}; i<V-2; i++){
//         int c = G[T[0][i]][T[1][i]];
//         cout << "[" << T[0][i] << "]---[" << T[1][i] << "] cost: " << c << endl;
//         sum += c;
//     }
//     cout << endl;
//     cout << "Total cost of MST: " << sum << endl;
// }
 
// void PrimsMST(int G[V][V], int n){
//     int u;
//     int v;
//     int min {I};
//     int track [V];
//     int T[2][V-2] {0};
 
//     // Initial: Find min cost edge
//     for (int i {1}; i<V; i++){
//         track[i] = I;  // Initialize track array with INFINITY
//         for (int j {i}; j<V; j++){
//             if (G[i][j] < min){
//                 min = G[i][j];
//                 u = i;
//                 v = j;
//             }
//         }
//     }
//     T[0][0] = u;
//     T[1][0] = v;
//     track[u] = track[v] = 0;
 
//     // Initialize track array to track min cost edges
//     for (int i {1}; i<V; i++){
//         if (track[i] != 0){
//             if (G[i][u] < G[i][v]){
//                 track[i] = u;
//             } else {
//                 track[i] = v;
//             }
//         }
//     }
 
//     // Repeat
//     for (int i {1}; i<n-1; i++){
//         int k;
//         min = I;
//         for (int j {1}; j<V; j++){
//             if (track[j] != 0 && G[j][track[j]] < min){
//                 k = j;
//                 min = G[j][track[j]];
//             }
//         }
//         T[0][i] = k;
//         T[1][i] = track[k];
//         track[k] = 0;
 
//         // Update track array to track min cost edges
//         for (int j {1}; j<V; j++){
//             if (track[j] != 0 && G[j][k] < G[j][track[j]]){
//                 track[j] = k;
//             }
//         }
//     }
//     PrintMST(T, G);
// }
 
// int main() {
 
//     int cost [V][V] {
//             {I, I, I, I, I, I, I, I},
//             {I, I, 25, I, I, I, 5, I},
//             {I, 25, I, 12, I, I, I, 10},
//             {I, I, 12, I, 8, I, I, I},
//             {I, I, I, 8, I, 16, I, 14},
//             {I, I, I, I, 16, I, 20, 18},
//             {I, 5, I, I, I, 20, I, I},
//             {I, I, 10, I, 14, 18, I, I},
//     };
 
//     int n = sizeof(cost[0])/sizeof(cost[0][0]) - 1;
 
//     PrimsMST(cost, n);
 
//     return 0;
// }