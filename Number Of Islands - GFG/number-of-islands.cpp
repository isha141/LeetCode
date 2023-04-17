//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++ 

class disjoint{
    public:
    vector<int>parent;
    vector<int>rank;
    disjoint(int n){
         parent.resize(n);
         for(int i=0;i<n;++i){
             parent[i]=i;
         }
         rank.resize(n,0);
    }
    void unionbyrank(int u,int v){
        u=findparent(u);
        v=findparent(v);
        if(rank[u]<rank[v]){
            parent[u]=v;
            rank[v]++;
        }
        else if(rank[u]>rank[v]){
            parent[v]=u;
            rank[u]++;
        }
        else{
            parent[u]=v;
            rank[v]++;
        }
    }
    int findparent(int u){
        if(u==parent[u])
          return u;
          return parent[u]=findparent(parent[u]);
    }
};
class Solution { 
    private:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &ope) {
         disjoint ds(n*m);
         vector<int>ans;
         int count=0;
         vector<vector<int>>vis(n,vector<int>(m,0));
         for(auto itr: ope){
             int u=itr[0];
             int v=itr[1];
             if(!vis[u][v]){
                   vis[u][v]=1;
                   count+=1;
                   for(int k=0;k<4;++k){
                       int ni=dx[k]+u;
                       int nj=dy[k]+v;
                       if(ni>=0 && ni<n && nj>=0 && nj<m && vis[ni][nj]){
                           int node=ni*m+nj; 
                           int root=u*m+v;
                           int par1=ds.findparent(node); 
                           int par2=ds.findparent(root);
                           if(par1!=par2){
                               count-=1;
                               ds.unionbyrank(par1,par2);
                           }
                       }
                   }
                   ans.push_back(count);
             }
             else{
                 ans.push_back(count);
             }
         }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends