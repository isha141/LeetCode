class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int mini=INT_MAX;
        for(auto itr: nums){
            mini=min(mini,itr);
        }
        for(auto itr: nums){
            ans+=(itr-mini);
        }
        return ans;
    }
};