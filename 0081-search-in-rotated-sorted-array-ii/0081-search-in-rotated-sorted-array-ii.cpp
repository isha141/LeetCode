class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int high=nums.size()-1;
        int low=0;
        while(low<=high){
            int mid=(low+high)>>1;
            if(nums[mid]==target) 
                return 1;  
            if(nums[low]==nums[mid]&& nums[mid]==nums[high]){
                low++;
                high--;
                continue;
            }
            if(nums[low]<=nums[mid]){
                if(target>=nums[low] && target<nums[mid]){
                    high=mid-1;
                }
             else
                 low=mid+1;
                // continue;
            }
            else if(nums[mid]<=nums[high]){
                if(target>nums[mid] && target<=nums[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                    
                }
            }
        }
        return 0;
    }
};