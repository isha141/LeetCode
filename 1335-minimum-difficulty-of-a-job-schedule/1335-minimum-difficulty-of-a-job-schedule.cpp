class Solution { 
    private: 
    int n;
    int solve(int i,vector<int>&j,int d,vector<vector<int>>&dp)
    { 
        if(d==0 && i>=n)
            return 0;
        if(i>=n)
            return 1e9; 
        if(d==0)
            return 1e9;
        if(dp[i][d]!=-1)
            return dp[i][d];
        int maxi=0;
        int ans=1e9;
        for(int k=i;k<n;++k){
            maxi=max(maxi,j[k]);
            int temp=maxi+solve(k+1,j,d-1,dp);
            ans=min(ans,temp);
        }
        return dp[i][d]=ans;
    }
public:
    
    int minDifficulty(vector<int>& j, int d) {
        n=j.size(); 
        if(d>n)
            return -1;
        int maxi=0;
        vector<vector<int>>dp(n,vector<int>(d+1,-1));
        return solve(0,j,d,dp);
    }
};