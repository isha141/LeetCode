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
     public:
     disjoint(int n){
         parent.resize(n+1);
         for(int i=0;i<=n;++i){
             parent[i]=i;
         }
         rank.resize(n+1,1);
     }
     void unionbyrank(int u,int v){
         u=findparent(u);
         v=findparent(v);
         if(u==v) return ;
         if(rank[u]<rank[v]){
             parent[u]=v;
             rank[v]+=rank[u];
         }
        //  else if(rank[v]<rank[u]){
        //      parent[v]=u;
        //      rank[u]+=rank[v];
        //  }
         else{
             parent[v]=u;
             rank[u]+=rank[v];
         }
     }
     int findparent(int u){
         if(parent[u]==u)
          return u;
          return parent[u]=findparent(parent[u]);
     }
};
class Solution { 
    private:
    int n,m; 
     int ans=0; 
     int dx[4]={-1,0,0,1};
     int dy[4]={0,1,-1,0}; 
     bool isvalid(int i,int j){
         return i>=0 && i<n && j>=0 && j<m;
     }
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        // code here 
        n=grid.size();
        m=grid[0].size();  
        disjoint ds(n*m); 
        
        for(int i=0;i<n;++i){
             for(int j=0;j<m;++j){ 
                if(grid[i][j]==1){
                    for(int k=0;k<4;++k){
                     int nx=dx[k]+i;
                     int ny=dy[k]+j;
                     if(isvalid(nx,ny) && grid[nx][ny]==1){ 
                         int nodeval=i*m+j;
                         int adjval=nx*m+ny;
                         ds.unionbyrank(nodeval,adjval); 
                     }
                 }
            }
        }
    }  
      for(int i=0;i<n;++i){
          for(int j=0;j<m;++j){
              if(grid[i][j]==0){ 
                   int count=1; 
                   set<int>s;
                for(int k=0;k<4;++k){
                     int nx=dx[k]+i;
                     int ny=dy[k]+j;
                     if(isvalid(nx,ny) && grid[nx][ny]==1){ 
                         int nodeval=i*m+j;
                         int adjval=nx*m+ny;
                         nodeval=ds.findparent(nodeval);
                         adjval=ds.findparent(adjval);
                         if(s.find(adjval)==s.end()){ 
                             s.insert(adjval);
                             count+=ds.rank[adjval];
                         }
                     }  
              }
              ans=max(ans,count);
          }
      }
    } 
      if(ans==0)
        return n*m;
        return ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends