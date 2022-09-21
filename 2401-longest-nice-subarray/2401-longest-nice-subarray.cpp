class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        int i=0;
        int j=0;
        int a=0;
        while(j<n)
        {
            while((i<j && a & nums[j])>0)
                a^=nums[i++];
            a|=nums[j];
            res=max(res,j-i+1);
            j++;
        }
        return res;
    }
};