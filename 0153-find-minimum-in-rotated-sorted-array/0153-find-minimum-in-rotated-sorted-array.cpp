class Solution {
public:
    int findMin(vector<int>& nums) {
          int low=0;
          int n=nums.size();
        if(n==1) 
            return nums[0];
          int high=nums.size()-1;
         int mini=nums[0];
          while(low<=high){
              int mid=(low+high)>>1;
              if(mid-1>0 && mid+1<n &&  nums[mid-1]>nums[mid]){
                  mini=min(mini,nums[mid]);
                  return mini;
              }
              if(mid-1>=0 && nums[mid-1]>nums[mid]){
                  mini=min(mini,nums[mid]);
                  return mini;
              }
              if(nums[low]<=nums[mid] && nums[mid]<nums[high]){
                  high=mid-1;
              }
              else if(nums[low]>nums[mid] && nums[mid]<nums[high]){
                  high=mid-1;
              }
              else{
                  low=mid+1;
              }
          }
        return mini;
    }
};