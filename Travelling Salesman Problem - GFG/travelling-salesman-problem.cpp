//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int dp[20][(1<<20)+1];
class Solution {
    private:
    int n;
    bool ok(int mask){
        // for(int i=0;i<n;++i){
        //     if((mask & (1<<i))==0)
        //     return 0;
        // }
        // return 1;
    }
    int solve(int node,int mask,vector<vector<int>>&cost){
        if(mask==((1<<n)-1)){
            return cost[node][0];
        }
        if(dp[node][mask]!=-1)
          return dp[node][mask];
        int ans=INT_MAX;
        for(int j=0;j<n;++j){
            if((mask&(1<<j))==0 && node!=j){
                ans=min(ans,cost[node][j]+solve(j,(mask|(1<<j)),cost));
            }
        }
        return dp[node][mask]=ans;
    }
public:
int total_cost(vector<vector<int>>cost){
    // Code here
     n=cost.size();
    memset(dp,-1,sizeof(dp));
    vector<int>vis(n,0);
    int mask=0;
    return solve(0,1,cost);
} 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends