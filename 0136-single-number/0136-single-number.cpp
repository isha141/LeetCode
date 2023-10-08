class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(auto itr: nums){
            ans^=itr;
        }
        return ans;
    }
};