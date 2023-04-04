class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
          int n=nums.size();
          int cnt[101]={0}; 
          int ans=0;
         // for(auto itr: nums)
              // cnt[itr]++;
          for(auto itr: nums){  
           ans+=(itr+k<=100?cnt[itr+k]:0)+(itr-k>=1?cnt[itr-k]:0);   
              cnt[itr]++;
          }
        return (ans);
    }
};