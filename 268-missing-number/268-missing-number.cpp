class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int a=0;
        int b=0;
        int ans;
        for(int i=0;i<=n;i++)
            a=a^i;
        for(auto itr: nums)
            b=b^itr;
        return a^b;
    }
};
