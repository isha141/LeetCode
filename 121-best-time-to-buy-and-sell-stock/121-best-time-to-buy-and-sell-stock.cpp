class Solution {
public:
    int maxProfit(vector<int>& nums) { 
        int pr=0;
        int low=0;
        int high=0;
        int n=nums.size();
        while(high<n)
        {
            if(nums[high]<=nums[low])
            {
                low=high;
            }
            else
                pr=max(pr,nums[high]-nums[low]);
            high++;
        }
        return pr;
        
    }
};