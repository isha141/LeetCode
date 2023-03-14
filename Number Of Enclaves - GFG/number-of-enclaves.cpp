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
    void solve(int i,int j,vector<vector<int>>&grid){
        grid[i][j]=-1; 
        for(int k=0;k<4;++k){
            int ni=i+dx[k];
            int nj=j+dy[k];
            if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]==1){
                solve(ni,nj,grid);
            }
        }
    }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here 
        n=grid.size();
        m=grid[0].size();
        for(int i=0;i<m;++i){
            if(grid[0][i]==1){
                // cout<<0<<",. "<<i<<endl;
                solve(0,i,grid);
            }
            if(grid[n-1][i]==1){ 
                // cout<<n-1<<"-- "<<i<<endl;
                solve(n-1,i,grid);
            }
        } 
        for(int i=0;i<n;++i){
            if(grid[i][0]==1){ 
                // cout<<i<<" **"<<0<<endl;
                solve(i,0,grid);
            }
            if(grid[i][m-1]==1){ 
                // cout<<i<<"&&"<<m-1<<endl;
                solve(i,m-1,grid);
            }
        } 
        int ans=0; 
        // cout<<"*********"<<endl;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==1)
                ans++; 
                // cout<<grid[i][j]<<" ";
            }
            // cout<<endl;
        }
        return ans;
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends