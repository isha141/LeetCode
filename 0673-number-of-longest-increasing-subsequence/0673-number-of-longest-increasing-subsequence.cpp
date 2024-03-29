class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
         int n=nums.size();
         vector<int>count(n,0);
         vector<int>dp(n,0);
         // dp[0]=1; 
          for(int i=0;i<n;++i) {
           count[i]=1; 
           dp[i]=1;
         }
         int maxi=1;
         for(int i=1;i<n;++i){
             for(int j=0;j<i;++j){
                 if(nums[j]<nums[i]){
                     if(dp[i]<dp[j]+1){
                         dp[i]=dp[j]+1;
                         count[i]=count[j];
                     } 
                     else if(dp[i]==dp[j]+1){
                         count[i]+=count[j];
                     }
                 } 
             }
             maxi=max(maxi,dp[i]);
         } 
        int ans=0;
        for(auto i=0;i<n;++i){
              if(dp[i]==maxi){
                  ans+=count[i];
              }
        }
         return ans;
    }
};