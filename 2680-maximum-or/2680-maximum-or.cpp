long long dp[100006][20];
class Solution { 
    private:
    int n;
     long long solve(int i,vector<int>&nums,int k){
         if(i>=n) return 0;   
         if(k<0) return 0;
         if(dp[i][k]!=-1) 
             return dp[i][k];
         long long ans=nums[i] |solve(i+1,nums,k);
         for(int j=1;j<=k;++j){
              long long temp=(1ll*nums[i]<<j);
             ans=max(ans,(solve(i+1,nums,k-j)|temp));
         }
         return dp[i][k]=ans;
     }
public:
    long long maximumOr(vector<int>& nums, int k) {
        n=nums.size(); 
        memset(dp,-1,sizeof(dp));
        return solve(0,nums,k);
    }
};