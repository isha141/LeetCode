// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{ 
    private:
    int ways(queue<pair<int,int>>q, vector<vector<int>>&grid)
    { 
    int c=0; 
    int m=grid.size();
    int n=grid[0].size();
        while(!q.empty())
        {
            auto itr=q.front();
            q.pop();
            int x=itr.first;
            int y=itr.second;
            if(x!=-1 && y!=-1){
            if(x-1>=0  && grid[x-1][y]==1){
                grid[x-1][y]=2; 
                q.push({x-1,y});
            }
            if(x+1<m && grid[x+1][y]==1){
            grid[x+1][y]=2;
            q.push({x+1,y});
            }
            if(y-1>=0 && grid[x][y-1]==1){
                grid[x][y-1]=2;
                q.push({x,y-1});
            }
            if(y+1<n && grid[x][y+1]==1){
                grid[x][y+1]=2;
                q.push({x,y+1});
            }
            }
            else if(!q.empty()){
            c++;
            q.push({-1,-1}); 
            }
            else
            return c;
        }
        return c;
    }
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<pair<int,int>>q;
        int count=0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[i].size();++j){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        q.push({-1,-1});
        count=ways(q,grid); 
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[i].size();++j){
                if(grid[i][j]==1)
                return -1;
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends