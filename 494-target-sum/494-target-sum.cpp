class Solution { 
    private:
    int solve(int i,vector<int>&nums,int &target,int sum)
    {
        if(i>=nums.size()){
            return sum==target;
        }
        int l=solve(i+1,nums,target,sum+nums[i]);
        int r=solve(i+1,nums,target,sum-nums[i]);
        return l+r;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size(); 
        int sum=0;
        return solve(0,nums,target,sum);
    }
};