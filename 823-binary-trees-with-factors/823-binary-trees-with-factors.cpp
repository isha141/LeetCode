#define ll long 
class Solution { 
    const ll mod=1e9+7;
    private:
    int solve(int i,vector<int>&nums,int n)
    {
        map<ll,ll>mp;
        for(auto itr: nums)
            mp[itr]++;  
        ll ans=0;
        for(int i=0;i<n;++i){ 
            ll count=0;
            for(int j=0;j<i;++j){
                if(nums[i]%nums[j]==0){
                    if(mp.find(nums[i]/nums[j])!=mp.end()){
                        count+=(mp[nums[j]]* mp[nums[i]/nums[j]]);
                    }
                }
            }
            mp[nums[i]]+=(count)%mod; 
            // ans+=mp[nums[i]]%mod;
        }
        // ll ans=0;
        for(auto [x,y] : mp){
            ans=(ans+(y))%mod;
        }
        return ans;
    }
public:
    int numFactoredBinaryTrees(vector<int>& nums) { 
        sort(nums.begin(),nums.end());
        int n=nums.size();
        return solve(0,nums,n);
    }
};