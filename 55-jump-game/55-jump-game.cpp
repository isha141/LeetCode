class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int goal=0;
        for(int i=0;i<n;i++)
        {
            if(goal<i)
                return false;
            goal=max(goal,i+nums[i]);
        }
        return true;
    }
};