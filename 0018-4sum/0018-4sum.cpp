class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
         sort(nums.begin(),nums.end());
         int n=nums.size();
         vector<vector<int>>ans;
         for(int i=0;i<n;){
             for(int j=i+1;j<n;){
                 long long sum=nums[i]+nums[j];
                 long long rem=target-(sum);
                 int low=j+1;
                 int high=n-1;
                 while(low<high){
                     if(nums[low]+nums[high]==rem){
                         ans.push_back({nums[i],nums[j],nums[low],nums[high]});
                         int k=low;
                         while(k<n && nums[k]==nums[low])
                             k++;
                         low=k;
                         k=high;
                         while(k>low && nums[k]==nums[high])
                             k--;
                         high=k;
                     }
                     else if(nums[low]+nums[high]<rem)
                           low++;
                     else
                         high--;
                 }
                 int k=j;
                 while(k<n && nums[j]==nums[k])
                       k++;
                 j=k;
             }
            int k=i;
            while(k<n && nums[i]==nums[k])
                       k++;
           i=k;
         }
         return ans;
    }
};