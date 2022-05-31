// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour. 
bool ispossible(int node,int k,int n,int m,vector<int>&col,bool graph[101][101])
{
    // if(node==n)
    // return 1;
   for(int i=0;i<n;i++)
   { 
      if(i!=node && graph[i][node]==1 && col[i]== k)
      return 0;
   }
   return 1;
}
bool solve(int node,bool graph[101][101],int n,int m, vector<int>&col)
{
    if(node==n) return true;
    for(int i=1;i<=m;i++)
    {  
       if(ispossible(node,i,n,m,col,graph)){
        col[node]=i;
        if(solve(node+1,graph,n,m,col))
                  return 1;
        col[node]=0;
       }
    }
    return 0;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here  
    vector<int>col(n,0);
        if(solve(0,graph,n,m,col))
            return 1;
    return 0;
} 

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends