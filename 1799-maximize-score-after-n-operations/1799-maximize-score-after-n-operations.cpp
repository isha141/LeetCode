class Solution { 
    private:
     int n; 
     int dp[15][500000];
     int solve(int i,vector<int>&nums,int c,int mask){
         if(c==n/2){
             return 0;
         }
          if(dp[c][mask]!=-1)
               return dp[c][mask]; 
         int ans=0;
          for(int j=0;j<n;++j){
              for(int k=j+1;k<n;++k){
                  if((mask &(1<<j))==0 && (mask & (1<<k))==0){
                      int new_mask=(mask|(1<<j));
                       new_mask=(new_mask|(1<<k));
                     ans=max(ans,(c+1)*__gcd(nums[j],nums[k])+solve(i+1,nums,c+1,new_mask));
                  }
              }
          }
          return dp[c][mask]=ans;
     }
public:
    int maxScore(vector<int>& nums) {
         n=nums.size(); 
        memset(dp,-1,sizeof(dp));
         return solve(0,nums,0,0);
    }
};