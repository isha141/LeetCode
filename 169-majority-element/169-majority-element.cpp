class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end()); 
        int low=0;
        int high=nums.size()-1;
        int mid=(low+high)/2;
        return nums[mid];
    }
};