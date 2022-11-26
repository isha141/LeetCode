class Solution { 
    private: 
    int n;
    int solve(int i,vector<int>&arr,vector<int>&dp){
        if(i<0 || i>=n || arr[i]<0) return 0; 
        if(dp[i]!=-1) return dp[i];
        if(arr[i]==0)
            return 1;
        bool take=0;
        bool not_take=0; 
        arr[i]=-1*arr[i];
        take=solve(i-abs(arr[i]),arr,dp);
         arr[i]=-1*arr[i];
        not_take=solve(i+abs(arr[i]),arr,dp);
        return dp[i]=(take || not_take);
    }
public:
    bool canReach(vector<int>& arr, int start) {
         n=arr.size(); 
        vector<int>dp(n+1,-1); 
        return solve(start,arr,dp);
    }
};