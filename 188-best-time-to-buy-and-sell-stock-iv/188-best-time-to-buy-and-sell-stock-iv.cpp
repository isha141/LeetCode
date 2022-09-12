int dp[1002][102][2];
class Solution { 
    private: 
    int ans=-1e9;
    int solve(int i,vector<int>& prices,int k,int n,int flag){
        if(i==n-1 && flag==1)
            return prices[n-1];
        if(i>=n)
            return 0;  
        if(k<=0) return 0; 
        if(dp[i][k][flag]!=-1)
            return dp[i][k][flag];
        int buy=0;
        int sell=0;
        if(!flag){
            buy=max(-prices[i]+solve(i+1,prices,k,n,!flag),solve(i+1,prices,k,n,flag));
        }
        else {
            sell=max(prices[i]+solve(i+1,prices,k-1 ,n,!flag),solve(i+1,prices,k,n,flag));
        }
        return dp[i][k][flag]=max(buy,sell); 
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size(); 
        memset(dp,-1,sizeof(dp));
        return solve(0,prices,k,n,0);
    }
};