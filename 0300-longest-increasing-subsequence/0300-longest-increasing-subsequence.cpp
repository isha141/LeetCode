class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
          int n=nums.size();
          vector<int>ans;
          for(int i=0;i<n;++i){
              if(ans.size()==0 || ans.back()<nums[i]){
                  ans.push_back(nums[i]);
              }
              else{
                  int ind=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                  ans[ind]=nums[i];
              }
          }
          return ans.size();
    }
};