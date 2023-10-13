class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
       long long ans=0;
        int n=nums.size();
       int maxi=nums[n-1];
        for(int i=n-2;i>=0;--i){
            if(nums[i]>maxi){
                int part=(nums[i]+maxi-1)/maxi;
                ans+=part-1;
                maxi=nums[i]/part;
            }
            else{
                maxi=nums[i];
            }
        }
         return ans;
    }
};