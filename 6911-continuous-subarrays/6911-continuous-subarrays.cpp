class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
            int n=nums.size();
           map<int,int>mp;
           long long ans=0;
           int j=0;
          for(int i=0;i<n;++i){
              mp[nums[i]]++;
              while((mp.rbegin()->first-mp.begin()->first)>2){
                 mp[nums[j]]--;
                  if(mp[nums[j]]==0){
                      mp.erase(nums[j]);
                  }
                  j++;
              }
              ans+=(i-j+1);
          }
        return ans;
    }
};