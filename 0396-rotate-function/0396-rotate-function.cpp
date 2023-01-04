class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int ans=0; 
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;++i){
            ans+=nums[i]*i;
            sum+=nums[i];
        }
        int maxi=INT_MIN; 
        maxi=max(maxi,ans);
        vector<int>dp(n,0);
        dp[0]=ans;
        int k=n-1;
        for(int i=1;i<n;++i){
            dp[i]=dp[i-1]+sum-(n*nums[k]);
            k--;
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};