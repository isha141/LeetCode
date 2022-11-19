class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size(); 
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.count(target-nums[i]))
            {
                return {i,mp[target-nums[i]]};
            }
            else
                mp[nums[i]]=i;
        }
        return {};
    }
};