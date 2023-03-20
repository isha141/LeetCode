//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution { 
    private:
    int n,m; 
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
  public: 
    int shortestXYDist(vector<vector<char>> grid, int n, int m) {
        // code here 
        n=grid.size(); 
        m=grid[0].size(); 
        int ans=1e9;
        vector<vector<int>>vis(n,vector<int>(m,1e9)); 
        queue<pair<int,int>>q;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]=='X'){
                    q.push({i,j}); 
                    vis[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            auto itr=q.front();
            q.pop(); 
            int x=itr.first;
            int y=itr.second; 
            if(grid[x][y]=='Y'){
                ans=min(ans,vis[x][y]);
            }
            for(int k=0;k<4;++k){
                int nx=x+dx[k];
                int ny=y+dy[k]; 
                if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]!='X'){ 
                    int d=abs(nx-x)+abs(ny-y)+vis[x][y];
                    if(vis[nx][ny]>d){
                        q.push({nx,ny});
                        vis[nx][ny]=d;
                    }
                }
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
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends