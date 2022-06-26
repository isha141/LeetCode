class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int ans=0;
        for(auto itr: nums)
            ans=ans| itr;
        return ans;
    }
};