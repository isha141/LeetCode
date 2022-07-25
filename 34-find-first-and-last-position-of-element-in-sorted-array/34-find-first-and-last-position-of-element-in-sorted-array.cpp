class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                int i=mid;
                    int j=mid;
                while(i>=0 && nums[i]==target)
                    i--;
                while(j<nums.size() && nums[j]==target)
                    j++;
                return 
                {i+1,j-1};
            }
            if(nums[mid]<target)
                low=mid+1;
            else
                 high=mid-1;
        }
        return {-1,-1};
    }
};