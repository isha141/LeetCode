class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans=0;
        multiset<int>m;
        int i=0;
        int j=0;
        while(j<nums.size()){
            m.insert(nums[j]);
            if(*m.rbegin()-*m.begin()>limit)
                m.erase(m.find(nums[i++]));
            j++;
        }
        return j-i;
    }
};