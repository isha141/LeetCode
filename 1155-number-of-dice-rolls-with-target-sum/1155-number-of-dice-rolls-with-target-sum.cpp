class Solution {  
    private:
    int dp[32][1002]={0}; 
    #define MOD 1000000007
   int solve(int n,int k,int target){
        if(n==0 && target==0) {
              return 1;
        } 
       if(n<=0 || target<=0) return 0;
        if(dp[n][target] !=-1) return dp[n][target];
       int res=0;
        for(int i=1;i<=k;++i){
           res=((res%MOD+ solve(n-1,k,target-i))%MOD)%MOD; 
        }
            dp[n][target]=res; 
        return dp[n][target];
    }
public: 
    int numRollsToTarget(int n, int k, int target) {  
        memset(dp,-1,sizeof(dp));
     return solve(n,k,target);   
    }
};