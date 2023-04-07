//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution { 
    private:
    int dx[8]={2,2,-2,1,-1,1,-1,-2};
    int dy[8]={-1,1,-1,2,-2,-2,2,1};
public:
	int minStepToReachTarget(vector<int>&k, vector<int>&ta, int n){
	    // Code here 
	    vector<vector<int>>vis(n+2,vector<int>(n+2,0));
	    queue<pair<int,int>>q;
	    q.push({k[0],k[1]});
	    int c=0;
	    while(!q.empty()){
	        int t=q.size();
	        while(t--){
	            auto itr=q.front();
	            q.pop();
	            int x=itr.first; 
	            int y=itr.second;
	            vis[x][y]=1;
	            if(x==ta[0] && y==ta[1]){
	                return c;
	            }
	            for(int k=0;k<8;++k){
	                int nx=dx[k]+x;
	                int ny=dy[k]+y;
	                if(nx>=0 && nx<=n && ny>=0 && ny<=n && vis[nx][ny]==0){
	                    vis[nx][ny]=1;
	                    q.push({nx,ny});
	                }
	            }
	        }
	        c++;
	    }
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends