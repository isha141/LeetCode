class Solution {  
    int dp[31][1001];
    private:
   int solve(int sum,int n,int k,int target){
        if(n==0 && sum==target) {
              return 1;
        } 
       if(n<0) return 0;
       if(sum>target) return 0;
        if(dp[n][sum]) return dp[n][sum]-1;
       int res=0;
        for(int i=1;i<=k;i++){ 
           // sum+=i;
           res=(res+ solve(sum+i,n-1,k,target))%1000000007; 
            dp[n][sum]=res+1;
            //sum-=i;
        }  
        return res;
    }
public: 
    int numRollsToTarget(int n, int k, int target) { 
        int sum=0;
     //   dp[0][tagret]==1;
      return solve(sum,n,k,target);  
        //return dp[99][10000]
    }
};