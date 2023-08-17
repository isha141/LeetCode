class Solution {
public:
    int minMoves(vector<int>& nums) {
          int n=nums.size();
          int maxi=0;
          int mini=INT_MAX; 
        long ans=0;
          for(auto itr: nums){
              maxi=max(maxi,itr);
              mini=min(mini,itr);
          }
          for(auto itr: nums){
              ans+=abs(itr-mini);
          } 
        return ans;
    }
};