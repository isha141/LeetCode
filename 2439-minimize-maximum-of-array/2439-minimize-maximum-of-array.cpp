class Solution {
    int solve(vector<int>&nums,long long mid){
        if(nums[0]>mid)
            return 0;
        long long sum=nums[0];
        for(int i=1;i<nums.size();++i){
           sum+=nums[i];
            if(sum>(i+1)*mid)
                return 0;
        }
        return 1;
    }
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n=nums.size();
        long long low=0;
        int ans=1e9;
        long long high=1e9;
        while(low<=high){
            long long mid=(low+high)>>1;
            if(solve(nums,mid)){
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};