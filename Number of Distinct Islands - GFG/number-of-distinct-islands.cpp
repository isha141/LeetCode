//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    int n,m;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    void solve(int x,int y,int r,int c,vector<pair<int,int>>&ds,vector<vector<int>>&grid){
        grid[x][y]=0;
         ds.push_back({x-r,y-c});
       for(int k=0;k<4;++k){
           int nx=dx[k]+x;
           int ny=dy[k]+y;
           if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1){
               solve(nx,ny,r,c,ds,grid);
           }
       }
       return ;
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        set<vector<pair<int,int>>>s;
         n=grid.size();
         m=grid[0].size();
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==1){
                    vector<pair<int,int>>ds;
                    solve(i,j,i,j,ds,grid);
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