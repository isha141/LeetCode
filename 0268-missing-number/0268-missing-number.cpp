class Solution { 
    private: 
    int n;
    int ok(int mid,vector<int>&nums){
        int count=0;
        for(int i=0;i<n;++i){
            if(nums[i]<=mid)
                  count+=1;
        }
        return count;
    }
public:
    int missingNumber(vector<int>& nums) {
         n=nums.size();
        int low=0;
        int high=n; 
        int ans=0;
        while(low<=high){
            int mid=(low+high)>>1; 
            // cout<<mid<<";;";
            if(ok(mid,nums)>mid){
                low=mid+1;
            }
            else{ 
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};