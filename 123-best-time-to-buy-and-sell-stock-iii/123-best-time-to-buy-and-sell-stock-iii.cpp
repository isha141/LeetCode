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
       vector<vector<int>>prev(2,vector<int>(3,0));
        for(int i=0;i<=1;++i){
            for(int j=0;j<=2;++j){
              prev[i][0]=0;
            }
        }
       
        for(int i=n-1;i>=0;--i){ 
             vector<vector<int>>curr(2,vector<int>(3,0));
            for(int buy=0;buy<=1;++buy){
                for(int count=1;count<=2;++count){ 
                    if(buy)
                   curr[buy][count]=max(-prices[i]+prev[0][count],prev[1][count]);
                    else
                 curr[buy][count]=max(prices[i]+prev[1][count-1],prev[0][count]);
                }
            } 
            prev=curr;
        }
        return prev[1][2];
    }
};