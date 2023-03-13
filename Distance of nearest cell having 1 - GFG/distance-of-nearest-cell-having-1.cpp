//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{ 
    private:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>>ans(n,vector<int>(m,0)); 
	    vector<vector<int>>vis(n,vector<int>(m,0));
	    queue<pair<int,pair<int,int>>>q;
	    for(int i=0;i<n;++i){
	        for(int j=0;j<m;++j){
	            if(grid[i][j]==1){
	                q.push({0,{i,j}});
	                vis[i][j]=1;
	            }
	        }
	    }
	    while(!q.empty()){
	        auto itr=q.front();
	        q.pop(); 
	        int dis=itr.first;
	        int x=itr.second.first;
	        int y=itr.second.second;
	        ans[x][y]=dis;
	        for(int k=0;k<4;++k){
	            int nx=x+dx[k];
	            int ny=y+dy[k];
	            if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny]){
	                q.push({dis+1,{nx,ny}});
	                vis[nx][ny]=1;
	            }
	        }
	    }
	    return ans;
	    
	}
};

//{ Driver Code Starts.
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends