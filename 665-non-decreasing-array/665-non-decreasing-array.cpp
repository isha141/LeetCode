class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;++i){
            if(nums[i]>nums[i+1]){
                int prev=nums[i];
                nums[i]=nums[i+1];
                if(is_sorted(nums.begin(),nums.end()))
                    return 1;
                nums[i]=prev;
                nums[i+1]=nums[i];
                if(is_sorted(nums.begin(),nums.end()))
                    return 1;
                else
                    return 0;
            }
        }
        return 1;
    }
};