class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0; 
        unordered_map<int,int>mp;
        int n=nums.size();
        int i=0; 
        long long sum=0;
        while(i<k){
            mp[nums[i]]++;
             sum+=nums[i];
            i++;
        }
        if(mp.size()==k)
            ans=sum;
        while(i<n){
            mp[nums[i]]++;
            sum+=nums[i];
            sum-=nums[i-k];
            mp[nums[i-k]]--;
            if(mp[nums[i-k]]==0)
                mp.erase(nums[i-k]);
            if(mp.size()==k)
                ans=max(ans,sum);
            i++;
        }
        return ans;
    }
};