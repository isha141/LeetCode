class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        map<int,int>mp;
        for(auto itr: nums)
        {
            mp[itr]++;
            if(mp[itr]==2)
                ans.push_back(itr);
        }
        return ans;
    }
};