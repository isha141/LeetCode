int dp[72][5000];
class Solution { 
    int m;
    int n; 
    private:
    int solve(int i,int sum,vector<vector<int>>& mat, int target)
    {
        if(i==m)
            return abs(sum-target);
         if(dp[i][sum]!=-1)
             return dp[i][sum];
        int mini=INT_MAX;
        for(int k=0;k<n;++k){
            mini=min(mini,solve(i+1,sum+mat[i][k],mat,target));
        }
        return dp[i][sum]=mini;
    }
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        m=mat.size();
        n=mat[0].size(); 
        memset(dp,-1,sizeof(dp));
        return solve(0,0,mat,target);
    }
};