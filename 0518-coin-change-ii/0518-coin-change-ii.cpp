class Solution {
public:
    int change(int amount, vector<int>& coins) {
         int n=coins.size();
         vector<vector<int>>dp(n,vector<int>(amount+1,0));
         for(int i=0;i<=amount;++i){
             if(i%coins[0]==0){
                 dp[0][i]=1;
             }
         }
         for(int i=1;i<n;++i){
             for(int tot=0;tot<=amount;++tot){
                 int not_take=0;
                 int take=0;
                 if(coins[i]<=tot){
                     take=dp[i][tot-coins[i]];
                 }
                 not_take=dp[i-1][tot];
                 dp[i][tot]=(take+not_take);
             }
         }
         return dp[n-1][amount];
    }
};