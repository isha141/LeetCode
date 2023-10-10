class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        set<int>s(nums.begin(),nums.end());
        nums.clear();
        for(auto itt:s){
            nums.push_back(itt);
        }
         int ans=1;
        for(auto i=0;i<nums.size();++i){
            int upp=nums[i]+n-1;
            int ind2=upper_bound(nums.begin(),nums.end(),upp)-nums.begin();
            ans=max(ans,ind2-i);
        } 
        return n-ans;
    }
};