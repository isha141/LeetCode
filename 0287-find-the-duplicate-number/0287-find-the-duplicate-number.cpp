class Solution { 
    int helper(int mid,vector<int>&nums){
        int n=nums.size();
        int count=0;
        for(auto itr: nums){
            if(itr<=mid)
                count+=1;
        }
         return count;
    }
public:
    int findDuplicate(vector<int>& nums) {
         int low=1;
         int high=nums.size();
          int ans=-1;
          while(low<=high){
              int mid=(low+high)>>1;
              if(helper(mid,nums)>mid){
                  ans=mid;
                  high=mid-1;
              }
              else
                  low=mid+1;
          }
         return ans;
    }
};