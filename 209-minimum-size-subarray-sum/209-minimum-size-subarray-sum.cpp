class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int low=0;
        int high=0; 
        int ans=INT_MAX;
        while(high<n){
            if(sum<target)
                sum+=nums[high++];
            while(sum>=target){
                ans=min(ans,high-low);
                sum-=nums[low++];
            }
        }
        return ans==INT_MAX?0: ans;
    }
};