class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int ind=0; 
        int n=nums.size(); 
        if(nums.size()==1) 
            return 0;
        int i=1;
        for( i=1;i<n-1;i++)
        {
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1])
                return i;
        }
        if(n>1 && nums[0]>nums[1]) 
            return 0;
        else 
            return n-1; 
        
    }
};