// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution { 
    private:
    void solve(int i,int j,vector<vector<char>>& grid)
    {
        if(i<0|| i==grid.size() || j<0 || j==grid[0].size()|| grid[i][j]=='0')
        return ;
        grid[i][j]='0';
        solve(i+1,j,grid);
        solve(i-1,j,grid);
        solve(i,j+1,grid);
        solve(i,j-1,grid);
        solve(i-1,j-1,grid);
        solve(i-1,j+1,grid);
        solve(i+1,j-1,grid);
        solve(i+1,j+1,grid);
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int count=0; 
        int n=grid.size();
        int m=grid[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='1')
            {
                solve(i,j,grid);
                count++;
            }
        }
    }
    return count;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends