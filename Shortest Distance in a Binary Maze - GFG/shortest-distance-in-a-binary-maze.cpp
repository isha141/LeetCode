//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution { 
    private:
    int dx[4]={-1,0,0,1};
    int dy[4]={0,1,-1,0};
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> s,
                     pair<int, int> d) {
        // code here 
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{s.first,s.second}}); 
        grid[s.first][s.second]=0;
        while(!q.empty()){
            int t=q.size();
            while(t--){
                auto itr=q.front();
                q.pop();
                int x=itr.second.first;
                int y=itr.second.second;
                int val=itr.first;
                if(x==d.first && y==d.second){
                    return val;
                }
                for(int k=0;k<4;++k){
                    int nx=dx[k]+x;
                    int ny=dy[k]+y;
                    if(nx>=0 && ny>=0  && nx<n && ny<m && grid[nx][ny]==1){
                        q.push({val+1,{nx,ny}});
                         grid[nx][ny]=0;
                    }
                }
            }
        }
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends