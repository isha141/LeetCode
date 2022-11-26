class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;++i){
            if(i>maxi)
                return 0;
            maxi=max(maxi,i+nums[i]);
        }
        return 2;
    }
};