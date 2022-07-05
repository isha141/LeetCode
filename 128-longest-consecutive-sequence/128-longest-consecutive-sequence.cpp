class Solution {
public:
    int longestConsecutive(vector<int>& nums) { 
        if(nums.size()==0) return 0;
        int n=nums.size();
        int res=0;
        sort(nums.begin(),nums.end());
        int len=1;
        for(int i=0;i<n-1;++i){ 
            if(nums[i]==nums[i+1])
                continue;
            if(nums[i]+1==nums[i+1] ){
                len++;
            }
            else{
                res=max(res,len);
                len=1;
            }
        }
        res=max(res,len);
        return res;
    }
};