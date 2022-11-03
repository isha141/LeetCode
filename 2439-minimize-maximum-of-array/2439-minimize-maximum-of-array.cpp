class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        long long sum=0;
        for(int i=0;i<n;++i){
            sum+=nums[i];
            ans=max((sum+i)/(i+1),ans);
        }
        return ans;
    }
};