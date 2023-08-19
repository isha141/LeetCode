class Solution {
public:
    int findPeakElement(vector<int>& nums) {
         int n=nums.size();
          int low=0;
          int high=n-1;
          while(low<high){
              int mid=(low+high)>>1;
              if((mid==0 || (nums[mid]>nums[mid-1])) && (mid==n or nums[mid]>nums[mid+1]))
                    return mid;
              if(mid==0 or nums[mid-1]<nums[mid]){
                   low=mid+1;
              }
              else{
                  high=mid-1;
              }
          }
         return low;
        
    }
};