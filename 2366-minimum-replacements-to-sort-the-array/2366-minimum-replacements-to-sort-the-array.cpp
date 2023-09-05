class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
         int n=nums.size();
         long long ans=0;
         int maxi=nums[n-1];
         for(int i=n-2;i>=0;--i){
             if(nums[i]>maxi){
                int parts=((nums[i]+maxi-1)/maxi);
                ans+=parts-1;
                maxi=nums[i]/parts;
             }
             else{
                 maxi=nums[i];
             }
         }
         return ans;
    }
};