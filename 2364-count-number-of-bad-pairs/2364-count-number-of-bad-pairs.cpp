#define ll long long
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {  
        ll n=nums.size();
       map<ll,ll>mp;
        for(int i=0;i<nums.size();++i){
            mp[nums[i]-i]++;
        }
        ll total=(n*(n-1))/2; 
        ll ans=0;
        for(auto itr: mp)
            ans+=(itr.second*(itr.second-1))/2;
        return total-ans;
        
        
    }
};