class Solution { 
    private: 
    int n;
    int solve(bool flag,int i,int j,vector<int>&piles,vector<vector<int>>&dp){
        if(i>=n || j<0)
            return 0;  
        if(dp[i][j]!=-1)
            return dp[i][j];
        int take=INT_MIN;
        int not_take=INT_MIN;
        if(flag==0){
            take=max(piles[i]+solve(!flag,i+1,j,piles,dp),piles[j]+solve(!flag,i,j-1,piles,dp));
        }
        else
            not_take=min(-piles[j]+solve(!flag,i,j-1,piles,dp),piles[i]+solve(!flag,i+1,j,piles,dp));
        return dp[i][j]=max(take,not_take);
        
    }
public:
    bool stoneGame(vector<int>& piles) {
         n=piles.size(); 
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,0,n-1,piles,dp)>0; 
    }
};