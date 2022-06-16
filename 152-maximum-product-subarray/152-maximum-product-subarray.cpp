class Solution {
public:
    int maxProduct(vector<int>& nums) {
      int n=nums.size();
        vector<int>dp1(n);
        vector<int>dp2(n);
       for(int i=0;i<n;i++){
           dp1[i]=nums[i];
           dp2[i]=nums[i];
       }         
        int ans=nums[0];
        for(int i=1;i<n;++i){
            dp1[i]=min(nums[i], nums[i]*  ( nums[i]>=0 ?dp1[i-1]:dp2[i-1]));
            dp2[i]=max(nums[i], nums[i]* (nums[i]>=0 ? dp2[i-1]:dp1[i-1]));
            ans=max(ans,max(dp2[i],dp1[i]));
        }
        return ans;
    }
};