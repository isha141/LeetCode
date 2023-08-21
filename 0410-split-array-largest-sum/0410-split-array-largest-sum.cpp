class Solution {
     private:
    int ok(int mid,vector<int>&nums,int k){
         int n=nums.size();
         int sum=0;
         for(auto i=0;i<n;++i){
              if(nums[i]>mid)
                    return 0;
             if((sum+nums[i])>mid && k>1){
                 sum=nums[i];
                 k-=1;
             } 
             else if(sum+nums[i]<=mid){
                 sum+=nums[i];
             }
             else
                 return 0;
         }
         if(k)
        return 1; 
        else
            return 0;
    }
public:
    int splitArray(vector<int>& nums, int k) {
         int low=0;
         int high=1e9;
         int ans=1e9;
          while(low<=high){
              int mid=(low+high)>>1;
              if(ok(mid,nums,k)){
                  ans=mid;
                  high=mid-1;
              }
              else{
                  low=mid+1;
              }
          }
        return ans;
    }
};