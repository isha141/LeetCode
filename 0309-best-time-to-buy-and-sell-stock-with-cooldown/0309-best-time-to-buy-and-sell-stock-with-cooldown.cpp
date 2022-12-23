int dp[5003][3];
class Solution { 
    private:
    int solve(int i,int buy,vector<int>&p,int n){
        if(i>=n)
            return 0;
        int take=0;
        int not_take=0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy==0)
        take=max(-p[i]+solve(i+1,1,p,n),solve(i+1,0,p,n));
        else
        not_take=max(p[i]+solve(i+2,0,p,n),solve(i+1,1,p,n));
        return dp[i][buy]=max(take,not_take);
    }
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,p,n);
    }
};