class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) { 
        int n=nums.size();
          vector<int>dp(n,0),hash(n,0); 
        sort(nums.begin(),nums.end()); 
        int maxi=0;
        int len=0;
        for(int i=0;i<n;++i){ 
            hash[i]=i;
            for(int j=0;j<i;++j){
                int take=0;
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
        if(dp[i]>maxi){
            maxi=dp[i];
            len=i;
        } 
        } 
        vector<int>ans;
        while(hash[len]!=len){
            ans.push_back(nums[len]);
            len=hash[len];
        } 
        ans.push_back(nums[len]);
        // re
        return ans;
    }
};