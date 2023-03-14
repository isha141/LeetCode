//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution { 
    private:
    int n,m; 
    set<vector<pair<int,int>>>s; 
    vector<vector<int>>vis; 
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    void solve(int i,int j,int r1,int r2,vector<vector<int>>&grid,vector<pair<int,int>>&ds){
          
          vis[i][j]=1;
          ds.push_back({i-r1,j-r2});
          for(int k=0;k<4;++k){
              int ni=i+dx[k];
              int nj=j+dy[k];
              if(ni>=0 && ni<n && nj>=0 && nj<m && !vis[ni][nj] && grid[ni][nj]==1){
                    solve(ni,nj,r1,r2,grid,ds);
              }
          }
    }
  public: 
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here 
        n=grid.size();
        m=grid[0].size();
        vis.resize(n,vector<int>(m,0));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==1 && vis[i][j]==0){ 
                   vector<pair<int,int>>ds;
                    solve(i,j,i,j,grid,ds); 
                    s.insert(ds);
                }
            }
        }
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends