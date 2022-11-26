class Solution { 
    private: 
    int n;
    int solve(int i,vector<int>&arr,vector<int>&dp,vector<int>&vis){
        if(i<0 || i>=n || vis[i]) return 0; 
        // cout<<i<<" ..";
        if(dp[i]!=-1) return dp[i];
        if(arr[i]==0)
            return 1;
        bool take=0;
        bool not_take=0; 
        vis[i]=1;
        take=solve(i-arr[i],arr,dp,vis);
        vis[i]=0;
        not_take=solve(i+arr[i],arr,dp,vis);
        return dp[i]=(take || not_take);
    }
public:
    bool canReach(vector<int>& arr, int start) {
         n=arr.size(); 
        vector<int>dp(n+1,-1); 
        vector<int>vis(n+1,0);
        return solve(start,arr,dp,vis);
    }
};