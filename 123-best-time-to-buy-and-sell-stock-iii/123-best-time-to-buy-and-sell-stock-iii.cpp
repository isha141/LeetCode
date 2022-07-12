int dp[100001][2][3]={-1};
class Solution { 
    int solve(int ind,vector<int>&prices,int count,int buy,int n,vector<vector<vector<int>>>&dp)
    {
        if(ind>=n)
            return 0; 
        if(count>2) return 0; 
        
        int maxi=-1e9; 
        if(dp[ind][buy][count]!=-1)
            return dp[ind][buy][count]; 
        if(count<=2){
        if(buy)
         return  dp[ind][buy][count]=max(-prices[ind]+solve(ind+1,prices,count+1,!buy,n,dp),solve(ind+1,prices,count,buy,n,dp)); 
            else
           return dp[ind][buy][count]=max(prices[ind]+solve(ind+1,prices,count,!buy,n,dp),solve(ind+1,prices,count,buy,n,dp));
            dp[ind][buy][count]=maxi;
        }
        return dp[ind][buy][count];
    }
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        int n=prices.size();   
         vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int buy=0;buy<=1;++buy){
            for(int cap=0;cap<=2;++cap)
                dp[n][buy][cap]=0;
        }
        for(int i=0;i<=n;++i){
            for(int j=0;j<=1;++j){
                dp[i][j][0]=0;
            }
        }
       
        for(int i=n-1;i>=0;--i){
            for(int buy=0;buy<=1;++buy){
                for(int count=1;count<=2;++count){ 
                    
                    if(buy)
                  dp[i][buy][count]=max(-prices[i]+dp[i+1][0][count],dp[i+1][1][count]);
                    else
                 dp[i][buy][count]=max(prices[i]+dp[i+1][1][count-1],dp[i+1][0][count]);
                }
            }
        }
        return dp[0][1][2];
    }
};