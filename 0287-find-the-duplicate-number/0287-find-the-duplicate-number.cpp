class Solution { 
    int ok(int mid,vector<int>&nums){
        int count=0;
        for(auto itr: nums){
            if(itr<=mid)
                 count+=1;
        }
         return count;
    }
public:
    int findDuplicate(vector<int>& nums) {
         int low=0;
        int high=nums.size(); 
        int ans=0;
         while(low<=high){
             int mid=(low+high)>>1;
             if(ok(mid,nums)>mid){
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