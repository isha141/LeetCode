class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
         int n=nums.size();
         int sum=0;
         int ans=0;
         map<int,int>mp;
          for(int i=0;i<n;++i){
              sum+=nums[i];
              if(sum==k){
                  ans+=1;
              }
              if(mp.find(sum-k)!=mp.end()){
                  ans+=mp[sum-k];
              } 
              mp[sum]++;
          }
        return ans;
    }
};