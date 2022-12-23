// int dp[5003][3];
class Solution { 
    private:
    // int solve(int i,int buy,vector<int>&p,int n){
    //     if(i>=n)
    //         return 0;
    //     int take=0;
    //     int not_take=0;
    //     if(dp[i][buy]!=-1) return dp[i][buy];
    //     if(buy==0)
    //     take=max(-p[i]+solve(i+1,1,p,n),solve(i+1,0,p,n));
    //     else
    //     not_take=max(p[i]+solve(i+2,0,p,n),solve(i+1,1,p,n));
    //     return dp[i][buy]=max(take,not_take);
    // }
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
       vector<vector<int>>dp(n+2,vector<int>(3,0));
        for(int i=n-1;i>=0;--i){
            for(int j=0;j<=1;++j){ 
                 int take=0;
                 int not_take=0;
                if(!j){
                    take=max(-p[i]+dp[i+1][1],dp[i+1][0]);
                }
                else{
              not_take=max(p[i]+dp[i+2][0],dp[i+1][1]);
                }
            dp[i][j]=max(take,not_take);
            }
        }
        return dp[0][0];
    }
};