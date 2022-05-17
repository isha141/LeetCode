class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
       unordered_set<int>s;
        for(int i=0;i<nums.size();i++)
        {
            if(s.size()>k)
            {
                s.erase(nums[i-k-1]);
            }
            if(s.count(nums[i]))
                return true;
            else
            s.insert(nums[i]);
        }
        return false;
    }
};