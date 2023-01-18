class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
          int n=nums.size();
        int sum=0;
        int ans=INT_MIN;
        int mini_sum=INT_MAX;
        int max_sum=INT_MIN; 
        int curr_max=0;
        int curr_min=0;
        for(int i=0;i<n;++i){
            sum+=nums[i];
            ans=max(ans,sum); 
            curr_max=max(curr_max+nums[i],nums[i]);
            max_sum=max(max_sum,curr_max); 
            curr_min=min(curr_min+nums[i],nums[i]);
            mini_sum=min(mini_sum,curr_min);
            ans=max(ans,max_sum);
        } 
        // cout<<mini_sum<<endl;
        if(sum==mini_sum){
            return max_sum;
        }
        return max(ans,sum-mini_sum);
    }
};