class Solution {
    private:
    int solve(vector<int>&nums){ 
         int n=nums.size();
        vector<int>dp(n+1,-1); 
        if(n==1)
             return nums[0];
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;++i){
            int take=nums[i]+dp[i-2];
            int not_take=dp[i-1];
            dp[i]=max(take,not_take);
        }
        return dp[n-1];
    }
public:
    int rob(vector<int>& nums) {
           int n=nums.size(); 
           if(n==1)
                return nums[0];
          vector<int>v1;
          vector<int>v2;
          for(int i=0;i<n-1;++i)
              v1.push_back(nums[i]);
          for(int j=1;j<n;++j){
              v2.push_back(nums[j]);
          }
          int ans1=solve(v1);
          int ans2=solve(v2);
        return max(ans1,ans2);
    }
};