class Solution {
public:
    int countNicePairs(vector<int>& nums) {
         int n=nums.size();
         int ans=0;
         int mod=1e9+7;
         map<long long,int>mp;
         for(int i=0;i<n;++i){
             string s=to_string(nums[i]);
             reverse(s.begin(),s.end());
             int temp=stoll(s);
             long rem=nums[i]-temp;
             if(mp.find(rem)!=mp.end()){
                 ans+=(mp[rem])%mod;
                 ans%=mod;
             }
             mp[rem]+=1;
         }
         return ans;
    }
};