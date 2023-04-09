class Solution {
public:
    vector<long long> distance(vector<int>& nums) { 
        int n=nums.size();
        vector<long long> ans(n,0); 
        map<long,long>mp;
        map<long ,long>cnt;
        for(int i=0;i<n;++i){
            ans[i]=abs(i*cnt[nums[i]]-mp[nums[i]]);
            mp[nums[i]]+=i;
            cnt[nums[i]]++;
        }
        mp.clear();
        cnt.clear();
        map<long,long>right,sum; 
        for(int i=n-1;i>=0;--i){
            ans[i]+=abs(i*right[nums[i]]-sum[nums[i]]);
            right[nums[i]]++;
            sum[nums[i]]+=i;
        }
        return ans;
    }
};