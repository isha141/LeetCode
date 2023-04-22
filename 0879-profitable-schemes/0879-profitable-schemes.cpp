int dp[101][101][103];
class Solution {  
int mod=1e9 + 7;
    private:
    int solve(int i,int count,int profit,int n,int mini,vector<int>&g,vector<int>&p){
    //     if(i>=n)
    //          return 0;
        if(i>=g.size()){
            if(count<=n && profit>=mini)
                 return 1;
            return 0;
        }
        if(n<count) 
            return 0;
         if(dp[i][count][profit]!=-1)
              return dp[i][count][profit];
        int take=0;
        int not_take=0;
        take=solve(i+1,count+g[i],min(mini,profit+p[i]),n,mini,g,p);
        not_take=solve(i+1,count,profit,n,mini,g,p);
        return dp[i][count][profit]= ( take % mod + not_take % mod) %mod;
    }
public:
    int profitableSchemes(int n, int mini, vector<int>& g, vector<int>& p) { 
         memset(dp,-1,sizeof(dp));
         return solve(0,0,0,n,mini,g,p);
    }
};