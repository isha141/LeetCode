//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class disjoint{
    public:
    vector<int>parent;
    vector<int>rank;
    disjoint(int n){
        parent.resize(n+1,0);
        rank.resize(n+1,0); 
        for(int i=0;i<n;++i){
            parent[i]=i;
        }
    }
    int findparent(int n){
        if(n==parent[n])
         return n;
         return parent[n]=findparent(parent[n]);
    }
    void unionbyrank(int u,int v){
        u=findparent(u);
        v=findparent(v);
        if(u==v)
         return;
        if(rank[u]<rank[v]){
            parent[u]=v;
            rank[v]++;
        }
        else{
            parent[v]=u;
            rank[u]++;
        }
    }
};
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edges) {
        // code here 
         int m=edges.size();
          if(m<(n-1)){
               return -1;
          }
          int count=0; 
          disjoint ds(n);
          for(auto itr: edges){
               ds.unionbyrank(itr[0],itr[1]);
          }
          for(int i=0;i<n;++i){
              if(ds.findparent(i)==i)
               count+=1;
          }
         return count-1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends