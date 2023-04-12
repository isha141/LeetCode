class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
         int n=nums.size();
         int ans=1e9;
         int sum=0;
         int i=0; 
        int j=0;
        while(i<n){
            sum+=nums[i]; 
            if(sum>=target){
                ans=min(ans,i+1);
            }
            while(j<n && sum-nums[j]>=target){
                ans=min(ans,i-j);
                sum-=nums[j]; 
                j++;
            }
            i++;
        }
        return ans==1e9?0:ans;
    }
};