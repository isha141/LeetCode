class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
         vector<int>count(n,1); 
        int ans=0;
        int maxi=1;
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                if(nums[i]>nums[j] && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    count[i]=count[j];
                }
                else if(nums[i]>nums[j] && dp[i]==dp[j]+1){
                    count[i]+=count[j];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        for(int i=0;i<n;++i){
            if(dp[i]==maxi){
                ans+=count[i];
            }
        }
         return ans;
    }
};