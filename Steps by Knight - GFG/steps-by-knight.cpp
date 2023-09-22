//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{ 
    int dx[8]={-1,-1,1,1,2,2,-2,-2};
    int dy[8]={2,-2,2,-2,1,-1,1,-1};
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&kpos,vector<int>&tpos,int n)
	{
	    // Code here  
	    queue<pair<int,pair<int,int>>>q;
	    q.push({kpos[0],{kpos[1],0}});
	    vector<vector<int>>dis(n+1,vector<int>(n+1,1e9));
	    dis[kpos[0]][kpos[1]]=0;
	    while(!q.empty()){ 
	        int t=q.size();
	        while(t--){
	        auto itr=q.front();
	        q.pop();
	        int x=itr.first;
	        int y=itr.second.first;
	        int steps=itr.second.second;
	        if(x==tpos[0] && y==tpos[1])
	           return steps;
	        for(int k=0;k<8;++k){
	            int nx=dx[k]+x;
	            int ny=dy[k]+y;
	            if(nx>=0 && ny>=0 && nx<=n && ny<=n && dis[nx][ny]>steps+1){
	                dis[nx][ny]=steps+1;
	                q.push({nx,{ny,steps+1}});
	            }
	        }
	        }
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